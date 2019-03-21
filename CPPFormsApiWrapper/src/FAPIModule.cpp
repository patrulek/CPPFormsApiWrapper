#include "FAPIModule.h"

#include "FAPIContext.h"
#include "FAPILogger.h"
#include "Property.h"
#include "FormsObject.h"

#include "FAPIUtil.h"

#include "d2fpr.h"

namespace CPPFAPIWrapper {
	using namespace std;

	FAPIModule::FAPIModule(FAPIContext * _ctx, const std::string & _filepath) 
		: ctx(_ctx), filepath(_filepath)	{ TRACE_FNC(_filepath) }
	FAPIModule::~FAPIModule() { TRACE_FNC(""); }

	bool FAPIModule::hasInternalObject(const int _type_id, const string & _fullname) const { TRACE_FNC(to_string(_type_id) + " | " + _fullname)
		auto splits = splitString(_fullname, ".");
		d2fob * obj{ nullptr };
		unordered_map<d2fob *, vector<d2fob *>> objects{ { mod.get(), {} } };


		for (const auto & split : splits) {
			FAPILogger::debug(split);

			for (auto & objects_ : objects) {
				if (!objects[objects_.first].empty())
					continue;

				for (const auto & type : type_hierarchy) {
					obj = nullptr;
					int status = d2fobfo_FindObj(getContext()->getContext(), objects_.first, stringToText(split), type.first, &obj);

					if (status != D2FS_SUCCESS && status != D2FS_OBJNOTFOUND)
						throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, "", status };

					if (obj) {
						objects_.second.push_back(obj);
						objects[obj] = {};
					}
				}
			}
		}

		obj = nullptr;

		for (auto & objects_ : objects) {
			if (!objects_.second.empty())
				continue;

			d2fotyp v_obj_typ;
			d2fobqt_QueryType(getContext()->getContext(), objects_.first, &v_obj_typ);

			if (v_obj_typ == _type_id) {
				obj = objects_.first;
				break;
			}
		}

		return obj;
	}

	void FAPIModule::markObject(FormsObject * _forms_object) { TRACE_FNC("")
		if (find(marked_objects.begin(), marked_objects.end(), _forms_object) == marked_objects.end())
			marked_objects.emplace_back(_forms_object);
	}

	void FAPIModule::unmarkObject(FormsObject * _forms_object) { TRACE_FNC("")
		auto idx = find(marked_objects.begin(), marked_objects.end(), _forms_object);

		if (idx != marked_objects.end())
			marked_objects.erase(idx);
	}

	bool FAPIModule::hasObject(const int _type_id, const string & _name) const { TRACE_FNC(to_string(_type_id) + " | " + _name)
		return root->hasObject(_type_id, _name);
	}

	Expected<FormsObject> FAPIModule::getObject(const int _type_id, const string & _fullname) const { TRACE_FNC(to_string(_type_id) + " | " + _fullname)
		auto splits = splitString(_fullname, ".");
		vector<FormsObject *> to_process{ root.get() };
		string name{ *splits.end() };

		for (const auto & split : splits) {
			FAPILogger::debug(split);

			vector<FormsObject *> new_process;

			while (!to_process.empty()) {
				auto curr{ to_process[0] }; to_process.erase(to_process.begin());
				auto & children_types{ type_hierarchy[curr->getId()] };

				for (const auto & type : children_types) {
					try {
						auto child = curr->getObject(type, split).get();

						if (child->getId() == _type_id && child->getName() == name)
							return Expected<FormsObject>(child);
						else
							new_process.emplace_back(child);
					}
					catch (exception & ex) { FAPILogger::warn(ex.what()); }
				}
			}

			to_process.insert(to_process.end(), new_process.begin(), new_process.end());
		}

		return Expected<FormsObject>(nullptr);
	}

	int FAPIModule::traverseObjects(d2fob * _obj, int _level, FormsObject * _forms_object) { TRACE_FNC("")
		if (root && _level == 0)
			root = nullptr;

		if (!_obj)
			_obj = mod.get();

		d2fctx * ctx = this->ctx->getContext();
		d2fob * v_subobj, *v_owner;
		d2fotyp v_obj_typ;
		int status;

		/*
		** Get object type.
		*/
		status = d2fobqt_QueryType(ctx, _obj, &v_obj_typ);

		if (status != D2FS_SUCCESS)
			return status;

		/*
		** If the object type is bogus, then this is something we're not
		** supposed to be messing with, so we won't.
		*/
		if (v_obj_typ > D2FFO_MAX)
			return D2FS_SUCCESS;

		/*
		** Make sure object is named.  We shouldn't be messing with any
		** object that doesn't have a name.
		*/
		if (d2fobhp_HasProp(ctx, _obj, D2FP_NAME) != D2FS_YES)
			return D2FS_SUCCESS;

		FormsObject * fo = new FormsObject{ this, v_obj_typ, _obj, _level };

		if (!root)
			root = unique_ptr<FormsObject>{ fo };

		vector<int> object_properties;

		/*
		** Walk through all properties.
		*/
		for (int prop_num = D2FP_MIN + 1; prop_num < D2FP_MAX + 1; ++prop_num) {
			text * v_prop_name{ nullptr };

			/*
			** If the object doesn't have this property, or we can't get
			** the name of the property, or if the property has no name,
			** then skip to the end of the loop.
			*/
			if (d2fobhp_HasProp(ctx, _obj, prop_num) != D2FS_YES || d2fprgn_GetName(ctx, prop_num, &v_prop_name) != D2FS_SUCCESS || v_prop_name == nullptr)
				continue;

			//if( v_prop_name )
			//	free(v_prop_name);

			if (isIrrelevantProperty(prop_num))
				continue;

			int prop_type = d2fprgt_GetType(ctx, prop_num);

			if (isValueProperty(ctx, prop_num)) {
				auto property = make_unique<Property>(fo, prop_num, prop_type);

				if (prop_num == D2FP_PAR_FLNAM && property->getValue() != "")
					source_modules.insert(truncModuleName(property->getValue()));

				fo->getProperties().emplace(prop_num, move(property));
			}
			else
				object_properties.emplace_back(prop_num);
		}

		for (int prop_num : object_properties) {

			/* Get the subobject pointed to by this property. */
			status = d2fobgo_GetObjProp(ctx, _obj, prop_num, &v_subobj);

			if (status != D2FS_SUCCESS)
				return status;

			/*  Continue if there are no subobjects. */
			if (!v_subobj)
				continue;

			/* Get the owner of the subobject. */
			status = d2fobg_owner(ctx, v_subobj, &v_owner);

			if (status != D2FS_SUCCESS)
				return status;

			/*
			** If the owner of the subobject isn't the original object,
			** then it's not really a subobject, so skip it.
			** This keeps use from examining next, previous, source, the
			** canvas of an item, etc.
			*/
			if (_obj != v_owner)
				continue;

			/*
			** Recursively process the subobject and all its siblings.
			*/
			while (v_subobj) {
				traverseObjects(v_subobj, _level + 1, fo);
				status = d2fobg_next(ctx, v_subobj, &v_subobj);

				if (status != D2FS_SUCCESS)
					return status;
			}
		}

		if (_forms_object)
			_forms_object->addChild(fo);

		return D2FS_SUCCESS;
	}

	vector<FormsObject *> FAPIModule::getObjects(const int _type_id) const { TRACE_FNC(to_string(_type_id))
		return root->getObjects(_type_id);
	}

	vector<FormsObject *> FAPIModule::getAttachedLibraries() const { TRACE_FNC("")
		return getObjects(D2FFO_ATT_LIB);
	}

	vector<FormsObject *> FAPIModule::getBlocks() const { TRACE_FNC("")
		return getObjects(D2FFO_BLOCK);
	}

	vector<FormsObject *> FAPIModule::getFormTriggers() const { TRACE_FNC("")
		return getObjects(D2FFO_TRIGGER);
	}

	vector<FormsObject *> FAPIModule::getTriggers() const { TRACE_FNC("")
		auto triggers = getFormTriggers();

		for (const auto & block : getBlocks()) {
			const auto & blk_triggers = block->getObjects(D2FFO_TRIGGER);
			copy(blk_triggers.begin(), blk_triggers.end(), back_inserter(triggers));

			for (const auto & item : block->getObjects(D2FFO_ITEM)) {
				const auto & itm_triggers = item->getObjects(D2FFO_TRIGGER);
				copy(itm_triggers.begin(), itm_triggers.end(), back_inserter(triggers));
			}
		}

		return triggers;
	}

	vector<FormsObject *> FAPIModule::getProgramUnits() const { TRACE_FNC("")
		return getObjects(D2FFO_PROG_UNIT);
	}

	vector<FormsObject *> FAPIModule::getCanvases() const { TRACE_FNC("")
		return getObjects(D2FFO_CANVAS);
	}

	vector<FormsObject *> FAPIModule::getParameters() const { TRACE_FNC("")
		return getObjects(D2FFO_FORM_PARAM);
	}

	string FAPIModule::getFilepath() const { TRACE_FNC("")
		return filepath;
	}

	FAPIContext * FAPIModule::getContext() const { TRACE_FNC("")
		return ctx;
	}

	FormsObject * FAPIModule::getRoot() const { TRACE_FNC("")
		return root.get();
	}

	string FAPIModule::getName() const { TRACE_FNC("")
		return root->getName();
	}

	unordered_set<string> FAPIModule::getSourceModules() const { TRACE_FNC("")
		return source_modules;
	}
}
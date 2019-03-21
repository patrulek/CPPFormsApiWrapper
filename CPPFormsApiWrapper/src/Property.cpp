#include "Property.h"

#include "D2FPR.H"
#include "D2FOB.H"
#include "FormsObject.h"
#include "FAPIContext.h"
#include "FAPIWrapper.h"

#include "Exceptions.h"
#include "FAPILogger.h"

namespace CPPFAPIWrapper {
	using namespace std;

	Property::Property(FormsObject * _parent, int _prop_id, int _prop_type)
		: parent(_parent), prop_id(_prop_id), prop_type(_prop_type), dirty(false) { TRACE_FNC(to_string(_prop_id) + " | " + to_string(_prop_type))
		checkValue();
		checkStateOnInit();
	}

	FormsObject * Property::getParent() const { TRACE_FNC("")
		return parent;
	}

	void Property::checkValue() { TRACE_FNC("")
		value = getObjectValue();
		original_value = value;
	}

	void Property::checkStateOnInit() { TRACE_FNC("")
		auto ctx = parent->getContext()->getContext();
		auto obj = parent->getFormsObj();

		state = PropState::DEFAULT;

		if (d2fobii_IspropInherited(ctx, obj, prop_id) == D2FS_YES)
			state = PropState::INHERITED;
		else if (d2fobid_IspropDefault(ctx, obj, prop_id) != D2FS_YES)
			state = PropState::LOCAL;

		original_state = state;
	}

	void Property::checkState() { TRACE_FNC("")
		auto ctx = parent->getContext()->getContext();
		auto obj = parent->getFormsObj();

		if (!parent->isSubclassed() || state != PropState::LOCAL || isNonInheritableProperty(prop_id)) // we want to check only inherited_overriden states
			return;

		bool overriden{ false };
		string source_prop;

		for (const auto & source : parent->findSources()) {
			auto & source_props = source->getProperties();

			if (source_props.find(prop_id) != source_props.end()) {
				source_prop = source_props[prop_id]->getValue();

				if (source_prop != value)
					overriden = true;

				break;
			}
		}

		if (overriden)
			state = PropState::OVERRIDEN;
		else { // values are equal but inheritance is broken so we'd like to restore it
			int status = d2fobip_InheritProp(ctx, obj, prop_id);

			if (status != D2FS_SUCCESS)
				throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, to_string(prop_id), status };
		}

		original_state = state;
	}

	string Property::getObjectValue() { TRACE_FNC("")
		auto ctx = parent->getContext()->getContext();
		auto obj = parent->getFormsObj();

		string value_;

		if (prop_type == D2FP_TYP_BOOLEAN) {
			int v_value;
			d2fobgb_GetBoolProp(ctx, obj, prop_id, &v_value);
			value_ = to_string(v_value);
		} else if (prop_type == D2FP_TYP_NUMBER) {
			number v_value;
			d2fobgn_GetNumProp(ctx, obj, prop_id, &v_value);
			value_ = to_string(v_value);
		} else if (prop_type == D2FP_TYP_TEXT) {
			text * v_value{ nullptr };
			d2fobgt_GetTextProp(ctx, obj, prop_id, &v_value);

			if (v_value) {
				value_ = string(reinterpret_cast<char *>(v_value));
				//free(v_value);
			}
		}

		return value_;
	}

	void Property::setObjectValue() { TRACE_FNC("")
		auto ctx = parent->getContext()->getContext();
		auto obj = parent->getFormsObj();

		int status{ D2FS_SUCCESS };

		if (prop_type == D2FP_TYP_BOOLEAN)
			status = d2fobsb_SetBoolProp(ctx, obj, prop_id, stoi(value));
		else if (prop_type == D2FP_TYP_NUMBER)
			status = d2fobsn_SetNumProp(ctx, obj, prop_id, stoi(value));
		else if (prop_type == D2FP_TYP_TEXT)
			status = d2fobst_SetTextProp(ctx, obj, prop_id, reinterpret_cast<text *>(const_cast<char *>(value.c_str())));

		if (status != D2FS_SUCCESS)
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, to_string(prop_id), status };
	}

	void Property::inherit() { TRACE_FNC("")
		if (!parent->isSubclassed() || state == PropState::DEFAULT || state == PropState::INHERITED || prop_type == D2FP_TYP_OBJECT)
			return;

		auto ctx = parent->getContext()->getContext();
		auto obj = parent->getFormsObj();
		int status = d2fobip_InheritProp(ctx, obj, prop_id);

		if (status != D2FS_SUCCESS)
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, to_string(prop_id), status };

		value = getObjectValue();
		dirty = (value != original_value);

		if (dirty) {
			if (state == PropState::LOCAL)
				state = PropState::DEFAULT;
			else if (state == PropState::OVERRIDEN)
				state = PropState::INHERITED;

			parent->markProperty(this);
		}
	}

	void Property::setValue(const string & _value) { TRACE_FNC(_value)
		if (_value == original_value) {
			value = original_value;
			state = original_state;
			dirty = false;
			parent->unmarkProperty(this);
			return;
		}

		if (_value == value)
			return;

		value = _value;
		dirty = true;
		state = state != PropState::OVERRIDEN ? PropState::LOCAL : state;
		parent->markProperty(this);
	}

	PropState Property::getOriginalState() const { TRACE_FNC("")
		return original_state;
	}

	PropState Property::getState() const { TRACE_FNC("")
		return state;
	}

	int Property::getId() const { TRACE_FNC("")
		return prop_id;
	}

	int Property::getType() const { TRACE_FNC("")
		return prop_type;
	}

	bool Property::isDirty() const { TRACE_FNC("")
		return dirty;
	}

	void Property::accept() { TRACE_FNC("")
		setObjectValue();

		original_state = state;
		original_value = value;
		dirty = false;
	}

	string Property::getValue() const { TRACE_FNC("")
		return value;
	}
}

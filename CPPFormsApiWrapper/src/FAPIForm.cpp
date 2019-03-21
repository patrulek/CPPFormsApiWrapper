#include "FAPIForm.h"

#include <algorithm>
#include <fstream>
#include <regex>

#include "Property.h"
#include "FAPIWrapper.h"
#include "FAPIContext.h"
#include "FormsObject.h"
#include "FAPIUtil.h"

#include "d2ffmd.h"
#include "d2fob.h"
#include "d2falb.h"

#include "Exceptions.h"
#include "FAPILogger.h"

namespace CPPFAPIWrapper {
	using namespace std;

	FAPIForm::FAPIForm(FAPIContext * _ctx, void * _mod, const string & _filepath)
		: FAPIModule(_ctx, _filepath) { TRACE_FNC(_filepath)
		auto deleter = [this](const void * data) { d2ffmdde_Destroy(this->ctx->getContext(), const_cast<void *>(data)); };
		mod = unique_ptr<void, function<void(const void*)>>{ _mod, deleter };
	}

	FAPIForm::~FAPIForm() { TRACE_FNC("") }

	vector<FormsObject *> FAPIForm::getAllObjects() const { TRACE_FNC("")
		vector<FormsObject *> objects;
		vector<FormsObject *> to_process{ root.get() };

		while (!to_process.empty()) {
			FormsObject * curr{ to_process[0] };
			to_process.erase(to_process.begin());
			objects.emplace_back(curr);
			auto & children = curr->getChildren();

			for (const auto & entry : children)
				transform(entry.second.begin(), entry.second.end(), back_inserter(to_process), [](const auto & _child) { return _child.get(); });
		}

		return objects;
	}

	void FAPIForm::findGlobals() { TRACE_FNC("")
		globals.clear();

		auto triggers = getTriggers();
		auto prog_units = getProgramUnits();
		regex pattern{ "global.[A-Za-z0-9_!@#$%^&*()]+", regex_constants::icase };
		smatch match;

		for (const auto & trg : triggers) {
			string code = trg->getProperties().at(D2FP_TRG_TXT)->getValue();
			regex_search(code, match, pattern);
			transform(match.begin(), match.end(), inserter(globals, globals.begin()), [](const auto & _val) { return _val.str().substr(GLOBAL_OFFSET); });
		}

		for (const auto & pgu : prog_units) {
			string code = pgu->getProperties().at(D2FP_PGU_TXT)->getValue();
			regex_search(code, match, pattern);
			transform(match.begin(), match.end(), inserter(globals, globals.begin()), [](const auto & _val) { return _val.str().substr(GLOBAL_OFFSET); });
		}
	}


	void FAPIForm::inheritAllProp() { TRACE_FNC("")
		for (const auto & obj : getAllObjects())
			obj->inheritAllProp();
	}

	void FAPIForm::inheritAllPLSQL() { TRACE_FNC("")
		for (const auto & obj : getAllObjects()) {
			if (obj->getId() == D2FFO_TRIGGER)
				obj->inheritProp(D2FP_TRG_TXT);
			else if (obj->getId() == D2FFO_PROG_UNIT)
				obj->inheritProp(D2FP_PGU_TXT);
		}
	}

	void FAPIForm::inheritPLSQL(const vector<string> & _units) { TRACE_FNC("")
		for (const auto & str : _units) {
			try {
				const auto pgu = getObject(D2FFO_PROG_UNIT, str);
				pgu->inheritProp(D2FP_PGU_TXT);
			} catch (exception & ex) { FAPILogger::warn(ex.what()); }

			try {
				const auto trg = getObject(D2FFO_TRIGGER, str);
				trg->inheritProp(D2FP_TRG_TXT);
			} catch (exception & ex) { FAPILogger::warn(ex.what()); }
		}
	}

	void FAPIForm::inheritPLSQL(const vector<FormsObject *> & _units) { TRACE_FNC("")
		for (const auto & obj : _units) {
			if (obj->getId() == D2FFO_TRIGGER)
				obj->inheritProp(D2FP_TRG_TXT);
			else if (obj->getId() == D2FFO_PROG_UNIT)
				obj->inheritProp(D2FP_PGU_TXT);
		}
	}

	string FAPIForm::createObjectReportFile(const string & _filepath) { TRACE_FNC(_filepath)
		string out_file = (_filepath != "" ? _filepath.substr(0, _filepath.rfind(".")) : filepath.substr(0, filepath.rfind("."))) + ".txt";
		string cmd = "ifcmp60.exe module=\"" + filepath + "\" output_file=\"" + out_file + "\" forms_doc=YES window_state=minimize"; // TODO

		if (ctx->getConnstring() != "")
			cmd += " userid=" + ctx->getConnstring();

		FAPILogger::debug("out_file=" + out_file + " cmd=" + cmd);
		system(cmd.c_str());

		if (!fileExists(out_file))
			throw FAPIException{ Reason::OTHER, __FILE__, __LINE__, filepath + "_" + out_file };

		return out_file;
	}

	void FAPIForm::checkOverriden() { TRACE_FNC("")
		for (const auto & fo : getAllObjects())
			for (const auto & entry : fo->getProperties())
				entry.second->checkState();
	}

	void FAPIForm::attachLib(const string & _lib_name) { TRACE_FNC(_lib_name)
		if (hasObject(D2FFO_ATT_LIB, _lib_name)) {
			FAPILogger::warn("Form already attach " + _lib_name);
			return;
		}

		d2falb *ppd2falb{ nullptr };
		int status = d2falbat_Attach(ctx->getContext(), mod.get(), &ppd2falb, FALSE, stringToText(_lib_name));

		if (status != D2FS_SUCCESS)
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, _lib_name, status };

		root->addChild(new FormsObject{ this, D2FFO_ATT_LIB, ppd2falb, 1 });
	}

	void FAPIForm::detachLib(const string & _lib_name) { TRACE_FNC(_lib_name)
		Expected<FormsObject> exp_lib = root->getObject(D2FFO_ATT_LIB, _lib_name);
		bool detached{ false };

		while (exp_lib.isValid()) {
			if (detached) {
				FAPILogger::warn("There are more instances of " + _lib_name + " attached to form! Form needs to be saved before detaching another again");
				saveModule();
			}

			int status = d2falbdt_Detach(ctx->getContext(), exp_lib->getFormsObj());

			if (status != D2FS_SUCCESS)
				throw FAPIException(Reason::INTERNAL_ERROR, __FILE__, __LINE__, _lib_name, status);

			detached = true;
			root->removeChild(exp_lib.get());
			exp_lib = root->getObject(D2FFO_ATT_LIB, _lib_name);
		}
	}

	void FAPIForm::saveModule(const string & _path) { TRACE_FNC(_path)
		string path { _path == "" ? filepath : _path };

		FAPILogger::debug(path);

		for (const auto & marked_obj : marked_objects) {
			auto & marked_properties = marked_obj->getMarkedProperties();

			for (const auto & marked_prop : marked_properties)
				marked_obj->setProperty(marked_prop);

			marked_properties.clear();
		}

		marked_objects.clear();
		int status = d2ffmdsv_Save(ctx->getContext(), mod.get(), stringToText(path), FALSE);

		if (status != D2FS_SUCCESS)
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, path, status };
	}

	void FAPIForm::compileModule() { TRACE_FNC("")
		int status = d2ffmdco_CompileObj(ctx->getContext(), mod.get());

		if (status != D2FS_SUCCESS)
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, "", status };
	}

	bool FAPIForm::isCompiling() noexcept { TRACE_FNC("")
		try {
			compileModule();
			return true;
		} catch (exception &) { return false; }
	}

	void FAPIForm::generateModule() { TRACE_FNC("")
		int status = d2ffmdcf_CompileFile(ctx->getContext(), mod.get());

		if (status != D2FS_SUCCESS)
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, "", status };
	}

	void * FAPIForm::getModule() const { TRACE_FNC("")
		return mod.get();
	}
}

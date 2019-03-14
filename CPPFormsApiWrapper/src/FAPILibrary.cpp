#include "FAPILibrary.h"

#include "Property.h"
#include "FormsObject.h"
#include "FAPIContext.h"
#include "FAPILogger.h"

#include "FAPIUtil.h"
#include "D2FLIB.H"

#include <regex>


namespace CPPFAPIWrapper {
	using namespace std;

	FAPILibrary::FAPILibrary(FAPIContext * _ctx, void * _mod, const std::string & _filepath) 
		: FAPIModule(_ctx, _filepath) { TRACE_FNC(_filepath)
		auto deleter = [this](const void * data) { d2flibde_Destroy(this->ctx->getContext(), const_cast<void *>(data)); };
		mod = unique_ptr<void, function<void(const void*)>>{ _mod, deleter };
	}

	FAPILibrary::~FAPILibrary() { TRACE_FNC("") }

	string FAPILibrary::createObjectReportFile(const string & _filepath) { TRACE_FNC(_filepath)
		string out_file = (_filepath != "" ? _filepath.substr(0, _filepath.rfind(".")) : filepath.substr(0, filepath.rfind("."))) + ".txt";
		string cmd = "ifcmp60.exe module=\"" + filepath + "\" output_file=\"" + out_file + "\" forms_doc=YES window_state=minimize module_type=LIBRARY"; // TODO

		if (ctx->getConnstring() != "")
			cmd += " userid=" + ctx->getConnstring();

		FAPILogger::debug("out_file=" + out_file + " cmd=" + cmd);
		system(cmd.c_str());

		if (!fileExists(out_file))
			throw FAPIException{ Reason::OTHER, __FILE__, __LINE__, filepath + "_" + out_file };

		return out_file;
	}

	vector<FormsObject *> FAPILibrary::getAllObjects() const {
		vector<FormsObject *> objects;
		auto & children = root->getChildren().at(D2FFO_LIB_PROG_UNIT);
		transform(children.begin(), children.end(), back_inserter(objects), [](const auto & _child) { return _child.get(); });

		return objects;
	}

	void FAPILibrary::findGlobals() { TRACE_FNC("")
		globals.clear();

		auto prog_units = getAllObjects();
		regex pattern{ "global.[A-Za-z0-9_!@#$%^&*()]+", regex_constants::icase };
		smatch match;

		for (const auto & pgu : prog_units) {
			string code = pgu->getProperties().at(D2FP_PGU_TXT)->getValue();
			regex_search(code, match, pattern);
			transform(match.begin(), match.end(), inserter(globals, globals.begin()), [](const auto & _val) { return _val.str().substr(7); }); // 7 = `global.` offset
		}
	}

	void * FAPILibrary::getModule() const { TRACE_FNC("")
		return mod.get();
	}
}
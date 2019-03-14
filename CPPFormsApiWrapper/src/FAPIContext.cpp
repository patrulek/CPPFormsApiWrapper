#include "FAPIContext.h"

#include "FAPIForm.h"
#include "FAPILibrary.h"
#include "FAPIWrapper.h"
#include "FAPIUtil.h"
#include <algorithm>

#include "Expected.h"
#include "Exceptions.h"
#include "FAPILogger.h"

#include "D2FLIB.H"
#include "D2FFMD.H"

namespace CPPFAPIWrapper {
	using namespace std;

	FAPIContext::FAPIContext()
		: is_connected(false) { TRACE_FNC("")
		d2fctx * ctx_ { nullptr };
		attr.mask_d2fctxa = (ub4)0;
		int status = d2fctxcr_Create(&ctx_, &attr);

		if (status != D2FS_SUCCESS)
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, "", status };

		auto deleter = [](d2fctx * data) { if (data) d2fctxde_Destroy(data); };
		ctx = unique_ptr<d2fctx, function<void(d2fctx *)>>{ ctx_, deleter };
	}

	FAPIContext::~FAPIContext() { TRACE_FNC(""); }

	unordered_map<string, vector<string>> FAPIContext::getBuiltins() { TRACE_FNC("")
		unordered_map<string, vector<string>> builtins;
		text *** arr{ nullptr };
		int status = d2fctxbi_BuiltIns(ctx.get(), &arr);

		if (status != D2FS_SUCCESS)
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, "", status };

		while (*arr) {
			text ** list{ *arr };

			vector<string> units;
			string package_name = string{ reinterpret_cast<char *>(*list) };

			while (*(++list)) {
				string unit_name = string{ reinterpret_cast<char *>(*list) };
				units.emplace_back(unit_name);
			}

			builtins[package_name] = units;
			++arr;
		}

		return builtins;
	}

	void FAPIContext::loadSourceModules(const FAPIForm * _module, const bool _ignore_missing_libs, const bool _ignore_missing_sub, const bool _traverse) { TRACE_FNC(to_string(_ignore_missing_libs) + " | " + to_string(_ignore_missing_sub))
		unordered_set<string> to_process = _module->getSourceModules();
		unordered_set<string> processed = _module->getSourceModules();
		processed.insert(_module->getName());

		while (true) {
			unordered_set<string> to_load;

			for (const auto & source_mod : to_process) {
				string path = modulePathFromName(source_mod);

				if (hasModule(path))
					continue;

				try {
					loadModule(path, _ignore_missing_libs, _ignore_missing_sub);
					auto parent_module = getModule(path);

					for (auto & source_mod2 : parent_module->getSourceModules()) {
						if (processed.find(source_mod2) == processed.end()) {
							to_load.insert(source_mod2);
							processed.insert(source_mod2);

							FAPILogger::debug("To process: " + source_mod2);
						}
					}
				}
				catch (exception & ex) { FAPILogger::error(ex.what()); }
			}

			if (to_load.empty())
				break;

			to_process.insert(to_load.begin(), to_load.end());
		}
	}

	void FAPIContext::loadModuleWithSources(const string & _filepath, const bool _ignore_missing_libs, const bool _ignore_missing_sub, const bool _traverse) { TRACE_FNC(_filepath + " | " + to_string(_ignore_missing_libs) + " | " + to_string(_ignore_missing_sub))
		loadModule(_filepath, _ignore_missing_libs, _ignore_missing_sub);
		auto module = getModule(_filepath);
		loadSourceModules(module, _ignore_missing_libs, _ignore_missing_sub);
		module->checkOverriden();
	}

	void FAPIContext::loadModule(const string & _filepath, const bool _ignore_missing_libs, const bool _ignore_missing_sub, const bool _traverse) { TRACE_FNC(_filepath + " | " + to_string(_ignore_missing_libs) + " | " + to_string(_ignore_missing_sub))
		if (hasModule(_filepath))
			throw FAPIException{ Reason::OTHER, __FILE__, __LINE__, _filepath };

		if (!fileExists(_filepath))
			throw FAPIException{ Reason::OTHER, __FILE__, __LINE__, _filepath };

		d2ffmd * mod{ nullptr };
		int status = d2ffmdld_Load(ctx.get(), &mod, stringToText(_filepath), FALSE);

		if ((status != D2FS_SUCCESS && status != D2FS_MISSINGLIBMOD && status != D2FS_MISSINGSUBCLMOD)
			|| (!_ignore_missing_libs && status == D2FS_MISSINGLIBMOD)
			|| (!_ignore_missing_sub && status == D2FS_MISSINGSUBCLMOD))
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, _filepath, status }; // "operation failed", when trying to load, already loaded, module

		auto module = make_unique<FAPIForm>(this, mod, _filepath);

		if (_traverse) {
			status = module->traverseObjects();

			if (status != D2FS_SUCCESS)
				throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, "", status };
		}

		modules[toUpper(_filepath)] = move(module);
	}

	void FAPIContext::loadLibrary(const std::string & _filepath) { TRACE_FNC(_filepath)
		if (hasLibrary(_filepath))
			throw FAPIException{ Reason::OTHER, __FILE__, __LINE__, _filepath };

		if (!fileExists(_filepath))
			throw FAPIException{ Reason::OTHER, __FILE__, __LINE__, _filepath };

		d2flib * lib{ nullptr };
		int status = d2flibld_Load(ctx.get(), &lib, stringToText(_filepath), FALSE);

		if (status != D2FS_SUCCESS )
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, _filepath, status }; // "operation failed", when trying to load, already loaded, module

		auto library = make_unique<FAPILibrary>(this, lib, _filepath);

		status = library->traverseObjects();

		if (status != D2FS_SUCCESS)
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, "", status };

		libs[toUpper(_filepath)] = move(library);
	}

	FAPIForm * FAPIContext::getModule(const string & _filepath) { TRACE_FNC(_filepath)
		return Expected<FAPIForm>{ modules[toUpper(_filepath)].get() }.get();
	}

	FAPILibrary * FAPIContext::getLibrary(const string & _filepath) { TRACE_FNC(_filepath)
		return Expected<FAPILibrary>{ libs[toUpper(_filepath)].get() }.get();
	}

	bool FAPIContext::hasModule(const string & _filepath) { TRACE_FNC(_filepath)
		return modules.find(toUpper(_filepath)) != modules.end();
	}

	bool FAPIContext::hasLibrary(const string & _filepath) { TRACE_FNC(_filepath)
		return libs.find(toUpper(_filepath)) != libs.end();
	}

	void FAPIContext::createModule(const string & _filepath) { TRACE_FNC(_filepath)
		d2ffmd * mod { nullptr };
		string name = moduleNameFromPath(_filepath);
		int status = d2ffmdcr_Create(ctx.get(), &mod, stringToText(name));

		FAPILogger::debug(name);

		if (status != D2FS_SUCCESS)
			throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, name, status };

		modules[toUpper(_filepath)] = make_unique<FAPIForm>(this, mod, _filepath);
	}

	void FAPIContext::removeModule(const string & _filepath) { TRACE_FNC(_filepath)
		modules.erase(toUpper(_filepath));
	}

	void FAPIContext::removeLibrary(const string & _filepath) { TRACE_FNC(_filepath)
		libs.erase(toUpper(_filepath));
	}

	bool FAPIContext::connectContextToDB(const string & _connstring) { TRACE_FNC(_connstring)
		if (_connstring.empty()) {
			FAPILogger::warn("Need to provide database connection string!");
			return is_connected;
		}

		if (!is_connected) {
			int status = d2fctxcn_Connect(ctx.get(), stringToText(_connstring), nullptr);

			if (status != D2FS_SUCCESS)
				throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, _connstring, status };

			is_connected = true;
			connstring = _connstring;
		}

		return is_connected;
	}

	bool FAPIContext::disconnectContextFromDB() { TRACE_FNC("")
		if (is_connected) {
			int status = d2fctxdc_Disconnect(ctx.get());

			if (status != D2FS_SUCCESS)
				throw FAPIException{ Reason::INTERNAL_ERROR, __FILE__, __LINE__, "", status };

			is_connected = false;
			connstring = "";
		}

		return is_connected;
	}

	bool FAPIContext::isConnected() const { TRACE_FNC("")
		return is_connected;
	}

	d2fctx * FAPIContext::getContext() const { TRACE_FNC("")
		return ctx.get();
	}

	unordered_map<string, unique_ptr<FAPIForm>>& FAPIContext::getModules() { TRACE_FNC("")
		return modules;
	}

	unordered_map<string, unique_ptr<FAPILibrary>>& FAPIContext::getLibraries() { TRACE_FNC("")
		return libs;
	}

	string FAPIContext::getConnstring() const { TRACE_FNC("")
		return connstring;
	}
}

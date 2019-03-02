#include "FAPIUtil.h"

#include <algorithm>
#include <fstream>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "Exceptions.h"

#include "FAPILogger.h"

namespace CPPFAPIWrapper {
	using namespace std;

	easylogger::LogLevel levelFromStr(string & _str) { TRACE_FNC(_str)
		string level = toUpper(_str);

		if (level == "T" || level == "TRACE")
			return easylogger::LogLevel::LEVEL_TRACE;
		else if (level == "D" || level == "DEBUG")
			return easylogger::LogLevel::LEVEL_DEBUG;
		else if (level == "I" || level == "INFO")
			return easylogger::LogLevel::LEVEL_INFO;
		else if (level == "W" || level == "WARN" || level == "WARNING")
			return easylogger::LogLevel::LEVEL_WARNING;
		else if (level == "E" || level == "ERROR")
			return easylogger::LogLevel::LEVEL_ERROR;
		
		return easylogger::LogLevel::LEVEL_FATAL;
	}

	string toUpper(string _str) { TRACE_FNC(_str)
		transform(_str.begin(), _str.end(), _str.begin(), ::toupper);
		return _str;
	}

	string toLower(string _str) { TRACE_FNC(_str)
		transform(_str.begin(), _str.end(), _str.begin(), ::tolower);
		return _str;
	}

	text * stringToText(const string & _str) { TRACE_FNC(_str)
		return reinterpret_cast<text *>(const_cast<char *>(_str.c_str()));
	}

	string modulePathFromName(const string & _str) { TRACE_FNC(_str)
		vector<string> fmb_paths = getFMBPaths();
		string name = truncModuleName(_str) + ".FMB";

		for (const auto & fmb_path : fmb_paths) {
			string filepath = fmb_path + name;
			FAPILogger::debug(filepath);

			if (fileExists(filepath))
				return toUpper(filepath);
		}

		throw FAPIException{ Reason::OTHER, __FILE__, __LINE__ };
	}

	bool fileExists(const string & _filepath) { TRACE_FNC(_filepath)
		ifstream file { _filepath };
		bool exists = file.is_open();
		file.close();

		return exists;
	}

	string moduleNameFromPath(const string & _str) { TRACE_FNC(_str)
		int pos1 = _str.rfind("/") + 1;
		int pos2 = _str.find(".", pos1);

		return toUpper(_str.substr(pos1, pos2 - pos1));
	}

	string truncModuleName(const string & _str) { TRACE_FNC(_str)
		unsigned int pos = _str.find(".");
		return pos == string::npos ? toUpper(_str) : toUpper(_str.substr(0, pos));
	}

	string readRegistryKey(HKEY _hkey, string _key_path, string _key_name) { TRACE_FNC(_key_path + " | " + _key_name)
		HKEY hKey;
		ULONG lRes = RegOpenKeyExA(_hkey, (LPCSTR)_key_path.c_str(), 0, KEY_READ, &hKey);

		if (lRes != ERROR_SUCCESS)
			throw FAPIException{ Reason::OTHER, __FILE__, __LINE__, "Couldn't open registry key: " + _key_path };

		LPCSTR szBuffer[512];
		DWORD dwBufferSize{ sizeof(szBuffer) };
		lRes = RegQueryValueExA(hKey, (LPCSTR)_key_name.c_str(), 0, NULL, (LPBYTE)szBuffer, &dwBufferSize);
		FAPILogger::debug(reinterpret_cast<char *>(szBuffer));

		if (lRes != ERROR_SUCCESS)
			throw FAPIException{ Reason::OTHER, __FILE__, __LINE__, "Couldn't read registry key: " + _key_name };

		RegCloseKey(hKey);

		return string{ reinterpret_cast<char *>(szBuffer) };
	}

	vector<string> splitString(string _str, const string & _delimiter) { TRACE_FNC(_str + " | " + _delimiter)
		vector<string> strings;
		unsigned int pos = _str.find(_delimiter);

		while (pos != string::npos) {
			string path = _str.substr(0, pos);

			if (path.back() != '\\' && path.back() != '/')
				path += "\\";

			_str = _str.substr(pos + 1);
			pos = _str.find(_delimiter);
			strings.emplace_back(path);
		}

		strings.emplace_back(_str);

		return strings;
	}

	vector<string> getFMBPaths() { TRACE_FNC("")
		string paths = readRegistryKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\ORACLE", "FORMS60_PATH");
		return splitString(paths);
	}
}

#include "FAPILogger.h"
#include "easylogger-impl.h"
#include "date\date.h"

#include <chrono>
#include <ctime>

using namespace std::chrono;

namespace CPPFAPIWrapper {
	std::string FAPILogger::filepath{ "c:/temp/cppfapilog.txt" };
	std::ofstream FAPILogger::stream = std::ofstream{ filepath };
	bool FAPILogger::is_enabled{ true };
	easylogger::LogLevel FAPILogger::level{ easylogger::LEVEL_WARNING };
	easylogger::Logger FAPILogger::logger = easylogger::Logger{ "CPPFapiLogger" };

	std::string FAPILogger::getTimestamp() {
		return date::format("[%F %T] ", time_point_cast<milliseconds>(system_clock::now()));
	}

	void FAPILogger::trace(const std::string & _str) {
		if (is_enabled) {
			LOG_TRACE(logger, getTimestamp() + _str);
			flush();
		}
	}

	std::string FAPILogger::getFilepath() {
		return filepath;
	}

	bool FAPILogger::isEnabled() {
		return is_enabled;
	}

	easylogger::LogLevel FAPILogger::getLogLevel() {
		return level;
	}

	void FAPILogger::debug(const std::string & _str) {
		if (is_enabled) {
			LOG_DEBUG(logger, getTimestamp() + _str);
			flush();
		}
	}

	void FAPILogger::info(const std::string & _str) {
		if (is_enabled) {
			LOG_INFO(logger, getTimestamp() + _str);
			flush();
		}
	}

	void FAPILogger::warn(const std::string & _str) {
		if (is_enabled) {
			LOG_WARNING(logger, getTimestamp() + _str);
			flush();
		}
	}

	void FAPILogger::error(const std::string & _str) {
		if (is_enabled) {
			LOG_ERROR(logger, getTimestamp() + _str);
			flush();
		}
	}

	void FAPILogger::fatal(const std::string & _str) {
		if (is_enabled) {
			LOG_FATAL(logger, getTimestamp() + _str);
			flush();
		}
	}

	void FAPILogger::changePath(const std::string & _logpath) {
		filepath = _logpath;
		stream = std::ofstream{ filepath };
	}

	void FAPILogger::setLevel(easylogger::LogLevel _level) { level = _level; logger.Level(level); }
	void FAPILogger::enable() { is_enabled = true; }
	void FAPILogger::disable() { is_enabled = false; }
	void FAPILogger::flush() { logger.Stream(stream); }
}

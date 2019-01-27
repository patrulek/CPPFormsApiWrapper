#include "FAPILogger.h"
#include "easylogger-impl.h"

namespace CPPFAPIWrapper {
   std::string FAPILogger::filepath = "c:/temp/cppfapilog.txt";
   std::ofstream FAPILogger::stream = std::ofstream(filepath);
   bool FAPILogger::is_enabled = true;
   easylogger::LogLevel FAPILogger::level = easylogger::LEVEL_WARNING;
   easylogger::Logger FAPILogger::logger = easylogger::Logger("CPPFapiLogger");

   void FAPILogger::trace(std::string _str) {
      if( is_enabled ) {
         LOG_TRACE(logger, _str);
         flush();
      }
   }

   void FAPILogger::debug(std::string _str) {
      if( is_enabled ) {
         LOG_DEBUG(logger, _str);
         flush();
      }
   }

   void FAPILogger::info(std::string _str) {
      if( is_enabled ) {
         LOG_INFO(logger, _str);
         flush();
      }
   }

   void FAPILogger::warn(std::string _str) {
      if( is_enabled ) {
         LOG_WARNING(logger, _str);
         flush();
      }
   }

   void FAPILogger::error(std::string _str) {
      if( is_enabled ) {
         LOG_ERROR(logger, _str);
         flush();
      }
   }

   void FAPILogger::fatal(std::string _str) {
      if( is_enabled ) {
         LOG_FATAL(logger, _str);
         flush();
      }
   }

   void FAPILogger::changePath(std::string _logpath) {
      filepath = _logpath;
      stream = std::ofstream(filepath);
   }

   void FAPILogger::setLevel(easylogger::LogLevel _level) { level = _level; logger.Level(level); }
   void FAPILogger::enable() { is_enabled = true; }
   void FAPILogger::disable() { is_enabled = false; }
   void FAPILogger::flush() { logger.Stream(stream); }
}

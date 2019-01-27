#ifndef FAPIUTIL_H_INCLUDED
#define FAPIUTIL_H_INCLUDED

#include <string>
#include <vector>
#include "ORATYPES.H"
#include "dllmain.h"

#include "easylogger.h"

namespace CPPFAPIWrapper {

   /** Returns uppercase string
   *
   * \param _str String to transform
   * \return Uppercase string
   */
	CPPFAPIWRAPPER std::string toUpper(std::string _str);

   /** Returns lowercase string
   *
   * \param _str String to transform
   * \return Lowercase string
   */
	CPPFAPIWRAPPER std::string toLower(std::string _str);

   /** Convenient function for returning ptr to 'text' type from string
   *
   * \param _str String to transform
   * \return Pointer to text
   */
	CPPFAPIWRAPPER text * stringToText(const std::string & _str);

   /** Gets filepath for a module with a given name. It searches nearest path depending on registry value from key SOFTWARE/ORACLE/FORMS60_PATH.
   * If there's no module in specified paths, throws an exception.
   *
   * \param _str Name of a module
   * \return Path to .fmb with a given module name
   */
	CPPFAPIWRAPPER std::string modulePathFromName(std::string _str);

   /** Removes folder path and extension from a given path and returns pure file(module) name
   *
   * \param _str Path to .fmb
   * \return File name without extension
   */
	CPPFAPIWRAPPER std::string moduleNameFromPath(std::string _str);

   /** Removes extension from a given module and returns pure module name (example: MODULE.FMB -> MODULE)
   *
   * \param _str Module name with(or without) extension
   * \return Module name without extension
   */
	CPPFAPIWRAPPER std::string truncModuleName(std::string _str);

   /** Splits string by a given delimiter
   *
   * \param _str Input string
   * \param _delimiter Delimiter
   * \return Collection of a words divided by delimiter
   */
	CPPFAPIWRAPPER std::vector<std::string> splitString(std::string _str, const std::string & _delimiter = ";");

   /** Gets folders paths where .fmb should be searched.
   *
   * \return Collection of folders paths, basing on registry key SOFTWARE/ORACLE/FORMS60_PATH
   */
	CPPFAPIWRAPPER std::vector<std::string> getFMBPaths();

   /** Check if file exists.
   *
   * \param _filepath Path to a file.
   * \return True if file exists
   */
	CPPFAPIWRAPPER bool fileExists(const std::string & _filepath);

   /** Returns logging level from a given string.
   *
   * \param _str String describing the logging level. It should be: TRACE/DEBUG/INFO/WARN/ERROR/FATAL or it's first letters.
   * \return LogLevel value.
   */
	CPPFAPIWRAPPER easylogger::LogLevel levelFromStr(std::string & _str);
}

#endif // FAPIUTIL_H_INCLUDED

#ifndef FAPIWRAPPER_H
#define FAPIWRAPPER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "dllmain.h"

namespace CPPFAPIWrapper {
   class FAPIContext;

   /// OracleForms type hierarchy
   CPPFAPIWRAPPER extern std::unordered_map<int, std::vector<int>> type_hierarchy;

   /// OracleForms status errors
   CPPFAPIWRAPPER extern const std::vector<std::string> errors;

   /// OracleForms object type ids
   CPPFAPIWRAPPER extern const std::vector<std::string> obj_types;

   /// OracleForms property constant names
   CPPFAPIWRAPPER extern const std::vector<std::string> prop_consts;

   /// OracleForms property names
   CPPFAPIWRAPPER extern const std::vector<std::string> prop_names;

   /** Creates OracleForms context and connect it to database if proper string provided.
   *
   * \param _connstring Database connection string, eg. scott/tiger@db
   * \return Unique pointer to FAPIContext object
   */
   CPPFAPIWRAPPER std::unique_ptr<FAPIContext> createContext(const std::string & _connstring = "");

   /** Gets current library version
   *
   * \return Library version
   */
   CPPFAPIWRAPPER std::string getLibVersion();

   /** Check if given property is irrelevant and does not have to be loaded from .fmb
   *
   * \param _prop_num Property id to check
   * \return True if _prop_num contains in a given set
   */
   CPPFAPIWRAPPER bool isIrrelevantProperty(const int _prop_num);

   /** Check if given property is not inheritable from other OracleForms object
   *
   * \param _prop_num Property id to check
   * \return True if _prop_num contains in a given set
   */
   CPPFAPIWRAPPER bool isNonInheritableProperty(const int _prop_num);

   /** Returns OracleForms object type id from a given constant type name
   *
   * \param _type_name Constant name of a object's type
   * \return OracleForms object's id
   */
   CPPFAPIWRAPPER int typeNameToID(const std::string & _type_name);
}

#endif // FAPIWRAPPER_H

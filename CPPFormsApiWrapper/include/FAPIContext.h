#ifndef FAPICONTEXT_H
#define FAPICONTEXT_H

#include "D2FCTX.H"
#include "dllmain.h"

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <unordered_map>

namespace CPPFAPIWrapper {
   class FAPIModule;

   class FAPIContext
   {
      public:
         /** Creates FAPIContext object */
		  CPPFAPIWRAPPER FAPIContext();

         /** Loads OracleForms module and binds it with current context. Throws an exception when there
         * are missing libs (.pll) or cant resolve inheritance and ignore parameters are set to false.
         * Important: this function will not load parent modules, which loaded module inherits objects from.
         * Therefore properties will be not checked for broken inheritance.
         *
         * \param _filepath Path to .fmb file
         * \param _ignore_missing_libs If True, module will be loaded regardless of missing PLSQL libraries (.pll)
         * \param _ignore_missing_sub If True, module will be loaded regardless of missing subobjects
         */
         CPPFAPIWRAPPER void loadModule(const std::string & _filepath, const bool _ignore_missing_libs = false, const bool _ignore_missing_sub = false);

         /** Recurrently loads all sources for given module.
         *
         * \param _module Pointer to FAPIModule object, which sources needs to be loaded for
         * \param _ignore_missing_libs If True, all modules will be loaded regardless of missing PLSQL libraries (.pll)
         * \param _ignore_missing_sub If True, all modules will be loaded regardless of missing subobjects
         */
		 CPPFAPIWRAPPER void loadSourceModules(const FAPIModule * _module, const bool _ignore_missing_libs = false, const bool _ignore_missing_sub = false);

         /** Combination of functions: loadModule and loadSourceModules. After loading all modules
         * properties will be checked for broken inheritance of a module pointed by _filepath param.
         *
         * \param _filepath Path to .fmb file
         * \param _ignore_missing_libs If True, all modules will be loaded regardless of missing PLSQL libraries (.pll)
         * \param _ignore_missing_sub If True, all modules will be loaded regardless of missing subobjects
         */
		 CPPFAPIWRAPPER void loadModuleWithSources(const std::string & _filepath, const bool _ignore_missing_libs = false, const bool _ignore_missing_sub = false);

         /** Creates new FAPIModule object in location pointed by _filepath param. The file is not generated
         * althought, until saveModule function wont be called.
         *
         * \param _filepath Path to .fmb file
         */
		 CPPFAPIWRAPPER void createModule(const std::string & _filepath);

         /** Gets module by a given key, which is path to the file
         *
         * \param _filepath Path to .fmb file
         * \return Pointer to FAPIModule object if exists, else throws an exception.
         */
		 CPPFAPIWRAPPER FAPIModule * getModule(const std::string & _filepath);

         /** Checks if context has attached module pointed by a _filepath param.
         *
         * \param _filepath Path to .fmb file
         * \return True if context already loaded a module given by a _filepath param.
         */
		 CPPFAPIWRAPPER bool hasModule(const std::string & _filepath);

         /** Removes module from context
         *
         * \param _filepath Path to .fmb file
         */
		 CPPFAPIWRAPPER void removeModule(const std::string & _filepath);

         /** Connects context with a database.
         *
         * \param _connstring Connection string for a database, ex. scott/tiger@db
         * \return Status of connection.
         */
		 CPPFAPIWRAPPER bool connectContextToDB(const std::string & _connstring);

         /** Disconnects context from a database.
         *
         * \return Status of connection.
         */
		 CPPFAPIWRAPPER bool disconnectContextFromDB();

         /** Checks if context is connected to database
         *
         * /return Status of connection.
         */
		 CPPFAPIWRAPPER bool isConnected() const { return is_connected; }

         /** Gets pointer to OracleForms context object
         *
         * \return Pointer to OracleForms context object
         */
		 CPPFAPIWRAPPER d2fctx * getContext() const { return ctx.get(); }

         /** Gets referenced map of context's modules
         *
         * \return Map of modules, where key is path to .fmb file.
         */
		 CPPFAPIWRAPPER std::unordered_map<std::string, std::unique_ptr<FAPIModule>> & getModules() { return modules; }

         /** Gets string which were used for connecting to database
         *
         * \return Connection string which were used for connecting to database
         */
		 CPPFAPIWRAPPER std::string getConnstring() const { return connstring; }
      private:
         std::unique_ptr<d2fctx, std::function<void(d2fctx *)>> ctx;
         std::unordered_map<std::string, std::unique_ptr<FAPIModule>> modules;
         std::string connstring;
         d2fctxa attr;
         bool is_connected;
   };
}

#endif // FAPICONTEXT_H

#ifndef FAPIMODULE_H
#define FAPIMODULE_H

#include "D2FFMD.H"
#include "dllmain.h"

#include <string>
#include <unordered_set>
#include <vector>
#include <memory>
#include <functional>

namespace CPPFAPIWrapper {
   class FAPIContext;
   class FormsObject;

   class FAPIModule
   {
      public:
         /** Creates FAPIModule object. Used by FAPIContext, shouldn' be called directly.
         *
         * \param _ctx Pointer to FAPIContext.
         * \param _mod Pointer to OracleForms form object
         * \param _filepath Path to .fmb module
         */
         CPPFAPIWRAPPER FAPIModule(FAPIContext * _ctx, d2ffmd * _mod, const std::string & _filepath);
		 CPPFAPIWRAPPER ~FAPIModule();

		 CPPFAPIWRAPPER FAPIModule() = delete;
		 CPPFAPIWRAPPER FAPIModule(const FAPIModule & _module) = delete;
		 CPPFAPIWRAPPER FAPIModule(FAPIModule && _module) = delete;

		 CPPFAPIWRAPPER FAPIModule & operator=(const FAPIModule & _module) = delete;
		 CPPFAPIWRAPPER FAPIModule & operator=(FAPIModule && _module) = delete;

         /** Inherits all properties from source modules */
		 CPPFAPIWRAPPER void inheritAllProp();

         /** Inherits text property for all PLSQL objects (triggers/program units) */
		 CPPFAPIWRAPPER void inheritAllPLSQL();

         /** Inherits text property for a given PLSQL objects
         *
         * \param _units Collection of objects' fullnames (ex. MY_PROGRAM_UNIT, BLOCK.WHEN-NEW-BLOCK-INSTANCE)
         */
		 CPPFAPIWRAPPER void inheritPLSQL(const std::vector<std::string> & _units);

         /** Inherits text property for a given PLSQL objects
         *
         * \param _units Collection of FormsObject pointers
         */
		 CPPFAPIWRAPPER void inheritPLSQL(const std::vector<FormsObject *> & _units);

         /** Creates object report file for a given module
         *
         * \param _filepath Location of output file. If not provided, will reside in same folder as module
         * \return Returns output filepath.
         */
		 CPPFAPIWRAPPER std::string createObjectReportFile(const std::string & _filepath = "");

         /** Attach PLSQL library to a module
         *
         * \param _lib_name Library name
         */
		 CPPFAPIWRAPPER void attachLib(const std::string & _lib_name);


		 /** Detach PLSQL library to a module
		 *
		 * \param _lib_name Library name
		 */
		 CPPFAPIWRAPPER void detachLib(const std::string & _lib_name);

         /** Saves .fmb module to a disk.
         *
         * \param _path If not provided, module will be saved to a location pointed by filepath object member
         */
		 CPPFAPIWRAPPER void saveModule(const std::string & _path = "");

         /** Compiles all PLSQL objects in .fmb module*/
		 CPPFAPIWRAPPER void compileModule();

         /** Generates .fmx file in same folder as module */
		 CPPFAPIWRAPPER void generateModule();

         /** Checks properties for broken inheritance. Search for and loads source modules if needed */
		 CPPFAPIWRAPPER void checkOverriden();

         /** Recurrently traverse .fmb module and load all relevant objects and its properties.
         *
         * \param _obj Pointer to OracleForms object
         * \param _level Level of object hierarchy
         * \param _forms_object Parent of current object
         * \return OracleForms status of operation
         */
		 CPPFAPIWRAPPER int traverseObjects(d2fob * _obj = nullptr, int _level = 0, FormsObject * _forms_object = nullptr);

         /** Mark object for setting its properties' values
         *
         * \param _forms_object Object to mark
         */
		 CPPFAPIWRAPPER void markObject(FormsObject * _forms_object);

         /** Unmark object for setting its properties' values
         *
         * \param _forms_object Object to unmark
         */
		 CPPFAPIWRAPPER void unmarkObject(FormsObject * _forms_object);

         /** Checks if contains a given object.
         *
         * \param _type_id OracleForms object type id
         * \param _name Name of object
         * \return True if module has object, else otherwise.
         */
		 CPPFAPIWRAPPER bool hasObject(const int _type_id, const std::string & _name) const;

         /** Gets given object from module
         *
         * \param _type_id OracleForms object type id
         * \param _fullname Full name of object (ex. for item object you could try to find "MY_BLOCK.MY_ITEM")
         * \return Pointer to FormsObject if exists, otherwise throws exception.
         */
		 CPPFAPIWRAPPER FormsObject * getObject(const int _type_id, const std::string & _fullname) const;

         /** Gets given object which lies directly under root object in hierarchy
         *
         * \param _type_id OracleForms object type id
         * \param _name Name of object.
         * \return Pointer to FormsObject
         */
		 CPPFAPIWRAPPER FormsObject * getRootObject(const int _type_id, const std::string & _name) const;

         /** Gets objects which lies directly under root object in hierarchy
         *
         * \param _type_id OracleForms object type id
         * \return Collection of FormsObject pointers
         */
		 CPPFAPIWRAPPER std::vector<FormsObject *> getObjects(const int _type_id) const;

         /** Gets all objects from all hierarchy levels
         *
         * \return Collection of FormsObject pointers
         */
		 CPPFAPIWRAPPER std::vector<FormsObject *> getAllObjects() const;

         // Convenient functions
         /** Gets all AttachedLibrary objects
         *
         * \return Collection of FormsObject pointers to AttachedLibrary
         */
		 CPPFAPIWRAPPER std::vector<FormsObject *> getAttachedLibraries() const;

         /** Gets all Block objects
         *
         * \return Collection of FormsObject pointers to Block
         */
		 CPPFAPIWRAPPER std::vector<FormsObject *> getBlocks() const;

         /** Gets all Trigger objects, which lies directly under root object
         *
         * \return Collection of FormsObject pointers to form Trigger.
         */
		 CPPFAPIWRAPPER std::vector<FormsObject *> getFormTriggers() const;

         /** Gets all Trigger objects, at all hierarchy levels
         *
         * \return Collection of FormsObject pointers to Trigger.
         */
		 CPPFAPIWRAPPER std::vector<FormsObject *> getTriggers() const;

         /** Gets all ProgramUnit objects
         *
         * \return Collection of FormsObject poiners to ProgramUnit.
         */
		 CPPFAPIWRAPPER std::vector<FormsObject *> getProgramUnits() const;

         /** Gets all Canvas objects
         *
         * \return Collection of FormsObject pointers to Canvas.
         */
		 CPPFAPIWRAPPER std::vector<FormsObject *> getCanvases() const;

         /** Gets all FormParameter objects.
         *
         * \return Collection of FormsObject pointers to FormParameter.
         */
		 CPPFAPIWRAPPER std::vector<FormsObject *> getParameters() const;

         /** Gets filepath to module
         *
         * \return Filepath to module
         */
		 CPPFAPIWRAPPER std::string getFilepath() const { return filepath; }

         /** Gets FAPIContext pointer which module is attached to
         *
         * \return FAPIContext pointer.
         */
         FAPIContext * getContext() const { return ctx; }

         /** Gets pointer to OracleForms object
         *
         * \return Pointer to OracleForms object
         */
         d2ffmd * getModule() const { return mod.get(); }

         /** Gets root object of module
         *
         * \return Pointer to FormsObject root object.
         */
         FormsObject * getRoot() const { return root.get(); }

         /** Gets name of a module
         *
         * \return Name of module.
         */
         std::string getName() const;

         /** Gets names of source modules, which current module inherits from
         *
         * \return Set of source module names.
         */
         std::unordered_set<std::string> getSourceModules() const { return source_modules; }
      private:
         FAPIContext * ctx;
         std::string filepath;
         std::unique_ptr<d2ffmd, std::function<void(const void*)>> mod;
         std::unique_ptr<FormsObject> root;
         std::vector<FormsObject *> marked_objects;
         std::unordered_set<std::string> source_modules;
   };
}
#endif // FAPIMODULE_H

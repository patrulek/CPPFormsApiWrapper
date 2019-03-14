#pragma once

#include <memory>
#include <unordered_set>
#include <functional>

#include "dllmain.h"
#include "D2FOB.H"


namespace CPPFAPIWrapper {
	class FAPIContext;
	class FormsObject;

	class FAPIModule
	{
		public:
			CPPFAPIWRAPPER virtual ~FAPIModule();

			/** Recurrently traverse .fmb/.pll and load all relevant objects and its properties.
			*
			* \param _obj Pointer to OracleForms object
			* \param _level Level of object hierarchy
			* \param _forms_object Parent of current object
			* \return OracleForms status of operation
			*/
			CPPFAPIWRAPPER int traverseObjects(d2fob * _obj = nullptr, int _level = 0, FormsObject * _forms_object = nullptr);

			/** Gets filepath to module
			*
			* \return Filepath to module
			*/
			CPPFAPIWRAPPER std::string getFilepath() const;

			/** Gets FAPIContext pointer which module is attached to
			*
			* \return FAPIContext pointer.
			*/
			CPPFAPIWRAPPER FAPIContext * getContext() const;

			/** Gets root object of module
			*
			* \return Pointer to FormsObject root object.
			*/
			CPPFAPIWRAPPER FormsObject * getRoot() const;

			/** Gets name of a module
			*
			* \return Name of module.
			*/
			CPPFAPIWRAPPER std::string getName() const;

			/** Gets names of source modules, which current module inherits from
			*
			* \return Set of source module names.
			*/
			CPPFAPIWRAPPER std::unordered_set<std::string> getSourceModules() const;

			/** Checks if contains internal object
			* \param _type_id OracleForms object type id
			* \param _fullname Full name of object (eg. BLOCK.ITEM.TRIGGER, PRG_UNIT ...)
			* \return True if module contains internal object, false otherwise
			*/
			CPPFAPIWRAPPER bool hasInternalObject(const int _type_id, const std::string & _fullname) const;

			/** Checks if contains a given object.
			*
			* \param _type_id OracleForms object type id
			* \param _name Name of object
			* \return True if module has object, false otherwise.
			*/
			CPPFAPIWRAPPER bool hasObject(const int _type_id, const std::string & _name) const;

			/** Gets given object from module
			*
			* \param _type_id OracleForms object type id
			* \param _fullname Full name of object (ex. for item object you could try to find "MY_BLOCK.MY_ITEM")
			* \return Pointer to FormsObject if exists, otherwise throws exception.
			*/
			CPPFAPIWRAPPER FormsObject * getObject(const int _type_id, const std::string & _fullname) const;

			/** Gets objects which lies directly under root object in hierarchy
			*
			* \param _type_id OracleForms object type id
			* \return Collection of FormsObject pointers
			*/
			CPPFAPIWRAPPER std::vector<FormsObject *> getObjects(const int _type_id) const;

			/** Gets given object which lies directly under root object in hierarchy
			*
			* \param _type_id OracleForms object type id
			* \param _name Name of object.
			* \return Pointer to FormsObject
			*/
			CPPFAPIWRAPPER FormsObject * getRootObject(const int _type_id, const std::string & _name) const;
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

			/** Creates object report file for a given Library
			*
			* \param _filepath Location of output file. If not provided, will reside in same folder as Library
			* \return Returns output filepath.
			*/
			CPPFAPIWRAPPER virtual std::string createObjectReportFile(const std::string & _filepath = "") = 0;

			/** Finds all global variables from all program units */
			CPPFAPIWRAPPER virtual void findGlobals() = 0;

			/** Gets pointer to OracleForms object
			*
			* \return Pointer to OracleForms object
			*/
			CPPFAPIWRAPPER virtual void * getModule() const = 0;

			/** Gets all library's program units
			*
			* \return Collection of FormsObject pointers
			*/
			CPPFAPIWRAPPER virtual std::vector<FormsObject *> getAllObjects() const = 0;

		protected:
			CPPFAPIWRAPPER FAPIModule(FAPIContext * _ctx, const std::string & _filepath);
			FAPIModule() = delete;
			FAPIModule(FAPIModule && _Library) = delete;
			FAPIModule & operator=(FAPIModule && _Library) = delete;
			FAPIModule(const FAPIModule & _Library) = delete;
			FAPIModule & operator=(const FAPIModule & _Library) = delete;

			FAPIContext * ctx;
			std::string filepath;
			std::unique_ptr<FormsObject> root;
			std::unordered_set<std::string> globals;
			std::unique_ptr<void, std::function<void(const void*)>> mod;
			std::unordered_set<std::string> source_modules;
			std::vector<FormsObject *> marked_objects;
		};
}


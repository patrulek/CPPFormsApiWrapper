#ifndef FAPIMODULE_H
#define FAPIMODULE_H

#include "dllmain.h"
#include "FAPIModule.h"

namespace CPPFAPIWrapper {
	class FAPIForm : public FAPIModule
	{
	public:
		/** Creates FAPIModule object. Used by FAPIContext, shouldn' be called directly.
		*
		* \param _ctx Pointer to FAPIContext.
		* \param _mod Pointer to OracleForms form object
		* \param _filepath Path to .fmb module
		*/
		CPPFAPIWRAPPER FAPIForm(FAPIContext * _ctx, void * _mod, const std::string & _filepath);
		CPPFAPIWRAPPER ~FAPIForm();

		FAPIForm() = delete;
		FAPIForm(FAPIForm && _Library) = delete;
		FAPIForm & operator=(FAPIForm && _Library) = delete;
		FAPIForm(const FAPIForm & _Library) = delete;
		FAPIForm & operator=(const FAPIForm & _Library) = delete;

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

		/** Check if module is compiling correctly */
		CPPFAPIWRAPPER bool isCompiling() noexcept;

		/** Generates .fmx file in same folder as module */
		CPPFAPIWRAPPER void generateModule();

		/** Checks properties for broken inheritance. Search for and loads source modules if needed */
		CPPFAPIWRAPPER void checkOverriden();

		void * getModule() const override;
		std::string createObjectReportFile(const std::string & _filepath = "") override;
		std::vector<FormsObject *> getAllObjects() const override;
		void findGlobals() override;
	};
}
#endif // FAPIMODULE_H

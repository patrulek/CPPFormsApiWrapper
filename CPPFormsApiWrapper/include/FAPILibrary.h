#ifndef FAPILIBRARY_H
#define FAPILIBRARY_H

#include "dllmain.h"
#include "FAPIModule.h"

namespace CPPFAPIWrapper {

	class FAPILibrary : public FAPIModule
	{
	public:
		/** Creates FAPILibrary object. Used by FAPIContext, shouldn' be called directly.
		*
		* \param _ctx Pointer to FAPIContext.
		* \param _pll Pointer to OracleForms library object
		* \param _filepath Path to .pll Library
		*/
		CPPFAPIWRAPPER FAPILibrary(FAPIContext * _ctx, void * _mod, const std::string & _filepath);
		CPPFAPIWRAPPER ~FAPILibrary();

		FAPILibrary() = delete;
		FAPILibrary(FAPILibrary && _Library) = delete;
		FAPILibrary & operator=(FAPILibrary && _Library) = delete;
		FAPILibrary(const FAPILibrary & _Library) = delete;
		FAPILibrary & operator=(const FAPILibrary & _Library) = delete;

		void * getModule() const override;
		std::string createObjectReportFile(const std::string & _filepath = "") override;
		std::vector<FormsObject *> getAllObjects() const override;
		void findGlobals() override;
	};
}
#endif // FAPILIBRARY_H
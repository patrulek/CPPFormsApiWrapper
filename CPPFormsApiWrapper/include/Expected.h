#ifndef EXPECTED_H
#define EXPECTED_H

#include "Exceptions.h"

namespace CPPFAPIWrapper {
	template<class T>
	class Expected
	{
	public:
		CPPFAPIWRAPPER explicit Expected(T * _r) : result(_r), gotResult(_r) { TRACE_FNC("")
			if (!gotResult)
				ex = FAPIException{ Reason::OBJECT_NOT_FOUND, __FILE__, __LINE__, typeid(T).name() };
		}

		CPPFAPIWRAPPER explicit Expected(T & _r) : result(&_r), gotResult(true) { TRACE_FNC("") };

		Expected() = delete;

		CPPFAPIWRAPPER T * operator->() const { TRACE_FNC("")
			return get();
		}

		CPPFAPIWRAPPER T * get() const { TRACE_FNC("")
			if (!result)
				throw ex;

			return result;
		}

		CPPFAPIWRAPPER bool isValid() const { TRACE_FNC("")
			return gotResult;
		}

	private:
		T * result;
		std::exception ex;
		bool gotResult;
	};
}

#endif // EXPECTED_H

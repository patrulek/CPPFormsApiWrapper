#ifndef EXPECTED_H
#define EXPECTED_H

#include "Exceptions.h"

namespace CPPFAPIWrapper {
   template<class T>
   class Expected
   {
      public:
		 CPPFAPIWRAPPER Expected(T * _r) : result(_r), gotResult(_r) {
            if( !gotResult )
               ex = FAPIException(Reason::OBJECT_NOT_FOUND, __FILE__, __LINE__, typeid(T).name());
         }
         CPPFAPIWRAPPER Expected(T & _r) : result(&_r), gotResult(true) {};
		 CPPFAPIWRAPPER ~Expected() {};

		 CPPFAPIWRAPPER T * operator->() const {
            return get();
         }

		 CPPFAPIWRAPPER T * get() const {
            if( !result )
               throw ex;

            return result;
         }

		 CPPFAPIWRAPPER bool isValid() const { return gotResult; }

      private:
         T * result;
         std::exception ex;
         bool gotResult;
   };
}

#endif // EXPECTED_H

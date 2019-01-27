#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include "dllmain.h"

#include <string>
#include <exception>

#include "FAPIWrapper.h"

namespace CPPFAPIWrapper {

   enum class CPPFAPIWRAPPER  Reason {
      INTERNAL_ERROR, // c forms api status != success
      OBJECT_NOT_FOUND,
      OTHER
   };

   class FAPIException : public std::exception {
      public:
         CPPFAPIWRAPPER FAPIException(Reason _reason, const char * _file, int _line, std::string _msg = "", int _status = -1)
            : reason(_reason), file(_file), line(_line), msg(_msg), status(_status) {
            prepareString();
         }
		 CPPFAPIWRAPPER virtual ~FAPIException() {}

		 CPPFAPIWRAPPER virtual const char * what() const throw() {
            return msg.c_str();
         }

      private:
         CPPFAPIWRAPPER void prepareString() {
            std::string str = std::string(file) + " line: " + std::to_string(line);

            if( status > -1 )
               str += ": " + errors[status];

            msg += "\n" + reasonStr() + ": " + str;
         }

		 CPPFAPIWRAPPER std::string reasonStr() {
            if( reason == Reason::INTERNAL_ERROR )
               return "C Forms Api error";
            else if( reason == Reason::OBJECT_NOT_FOUND )
               return "Object not found";
            else
               return "Other error";
         }

         Reason reason;
         const char * file;
         int line;
         std::string msg;
         int status;
   };
}


#endif // EXCEPTIONS_H_INCLUDED

#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include "dllmain.h"

namespace CPPFAPIWrapper {
   class FormsObject;

   enum class CPPFAPIWRAPPER PropState {
      DEFAULT,
      LOCAL,
      INHERITED,
      OVERRIDEN
   };

   class Property {
      public:
         /** Creates Property object. Used by FAPIModule, shouldn't be called directly.
         *
         * \param _parent Pointer to parent FormsObject
         * \param _prop_id OracleForms property id
         * \param _prop_type OracleForms property type
         */
		 CPPFAPIWRAPPER Property(FormsObject * _parent, int _prop_id = -1, int _prop_type = -1);

         /** Inherits value from source object property*/
		 CPPFAPIWRAPPER void inherit();

         /** Sets its original state and value to current state and value. Performing after saving module*/
		 CPPFAPIWRAPPER void accept();

         /** Checks if property has broken inheritance (OVERRIDEN state)*/
		 CPPFAPIWRAPPER void checkState();

         /** Gets current property value
         *
         * \return Property value
         */
		 CPPFAPIWRAPPER std::string getValue() const;

         /** Sets current property value, updating its state and marking to set OracleForms internal value
         *
         * \param _value New property value
         */
		 CPPFAPIWRAPPER void setValue(const std::string & _value);

         /** Gets original state of property
         *
         * \return Property original state
         */
		 CPPFAPIWRAPPER PropState getOriginalState() const { return original_state; }

         /** Gets current state of property
         *
         * \return Property current state
         */
		 CPPFAPIWRAPPER PropState getState() const { return state; }

         /** Gets property id
         *
         * \return OracleForms property id
         */
		 CPPFAPIWRAPPER int getId() const { return prop_id; }

         /** Gets property type
         *
         * \return OracleForms property type
         */
		 CPPFAPIWRAPPER int getType() const { return prop_type; }

         /** Gets property dirtiness. If true, internal OracleForms property value needs to be set.
         *
         * \return Dirtiness flag.
         */
		 CPPFAPIWRAPPER bool isDirty() const { return dirty; }

         /** Gets parent object which property is assigned to
         *
         * \return FormsObject pointer
         */
		 CPPFAPIWRAPPER FormsObject * getParent() const { return parent; }
      private:
		 CPPFAPIWRAPPER void checkValue();
		 CPPFAPIWRAPPER void checkStateOnInit();

		 CPPFAPIWRAPPER std::string getObjectValue();
		 CPPFAPIWRAPPER void setObjectValue(const std::string & _value);

         FormsObject * parent;
         PropState original_state;
         PropState state;    // forms api property state
         int prop_id;      // internal forms api property id
         int prop_type;    // internal forms api property type
         bool dirty;       // was property value changed
         std::string original_value;
         std::string value;
   };
}

#endif // PROPERTY_H

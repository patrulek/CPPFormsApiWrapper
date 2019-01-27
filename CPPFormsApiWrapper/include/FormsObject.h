#ifndef FORMSOBJECT_H
#define FORMSOBJECT_H

#include "D2FOB.H"
#include "dllmain.h"

#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

#include "Expected.h"

namespace CPPFAPIWrapper {
   class FAPIModule;
   class FAPIContext;
   class Property;

   class FormsObject {
      public:
         /** Creates FormsObject object. Used by FAPIModule, shouldn't be called directly.
         *
         * \param _ctx Pointer to FAPIModule.
         * \param _type_id OracleForms object type id
         * \param _mod Pointer to OracleForms form object
         * \param _level Hierarchy level of object
         */
         CPPFAPIWRAPPER FormsObject(FAPIModule * _module, int _type_id, d2fob * _forms_obj, int _level);

         /** Marks property for setting its value
         *
         * \param _property Pointer to property
         */
		 CPPFAPIWRAPPER void markProperty(Property * _property);

         /** Unmarks property from setting its value. In addition, unmarks current FormsObject
         * from FAPIModule if last property is unmarked.
         *
         * \param _property Pointer to property
         */
		 CPPFAPIWRAPPER void unmarkProperty(Property * _property);

         /** Sets internal OracleForms property value (in .fmb)
         *
         * \param _property Property
         */
		 CPPFAPIWRAPPER void setProperty(Property * _property);

         /** Inherits all properties for current object from source object */
		 CPPFAPIWRAPPER void inheritAllProp();

         /** Inherits given properties for current object
         *
         * \param _prop_nums Collection of OracleForms property ids
         */
		 CPPFAPIWRAPPER void inheritProps(const std::vector<int> & _prop_nums);

         /** Inherits given property for current object
         *
         * \param _property Pointer to property.
         */
		 CPPFAPIWRAPPER void inheritProp(Property * _property);

         /** Inherits give property from OracleForms prop_id for current object
         *
         * \param _prop_num OracleForms property id
         */
		 CPPFAPIWRAPPER void inheritProp(const int _prop_num);

         /** Checks if object has child given by a parameter.
         *
         * \param _fo Pointer to FormsObject
         * \return True if object has child.
         */
		 CPPFAPIWRAPPER bool hasChild(FormsObject * _fo);

         /** Adds child to current object
         *
         * \param _fo Pointer to FormsObject
         */
		 CPPFAPIWRAPPER void addChild(FormsObject * _fo);

         /** Removes child from current object
         *
         * \param _fo Pointer to FormsObject
         */
		 CPPFAPIWRAPPER void removeChild(FormsObject * _fo);

         /** Changes parent for current object [NOT IMPLEMENTED YET!]
         *
         * \param _parent Pointer to FormsObject, as new parent for current object
         */
		 CPPFAPIWRAPPER void changeParent(FormsObject * _parent);

         /** Searches for source objects in current (or external) modules and returns a hierarchy
         * of source object to the last base object.
         *
         * \return Collection of ptr's to FormsObject with hierarchy of source objects to current object.
         */
		 CPPFAPIWRAPPER std::vector<FormsObject *> findSources();

         /** Checks if object is subclassed from another object.
         *
         * \return True if subclassed.
         */
		 CPPFAPIWRAPPER bool isSubclassed() const;

         /** Checks if has child object given by a parameters.
         *
         * \param _type_id OracleForms object type id
         * \param _name Object's name
         * \return True if current object has child.
         */
		 CPPFAPIWRAPPER bool hasObject(const int _type_id, const std::string & _name);

         /** Gets child object given by a parameters.
         *
         * \param _type_id OracleForms object type id
         * \param _name Object's name
         * \return Expected object containing child object given by a parameters if exists, otherwise Expected object containing nullptr and an appropriate exception.
         */
		 CPPFAPIWRAPPER Expected<FormsObject> getObject(const int _type_id, const std::string & _name);

         /** Gets all childs by a given type
         *
         * \param _type_id OracleForms object type id
         * \return Collecion of ptr's to FormsObject as children objects
         */
		 CPPFAPIWRAPPER std::vector<FormsObject *> getObjects(const int _type_id);

         /** Gets parent object
         *
         * \return Pointer to FormsObject
         */
		 CPPFAPIWRAPPER FormsObject * getParent() const { return parent; }

         /** Gets hierarchy level
         *
         * \return Hierarchy level of an object
         */
		 CPPFAPIWRAPPER int getLevel() const { return level; }

         /** Gets object's type id
         *
         * \return OracleForms object's type id
         */
		 CPPFAPIWRAPPER int getId() const { return type_id; }

         /** Gets OracleForms object pointer
         *
         * \return OracleForms object pointer
         */
		 CPPFAPIWRAPPER d2fob * getFormsObj() const { return forms_obj; }

         /** Gets FAPIContext which module is assigned to.
         *
         * \return FAPIContext pointer
         */
		 CPPFAPIWRAPPER FAPIContext * getContext() const;

         /** Gets FAPIModule which object is assigned to.
         *
         * \return FAPIModule pointer
         */
		 CPPFAPIWRAPPER FAPIModule * getModule() const { return module; }

         /** Gets name of an object
         *
         * \return Name of an object.
         */
		 CPPFAPIWRAPPER std::string getName();

         /** Gets map of children (all children) as a reference
         *
         * \return Map of children
         */
		 CPPFAPIWRAPPER std::unordered_map<int, std::vector<std::unique_ptr<FormsObject>>> & getChildren() { return children; }

         /** Gets map of properties (all properties) as a reference
         *
         * \return Map of properties
         */
		 CPPFAPIWRAPPER std::unordered_map<int, std::unique_ptr<Property>> & getProperties() { return properties; }

         /** Gets properties marked for set
         *
         * \return Collection of Property pointers
         */
		 CPPFAPIWRAPPER std::vector<Property *> & getMarkedProperties() { return marked_properties; }
      private:
         FAPIModule * module;
         FormsObject * parent;
         int type_id;       // internal forms api obj type id
         d2fob * forms_obj;  // internal forms api obj
         int level;
         std::unordered_map<int, std::vector<std::unique_ptr<FormsObject>>> children;
         std::unordered_map<int, std::unique_ptr<Property>> properties;
         std::vector<Property *> marked_properties;
   };
}

#endif // FORMSOBJECT_H

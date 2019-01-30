#include "FAPIModule.h"

#include <algorithm>
#include <fstream>
#include <regex>

#include "Property.h"
#include "FAPIWrapper.h"
#include "FAPIContext.h"
#include "FormsObject.h"
#include "FAPIUtil.h"

#include "d2ffmd.h"
#include "d2fob.h"
#include "d2fpr.h"
#include "d2falb.h"

#include "Exceptions.h"
#include "FAPILogger.h"

namespace CPPFAPIWrapper {
   using namespace std;

   FAPIModule::FAPIModule(FAPIContext * _ctx, d2ffmd * _mod, const string & _filepath)
      : ctx(_ctx), filepath(_filepath) { TRACE_FNC(_filepath)
      auto deleter = [this](const void * data) { d2ffmdde_Destroy(this->ctx->getContext(), const_cast<d2ffmd *>(data)); };
      mod = unique_ptr<d2ffmd, function<void(const void*)>>(_mod, deleter);
   }

   FAPIModule::~FAPIModule() {}

   bool FAPIModule::hasObject(const int _type_id, const string & _name) const { TRACE_FNC(to_string(_type_id) + " | " + _name)
      return root->hasObject(_type_id, _name);
   }

   FormsObject * FAPIModule::getRootObject(const int _type_id, const string & _name) const { TRACE_FNC(to_string(_type_id) + " | " + _name)
      return root->getObject(_type_id, _name).get();
   }

   FormsObject * FAPIModule::getObject(const int _type_id, const string & _fullname) const { TRACE_FNC(to_string(_type_id) + " | " + _fullname)
      auto splits = splitString(_fullname, ".");
      vector<FormsObject *> to_process = { root.get() };
      string name = *splits.end();

      for( auto & split : splits ) {
         FAPILogger::debug(split);

         vector<FormsObject *> new_process;

         while( !to_process.empty() ) {
            auto curr = to_process[0]; to_process.erase(to_process.begin());
            auto & children_types = type_hierarchy[curr->getId()];

            for( auto & type : children_types ) {
               try {
                  auto child = curr->getObject(type, split).get();

                  if( child->getId() == _type_id && child->getName() == name )
                     return child;
                  else
                     new_process.emplace_back(child);
               } catch( exception & ex ) { FAPILogger::warn(ex.what()); }
            }
         }

         to_process.insert(to_process.end(), new_process.begin(), new_process.end());
      }

      throw FAPIException(Reason::OBJECT_NOT_FOUND, __FILE__, __LINE__, to_string(_type_id) + " | " + _fullname);
   }

   vector<FormsObject *> FAPIModule::getObjects(const int _type_id) const { TRACE_FNC(to_string(_type_id))
      return root->getObjects(_type_id);
   }

   vector<FormsObject *> FAPIModule::getAllObjects() const { TRACE_FNC("")
      vector<FormsObject *> objects;
      vector<FormsObject *> to_process = { root.get() };

      while( !to_process.empty() ) {
         FormsObject * curr = to_process[0];
         to_process.erase(to_process.begin());
         objects.emplace_back(curr);
         auto & children = curr->getChildren();

         for( auto & entry : children )
            for( auto & child : entry.second )
               to_process.emplace_back(child.get());
      }

      return objects;
   }

   void FAPIModule::markObject(FormsObject * _forms_object) { TRACE_FNC("")
      if( find(marked_objects.begin(), marked_objects.end(), _forms_object) == marked_objects.end() )
         marked_objects.emplace_back(_forms_object);
   }

   void FAPIModule::unmarkObject(FormsObject * _forms_object) { TRACE_FNC("")
      auto idx = find(marked_objects.begin(), marked_objects.end(), _forms_object);

      if( idx != marked_objects.end() )
         marked_objects.erase(idx);
   }

   void FAPIModule::inheritAllProp() { TRACE_FNC("")
      for( auto obj : getAllObjects() )
         obj->inheritAllProp();
   }

   void FAPIModule::inheritAllPLSQL() { TRACE_FNC("")
      for( auto obj : getAllObjects() ) {
         if( obj->getId() == D2FFO_TRIGGER )
            obj->inheritProp(D2FP_TRG_TXT);
         else if( obj->getId() == D2FFO_PROG_UNIT )
            obj->inheritProp(D2FP_PGU_TXT);
      }
   }

   void FAPIModule::inheritPLSQL(const vector<string> & _units) { TRACE_FNC("")
      for( auto & str : _units ) {
         try {
            auto pgu = getObject(D2FFO_PROG_UNIT, str);
            pgu->inheritProp(D2FP_PGU_TXT);
         } catch( exception & ex ) { FAPILogger::warn(ex.what()); }

         try{
            auto trg = getObject(D2FFO_TRIGGER, str);
            trg->inheritProp(D2FP_TRG_TXT);
         } catch( exception & ex ) { FAPILogger::warn(ex.what()); }
      }
   }

   void FAPIModule::inheritPLSQL(const vector<FormsObject *> & _units) { TRACE_FNC("")
      for( auto obj : _units ) {
         if( obj->getId() == D2FFO_TRIGGER )
            obj->inheritProp(D2FP_TRG_TXT);
         else if( obj->getId() == D2FFO_PROG_UNIT )
            obj->inheritProp(D2FP_PGU_TXT);
      }
   }

   string FAPIModule::createObjectReportFile(const string & _filepath) { TRACE_FNC(_filepath)
      string out_file = (_filepath != "" ? _filepath.substr(0, _filepath.rfind(".")) : filepath.substr(0, filepath.rfind("."))) + ".txt";
      string cmd = "ifcmp60.exe module=\"" + filepath + "\" output_file=\"" + out_file + "\" forms_doc=YES window_state=minimize"; // TODO

      if( ctx->getConnstring() != "" )
         cmd += " userid=" + ctx->getConnstring();

      FAPILogger::debug("out_file=" + out_file + " cmd=" + cmd);
      system(cmd.c_str());

      if( !fileExists(out_file) )
         throw FAPIException(Reason::OTHER, __FILE__, __LINE__, filepath + "_" + out_file);

      return out_file;
   }

   void FAPIModule::checkOverriden() { TRACE_FNC("")
      for( auto fo : getAllObjects() )
         for( auto & entry : fo->getProperties() )
            entry.second->checkState();
   }

   void FAPIModule::attachLib(const string & _lib_name) { TRACE_FNC(_lib_name)
	   if (hasObject(D2FFO_ATT_LIB, _lib_name)) {
		   FAPILogger::warn("Form already attach " + _lib_name);
		   return;
	   }

      d2falb *ppd2falb = nullptr;
      int status = d2falbat_Attach(ctx->getContext(), mod.get(), &ppd2falb, FALSE, stringToText(_lib_name));

      if( status != D2FS_SUCCESS )
         throw FAPIException(Reason::INTERNAL_ERROR, __FILE__, __LINE__, _lib_name, status);

	  FormsObject * lib = new FormsObject(this, D2FFO_ATT_LIB, ppd2falb, 1);
	  root->addChild(lib);
   }

   void FAPIModule::detachLib(const std::string & _lib_name) { TRACE_FNC(_lib_name)
	   Expected<FormsObject> exp_lib = root->getObject(D2FFO_ATT_LIB, _lib_name);
		bool detached = false;

	   while ( exp_lib.isValid() ) {
		   if (detached) {
			   FAPILogger::warn("There are more instances of " + _lib_name + " attached to form! Form needs to be saved before detaching another again");
			   saveModule();
		   }

			int status = d2falbdt_Detach(ctx->getContext(), exp_lib->getFormsObj());

			if (status != D2FS_SUCCESS)
				throw FAPIException(Reason::INTERNAL_ERROR, __FILE__, __LINE__, _lib_name, status);

			detached = true;
			root->removeChild(exp_lib.get());
			exp_lib = root->getObject(D2FFO_ATT_LIB, _lib_name);
	   }
   }

   void FAPIModule::saveModule(const string & _path) { TRACE_FNC(_path)
      string path = _path == "" ? filepath : _path;

      FAPILogger::debug(path);

      for( auto marked_obj : marked_objects ) {
         auto & marked_properties = marked_obj->getMarkedProperties();

         for( auto & marked_prop : marked_properties )
            marked_obj->setProperty(marked_prop);

         marked_properties.clear();
      }

      marked_objects.clear();
      int status = d2ffmdsv_Save(ctx->getContext(), mod.get(), stringToText(path), FALSE);

      if( status != D2FS_SUCCESS )
         throw FAPIException(Reason::INTERNAL_ERROR, __FILE__, __LINE__, path, status);
   }

   void FAPIModule::compileModule() { TRACE_FNC("")
      int status = d2ffmdco_CompileObj(ctx->getContext(), mod.get());

      if( status != D2FS_SUCCESS )
         throw FAPIException(Reason::INTERNAL_ERROR, __FILE__, __LINE__, "", status);
   }

   void FAPIModule::generateModule() { TRACE_FNC("")
      int status = d2ffmdcf_CompileFile(ctx->getContext(), mod.get());

      if( status != D2FS_SUCCESS )
         throw FAPIException(Reason::INTERNAL_ERROR, __FILE__, __LINE__, "", status);
   }

   vector<FormsObject *> FAPIModule::getAttachedLibraries() const { TRACE_FNC("")
      return getObjects(D2FFO_ATT_LIB);
   }

   vector<FormsObject *> FAPIModule::getBlocks() const { TRACE_FNC("")
      return getObjects(D2FFO_BLOCK);
   }

   vector<FormsObject *> FAPIModule::getFormTriggers() const { TRACE_FNC("")
      return getObjects(D2FFO_TRIGGER);
   }

   vector<FormsObject *> FAPIModule::getTriggers() const { TRACE_FNC("")
      auto triggers = getFormTriggers();

      for( auto block : getBlocks() ) {
         for( auto block_trigger : block->getObjects(D2FFO_TRIGGER) )
            triggers.emplace_back(block_trigger);

         for( auto item : block->getObjects(D2FFO_ITEM) )
            for( auto item_trigger : item->getObjects(D2FFO_TRIGGER) )
               triggers.emplace_back(item_trigger);
      }

      return triggers;
   }

   vector<FormsObject *> FAPIModule::getProgramUnits() const { TRACE_FNC("")
      return getObjects(D2FFO_PROG_UNIT);
   }

   vector<FormsObject *> FAPIModule::getCanvases() const { TRACE_FNC("")
      return getObjects(D2FFO_CANVAS);
   }

   vector<FormsObject *> FAPIModule::getParameters() const { TRACE_FNC("")
      return getObjects(D2FFO_FORM_PARAM);
   }

   int FAPIModule::traverseObjects(d2fob * _obj, int _level, FormsObject * _forms_object) { TRACE_FNC("")
      if( root && _level == 0 )
         root = nullptr;

      if( !_obj )
         _obj = mod.get();

      d2fctx * ctx = this->ctx->getContext();
      d2fob * v_subobj, * v_owner;
      d2fotyp v_obj_typ;
      int status;

      /*
      ** Get object type.
      */
      status = d2fobqt_QueryType(ctx, _obj, &v_obj_typ);

      if( status != D2FS_SUCCESS )
        return status;

      /*
      ** If the object type is bogus, then this is something we're not
      ** supposed to be messing with, so we won't.
      */
      if( v_obj_typ > D2FFO_MAX )
        return D2FS_SUCCESS;

      /*
      ** Make sure object is named.  We shouldn't be messing with any
      ** object that doesn't have a name.
      */
      if( d2fobhp_HasProp(ctx, _obj, D2FP_NAME) != D2FS_YES )
        return D2FS_SUCCESS;
	  
      FormsObject * fo = new FormsObject(this, v_obj_typ, _obj, _level);
	  
      if( !root )
         root = unique_ptr<FormsObject>(fo);
	  
      vector<int> object_properties;
	  
      /*
      ** Walk through all properties.
      */
      for ( int prop_num = D2FP_MIN + 1; prop_num < D2FP_MAX + 1; ++prop_num ) {
         text * v_prop_name = nullptr;
         /*
         ** If the object doesn't have this property, or we can't get
         ** the name of the property, or if the property has no name,
         ** then skip to the end of the loop.
         */
         if ( d2fobhp_HasProp(ctx, _obj, prop_num) != D2FS_YES || d2fprgn_GetName(ctx, prop_num, &v_prop_name) != D2FS_SUCCESS || v_prop_name == nullptr )
            continue;
		 
		 //if( v_prop_name )
		 //	free(v_prop_name);
		 
         if( isIrrelevantProperty(prop_num) )
            continue;
		 
         int prop_type = d2fprgt_GetType(ctx, prop_num);
         auto & properties = fo->getProperties();
		 
         if( prop_type == D2FP_TYP_BOOLEAN || prop_type == D2FP_TYP_NUMBER || prop_type == D2FP_TYP_TEXT ) {
            auto property = make_unique<Property>(fo, prop_num, prop_type);

            if( prop_num == D2FP_PAR_FLNAM && property->getValue() != "" )
               source_modules.insert(truncModuleName(property->getValue()));

            properties.emplace(prop_num, move(property));
         }
         else if( prop_type == D2FP_TYP_OBJECT )
            object_properties.emplace_back(prop_num);
      }
	  
      for( int prop_num : object_properties ) {

         /* Get the subobject pointed to by this property. */
         status = d2fobgo_GetObjProp(ctx, _obj, prop_num, &v_subobj);
		 
         if ( status != D2FS_SUCCESS )
            return status;

         /*  Continue if there are no subobjects. */
         if( !v_subobj )
            continue;
		 
         /* Get the owner of the subobject. */
         status = d2fobg_owner(ctx, v_subobj, &v_owner);

         if( status != D2FS_SUCCESS )
            return status;
		 
         /*
         ** If the owner of the subobject isn't the original object,
         ** then it's not really a subobject, so skip it.
         ** This keeps use from examining next, previous, source, the
         ** canvas of an item, etc.
         */
         if (_obj != v_owner)
            continue;
		 
         /*
         ** Recursively process the subobject and all its siblings.
         */
         while( v_subobj ) {
            traverseObjects(v_subobj, _level + 1, fo);
            status = d2fobg_next(ctx, v_subobj, &v_subobj);

            if( status != D2FS_SUCCESS )
               return status;
         }
      }

      if( _forms_object )
         _forms_object->addChild(fo);

      return D2FS_SUCCESS;
   }

   string FAPIModule::getName() const { return root->getName(); }
}

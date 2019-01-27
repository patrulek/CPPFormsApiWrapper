/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FOLB.H -- Dev2K Forms API Object Library declarations

   DESCRIPTION
    Contains the public declarations for the Forms API object library module

   PUBLIC FUNCTIONS
    d2folbcr_Create          - Cover for d2fobcr_Create
    d2folbde_Destroy         - Cover for d2fobde_Destroy
    d2folbdl_Delete          - Delete the module from the database
    d2folbdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2folbao_AddObj          - Add an object to the object library
    d2folbro_RemoveObj       - Remove an object from the object library
    d2folbf2_Findobjbypos    - Find a specific object in the object library
    d2folbld_Load            - Load a obj lib module into memory
    d2folbsv_Save            - Save a obj lib module to disk
    d2folbfv_FileVersion     - Return the version number of the module
    d2folbg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2folbs?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2folbhp_HasProp         - Cover for d2fobhp_HasProp
    d2folbip_InheritProp     - Cover for d2fobip_InheritProp
    d2folbii_IspropInherited - Cover for d2fobii_IspropInherited
    d2folbid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2folbss_SetSmartclass   - Set or Clear the Smartclass flag for an object
    d2folbis_IsSmartclassed  - Return whether a specific object is a smartclass
    d2folbsd_SetDesc         - Set the descriptive text associated with object
    d2folbgd_GetDesc         - Get the descriptive text associated with object
    d2folbot_ObjTabname      - Get the name of the tab where the object lives
*/

#ifndef D2FOLB
#define D2FOLB

#ifndef ORATYPES
# include <oratypes.h>
#endif

#ifndef D2FPRIV
# include <d2fpriv.h>
# endif

/* C++ Support */
#ifdef __cplusplus
extern "C"
{
#endif

/*
** Object: Object Lib
**  
*/
ORA_RETTYPE(d2fstatus) d2folbcr_Create( d2fctx *pd2fctx, d2folb **ppd2folb,  
                                        text *name  );
ORA_RETTYPE(d2fstatus) d2folbde_Destroy( d2fctx *pd2fctx, d2folb *pd2folb );
ORA_RETTYPE(d2fstatus) d2folbdl_Delete( d2fctx *pd2fctx, text *name,
                                        boolean db);
ORA_RETTYPE(d2fstatus) d2folbdu_Duplicate( d2fctx *pd2fctx,
                                           d2folb *pd2folb_src,
                                           d2folb **ppd2folb_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2folbao_AddObj( d2fctx *pd2fctx, d2folb *pd2folb,
                                        d2folt *pd2folt, d2fob *pd2fob,
                                        d2fob **ppd2fob, boolean replace );
ORA_RETTYPE(d2fstatus) d2folbro_RemoveObj( d2fctx *pd2fctx, d2folb *po2olb,
                                           d2fob *pd2fob );
ORA_RETTYPE(d2fstatus) d2folbf2_Findobjbypos(d2fctx  *pd2fctx,
                                             d2folb  *pd2folb,
                                             number   pos,
                                             d2fob  **ppret_obj);
ORA_RETTYPE(d2fstatus) d2folbld_Load( d2fctx *pd2fctx, d2folb **ppd2folb,
                                      text *olibname, boolean db);
ORA_RETTYPE(d2fstatus) d2folbsv_Save( d2fctx *pd2fctx, d2folb *pd2folb,
                                      text *olibname, boolean db);
ORA_RETTYPE(d2fstatus) d2folbfv_FileVersion( d2fctx *pd2fctx, text *olibname,
                                             boolean db, number *version );
ORA_RETTYPE(d2fstatus) d2folbgb_GetBoolProp( d2fctx *pd2fctx, d2folb *pd2folb,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2folbgn_GetNumProp( d2fctx *pd2fctx, d2folb *pd2folb,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2folbgt_GetTextProp( d2fctx *pd2fctx, d2folb *pd2folb,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2folbgo_GetObjProp( d2fctx *pd2fctx, d2folb *pd2folb,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2folbgp_GetBlobProp( d2fctx *pd2fctx, d2folb *pd2folb,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2folbsb_SetBoolProp( d2fctx *pd2fctx, d2folb *pd2folb,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2folbsn_SetNumProp( d2fctx *pd2fctx, d2folb *pd2folb,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2folbst_SetTextProp( d2fctx *pd2fctx, d2folb *pd2folb,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2folbso_SetObjProp( d2fctx *pd2fctx, d2folb *pd2folb,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2folbsp_SetBlobProp( d2fctx *pd2fctx, d2folb *pd2folb,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2folbhp_HasProp( d2fctx *pd2fctx, d2folb *pd2folb,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2folbip_InheritProp( d2fctx *pd2fctx,
                                             d2folb *pd2folb,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2folbii_IspropInherited( d2fctx *pd2fctx,
                                                 d2folb *pd2folb,
                                                 ub2 pnum );
ORA_RETTYPE(d2fstatus) d2folbid_IspropDefault( d2fctx *pd2fctx,
                                               d2folb *pd2folb,
                                               ub2 pnum);
ORA_RETTYPE(d2fstatus) d2folbss_SetSmartclass( d2fctx  *pd2fctx,
                                               d2folb  *pd2folb,
                                               d2fob   *pd2fob,
                                               boolean  state);
ORA_RETTYPE(d2fstatus) d2folbis_IsSmartclassed( d2fctx *pd2fctx,
                                                d2folb *pd2folb,
                                                d2fob  *pd2fob);
ORA_RETTYPE(d2fstatus) d2folbsd_SetDesc( d2fctx  *pd2fctx,
                                         d2folb  *pd2folb,
                                         d2fob   *pd2fob,
                                         text    *desc);
ORA_RETTYPE(d2fstatus) d2folbgd_GetDesc( d2fctx *pd2fctx,
                                         d2folb *pd2folb,
                                         d2fob  *pd2fob,
                                         text  **desc);
ORA_RETTYPE(d2fstatus) d2folbot_ObjTabname(d2fctx *pd2fctx,
                                           d2folb *pd2folb,
                                           d2fob  *pd2fob,
                                           text  **tname);


/* Begin convenience macros  */
#define d2folbg_client_info(ctx,obj,val) \
           d2folbgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2folbg_name(ctx,obj,val) \
           d2folbgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2folbg_next(ctx,obj,val) \
           d2folbgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2folbg_obj_count(ctx,obj,val) \
           d2folbgn_GetNumProp(ctx,obj,D2FP_OBJ_COUNT,val)
#define d2folbg_obj_lib_tab(ctx,obj,val) \
           d2folbgo_GetObjProp(ctx,obj,D2FP_OBJ_LIB_TAB,val)
#define d2folbg_persist_client_info(ctx,obj,val) \
           d2folbgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2folbg_persist_clt_inf_len(ctx,obj,val) \
           d2folbgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2folbg_previous(ctx,obj,val) \
           d2folbgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)

#define d2folbs_client_info(ctx,obj,val) \
           d2folbsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2folbs_name(ctx,obj,val) \
           d2folbst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2folbs_persist_client_info(ctx,obj,val) \
           d2folbsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2folbs_persist_clt_inf_len(ctx,obj,val) \
           d2folbsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FOLB */

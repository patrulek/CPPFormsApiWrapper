/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FMMD.H -- Dev2K Forms API Menu MoDule declarations

   DESCRIPTION
    Contains the public declarations for the Forms API menu module

   PUBLIC FUNCTIONS
    d2fmmdcr_Create          - Cover for d2fobcr_Create
    d2fmmdde_Destroy         - Cover for d2fobde_Destroy
    d2fmmddl_Delete          - Delete the module from the database
    d2fmmddu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fmmdco_CompileObj      - Compile PL/SQL in the menu module
    d2fmmdcf_CompileFile     - Compile the menu module, creating an .mmx 
    d2fmmdld_Load            - Load a menu module into memory
    d2fmmdsv_Save            - Save a menu module to disk
    d2fmmdfv_FileVersion     - Return the version number of the module
    d2fmmdar_AddRole         - Insert a new menu role value by index
    d2fmmdrr_RemoveRole      - Remove the specified menu role
    d2fmmdgr_GetRole         - Get the value of a role specified by index
    d2fmmdg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fmmds?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fmmdhp_HasProp         - Cover for d2fobhp_HasProp
    d2fmmdip_InheritProp     - Cover for d2fobip_InheritProp
    d2fmmdii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fmmdid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fmmdis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FMMD
#define D2FMMD

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
** Object: Menu Module
**  
*/
ORA_RETTYPE(d2fstatus) d2fmmdcr_Create( d2fctx *pd2fctx, d2fmmd **ppd2fmmd,  
                            text *name );
ORA_RETTYPE(d2fstatus) d2fmmdde_Destroy( d2fctx *pd2fctx, d2fmmd *pd2fmmd );
ORA_RETTYPE(d2fstatus) d2fmmddl_Delete( d2fctx *pd2fctx, text *name,
                                        boolean db);
ORA_RETTYPE(d2fstatus) d2fmmddu_Duplicate( d2fctx *pd2fctx,
                                           d2fmmd *pd2fmmd_src,
                                           d2fmmd **ppd2fmmd_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2fmmdco_CompileObj( d2fctx *pd2fctx,
                                            d2fmmd *pd2fmmd );
ORA_RETTYPE(d2fstatus) d2fmmdcf_CompileFile( d2fctx *pd2fctx,
                                             d2fmmd *pd2fmmd );
ORA_RETTYPE(d2fstatus) d2fmmdld_Load( d2fctx *pd2fctx, d2fmmd **ppd2fmmd,
                                      text *menuname, boolean db);
ORA_RETTYPE(d2fstatus) d2fmmdsv_Save( d2fctx *pd2fctx,
                                      d2fmmd *pd2fmmd, text *menuname,
                                      boolean db);
ORA_RETTYPE(d2fstatus) d2fmmdfv_FileVersion( d2fctx *pd2fctx, text *menuname,
                                             boolean db, number *version );
ORA_RETTYPE(d2fstatus) d2fmmdar_AddRole( d2fctx *pd2fctx,
                                         d2fmmd *pd2fmmd,
                                         number index,
                                         text *role_name );
ORA_RETTYPE(d2fstatus) d2fmmdrr_RemoveRole( d2fctx *pd2fctx,
                                            d2fmmd *pd2fmmd,
                                            number index );
ORA_RETTYPE(d2fstatus) d2fmmdgr_GetRole( d2fctx *pd2fctx,
                                         d2fmmd *pd2fmmd,
                                         number index,
                                         text **role_name);
ORA_RETTYPE(d2fstatus) d2fmmdgb_GetBoolProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fmmdgn_GetNumProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fmmdgt_GetTextProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fmmdgo_GetObjProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fmmdgp_GetBlobProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fmmdsb_SetBoolProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fmmdsn_SetNumProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fmmdst_SetTextProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fmmdso_SetObjProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fmmdsp_SetBlobProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fmmdhp_HasProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmmdip_InheritProp( d2fctx *pd2fctx, d2fmmd *pd2fmmd,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmmdii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fmmd *pd2fmmd, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmmdid_IspropDefault( d2fctx *pd2fctx,
                                               d2fmmd *pd2fmmd, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fmmdis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fmmd *pd2fmmd);




/* Begin convenience macros  */
#define d2fmmdg_att_lib(ctx,obj,val) \
           d2fmmdgo_GetObjProp(ctx,obj,D2FP_ATT_LIB,val)
#define d2fmmdg_client_info(ctx,obj,val) \
           d2fmmdgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fmmdg_comment(ctx,obj,val) \
           d2fmmdgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fmmdg_main_mnu(ctx,obj,val) \
           d2fmmdgt_GetTextProp(ctx,obj,D2FP_MAIN_MNU,val)
#define d2fmmdg_menu(ctx,obj,val) \
           d2fmmdgo_GetObjProp(ctx,obj,D2FP_MENU,val)
#define d2fmmdg_mnu_drctry(ctx,obj,val) \
           d2fmmdgt_GetTextProp(ctx,obj,D2FP_MNU_DRCTRY,val)
#define d2fmmdg_mnu_flnam(ctx,obj,val) \
           d2fmmdgt_GetTextProp(ctx,obj,D2FP_MNU_FLNAM,val)
#define d2fmmdg_mnu_param(ctx,obj,val) \
           d2fmmdgo_GetObjProp(ctx,obj,D2FP_MNU_PARAM,val)
#define d2fmmdg_name(ctx,obj,val) \
           d2fmmdgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fmmdg_next(ctx,obj,val) \
           d2fmmdgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fmmdg_obj_grp(ctx,obj,val) \
           d2fmmdgo_GetObjProp(ctx,obj,D2FP_OBJ_GRP,val)
#define d2fmmdg_par_flnam(ctx,obj,val) \
           d2fmmdgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fmmdg_par_flpath(ctx,obj,val) \
           d2fmmdgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fmmdg_par_modstr(ctx,obj,val) \
           d2fmmdgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fmmdg_par_modtyp(ctx,obj,val) \
           d2fmmdgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fmmdg_par_module(ctx,obj,val) \
           d2fmmdgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fmmdg_par_nam(ctx,obj,val) \
           d2fmmdgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fmmdg_par_typ(ctx,obj,val) \
           d2fmmdgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fmmdg_persist_client_info(ctx,obj,val) \
           d2fmmdgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fmmdg_persist_clt_inf_len(ctx,obj,val) \
           d2fmmdgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fmmdg_previous(ctx,obj,val) \
           d2fmmdgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fmmdg_prog_unit(ctx,obj,val) \
           d2fmmdgo_GetObjProp(ctx,obj,D2FP_PROG_UNIT,val)
#define d2fmmdg_prop_class(ctx,obj,val) \
           d2fmmdgo_GetObjProp(ctx,obj,D2FP_PROP_CLASS,val)
#define d2fmmdg_role_count(ctx,obj,val) \
           d2fmmdgn_GetNumProp(ctx,obj,D2FP_ROLE_COUNT,val)
#define d2fmmdg_share_lib(ctx,obj,val) \
           d2fmmdgb_GetBoolProp(ctx,obj,D2FP_SHARE_LIB,val)
#define d2fmmdg_strtup_code(ctx,obj,val) \
           d2fmmdgt_GetTextProp(ctx,obj,D2FP_STRTUP_CODE,val)
#define d2fmmdg_use_security(ctx,obj,val) \
           d2fmmdgb_GetBoolProp(ctx,obj,D2FP_USE_SECURITY,val)
#define d2fmmdg_vis_attr(ctx,obj,val) \
           d2fmmdgo_GetObjProp(ctx,obj,D2FP_VIS_ATTR,val)

#define d2fmmds_client_info(ctx,obj,val) \
           d2fmmdsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fmmds_comment(ctx,obj,val) \
           d2fmmdst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fmmds_main_mnu(ctx,obj,val) \
           d2fmmdst_SetTextProp(ctx,obj,D2FP_MAIN_MNU,val)
#define d2fmmds_mnu_drctry(ctx,obj,val) \
           d2fmmdst_SetTextProp(ctx,obj,D2FP_MNU_DRCTRY,val)
#define d2fmmds_mnu_flnam(ctx,obj,val) \
           d2fmmdst_SetTextProp(ctx,obj,D2FP_MNU_FLNAM,val)
#define d2fmmds_name(ctx,obj,val) \
           d2fmmdst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fmmds_par_flnam(ctx,obj,val) \
           d2fmmdst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fmmds_par_flpath(ctx,obj,val) \
           d2fmmdst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fmmds_par_modstr(ctx,obj,val) \
           d2fmmdsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fmmds_par_modtyp(ctx,obj,val) \
           d2fmmdsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fmmds_par_module(ctx,obj,val) \
           d2fmmdst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fmmds_par_nam(ctx,obj,val) \
           d2fmmdst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fmmds_par_typ(ctx,obj,val) \
           d2fmmdsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fmmds_persist_client_info(ctx,obj,val) \
           d2fmmdsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fmmds_persist_clt_inf_len(ctx,obj,val) \
           d2fmmdsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fmmds_share_lib(ctx,obj,val) \
           d2fmmdsb_SetBoolProp(ctx,obj,D2FP_SHARE_LIB,val)
#define d2fmmds_strtup_code(ctx,obj,val) \
           d2fmmdst_SetTextProp(ctx,obj,D2FP_STRTUP_CODE,val)
#define d2fmmds_use_security(ctx,obj,val) \
           d2fmmdsb_SetBoolProp(ctx,obj,D2FP_USE_SECURITY,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
 
#endif /* D2FMMD */

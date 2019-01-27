/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FMPM.H -- Dev2K Forms API Menu ParaMeter declarations

   DESCRIPTION
    Contains the public declarations for the Forms API menu parameter object

   PUBLIC FUNCTIONS
    d2fmpmcr_Create          - Cover for d2fobcr_Create
    d2fmpmde_Destroy         - Cover for d2fobde_Destroy
    d2fmpmdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fmpmsc_Subclass        - Cover for d2fobsc_Subclass
    d2fmpmaam_AddAssocMenu   - Insert a menu name in the assoc menu list
    d2fmpmram_RemoveAssocMenu- Remove a menu name from the assoc menu list
    d2fmpmgam_GetAssocMenu   - Get a menu name from the assoc menu list
    d2fmpmg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fmpms?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fmpmhp_HasProp         - Cover for d2fobhp_HasProp
    d2fmpmip_InheritProp     - Cover for d2fobip_InheritProp
    d2fmpmii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fmpmid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fmpmis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FMPM
#define D2FMPM

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
** Object: Form Menu Parameter
**  
*/
ORA_RETTYPE(d2fstatus) d2fmpmcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fmpm **ppd2fmpm, text *name );
ORA_RETTYPE(d2fstatus) d2fmpmde_Destroy( d2fctx *pd2fctx, d2fmpm *pd2fmpm );
ORA_RETTYPE(d2fstatus) d2fmpmdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fmpm *pd2fmpm_src,
                                           d2fmpm **ppd2fmpm_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2fmpmsc_SubClass( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fmpmaam_AddAssocMenu( d2fctx *pd2fctx,
                                               d2fmpm *pd2fmpm,
                                               number index,
                                               text *menu_name );
ORA_RETTYPE(d2fstatus) d2fmpmram_RemoveAssocMenu( d2fctx *pd2fctx,
                                                  d2fmpm *pd2fmpm,
                                                  number index );
ORA_RETTYPE(d2fstatus) d2fmpmgam_GetAssocMenu( d2fctx *pd2fctx,
                                               d2fmpm *pd2fmpm,
                                               number index,
                                               text **menu_name);
ORA_RETTYPE(d2fstatus) d2fmpmgb_GetBoolProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fmpmgn_GetNumProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fmpmgt_GetTextProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fmpmgo_GetObjProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fmpmgp_GetBlobProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fmpmsb_SetBoolProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fmpmsn_SetNumProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fmpmst_SetTextProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fmpmso_SetObjProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fmpmsp_SetBlobProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fmpmhp_HasProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmpmip_InheritProp( d2fctx *pd2fctx, d2fmpm *pd2fmpm,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmpmii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fmpm *pd2fmpm, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmpmid_IspropDefault( d2fctx *pd2fctx,
                                               d2fmpm *pd2fmpm, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fmpmis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fmpm *pd2fmpm);



/* Begin convenience macros  */
#define d2fmpmg_assoc_menus_count(ctx,obj,val) \
           d2fmpmgn_GetNumProp(ctx,obj,D2FP_ASSOC_MENUS_COUNT,val)
#define d2fmpmg_assoc_mnus(ctx,obj,val) \
           d2fmpmgo_GetObjProp(ctx,obj,D2FP_ASSOC_MNUS,val)
#define d2fmpmg_case_rstrction(ctx,obj,val) \
           d2fmpmgn_GetNumProp(ctx,obj,D2FP_CASE_RSTRCTION,val)
#define d2fmpmg_client_info(ctx,obj,val) \
           d2fmpmgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fmpmg_comment(ctx,obj,val) \
           d2fmpmgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fmpmg_conceal_data(ctx,obj,val) \
           d2fmpmgb_GetBoolProp(ctx,obj,D2FP_CONCEAL_DATA,val)
#define d2fmpmg_fixed_len(ctx,obj,val) \
           d2fmpmgb_GetBoolProp(ctx,obj,D2FP_FIXED_LEN,val)
#define d2fmpmg_hint(ctx,obj,val) \
           d2fmpmgt_GetTextProp(ctx,obj,D2FP_HINT,val)
#define d2fmpmg_label(ctx,obj,val) \
           d2fmpmgt_GetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2fmpmg_max_len(ctx,obj,val) \
           d2fmpmgn_GetNumProp(ctx,obj,D2FP_MAX_LEN,val)
#define d2fmpmg_mnu_param_init_val(ctx,obj,val) \
           d2fmpmgt_GetTextProp(ctx,obj,D2FP_MNU_PARAM_INIT_VAL,val)
#define d2fmpmg_module(ctx,obj,val) \
           d2fmpmgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fmpmg_name(ctx,obj,val) \
           d2fmpmgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fmpmg_next(ctx,obj,val) \
           d2fmpmgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fmpmg_owner(ctx,obj,val) \
           d2fmpmgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fmpmg_par_flnam(ctx,obj,val) \
           d2fmpmgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fmpmg_par_flpath(ctx,obj,val) \
           d2fmpmgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fmpmg_par_modstr(ctx,obj,val) \
           d2fmpmgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fmpmg_par_modtyp(ctx,obj,val) \
           d2fmpmgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fmpmg_par_module(ctx,obj,val) \
           d2fmpmgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fmpmg_par_nam(ctx,obj,val) \
           d2fmpmgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fmpmg_par_typ(ctx,obj,val) \
           d2fmpmgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fmpmg_persist_client_info(ctx,obj,val) \
           d2fmpmgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fmpmg_persist_clt_inf_len(ctx,obj,val) \
           d2fmpmgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fmpmg_previous(ctx,obj,val) \
           d2fmpmgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fmpmg_required(ctx,obj,val) \
           d2fmpmgb_GetBoolProp(ctx,obj,D2FP_REQUIRED,val)
#define d2fmpmg_source(ctx,obj,val) \
           d2fmpmgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)

#define d2fmpms_assoc_mnus(ctx,obj,val) \
           d2fmpmso_SetObjProp(ctx,obj,D2FP_ASSOC_MNUS,val)
#define d2fmpms_case_rstrction(ctx,obj,val) \
           d2fmpmsn_SetNumProp(ctx,obj,D2FP_CASE_RSTRCTION,val)
#define d2fmpms_client_info(ctx,obj,val) \
           d2fmpmsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fmpms_comment(ctx,obj,val) \
           d2fmpmst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fmpms_conceal_data(ctx,obj,val) \
           d2fmpmsb_SetBoolProp(ctx,obj,D2FP_CONCEAL_DATA,val)
#define d2fmpms_fixed_len(ctx,obj,val) \
           d2fmpmsb_SetBoolProp(ctx,obj,D2FP_FIXED_LEN,val)
#define d2fmpms_hint(ctx,obj,val) \
           d2fmpmst_SetTextProp(ctx,obj,D2FP_HINT,val)
#define d2fmpms_label(ctx,obj,val) \
           d2fmpmst_SetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2fmpms_max_len(ctx,obj,val) \
           d2fmpmsn_SetNumProp(ctx,obj,D2FP_MAX_LEN,val)
#define d2fmpms_mnu_param_init_val(ctx,obj,val) \
           d2fmpmst_SetTextProp(ctx,obj,D2FP_MNU_PARAM_INIT_VAL,val)
#define d2fmpms_name(ctx,obj,val) \
           d2fmpmst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fmpms_par_flnam(ctx,obj,val) \
           d2fmpmst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fmpms_par_flpath(ctx,obj,val) \
           d2fmpmst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fmpms_par_modstr(ctx,obj,val) \
           d2fmpmsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fmpms_par_modtyp(ctx,obj,val) \
           d2fmpmsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fmpms_par_module(ctx,obj,val) \
           d2fmpmst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fmpms_par_nam(ctx,obj,val) \
           d2fmpmst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fmpms_par_typ(ctx,obj,val) \
           d2fmpmsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fmpms_persist_client_info(ctx,obj,val) \
           d2fmpmsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fmpms_persist_clt_inf_len(ctx,obj,val) \
           d2fmpmsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fmpms_required(ctx,obj,val) \
           d2fmpmsb_SetBoolProp(ctx,obj,D2FP_REQUIRED,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FMPM */



/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FFPM.H -- Dev2K Forms API Form ParaMeter declarations

   DESCRIPTION
    Contains the public declarations for the Forms API Form ParaMeter object

   PUBLIC FUNCTIONS
    d2ffpmcr_Create          - Cover for d2fobcr_Create
    d2ffpmde_Destroy         - Cover for d2fobde_Destroy
    d2ffpmdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2ffpmsc_Subclass        - Cover for d2fobsc_Subclass
    d2ffpmg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2ffpms?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2ffpmhp_HasProp         - Cover for d2fobhp_HasProp
    d2ffpmip_InheritProp     - Cover for d2fobip_InheritProp
    d2ffpmii_IspropInherited - Cover for d2fobii_IspropInherited
    d2ffpmid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2ffpmis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FFPM
#define D2FFPM

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
** Object: Form Parameter
**  
*/
ORA_RETTYPE(d2fstatus) d2ffpmcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2ffpm **ppd2ffpm, text *name );
ORA_RETTYPE(d2fstatus) d2ffpmde_Destroy( d2fctx *pd2fctx, d2ffpm *pd2ffpm );
ORA_RETTYPE(d2fstatus) d2ffpmdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2ffpm *pd2ffpm_src,
                                           d2ffpm **ppd2ffpm_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2ffpmsc_SubClass( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2ffpmgb_GetBoolProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2ffpmgn_GetNumProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2ffpmgt_GetTextProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2ffpmgo_GetObjProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ffpmgp_GetBlobProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ffpmsb_SetBoolProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2ffpmsn_SetNumProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2ffpmst_SetTextProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2ffpmso_SetObjProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ffpmsp_SetBlobProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ffpmhp_HasProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ffpmip_InheritProp( d2fctx *pd2fctx, d2ffpm *pd2ffpm,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ffpmii_IspropInherited( d2fctx *pd2fctx,
                                                 d2ffpm *pd2ffpm, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ffpmid_IspropDefault( d2fctx *pd2fctx,
                                               d2ffpm *pd2ffpm, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2ffpmis_IsSubclassed( d2fctx *pd2fctx,
                                              d2ffpm *pd2ffpm);



/* Begin convenience macros  */
#define d2ffpmg_client_info(ctx,obj,val) \
           d2ffpmgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2ffpmg_comment(ctx,obj,val) \
           d2ffpmgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2ffpmg_max_len(ctx,obj,val) \
           d2ffpmgn_GetNumProp(ctx,obj,D2FP_MAX_LEN,val)
#define d2ffpmg_module(ctx,obj,val) \
           d2ffpmgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2ffpmg_name(ctx,obj,val) \
           d2ffpmgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2ffpmg_next(ctx,obj,val) \
           d2ffpmgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2ffpmg_owner(ctx,obj,val) \
           d2ffpmgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2ffpmg_par_flnam(ctx,obj,val) \
           d2ffpmgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2ffpmg_par_flpath(ctx,obj,val) \
           d2ffpmgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2ffpmg_par_modstr(ctx,obj,val) \
           d2ffpmgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2ffpmg_par_modtyp(ctx,obj,val) \
           d2ffpmgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2ffpmg_par_module(ctx,obj,val) \
           d2ffpmgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2ffpmg_par_nam(ctx,obj,val) \
           d2ffpmgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2ffpmg_par_typ(ctx,obj,val) \
           d2ffpmgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2ffpmg_param_dat_typ(ctx,obj,val) \
           d2ffpmgn_GetNumProp(ctx,obj,D2FP_PARAM_DAT_TYP,val)
#define d2ffpmg_param_init_val(ctx,obj,val) \
           d2ffpmgt_GetTextProp(ctx,obj,D2FP_PARAM_INIT_VAL,val)
#define d2ffpmg_persist_client_info(ctx,obj,val) \
           d2ffpmgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2ffpmg_persist_clt_inf_len(ctx,obj,val) \
           d2ffpmgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2ffpmg_previous(ctx,obj,val) \
           d2ffpmgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2ffpmg_source(ctx,obj,val) \
           d2ffpmgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)

#define d2ffpms_client_info(ctx,obj,val) \
           d2ffpmsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2ffpms_comment(ctx,obj,val) \
           d2ffpmst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2ffpms_max_len(ctx,obj,val) \
           d2ffpmsn_SetNumProp(ctx,obj,D2FP_MAX_LEN,val)
#define d2ffpms_name(ctx,obj,val) \
           d2ffpmst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2ffpms_par_flnam(ctx,obj,val) \
           d2ffpmst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2ffpms_par_flpath(ctx,obj,val) \
           d2ffpmst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2ffpms_par_modstr(ctx,obj,val) \
           d2ffpmsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2ffpms_par_modtyp(ctx,obj,val) \
           d2ffpmsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2ffpms_par_module(ctx,obj,val) \
           d2ffpmst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2ffpms_par_nam(ctx,obj,val) \
           d2ffpmst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2ffpms_par_typ(ctx,obj,val) \
           d2ffpmsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2ffpms_param_dat_typ(ctx,obj,val) \
           d2ffpmsn_SetNumProp(ctx,obj,D2FP_PARAM_DAT_TYP,val)
#define d2ffpms_param_init_val(ctx,obj,val) \
           d2ffpmst_SetTextProp(ctx,obj,D2FP_PARAM_INIT_VAL,val)
#define d2ffpms_persist_client_info(ctx,obj,val) \
           d2ffpmsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2ffpms_persist_clt_inf_len(ctx,obj,val) \
           d2ffpmsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FFPM */



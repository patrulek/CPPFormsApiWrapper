/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/* 
   NAME
    D2FDSC.H -- Dev2K Forms API Data Source Column declarations

   DESCRIPTION
    Contains the public declarations for the Forms API Data Source Column

   PUBLIC FUNCTIONS
    d2fdsccr_Create          - Cover for d2fobcr_Create
    d2fdscde_Destroy         - Cover for d2fobde_Destroy
    d2fdscdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fdscg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fdscs?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fdschp_HasProp         - Cover for d2fobhp_HasProp
    d2fdscip_InheritProp     - Cover for d2fobip_InheritProp
    d2fdscii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fdscid_IspropDefault   - Cover for d2fobid_IspropDefault
*/

#ifndef D2FDSC
#define D2FDSC

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
** Object: Data Source Column Object
**  
*/
ORA_RETTYPE(d2fstatus) d2fdsccr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fdsc **ppd2fdsc, ub2 owning_prop);
ORA_RETTYPE(d2fstatus) d2fdscde_Destroy( d2fctx *pd2fctx, d2fdsc *pd2fdsc );
ORA_RETTYPE(d2fstatus) d2fdscdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fdsc *pd2fdsc_src,
                                           d2fdsc **ppd2fdsc_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2fdscgb_GetBoolProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fdscgn_GetNumProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fdscgt_GetTextProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fdscgo_GetObjProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fdscgp_GetBlobProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fdscsb_SetBoolProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fdscsn_SetNumProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fdscst_SetTextProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fdscso_SetObjProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fdscsp_SetBlobProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fdschp_HasProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fdscip_InheritProp( d2fctx *pd2fctx, d2fdsc *pd2fdsc,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fdscii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fdsc *pd2fdsc, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fdscid_IspropDefault( d2fctx *pd2fctx,
                                               d2fdsc *pd2fdsc, ub2 pnum);

/* Begin convenience macros  */
#define d2fdscg_client_info(ctx,obj,val) \
           d2fdscgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fdscg_dsc_len(ctx,obj,val) \
           d2fdscgn_GetNumProp(ctx,obj,D2FP_DSC_LEN,val)
#define d2fdscg_dsc_mandatory(ctx,obj,val) \
           d2fdscgb_GetBoolProp(ctx,obj,D2FP_DSC_MANDATORY,val)
#define d2fdscg_dsc_nam(ctx,obj,val) \
           d2fdscgt_GetTextProp(ctx,obj,D2FP_DSC_NAM,val)
#define d2fdscg_dsc_nochildren(ctx,obj,val) \
           d2fdscgb_GetBoolProp(ctx,obj,D2FP_DSC_NOCHILDREN,val)
#define d2fdscg_dsc_parent_name(ctx,obj,val) \
           d2fdscgt_GetTextProp(ctx,obj,D2FP_DSC_PARENT_NAME,val)
#define d2fdscg_dsc_precision(ctx,obj,val) \
           d2fdscgn_GetNumProp(ctx,obj,D2FP_DSC_PRECISION,val)
#define d2fdscg_dsc_scale(ctx,obj,val) \
           d2fdscgn_GetNumProp(ctx,obj,D2FP_DSC_SCALE,val)
#define d2fdscg_dsc_typ(ctx,obj,val) \
           d2fdscgn_GetNumProp(ctx,obj,D2FP_DSC_TYP,val)
#define d2fdscg_dsc_type_name(ctx,obj,val) \
           d2fdscgt_GetTextProp(ctx,obj,D2FP_DSC_TYPE_NAME,val)
#define d2fdscg_next(ctx,obj,val) \
           d2fdscgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fdscg_persist_client_info(ctx,obj,val) \
           d2fdscgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fdscg_persist_clt_inf_len(ctx,obj,val) \
           d2fdscgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fdscg_previous(ctx,obj,val) \
           d2fdscgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)

#define d2fdscs_client_info(ctx,obj,val) \
           d2fdscsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fdscs_dsc_len(ctx,obj,val) \
           d2fdscsn_SetNumProp(ctx,obj,D2FP_DSC_LEN,val)
#define d2fdscs_dsc_mandatory(ctx,obj,val) \
           d2fdscsb_SetBoolProp(ctx,obj,D2FP_DSC_MANDATORY,val)
#define d2fdscs_dsc_nam(ctx,obj,val) \
           d2fdscst_SetTextProp(ctx,obj,D2FP_DSC_NAM,val)
#define d2fdscs_dsc_nochildren(ctx,obj,val) \
           d2fdscsb_SetBoolProp(ctx,obj,D2FP_DSC_NOCHILDREN,val)
#define d2fdscs_dsc_parent_name(ctx,obj,val) \
           d2fdscst_SetTextProp(ctx,obj,D2FP_DSC_PARENT_NAME,val)
#define d2fdscs_dsc_precision(ctx,obj,val) \
           d2fdscsn_SetNumProp(ctx,obj,D2FP_DSC_PRECISION,val)
#define d2fdscs_dsc_scale(ctx,obj,val) \
           d2fdscsn_SetNumProp(ctx,obj,D2FP_DSC_SCALE,val)
#define d2fdscs_dsc_typ(ctx,obj,val) \
           d2fdscsn_SetNumProp(ctx,obj,D2FP_DSC_TYP,val)
#define d2fdscs_dsc_type_name(ctx,obj,val) \
           d2fdscst_SetTextProp(ctx,obj,D2FP_DSC_TYPE_NAME,val)
#define d2fdscs_persist_client_info(ctx,obj,val) \
           d2fdscsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fdscs_persist_clt_inf_len(ctx,obj,val) \
           d2fdscsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
/* End convenience macros  */


/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FDSC */


/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FLCM.H -- Dev2K Forms API LOV Column Mapping declarations

   DESCRIPTION
    Contains the public declarations for the Forms API LOV Column Mapping object

   PUBLIC FUNCTIONS
    d2flcmcr_Create          - Cover for d2fobcr_Create
    d2flcmde_Destroy         - Cover for d2fobde_Destroy
    d2flcmdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2flcmg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2flcms?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2flcmhp_HasProp         - Cover for d2fobhp_HasProp
    d2flcmip_InheritProp     - Cover for d2fobip_InheritProp
    d2flcmii_IspropInherited - Cover for d2fobii_IspropInherited
    d2flcmid_IspropDefault   - Cover for d2fobid_IspropDefault
*/

#ifndef D2FLCM
#define D2FLCM

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
** Object: LOV Column Mapping
**  
*/
ORA_RETTYPE(d2fstatus) d2flcmcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2flcm **ppd2flcm, text *name );
ORA_RETTYPE(d2fstatus) d2flcmde_Destroy( d2fctx *pd2fctx, d2flcm *pd2flcm );
ORA_RETTYPE(d2fstatus) d2flcmdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2flcm *pd2flcm_src,
                                           d2flcm **ppd2flcm_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2flcmgb_GetBoolProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2flcmgn_GetNumProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2flcmgt_GetTextProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2flcmgo_GetObjProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2flcmgp_GetBlobProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2flcmsb_SetBoolProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2flcmsn_SetNumProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2flcmst_SetTextProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2flcmso_SetObjProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2flcmsp_SetBlobProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2flcmhp_HasProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2flcmip_InheritProp( d2fctx *pd2fctx, d2flcm *pd2flcm,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2flcmii_IspropInherited( d2fctx *pd2fctx,
                                                 d2flcm *pd2flcm, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2flcmid_IspropDefault( d2fctx *pd2fctx,
                                               d2flcm *pd2flcm, ub2 pnum);


/* Begin convenience macros  */
#define d2flcmg_client_info(ctx,obj,val) \
           d2flcmgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2flcmg_disp_wid(ctx,obj,val) \
           d2flcmgn_GetNumProp(ctx,obj,D2FP_DISP_WID,val)
#define d2flcmg_name(ctx,obj,val) \
           d2flcmgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2flcmg_next(ctx,obj,val) \
           d2flcmgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2flcmg_persist_client_info(ctx,obj,val) \
           d2flcmgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2flcmg_persist_clt_inf_len(ctx,obj,val) \
           d2flcmgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2flcmg_previous(ctx,obj,val) \
           d2flcmgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2flcmg_rtrn_itm(ctx,obj,val) \
           d2flcmgt_GetTextProp(ctx,obj,D2FP_RTRN_ITM,val)
#define d2flcmg_title(ctx,obj,val) \
           d2flcmgt_GetTextProp(ctx,obj,D2FP_TITLE,val)

#define d2flcms_client_info(ctx,obj,val) \
           d2flcmsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2flcms_disp_wid(ctx,obj,val) \
           d2flcmsn_SetNumProp(ctx,obj,D2FP_DISP_WID,val)
#define d2flcms_name(ctx,obj,val) \
           d2flcmst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2flcms_persist_client_info(ctx,obj,val) \
           d2flcmsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2flcms_persist_clt_inf_len(ctx,obj,val) \
           d2flcmsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2flcms_rtrn_itm(ctx,obj,val) \
           d2flcmst_SetTextProp(ctx,obj,D2FP_RTRN_ITM,val)
#define d2flcms_title(ctx,obj,val) \
           d2flcmst_SetTextProp(ctx,obj,D2FP_TITLE,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
               
#endif /* D2FLCM */

/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/* 
   NAME
    D2FREL.H -- Dev2K Forms API RELation declarations

   DESCRIPTION
    Contains the public declarations for the Forms API RELation object

   PUBLIC FUNCTIONS
    d2frelcr_Create          - Cover for d2fobcr_Create
    d2frelde_Destroy         - Cover for d2fobde_Destroy
    d2freldu_Duplicate       - Cover for d2fobdu_Duplicate
    d2frelup_Update          - Update (Called to actually instantiate)
    d2frelg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2frels?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2frelhp_HasProp         - Cover for d2fobhp_HasProp
    d2frelip_InheritProp     - Cover for d2fobip_InheritProp
    d2frelii_IspropInherited - Cover for d2fobii_IspropInherited
    d2frelid_IspropDefault   - Cover for d2fobid_IspropDefault
*/

#ifndef D2FREL
#define D2FREL

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
** Object: Relation
**  
** d2frelup_Update - after creating the object, call Update() to
**                   create the triggers, program units, etc.
*/
ORA_RETTYPE(d2fstatus) d2frelcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2frel **ppd2frel, text *name  );
ORA_RETTYPE(d2fstatus) d2frelde_Destroy( d2fctx *pd2fctx, d2frel *pd2frel );
ORA_RETTYPE(d2fstatus) d2freldu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2frel *pd2frel_src,
                                           d2frel **ppd2frel_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2frelup_Update( d2fctx *pd2fctx, d2frel *pd2frel );
ORA_RETTYPE(d2fstatus) d2frelgb_GetBoolProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2frelgn_GetNumProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2frelgt_GetTextProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2frelgo_GetObjProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2frelgp_GetBlobProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2frelsb_SetBoolProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2frelsn_SetNumProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2frelst_SetTextProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2frelso_SetObjProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2frelsp_SetBlobProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2frelhp_HasProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                         ub2 pnum);
ORA_RETTYPE(d2fstatus) d2frelip_InheritProp( d2fctx *pd2fctx, d2frel *pd2frel,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frelii_IspropInherited( d2fctx *pd2fctx,
                                                 d2frel *pd2frel, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frelid_IspropDefault( d2fctx *pd2fctx,
                                               d2frel *pd2frel, ub2 pnum);


/* Begin convenience macros  */
#define d2frelg_auto_qry(ctx,obj,val) \
           d2frelgb_GetBoolProp(ctx,obj,D2FP_AUTO_QRY,val)
#define d2frelg_client_info(ctx,obj,val) \
           d2frelgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2frelg_comment(ctx,obj,val) \
           d2frelgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2frelg_deferred(ctx,obj,val) \
           d2frelgb_GetBoolProp(ctx,obj,D2FP_DEFERRED,val)
#define d2frelg_del_rec(ctx,obj,val) \
           d2frelgn_GetNumProp(ctx,obj,D2FP_DEL_REC,val)
#define d2frelg_detail_blk(ctx,obj,val) \
           d2frelgt_GetTextProp(ctx,obj,D2FP_DETAIL_BLK,val)
#define d2frelg_detail_itemref(ctx,obj,val) \
           d2frelgt_GetTextProp(ctx,obj,D2FP_DETAIL_ITEMREF,val)
#define d2frelg_join_cond(ctx,obj,val) \
           d2frelgt_GetTextProp(ctx,obj,D2FP_JOIN_COND,val)
#define d2frelg_module(ctx,obj,val) \
           d2frelgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2frelg_name(ctx,obj,val) \
           d2frelgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2frelg_next(ctx,obj,val) \
           d2frelgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2frelg_owner(ctx,obj,val) \
           d2frelgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2frelg_persist_client_info(ctx,obj,val) \
           d2frelgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2frelg_persist_clt_inf_len(ctx,obj,val) \
           d2frelgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2frelg_previous(ctx,obj,val) \
           d2frelgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2frelg_prvnt_mstrless_ops(ctx,obj,val) \
           d2frelgb_GetBoolProp(ctx,obj,D2FP_PRVNT_MSTRLESS_OPS,val)
#define d2frelg_rel_type(ctx,obj,val) \
           d2frelgn_GetNumProp(ctx,obj,D2FP_REL_TYPE,val)
#define d2frelg_source(ctx,obj,val) \
           d2frelgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)

#define d2frels_auto_qry(ctx,obj,val) \
           d2frelsb_SetBoolProp(ctx,obj,D2FP_AUTO_QRY,val)
#define d2frels_client_info(ctx,obj,val) \
           d2frelsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2frels_comment(ctx,obj,val) \
           d2frelst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2frels_deferred(ctx,obj,val) \
           d2frelsb_SetBoolProp(ctx,obj,D2FP_DEFERRED,val)
#define d2frels_del_rec(ctx,obj,val) \
           d2frelsn_SetNumProp(ctx,obj,D2FP_DEL_REC,val)
#define d2frels_detail_blk(ctx,obj,val) \
           d2frelst_SetTextProp(ctx,obj,D2FP_DETAIL_BLK,val)
#define d2frels_detail_itemref(ctx,obj,val) \
           d2frelst_SetTextProp(ctx,obj,D2FP_DETAIL_ITEMREF,val)
#define d2frels_join_cond(ctx,obj,val) \
           d2frelst_SetTextProp(ctx,obj,D2FP_JOIN_COND,val)
#define d2frels_name(ctx,obj,val) \
           d2frelst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2frels_persist_client_info(ctx,obj,val) \
           d2frelsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2frels_persist_clt_inf_len(ctx,obj,val) \
           d2frelsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2frels_prvnt_mstrless_ops(ctx,obj,val) \
           d2frelsb_SetBoolProp(ctx,obj,D2FP_PRVNT_MSTRLESS_OPS,val)
#define d2frels_rel_type(ctx,obj,val) \
           d2frelsn_SetNumProp(ctx,obj,D2FP_REL_TYPE,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
               
#endif /* D2FREL */

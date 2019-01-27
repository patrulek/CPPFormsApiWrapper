/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FOGC.H -- Dev2K Forms API Object Group Child declarations

   DESCRIPTION
    Contains the public declarations for the Forms API object group child object

   PUBLIC FUNCTIONS
    d2fogccr_Create          - Cover for d2fobcr_Create
    d2fogcde_Destroy         - Cover for d2fobde_Destroy
    d2fogcdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fogcg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fogcs?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fogchp_HasProp         - Cover for d2fobhp_HasProp
    d2fogcip_InheritProp     - Cover for d2fobip_InheritProp
    d2fogcii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fogcid_IspropDefault   - Cover for d2fobid_IspropDefault
*/

#ifndef D2FOGC
#define D2FOGC

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
** Object: Object Group Child
**  
*/
ORA_RETTYPE(d2fstatus) d2fogccr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fogc **ppd2fogc, text *name  );
ORA_RETTYPE(d2fstatus) d2fogcde_Destroy( d2fctx *pd2fctx, d2fogc *pd2fogc );
ORA_RETTYPE(d2fstatus) d2fogcdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fogc *pd2fogc_src,
                                           d2fogc **ppd2fogc_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2fogcgb_GetBoolProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fogcgn_GetNumProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fogcgt_GetTextProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fogcgo_GetObjProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fogcgp_GetBlobProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                             ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fogcsb_SetBoolProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fogcsn_SetNumProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fogcst_SetTextProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fogcso_SetObjProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fogcsp_SetBlobProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                             ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fogchp_HasProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fogcip_InheritProp( d2fctx *pd2fctx, d2fogc *pd2fogc,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fogcii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fogc *pd2fogc, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fogcid_IspropDefault( d2fctx *pd2fctx,
                                               d2fogc *pd2fogc, ub2 pnum);


/* Begin convenience macros  */
#define d2fogcg_client_info(ctx,obj,val) \
           d2fogcgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fogcg_name(ctx,obj,val) \
           d2fogcgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fogcg_next(ctx,obj,val) \
           d2fogcgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fogcg_obj_grp_child_real_obj(ctx,obj,val) \
           d2fogcgo_GetObjProp(ctx,obj,D2FP_OBJ_GRP_CHILD_REAL_OBJ,val)
#define d2fogcg_persist_client_info(ctx,obj,val) \
           d2fogcgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fogcg_persist_clt_inf_len(ctx,obj,val) \
           d2fogcgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fogcg_previous(ctx,obj,val) \
           d2fogcgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fogcg_source(ctx,obj,val) \
           d2fogcgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)

#define d2fogcs_client_info(ctx,obj,val) \
           d2fogcsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fogcs_name(ctx,obj,val) \
           d2fogcst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fogcs_obj_grp_child_real_obj(ctx,obj,val) \
           d2fogcso_SetObjProp(ctx,obj,D2FP_OBJ_GRP_CHILD_REAL_OBJ,val)
#define d2fogcs_persist_client_info(ctx,obj,val) \
           d2fogcsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fogcs_persist_clt_inf_len(ctx,obj,val) \
           d2fogcsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FOGC */

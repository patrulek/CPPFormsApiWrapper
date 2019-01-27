/*
 * $Header: d2folt.h@@/main/TOOLS_DEV2K_994/3 \
 * Checked in on Thu Aug 12 09:37:46 PDT 1999 by vobadm \
 * Copyright (c) 1999 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 1999.  All Rights Reserved. */

/*
   NAME
    D2FOLT.H -- Dev2K Forms API Object Library Tab declarations

   DESCRIPTION
    Contains the public declarations for the Forms API object library table object

   PUBLIC FUNCTIONS
    d2foltcr_Create          - Cover for d2fobcr_Create
    d2foltde_Destroy         - Cover for d2fobde_Destroy
    d2foltdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2foltf2_Findobjbypos    - Return a specific object by index
    d2foltg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2folts?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2folthp_HasProp         - Cover for d2fobhp_HasProp
    d2foltip_InheritProp     - Cover for d2fobip_InheritProp
    d2foltii_IspropInherited - Cover for d2fobii_IspropInherited
    d2foltid_IspropDefault   - Cover for d2fobid_IspropDefault
*/

#ifndef D2FOLT
#define D2FOLT

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
** Object: Object Library Tab Object
**  
*/
ORA_RETTYPE(d2fstatus) d2foltcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2folt **ppd2folt, text *name  );
ORA_RETTYPE(d2fstatus) d2foltde_Destroy( d2fctx *pd2fctx, d2folt *pd2folt );
ORA_RETTYPE(d2fstatus) d2foltdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2folt *pd2folt_src,
                                           d2folt **ppd2folt_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2foltf2_Findobjbypos(d2fctx  *pd2fctx,
                                             d2folt  *pd2folt,
                                             number   pos,
                                             d2fob  **ppret_obj);
ORA_RETTYPE(d2fstatus) d2foltgb_GetBoolProp( d2fctx *pd2fctx, d2folt *pd2folt,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2foltgn_GetNumProp( d2fctx *pd2fctx, d2folt *pd2folt,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2foltgt_GetTextProp( d2fctx *pd2fctx, d2folt *pd2folt,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2foltgo_GetObjProp( d2fctx *pd2fctx, d2folt *pd2folt,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2foltgp_GetBlobProp( d2fctx *pd2fctx, d2folt *pd2folt,
					    ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2foltsb_SetBoolProp( d2fctx *pd2fctx, d2folt *pd2folt,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2foltsn_SetNumProp( d2fctx *pd2fctx, d2folt *pd2folt,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2foltst_SetTextProp( d2fctx *pd2fctx, d2folt *pd2folt,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2foltso_SetObjProp( d2fctx *pd2fctx, d2folt *pd2folt,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2foltsp_SetBlobProp( d2fctx *pd2fctx, d2folt *pd2folt,
                                             ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2folthp_HasProp( d2fctx *pd2fctx, d2folt *pd2folt,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2foltip_InheritProp( d2fctx *pd2fctx, d2folt *pd2folt,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2foltii_IspropInherited( d2fctx *pd2fctx,
                                                 d2folt *pd2folt, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2foltid_IspropDefault( d2fctx *pd2fctx,
                                               d2folt *pd2folt, ub2 pnum);


/* Begin convenience macros  */
#define d2foltg_client_info(ctx,obj,val) \
           d2foltgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2foltg_comment(ctx,obj,val) \
           d2foltgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2foltg_label(ctx,obj,val) \
           d2foltgt_GetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2foltg_name(ctx,obj,val) \
           d2foltgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2foltg_next(ctx,obj,val) \
           d2foltgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2foltg_obj_count(ctx,obj,val) \
           d2foltgn_GetNumProp(ctx,obj,D2FP_OBJ_COUNT,val)
#define d2foltg_persist_client_info(ctx,obj,val) \
           d2foltgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2foltg_persist_clt_inf_len(ctx,obj,val) \
           d2foltgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2foltg_previous(ctx,obj,val) \
           d2foltgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)

#define d2folts_client_info(ctx,obj,val) \
           d2foltsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2folts_comment(ctx,obj,val) \
           d2foltst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2folts_label(ctx,obj,val) \
           d2foltst_SetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2folts_name(ctx,obj,val) \
           d2foltst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2folts_persist_client_info(ctx,obj,val) \
           d2foltsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2folts_persist_clt_inf_len(ctx,obj,val) \
           d2foltsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
/* End convenience macros  */


/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FOLT */


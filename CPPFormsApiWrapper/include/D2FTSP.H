/*
 * $Header: d2ftsp.h@@/main/TOOLS_DEV2K_994/1 \
 * Checked in on Thu Apr 27 08:42:17 PDT 2000 by vobadm \
 * Copyright (c) 2000 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 2000.  All Rights Reserved. */

/*
   NAME
    D2FTSP.H -- Dev2K Forms API Trigger SteP declarations

   DESCRIPTION
    Contains the public declarations for the Forms API trigger step object

   PUBLIC FUNCTIONS
    d2ftspde_Destroy         - Cover for d2fobde_Destroy
    d2ftspsc_Subclass        - Cover for d2fobsc_Subclass
    d2ftspco_CompileObj      - Compile the object's PL/SQL code
    d2ftspg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2ftsps?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2ftsphp_HasProp         - Cover for d2fobhp_HasProp
    d2ftspip_InheritProp     - Cover for d2fobip_InheritProp
    d2ftspii_IspropInherited - Cover for d2fobii_IspropInherited
    d2ftspid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2ftspis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FTSP
#define D2FTSP

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
** Object: Trigger Step
**  
*/
ORA_RETTYPE(d2fstatus) d2ftspde_Destroy( d2fctx *pd2fctx, d2ftsp *pd2ftsp );
ORA_RETTYPE(d2fstatus) d2ftspsc_SubClass( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2ftspco_CompileObj( d2fctx *pd2fctx,
                                               d2ftsp *pd2ftsp );
ORA_RETTYPE(d2fstatus) d2ftspgb_GetBoolProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2ftspgn_GetNumProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2ftspgt_GetTextProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2ftspgo_GetObjProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ftspgp_GetBlobProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ftspsb_SetBoolProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2ftspsn_SetNumProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2ftspst_SetTextProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2ftspso_SetObjProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ftspsp_SetBlobProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ftsphp_HasProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ftspip_InheritProp( d2fctx *pd2fctx, d2ftsp *pd2ftsp,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ftspii_IspropInherited( d2fctx *pd2fctx,
                                                 d2ftsp *pd2ftsp, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ftspid_IspropDefault( d2fctx *pd2fctx,
                                               d2ftsp *pd2ftsp, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2ftspis_IsSubclassed( d2fctx *pd2fctx,
                                              d2ftsp *pd2ftsp);


/* Begin convenience macros  */
#define d2ftspg_abort_fail(ctx,obj,val) \
           d2ftspgb_GetBoolProp(ctx,obj,D2FP_ABORT_FAIL,val)
#define d2ftspg_client_info(ctx,obj,val) \
           d2ftspgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2ftspg_comment(ctx,obj,val) \
           d2ftspgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2ftspg_fail_label(ctx,obj,val) \
           d2ftspgt_GetTextProp(ctx,obj,D2FP_FAIL_LABEL,val)
#define d2ftspg_fail_msg(ctx,obj,val) \
           d2ftspgt_GetTextProp(ctx,obj,D2FP_FAIL_MSG,val)
#define d2ftspg_label(ctx,obj,val) \
           d2ftspgt_GetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2ftspg_new_cursor(ctx,obj,val) \
           d2ftspgb_GetBoolProp(ctx,obj,D2FP_NEW_CURSOR,val)
#define d2ftspg_next(ctx,obj,val) \
           d2ftspgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2ftspg_persist_client_info(ctx,obj,val) \
           d2ftspgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2ftspg_persist_clt_inf_len(ctx,obj,val) \
           d2ftspgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2ftspg_previous(ctx,obj,val) \
           d2ftspgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2ftspg_rev_ret(ctx,obj,val) \
           d2ftspgb_GetBoolProp(ctx,obj,D2FP_REV_RET,val)
#define d2ftspg_succ_abort(ctx,obj,val) \
           d2ftspgb_GetBoolProp(ctx,obj,D2FP_SUCC_ABORT,val)
#define d2ftspg_succ_label(ctx,obj,val) \
           d2ftspgt_GetTextProp(ctx,obj,D2FP_SUCC_LABEL,val)
#define d2ftspg_trig_step_txt(ctx,obj,val) \
           d2ftspgt_GetTextProp(ctx,obj,D2FP_TRIG_STEP_TXT,val)

#define d2ftsps_abort_fail(ctx,obj,val) \
           d2ftspsb_SetBoolProp(ctx,obj,D2FP_ABORT_FAIL,val)
#define d2ftsps_client_info(ctx,obj,val) \
           d2ftspsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2ftsps_comment(ctx,obj,val) \
           d2ftspst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2ftsps_fail_label(ctx,obj,val) \
           d2ftspst_SetTextProp(ctx,obj,D2FP_FAIL_LABEL,val)
#define d2ftsps_fail_msg(ctx,obj,val) \
           d2ftspst_SetTextProp(ctx,obj,D2FP_FAIL_MSG,val)
#define d2ftsps_label(ctx,obj,val) \
           d2ftspst_SetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2ftsps_new_cursor(ctx,obj,val) \
           d2ftspsb_SetBoolProp(ctx,obj,D2FP_NEW_CURSOR,val)
#define d2ftsps_persist_client_info(ctx,obj,val) \
           d2ftspsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2ftsps_persist_clt_inf_len(ctx,obj,val) \
           d2ftspsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2ftsps_rev_ret(ctx,obj,val) \
           d2ftspsb_SetBoolProp(ctx,obj,D2FP_REV_RET,val)
#define d2ftsps_succ_abort(ctx,obj,val) \
           d2ftspsb_SetBoolProp(ctx,obj,D2FP_SUCC_ABORT,val)
#define d2ftsps_succ_label(ctx,obj,val) \
           d2ftspst_SetTextProp(ctx,obj,D2FP_SUCC_LABEL,val)
#define d2ftsps_trig_step_txt(ctx,obj,val) \
           d2ftspst_SetTextProp(ctx,obj,D2FP_TRIG_STEP_TXT,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FTSP */

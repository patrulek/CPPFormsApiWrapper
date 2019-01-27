/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FRPT.H -- Dev2K Forms API RePorT declarations

   DESCRIPTION
    Contains the public declarations for the Forms API RePorT object

   PUBLIC FUNCTIONS
    d2frptcr_Create          - Cover for d2fobcr_Create
    d2frptde_Destroy         - Cover for d2fobde_Destroy
    d2frptdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2frptsc_Subclass        - Cover for d2fobsc_Subclass
    d2frptg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2frpts?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2frpthp_HasProp         - Cover for d2fobhp_HasProp
    d2frptip_InheritProp     - Cover for d2fobip_InheritProp
    d2frptii_IspropInherited - Cover for d2fobii_IspropInherited
    d2frptid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2frptis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FRPT
#define D2FRPT

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
** Object: Report Object
**  
*/
ORA_RETTYPE(d2fstatus) d2frptcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2frpt **ppd2frpt, text *name  );
ORA_RETTYPE(d2fstatus) d2frptde_Destroy( d2fctx *pd2fctx, d2frpt *pd2frpt );
ORA_RETTYPE(d2fstatus) d2frptdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2frpt *pd2frpt_src,
                                           d2frpt **ppd2frpt_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2frptsc_SubClass( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2frptgb_GetBoolProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2frptgn_GetNumProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2frptgt_GetTextProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2frptgo_GetObjProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2frptgp_GetBlobProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                             ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2frptsb_SetBoolProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2frptsn_SetNumProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2frptst_SetTextProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2frptso_SetObjProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2frptsp_SetBlobProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                             ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2frpthp_HasProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frptip_InheritProp( d2fctx *pd2fctx, d2frpt *pd2frpt,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frptii_IspropInherited( d2fctx *pd2fctx,
                                                 d2frpt *pd2frpt, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frptid_IspropDefault( d2fctx *pd2fctx,
                                               d2frpt *pd2frpt, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2frptis_IsSubclassed( d2fctx *pd2fctx,
                                              d2frpt *pd2frpt);


/* Begin convenience macros  */
#define d2frptg_client_info(ctx,obj,val) \
           d2frptgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2frptg_comm_mode(ctx,obj,val) \
           d2frptgn_GetNumProp(ctx,obj,D2FP_COMM_MODE,val)
#define d2frptg_comment(ctx,obj,val) \
           d2frptgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2frptg_dat_src_blk(ctx,obj,val) \
           d2frptgt_GetTextProp(ctx,obj,D2FP_DAT_SRC_BLK,val)
#define d2frptg_exec_mode(ctx,obj,val) \
           d2frptgn_GetNumProp(ctx,obj,D2FP_EXEC_MODE,val)
#define d2frptg_flnam(ctx,obj,val) \
           d2frptgt_GetTextProp(ctx,obj,D2FP_FLNAM,val)
#define d2frptg_module(ctx,obj,val) \
           d2frptgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2frptg_name(ctx,obj,val) \
           d2frptgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2frptg_next(ctx,obj,val) \
           d2frptgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2frptg_owner(ctx,obj,val) \
           d2frptgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2frptg_persist_client_info(ctx,obj,val) \
           d2frptgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2frptg_persist_clt_inf_len(ctx,obj,val) \
           d2frptgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2frptg_previous(ctx,obj,val) \
           d2frptgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2frptg_rpt_destination_fmt(ctx,obj,val) \
           d2frptgt_GetTextProp(ctx,obj,D2FP_RPT_DESTINATION_FMT,val)
#define d2frptg_rpt_destination_nam(ctx,obj,val) \
           d2frptgt_GetTextProp(ctx,obj,D2FP_RPT_DESTINATION_NAM,val)
#define d2frptg_rpt_destination_typ(ctx,obj,val) \
           d2frptgn_GetNumProp(ctx,obj,D2FP_RPT_DESTINATION_TYP,val)
#define d2frptg_rpt_params(ctx,obj,val) \
           d2frptgt_GetTextProp(ctx,obj,D2FP_RPT_PARAMS,val)
#define d2frptg_rpt_srvr(ctx,obj,val) \
           d2frptgt_GetTextProp(ctx,obj,D2FP_RPT_SRVR,val)
#define d2frptg_source(ctx,obj,val) \
           d2frptgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)

#define d2frpts_client_info(ctx,obj,val) \
           d2frptsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2frpts_comm_mode(ctx,obj,val) \
           d2frptsn_SetNumProp(ctx,obj,D2FP_COMM_MODE,val)
#define d2frpts_comment(ctx,obj,val) \
           d2frptst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2frpts_dat_src_blk(ctx,obj,val) \
           d2frptst_SetTextProp(ctx,obj,D2FP_DAT_SRC_BLK,val)
#define d2frpts_exec_mode(ctx,obj,val) \
           d2frptsn_SetNumProp(ctx,obj,D2FP_EXEC_MODE,val)
#define d2frpts_flnam(ctx,obj,val) \
           d2frptst_SetTextProp(ctx,obj,D2FP_FLNAM,val)
#define d2frpts_name(ctx,obj,val) \
           d2frptst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2frpts_persist_client_info(ctx,obj,val) \
           d2frptsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2frpts_persist_clt_inf_len(ctx,obj,val) \
           d2frptsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2frpts_rpt_destination_fmt(ctx,obj,val) \
           d2frptst_SetTextProp(ctx,obj,D2FP_RPT_DESTINATION_FMT,val)
#define d2frpts_rpt_destination_nam(ctx,obj,val) \
           d2frptst_SetTextProp(ctx,obj,D2FP_RPT_DESTINATION_NAM,val)
#define d2frpts_rpt_destination_typ(ctx,obj,val) \
           d2frptsn_SetNumProp(ctx,obj,D2FP_RPT_DESTINATION_TYP,val)
#define d2frpts_rpt_params(ctx,obj,val) \
           d2frptst_SetTextProp(ctx,obj,D2FP_RPT_PARAMS,val)
#define d2frpts_rpt_srvr(ctx,obj,val) \
           d2frptst_SetTextProp(ctx,obj,D2FP_RPT_SRVR,val)
/* End convenience macros  */


/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FRPT */


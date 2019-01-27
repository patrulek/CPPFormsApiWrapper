/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FTBP.H -- Dev2K Forms API TaB Page declarations

   DESCRIPTION
    Contains the public declarations for the Forms API tab page object

   PUBLIC FUNCTIONS
    d2ftbpcr_Create          - Cover for d2fobcr_Create
    d2ftbpde_Destroy         - Cover for d2fobde_Destroy
    d2ftbpdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2ftbpsc_Subclass        - Cover for d2fobsc_Subclass
    d2ftbpco_CompileObj      -
    d2ftbpg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2ftbps?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2ftbphp_HasProp         - Cover for d2fobhp_HasProp
    d2ftbpip_InheritProp     - Cover for d2fobip_InheritProp
    d2ftbpii_IspropInherited - Cover for d2fobii_IspropInherited
    d2ftbpid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2ftbpis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FTBP
#define D2FTBP

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
** Object: Tab Page  Object
**  
*/
ORA_RETTYPE(d2fstatus) d2ftbpcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2ftbp **ppd2ftbp, text *name  );
ORA_RETTYPE(d2fstatus) d2ftbpde_Destroy( d2fctx *pd2fctx, d2ftbp *pd2ftbp );
ORA_RETTYPE(d2fstatus) d2ftbpdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2ftbp *pd2ftbp_src,
                                           d2ftbp **ppd2ftbp_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2ftbpsc_SubClass( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2ftbpgb_GetBoolProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2ftbpgn_GetNumProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2ftbpgt_GetTextProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2ftbpgo_GetObjProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ftbpgp_GetBlobProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
					    ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ftbpsb_SetBoolProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2ftbpsn_SetNumProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2ftbpst_SetTextProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2ftbpso_SetObjProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ftbpsp_SetBlobProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                             ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ftbphp_HasProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ftbpip_InheritProp( d2fctx *pd2fctx, d2ftbp *pd2ftbp,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ftbpii_IspropInherited( d2fctx *pd2fctx,
                                                 d2ftbp *pd2ftbp, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ftbpid_IspropDefault( d2fctx *pd2fctx,
                                               d2ftbp *pd2ftbp, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2ftbpis_IsSubclassed( d2fctx *pd2fctx,
                                              d2ftbp *pd2ftbp);


/* Begin convenience macros  */
#define d2ftbpg_client_info(ctx,obj,val) \
           d2ftbpgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2ftbpg_comment(ctx,obj,val) \
           d2ftbpgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2ftbpg_enabled(ctx,obj,val) \
           d2ftbpgb_GetBoolProp(ctx,obj,D2FP_ENABLED,val)
#define d2ftbpg_graphic(ctx,obj,val) \
           d2ftbpgo_GetObjProp(ctx,obj,D2FP_GRAPHIC,val)
#define d2ftbpg_label(ctx,obj,val) \
           d2ftbpgt_GetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2ftbpg_module(ctx,obj,val) \
           d2ftbpgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2ftbpg_name(ctx,obj,val) \
           d2ftbpgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2ftbpg_next(ctx,obj,val) \
           d2ftbpgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2ftbpg_owner(ctx,obj,val) \
           d2ftbpgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2ftbpg_persist_client_info(ctx,obj,val) \
           d2ftbpgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2ftbpg_persist_clt_inf_len(ctx,obj,val) \
           d2ftbpgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2ftbpg_previous(ctx,obj,val) \
           d2ftbpgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2ftbpg_source(ctx,obj,val) \
           d2ftbpgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2ftbpg_visible(ctx,obj,val) \
           d2ftbpgb_GetBoolProp(ctx,obj,D2FP_VISIBLE,val)

#define d2ftbps_client_info(ctx,obj,val) \
           d2ftbpsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2ftbps_comment(ctx,obj,val) \
           d2ftbpst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2ftbps_enabled(ctx,obj,val) \
           d2ftbpsb_SetBoolProp(ctx,obj,D2FP_ENABLED,val)
#define d2ftbps_label(ctx,obj,val) \
           d2ftbpst_SetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2ftbps_name(ctx,obj,val) \
           d2ftbpst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2ftbps_persist_client_info(ctx,obj,val) \
           d2ftbpsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2ftbps_persist_clt_inf_len(ctx,obj,val) \
           d2ftbpsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2ftbps_visible(ctx,obj,val) \
           d2ftbpsb_SetBoolProp(ctx,obj,D2FP_VISIBLE,val)
/* End convenience macros  */


/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FTBP */


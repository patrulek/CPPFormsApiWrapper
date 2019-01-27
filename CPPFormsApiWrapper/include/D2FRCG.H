/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FRCG.H -- Dev2K Forms API ReCord Group declarations

   DESCRIPTION
    Contains the public declarations for the Forms API record group object

   PUBLIC FUNCTIONS
    d2frcgcr_Create          - Cover for d2fobcr_Create
    d2frcgde_Destroy         - Cover for d2fobde_Destroy
    d2frcgdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2frcgsc_Subclass        - Cover for d2fobsc_Subclass
    d2frcgg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2frcgs?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2frcghp_HasProp         - Cover for d2fobhp_HasProp
    d2frcgip_InheritProp     - Cover for d2fobip_InheritProp
    d2frcgii_IspropInherited - Cover for d2fobii_IspropInherited
    d2frcgid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2frcgis_IsSubclassed    - Cover for d2fobis_IsSubclassed
    d2frcgs_qry_noparse      - Set Record Group Query without parsing the SQL
*/

#ifndef D2FRCG
#define D2FRCG

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
** Object: Record Group Object
**
** d2frcgs_qry_noparse - Set Record Group Query without parsing the SQL
**                       to create the Record Group Column Specifications
**
*/
ORA_RETTYPE(d2fstatus) d2frcgcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2frcg **ppd2frcg, text *name  );
ORA_RETTYPE(d2fstatus) d2frcgde_Destroy( d2fctx *pd2fctx, d2frcg *pd2frcg );
ORA_RETTYPE(d2fstatus) d2frcgdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2frcg *pd2frcg_src,
                                           d2frcg **ppd2frcg_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2frcgsc_SubClass( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2frcggb_GetBoolProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2frcggn_GetNumProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2frcggt_GetTextProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2frcggo_GetObjProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2frcggp_GetBlobProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2frcgsb_SetBoolProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2frcgsn_SetNumProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2frcgst_SetTextProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2frcgso_SetObjProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2frcgsp_SetBlobProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2frcghp_HasProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frcgip_InheritProp( d2fctx *pd2fctx, d2frcg *pd2frcg,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frcgii_IspropInherited( d2fctx *pd2fctx,
                                                 d2frcg *pd2frcg, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frcgid_IspropDefault( d2fctx *pd2fctx,
                                               d2frcg *pd2frcg, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2frcgis_IsSubclassed( d2fctx *pd2fctx,
                                              d2frcg *pd2frcg);
ORA_RETTYPE(d2fstatus) d2frcgs_qry_noparse( d2fctx *pd2fctx,
                                            d2frcg *pd2frcg,
                                            text *query);


/* Begin convenience macros  */
#define d2frcgg_client_info(ctx,obj,val) \
           d2frcggp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2frcgg_col_spec(ctx,obj,val) \
           d2frcggo_GetObjProp(ctx,obj,D2FP_COL_SPEC,val)
#define d2frcgg_comment(ctx,obj,val) \
           d2frcggt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2frcgg_module(ctx,obj,val) \
           d2frcggo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2frcgg_name(ctx,obj,val) \
           d2frcggt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2frcgg_next(ctx,obj,val) \
           d2frcggo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2frcgg_owner(ctx,obj,val) \
           d2frcggo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2frcgg_par_flnam(ctx,obj,val) \
           d2frcggt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2frcgg_par_flpath(ctx,obj,val) \
           d2frcggt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2frcgg_par_modstr(ctx,obj,val) \
           d2frcggn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2frcgg_par_modtyp(ctx,obj,val) \
           d2frcggn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2frcgg_par_module(ctx,obj,val) \
           d2frcggt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2frcgg_par_nam(ctx,obj,val) \
           d2frcggt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2frcgg_par_typ(ctx,obj,val) \
           d2frcggn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2frcgg_persist_client_info(ctx,obj,val) \
           d2frcggp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2frcgg_persist_clt_inf_len(ctx,obj,val) \
           d2frcggn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2frcgg_previous(ctx,obj,val) \
           d2frcggo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2frcgg_rec_grp_fetch_siz(ctx,obj,val) \
           d2frcggn_GetNumProp(ctx,obj,D2FP_REC_GRP_FETCH_SIZ,val)
#define d2frcgg_rec_grp_qry(ctx,obj,val) \
           d2frcggt_GetTextProp(ctx,obj,D2FP_REC_GRP_QRY,val)
#define d2frcgg_rec_grp_typ(ctx,obj,val) \
           d2frcggn_GetNumProp(ctx,obj,D2FP_REC_GRP_TYP,val)
#define d2frcgg_source(ctx,obj,val) \
           d2frcggo_GetObjProp(ctx,obj,D2FP_SOURCE,val)

#define d2frcgs_client_info(ctx,obj,val) \
           d2frcgsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2frcgs_comment(ctx,obj,val) \
           d2frcgst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2frcgs_name(ctx,obj,val) \
           d2frcgst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2frcgs_par_flnam(ctx,obj,val) \
           d2frcgst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2frcgs_par_flpath(ctx,obj,val) \
           d2frcgst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2frcgs_par_modstr(ctx,obj,val) \
           d2frcgsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2frcgs_par_modtyp(ctx,obj,val) \
           d2frcgsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2frcgs_par_module(ctx,obj,val) \
           d2frcgst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2frcgs_par_nam(ctx,obj,val) \
           d2frcgst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2frcgs_par_typ(ctx,obj,val) \
           d2frcgsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2frcgs_persist_client_info(ctx,obj,val) \
           d2frcgsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2frcgs_persist_clt_inf_len(ctx,obj,val) \
           d2frcgsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2frcgs_rec_grp_fetch_siz(ctx,obj,val) \
           d2frcgsn_SetNumProp(ctx,obj,D2FP_REC_GRP_FETCH_SIZ,val)
#define d2frcgs_rec_grp_qry(ctx,obj,val) \
           d2frcgst_SetTextProp(ctx,obj,D2FP_REC_GRP_QRY,val)
#define d2frcgs_rec_grp_typ(ctx,obj,val) \
           d2frcgsn_SetNumProp(ctx,obj,D2FP_REC_GRP_TYP,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
               
#endif /* D2FRCG */

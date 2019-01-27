/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FOBG.H -- Dev2K Forms API Object GRoup declarations

   DESCRIPTION
    Contains the public declarations for the Forms API object group

   PUBLIC FUNCTIONS
    d2fobgcr_Create          - Cover for d2fobcr_Create
    d2fobgde_Destroy         - Cover for d2fobde_Destroy
    d2fobgdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fobgsc_Subclass        - Cover for d2fobsc_Subclass
    d2fobgg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fobgs?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fobghp_HasProp         - Cover for d2fobhp_HasProp
    d2fobgip_InheritProp     - Cover for d2fobip_InheritProp
    d2fobgii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fobgid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fobgis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FOBG
#define D2FOBG

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
** Object: Object Group
**  
*/
ORA_RETTYPE(d2fstatus) d2fobgcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fobg **ppd2fobg, text *name );
ORA_RETTYPE(d2fstatus) d2fobgde_Destroy( d2fctx *pd2fctx, d2fobg *pd2fobg );
ORA_RETTYPE(d2fstatus) d2fobgdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fobg *pd2fobg_src,
                                           d2fobg **ppd2fobg_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2fobgsc_SubClass( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fobggb_GetBoolProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fobggn_GetNumProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fobggt_GetTextProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fobggo_GetObjProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fobggp_GetBlobProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                             ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fobgsb_SetBoolProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fobgsn_SetNumProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fobgst_SetTextProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fobgso_SetObjProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fobgsp_SetBlobProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                             ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fobghp_HasProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fobgip_InheritProp( d2fctx *pd2fctx, d2fobg *pd2fobg,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fobgii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fobg *pd2fobg, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fobgid_IspropDefault( d2fctx *pd2fctx,
                                               d2fobg *pd2fobg, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fobgis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fobg *pd2fobg);


/* Begin convenience macros  */
#define d2fobgg_client_info(ctx,obj,val) \
           d2fobggp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fobgg_comment(ctx,obj,val) \
           d2fobggt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fobgg_module(ctx,obj,val) \
           d2fobggo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fobgg_name(ctx,obj,val) \
           d2fobggt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fobgg_next(ctx,obj,val) \
           d2fobggo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fobgg_og_child(ctx,obj,val) \
           d2fobggo_GetObjProp(ctx,obj,D2FP_OG_CHILD,val)
#define d2fobgg_owner(ctx,obj,val) \
           d2fobggo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fobgg_par_flnam(ctx,obj,val) \
           d2fobggt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fobgg_par_flpath(ctx,obj,val) \
           d2fobggt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fobgg_par_modstr(ctx,obj,val) \
           d2fobggn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fobgg_par_modtyp(ctx,obj,val) \
           d2fobggn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fobgg_par_module(ctx,obj,val) \
           d2fobggt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fobgg_par_nam(ctx,obj,val) \
           d2fobggt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fobgg_par_typ(ctx,obj,val) \
           d2fobggn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fobgg_persist_client_info(ctx,obj,val) \
           d2fobggp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fobgg_persist_clt_inf_len(ctx,obj,val) \
           d2fobggn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fobgg_previous(ctx,obj,val) \
           d2fobggo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fobgg_source(ctx,obj,val) \
           d2fobggo_GetObjProp(ctx,obj,D2FP_SOURCE,val)

#define d2fobgs_client_info(ctx,obj,val) \
           d2fobgsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fobgs_comment(ctx,obj,val) \
           d2fobgst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fobgs_name(ctx,obj,val) \
           d2fobgst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fobgs_par_flnam(ctx,obj,val) \
           d2fobgst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fobgs_par_flpath(ctx,obj,val) \
           d2fobgst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fobgs_par_modstr(ctx,obj,val) \
           d2fobgsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fobgs_par_modtyp(ctx,obj,val) \
           d2fobgsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fobgs_par_module(ctx,obj,val) \
           d2fobgst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fobgs_par_nam(ctx,obj,val) \
           d2fobgst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fobgs_par_typ(ctx,obj,val) \
           d2fobgsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fobgs_persist_client_info(ctx,obj,val) \
           d2fobgsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fobgs_persist_clt_inf_len(ctx,obj,val) \
           d2fobgsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FOBG */

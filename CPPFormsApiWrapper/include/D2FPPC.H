/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FPPC.H -- Dev2K Forms API ProPerty Class declarations

   DESCRIPTION
    Contains the public declarations for the Forms API property class object

   PUBLIC FUNCTIONS
    d2fppccr_Create          - Cover for d2fobcr_Create
    d2fppcde_Destroy         - Cover for d2fobde_Destroy
    d2fppcdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fppcsc_Subclass        - Cover for d2fobsc_Subclass
    d2fppcrp_RemoveProp      - Remove the property from the Property class
    d2fppcg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fppcs?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fppchp_HasProp         - Cover for d2fobhp_HasProp
    d2fppcip_InheritProp     - Cover for d2fobip_InheritProp
    d2fppcii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fppcid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fppcis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FPPC
#define D2FPPC

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
** Object: Property Class
**  
*/
ORA_RETTYPE(d2fstatus) d2fppccr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fppc **ppd2fppc, text *name  );
ORA_RETTYPE(d2fstatus) d2fppcde_Destroy( d2fctx *pd2fctx, d2fppc *pd2fppc );
ORA_RETTYPE(d2fstatus) d2fppcdu_Duplicate( d2fctx *pd2fctx, d2fob *new_object,
                                           d2fppc *pd2fppc_src,
                                           d2fppc **ppd2fppc_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2fppcsc_SubClass( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fppcrp_RemoveProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                            ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fppcgb_GetBoolProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fppcgn_GetNumProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fppcgt_GetTextProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fppcgo_GetObjProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fppcgp_GetBlobProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                             ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fppcsb_SetBoolProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fppcsn_SetNumProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fppcst_SetTextProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fppcso_SetObjProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fppcsp_SetBlobProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                             ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fppchp_HasProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fppcip_InheritProp( d2fctx *pd2fctx, d2fppc *pd2fppc,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fppcii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fppc *pd2fppc, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fppcid_IspropDefault( d2fctx *pd2fctx,
                                               d2fppc *pd2fppc, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fppcis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fppc *pd2fppc);



/* Begin convenience macros  */
#define d2fppcg_client_info(ctx,obj,val) \
           d2fppcgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fppcg_comment(ctx,obj,val) \
           d2fppcgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fppcg_module(ctx,obj,val) \
           d2fppcgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fppcg_name(ctx,obj,val) \
           d2fppcgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fppcg_next(ctx,obj,val) \
           d2fppcgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fppcg_owner(ctx,obj,val) \
           d2fppcgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fppcg_par_flnam(ctx,obj,val) \
           d2fppcgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fppcg_par_flpath(ctx,obj,val) \
           d2fppcgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fppcg_par_modstr(ctx,obj,val) \
           d2fppcgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fppcg_par_modtyp(ctx,obj,val) \
           d2fppcgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fppcg_par_module(ctx,obj,val) \
           d2fppcgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fppcg_par_nam(ctx,obj,val) \
           d2fppcgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fppcg_par_typ(ctx,obj,val) \
           d2fppcgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fppcg_persist_client_info(ctx,obj,val) \
           d2fppcgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fppcg_persist_clt_inf_len(ctx,obj,val) \
           d2fppcgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fppcg_previous(ctx,obj,val) \
           d2fppcgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fppcg_source(ctx,obj,val) \
           d2fppcgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2fppcg_trigger(ctx,obj,val) \
           d2fppcgo_GetObjProp(ctx,obj,D2FP_TRIGGER,val)

#define d2fppcs_client_info(ctx,obj,val) \
           d2fppcsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fppcs_comment(ctx,obj,val) \
           d2fppcst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fppcs_name(ctx,obj,val) \
           d2fppcst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fppcs_par_flnam(ctx,obj,val) \
           d2fppcst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fppcs_par_flpath(ctx,obj,val) \
           d2fppcst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fppcs_par_modstr(ctx,obj,val) \
           d2fppcsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fppcs_par_modtyp(ctx,obj,val) \
           d2fppcsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fppcs_par_module(ctx,obj,val) \
           d2fppcst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fppcs_par_nam(ctx,obj,val) \
           d2fppcst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fppcs_par_typ(ctx,obj,val) \
           d2fppcsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fppcs_persist_client_info(ctx,obj,val) \
           d2fppcsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fppcs_persist_clt_inf_len(ctx,obj,val) \
           d2fppcsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FPPC */

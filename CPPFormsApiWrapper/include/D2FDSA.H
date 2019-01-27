/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FDSA.H -- Dev2K Forms API Data Source Argument declarations

   DESCRIPTION
    Contains the public declarations for the Forms API Data Src Arg 

   PUBLIC FUNCTIONS
    d2fdsacr_Create          - Cover for d2fobcr_Create
    d2fdsade_Destroy         - Cover for d2fobde_Destroy
    d2fdsadu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fdsag?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fdsas?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fdsahp_HasProp         - Cover for d2fobhp_HasProp
    d2fdsaip_InheritProp     - Cover for d2fobip_InheritProp
    d2fdsaii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fdsaid_IspropDefault   - Cover for d2fobid_IspropDefault
*/

#ifndef D2FDSA
#define D2FDSA

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
** Object: Data Source Argument  Object
**  
*/
ORA_RETTYPE(d2fstatus) d2fdsacr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fdsa **ppd2fdsa, ub2 owning_prop );
ORA_RETTYPE(d2fstatus) d2fdsade_Destroy( d2fctx *pd2fctx, d2fdsa *pd2fdsa );
ORA_RETTYPE(d2fstatus) d2fdsadu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fdsa *pd2fdsa_src,
                                           d2fdsa **ppd2fdsa_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2fdsagb_GetBoolProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fdsagn_GetNumProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fdsagt_GetTextProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fdsago_GetObjProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fdsagp_GetBlobProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fdsasb_SetBoolProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fdsasn_SetNumProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fdsast_SetTextProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fdsaso_SetObjProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fdsasp_SetBlobProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fdsahp_HasProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fdsaip_InheritProp( d2fctx *pd2fctx, d2fdsa *pd2fdsa,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fdsaii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fdsa *pd2fdsa, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fdsaid_IspropDefault( d2fctx *pd2fctx,
                                               d2fdsa *pd2fdsa, ub2 pnum);


/* Begin convenience macros  */
#define d2fdsag_client_info(ctx,obj,val) \
           d2fdsagp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fdsag_dsa_mode(ctx,obj,val) \
           d2fdsagn_GetNumProp(ctx,obj,D2FP_DSA_MODE,val)
#define d2fdsag_dsa_nam(ctx,obj,val) \
           d2fdsagt_GetTextProp(ctx,obj,D2FP_DSA_NAM,val)
#define d2fdsag_dsa_typ(ctx,obj,val) \
           d2fdsagn_GetNumProp(ctx,obj,D2FP_DSA_TYP,val)
#define d2fdsag_dsa_typ_nam(ctx,obj,val) \
           d2fdsagt_GetTextProp(ctx,obj,D2FP_DSA_TYP_NAM,val)
#define d2fdsag_dsa_val(ctx,obj,val) \
           d2fdsagt_GetTextProp(ctx,obj,D2FP_DSA_VAL,val)
#define d2fdsag_next(ctx,obj,val) \
           d2fdsago_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fdsag_persist_client_info(ctx,obj,val) \
           d2fdsagp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fdsag_persist_clt_inf_len(ctx,obj,val) \
           d2fdsagn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fdsag_previous(ctx,obj,val) \
           d2fdsago_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)

#define d2fdsas_client_info(ctx,obj,val) \
           d2fdsasp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fdsas_dsa_mode(ctx,obj,val) \
           d2fdsasn_SetNumProp(ctx,obj,D2FP_DSA_MODE,val)
#define d2fdsas_dsa_nam(ctx,obj,val) \
           d2fdsast_SetTextProp(ctx,obj,D2FP_DSA_NAM,val)
#define d2fdsas_dsa_typ(ctx,obj,val) \
           d2fdsasn_SetNumProp(ctx,obj,D2FP_DSA_TYP,val)
#define d2fdsas_dsa_typ_nam(ctx,obj,val) \
           d2fdsast_SetTextProp(ctx,obj,D2FP_DSA_TYP_NAM,val)
#define d2fdsas_dsa_val(ctx,obj,val) \
           d2fdsast_SetTextProp(ctx,obj,D2FP_DSA_VAL,val)
#define d2fdsas_persist_client_info(ctx,obj,val) \
           d2fdsasp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fdsas_persist_clt_inf_len(ctx,obj,val) \
           d2fdsasn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
/* End convenience macros  */


/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FDSA */


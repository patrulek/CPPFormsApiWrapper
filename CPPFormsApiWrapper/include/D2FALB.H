/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FALB.H -- Dev2K Forms API Attached LiBrary declarations

   DESCRIPTION
    Contains the public declarations for the Forms API BLocK object

   PUBLIC FUNCTIONS
    d2falbat_Attach          - Attach the specified PL/SQL library file
    d2falbdt_Detach          - Detach the specified library object.
    d2falbg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2falbs?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2falbhp_HasProp         - Cover for d2fobhp_HasProp
    d2falbip_InheritProp     - Cover for d2fobip_InheritProp
    d2falbii_IspropInherited - Cover for d2fobii_IspropInherited
    d2falbid_IspropDefault   - Cover for d2fobid_IspropDefault

*/

#ifndef D2FALB
#define D2FALB

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
** Object: Attached Library
**  
** Functions:
**  d2falbat_Attach - This function attaches a PL/SQL library to either a
**                    form module object or a menu module object.  The name
**                    of the attached library is the library's filename;
**                    the library can live in either the database or the 
**                    filesystem.  The 'parent' parameter is the form or
**                    menu module.
**
**  d2falbdt_Detach - This function detaches an existing PL/SQL attached
**                    library object.  The object is then destroyed.
**                    
*/
ORA_RETTYPE(d2fstatus) d2falbat_Attach( d2fctx *pd2fctx, d2fob *parent,
                                        d2falb **ppd2falb, boolean db,
                                        text *name  );
ORA_RETTYPE(d2fstatus) d2falbdt_Detach( d2fctx *pd2fctx, d2falb *pd2falb  );

ORA_RETTYPE(d2fstatus) d2falbgb_GetBoolProp( d2fctx *pd2fctx, d2falb *pd2falb,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2falbgn_GetNumProp( d2fctx *pd2fctx, d2falb *pd2falb,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2falbgt_GetTextProp( d2fctx *pd2fctx, d2falb *pd2falb,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2falbgo_GetObjProp( d2fctx *pd2fctx, d2falb *pd2falb,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2falbgp_GetBlobProp( d2fctx *pd2fctx, d2falb *pd2falb,
					    ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2falbsb_SetBoolProp( d2fctx *pd2fctx, d2falb *pd2falb,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2falbsn_SetNumProp( d2fctx *pd2fctx, d2falb *pd2falb,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2falbst_SetTextProp( d2fctx *pd2fctx, d2falb *pd2falb,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2falbso_SetObjProp( d2fctx *pd2fctx, d2falb *pd2falb,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2falbsp_SetBlobProp( d2fctx *pd2fctx, d2falb *pd2falb,
                                             ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2falbhp_HasProp( d2fctx *pd2fctx, d2falb *pd2falb,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2falbip_InheritProp( d2fctx *pd2fctx,
                                             d2fppc *pd2falb,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2falbii_IspropInherited( d2fctx *pd2fctx,
                                                 d2falb *pd2falb,
                                                 ub2 pnum );
ORA_RETTYPE(d2fstatus) d2falbid_IspropDefault( d2fctx *pd2fctx,
                                               d2falb *pd2falb,
                                               ub2 pnum);


/* Begin convenience macros  */
#define d2falbg_client_info(ctx,obj,val) \
           d2falbgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2falbg_comment(ctx,obj,val) \
           d2falbgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2falbg_lib_loc(ctx,obj,val) \
           d2falbgt_GetTextProp(ctx,obj,D2FP_LIB_LOC,val)
#define d2falbg_lib_src(ctx,obj,val) \
           d2falbgn_GetNumProp(ctx,obj,D2FP_LIB_SRC,val)
#define d2falbg_name(ctx,obj,val) \
           d2falbgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2falbg_next(ctx,obj,val) \
           d2falbgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2falbg_persist_client_info(ctx,obj,val) \
           d2falbgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2falbg_persist_clt_inf_len(ctx,obj,val) \
           d2falbgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2falbg_previous(ctx,obj,val) \
           d2falbgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)

#define d2falbs_client_info(ctx,obj,val) \
           d2falbsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2falbs_comment(ctx,obj,val) \
           d2falbst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2falbs_persist_client_info(ctx,obj,val) \
           d2falbsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2falbs_persist_clt_inf_len(ctx,obj,val) \
           d2falbsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FALB */





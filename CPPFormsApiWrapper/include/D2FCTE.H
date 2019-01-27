/*
 * $Header: d2fcte.h@@/main/TOOLS_DEV2K_994/1 \
 * Checked in on Mon Jul  2 10:05:27 PDT 2001 by vobadm \
 * Copyright (c) 2001 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 2001.  All Rights Reserved. */

/*
   NAME
    D2FCTE.H -- Dev2K Forms API Compound TExt

   DESCRIPTION
    Contains the public declarations for the Forms API Compound Text Object

   PUBLIC FUNCTIONS
    d2fctecr_Create          - Cover for d2fobcr_Create
    d2fctede_Destroy         - Cover for d2fobde_Destroy
    d2fctedu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fcteg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fctes?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fctehp_HasProp         - Cover for d2fobhp_HasProp
    d2fcteip_InheritProp     - Cover for d2fobip_InheritProp
    d2fcteid_IspropDefault   - Cover for d2fobid_IspropDefault
*/

#ifndef D2FCTE
#define D2FCTE

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
** Object: Compound Text
**
*/
ORA_RETTYPE(d2fstatus) d2fctecr_Create( d2fctx *pd2fctx, d2fob *parent,
                                        d2fcte **ppd2fcte, text *name  );
ORA_RETTYPE(d2fstatus) d2fctede_Destroy( d2fctx *pd2fctx, d2fcte *pd2fcte );
ORA_RETTYPE(d2fstatus) d2fctedu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fcte *pd2fcte_src,
                                           d2fcte **ppd2fcte_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2fctegb_GetBoolProp( d2fctx *pd2fctx, d2fcte *pd2fcte,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fctegn_GetNumProp( d2fctx *pd2fctx, d2fcte *pd2fcte,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fctegt_GetTextProp( d2fctx *pd2fctx, d2fcte *pd2fcte,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fctego_GetObjProp( d2fctx *pd2fctx, d2fcte *pd2fcte,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fctegp_GetBlobProp( d2fctx *pd2fctx, d2fcte *pd2fcte,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fctesb_SetBoolProp( d2fctx *pd2fctx, d2fcte *pd2fcte,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fctesn_SetNumProp( d2fctx *pd2fctx, d2fcte *pd2fcte,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fctest_SetTextProp( d2fctx *pd2fctx, d2fcte *pd2fcte,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fcteso_SetObjProp(d2fctx *pd2fctx, d2fcte *pd2fcte,
                                           ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fctesp_SetBlobProp(d2fctx *pd2fctx, d2fcte *pd2fcte,
                                           ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fctehp_HasProp( d2fctx *pd2fctx, d2fcte *pd2fcte,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fcteip_InheritProp( d2fctx *pd2fctx, d2fcte *pd2fcte,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fcteid_IspropDefault( d2fctx *pd2fctx,
                                               d2fcte *pd2fcte, ub2 pnum);


/* Begin convenience macros  */
#define d2fcteg_name(ctx,obj,val) \
           d2fctegt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fcteg_next(ctx,obj,val) \
           d2fctego_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fcteg_previous(ctx,obj,val) \
           d2fctego_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fcteg_text_seg(ctx,obj,val) \
           d2fctego_GetObjProp(ctx,obj,D2FP_TEXT_SEG,val)

#define d2fctes_name(ctx,obj,val) \
           d2fctest_SetTextProp(ctx,obj,D2FP_NAME,val)

/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FCTE */

/*
 * $Header: d2fpnt.h@@/main/TOOLS_DEV2K_994/1 \
 * Checked in on Mon Jul  2 10:05:34 PDT 2001 by vobadm \
 * Copyright (c) 2001 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 2001.  All Rights Reserved. */

/*
   NAME
    D2FPNT.H -- Dev2K Forms API Graphics PoiNT declarations

   DESCRIPTION
    Contains the public declarations for the Forms API Graphics point object

   PUBLIC FUNCTIONS
    d2fpntcr_Create          - Cover for d2fobcr_Create
    d2fpntde_Destroy         - Cover for d2fobde_Destroy
    d2fpntdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fpntg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fpnts?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fpnthp_HasProp         - Cover for d2fobhp_HasProp
    d2fpntip_InheritProp     - Cover for d2fobip_InheritProp
    d2fpntid_IspropDefault   - Cover for d2fobid_IspropDefault
*/

#ifndef D2FPNT
#define D2FPNT

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
** Object: Graphics Point Object (Boiler Plate)
**
*/
ORA_RETTYPE(d2fstatus) d2fpntcr_Create( d2fctx *pd2fctx, d2fob *parent,
                                        d2fpnt **ppd2fpnt, text *name  );
ORA_RETTYPE(d2fstatus) d2fpntde_Destroy( d2fctx *pd2fctx, d2fpnt *pd2fpnt );
ORA_RETTYPE(d2fstatus) d2fpntdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fpnt *pd2fpnt_src,
                                           d2fpnt **ppd2fpnt_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2fpntgb_GetBoolProp( d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fpntgn_GetNumProp( d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fpntgt_GetTextProp( d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fpntgo_GetObjProp( d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fpntgp_GetBlobProp( d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fpntsb_SetBoolProp( d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fpntsn_SetNumProp( d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fpntst_SetTextProp( d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fpntso_SetObjProp(d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                           ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fpntsp_SetBlobProp(d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                           ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fpnthp_HasProp( d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fpntip_InheritProp( d2fctx *pd2fctx, d2fpnt *pd2fpnt,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fpntid_IspropDefault( d2fctx *pd2fctx,
                                               d2fpnt *pd2fpnt, ub2 pnum);


/* Begin convenience macros  */
#define d2fpntg_name(ctx,obj,val) \
           d2fpntgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fpntg_next(ctx,obj,val) \
           d2fpntgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fpntg_previous(ctx,obj,val) \
           d2fpntgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fpntg_x_pos(ctx,obj,val) \
           d2fpntgn_GetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fpntg_y_pos(ctx,obj,val) \
           d2fpntgn_GetNumProp(ctx,obj,D2FP_Y_POS,val)

#define d2fpnts_name(ctx,obj,val) \
           d2fpntst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fpnts_x_pos(ctx,obj,val) \
           d2fpntsn_SetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fpnts_y_pos(ctx,obj,val) \
           d2fpntsn_SetNumProp(ctx,obj,D2FP_Y_POS,val)


/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FPNT */

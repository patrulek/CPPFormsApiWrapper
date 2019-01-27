/*
 * $Header: d2ffnt.h@@/main/TOOLS_DEV2K_994/1 \
 * Checked in on Thu Aug 12 09:35:55 PDT 1999 by vobadm \
 * Copyright (c) 1999 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 1999.  All Rights Reserved. */

/*
   NAME
    D2FFNT.H -- Dev2K Forms API FoNT declarations

   DESCRIPTION
    Contains the public declarations for the Forms API FoNT support

   PUBLIC FUNCTIONS
    d2ffntcr_Create          - Cover for d2fobcr_Create
    d2ffntde_Destroy         - Cover for d2fobde_Destroy
    d2ffntdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2ffntex_Extract         - Extract font info from object into font object
    d2ffntap_Applyl          - Apply font info from font object into object
    d2ffntg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2ffnts?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2ffnthp_HasProp         - Cover for d2fobhp_HasProp
*/

#ifndef D2FFNT
#define D2FFNT

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
** Object: Coordinate Info
**  
** d2ffntex_Extract - Extract the font object from an object that
**                    has font properties associated with it.  The
**                    vat_typ argument is one of the D2FC_VATY_* 
**                    constants.  The font object must already have
**                    been created.
**
** d2ffntap_Apply   - Apply the contents of the font object to the
**                    specified object.  This is a shortcut to 
**                    setting the individual font properties one-
**                    by-one.
*/
ORA_RETTYPE(d2fstatus) d2ffntcr_Create( d2fctx *pd2fctx, d2ffnt **ppd2ffnt );
ORA_RETTYPE(d2fstatus) d2ffntde_Destroy( d2fctx *pd2fctx, d2ffnt *pd2ffnt );
ORA_RETTYPE(d2fstatus) d2ffntdu_Duplicate( d2fctx *pd2fctx,
                                           d2ffnt *pd2ffnt_src,
                                           d2ffnt **ppd2ffnt_dst );
ORA_RETTYPE(d2fstatus) d2ffntex_Extract( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                         d2fob *pd2fob, number vat_typ );
ORA_RETTYPE(d2fstatus) d2ffntap_Apply( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                       d2fob *pd2fob, number vat_typ );
ORA_RETTYPE(d2fstatus) d2ffntgb_GetBoolProp( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2ffntgn_GetNumProp( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2ffntgt_GetTextProp( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2ffntgo_GetObjProp( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ffntgp_GetBlobProp( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ffntsb_SetBoolProp( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2ffntsn_SetNumProp( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2ffntst_SetTextProp( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2ffntso_SetObjProp( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ffntsp_SetBlobProp( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ffnthp_HasProp( d2fctx *pd2fctx, d2ffnt *pd2ffnt,
                                         ub2 pnum );



/* Begin convenience macros  */
#define d2ffntg_font_nam(ctx,obj,val) \
           d2ffntgt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2ffntg_font_siz(ctx,obj,val) \
           d2ffntgn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2ffntg_font_spcing(ctx,obj,val) \
           d2ffntgn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2ffntg_font_sty(ctx,obj,val) \
           d2ffntgn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2ffntg_font_wght(ctx,obj,val) \
           d2ffntgn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)

#define d2ffnts_font_nam(ctx,obj,val) \
           d2ffntst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2ffnts_font_siz(ctx,obj,val) \
           d2ffntsn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2ffnts_font_spcing(ctx,obj,val) \
           d2ffntsn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2ffnts_font_sty(ctx,obj,val) \
           d2ffntsn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2ffnts_font_wght(ctx,obj,val) \
           d2ffntsn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FFNT */

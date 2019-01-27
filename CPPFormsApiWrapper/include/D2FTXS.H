/*
 * $Header: d2ftxs.h@@/main/TOOLS_DEV2K_994/1 \
 * Checked in on Mon Jul  2 10:05:40 PDT 2001 by vobadm \
 * Copyright (c) 2001 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 2001.  All Rights Reserved. */

/*
   NAME
    D2FTXS.H -- Dev2K Forms API TeXt Segment

   DESCRIPTION
    Contains the public declarations for the Forms API Text Segment Object

   PUBLIC FUNCTIONS
    d2ftxscr_Create          - Cover for d2fobcr_Create
    d2ftxsde_Destroy         - Cover for d2fobde_Destroy
    d2ftxsdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2ftxsg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2ftxss?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2ftxshp_HasProp         - Cover for d2fobhp_HasProp
    d2ftxsip_InheritProp     - Cover for d2fobip_InheritProp
    d2ftxsid_IspropDefault   - Cover for d2fobid_IspropDefault
*/

#ifndef D2FTXS
#define D2FTXS

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
** Object: Text Segment
**
*/
ORA_RETTYPE(d2fstatus) d2ftxscr_Create( d2fctx *pd2fctx, d2fob *parent,
                                        d2ftxs **ppd2ftxs, text *name  );
ORA_RETTYPE(d2fstatus) d2ftxsde_Destroy( d2fctx *pd2fctx, d2ftxs *pd2ftxs );
ORA_RETTYPE(d2fstatus) d2ftxsdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2ftxs *pd2ftxs_src,
                                           d2ftxs **ppd2ftxs_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2ftxsgb_GetBoolProp( d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2ftxsgn_GetNumProp( d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2ftxsgt_GetTextProp( d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2ftxsgo_GetObjProp( d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ftxsgp_GetBlobProp( d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ftxssb_SetBoolProp( d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2ftxssn_SetNumProp( d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2ftxsst_SetTextProp( d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2ftxsso_SetObjProp(d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                           ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ftxssp_SetBlobProp(d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                           ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ftxshp_HasProp( d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ftxsip_InheritProp( d2fctx *pd2fctx, d2ftxs *pd2ftxs,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ftxsid_IspropDefault( d2fctx *pd2fctx,
                                               d2ftxs *pd2ftxs, ub2 pnum);


/* Begin convenience macros  */
#define d2ftxsg_font_nam(ctx,obj,val) \
           d2ftxsgt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2ftxsg_font_siz(ctx,obj,val) \
           d2ftxsgn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2ftxsg_font_spcing(ctx,obj,val) \
           d2ftxsgn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2ftxsg_font_sty(ctx,obj,val) \
           d2ftxsgn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2ftxsg_font_wght(ctx,obj,val) \
           d2ftxsgn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2ftxsg_fore_color(ctx,obj,val) \
           d2ftxsgt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2ftxsg_name(ctx,obj,val) \
           d2ftxsgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2ftxsg_next(ctx,obj,val) \
           d2ftxsgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2ftxsg_previous(ctx,obj,val) \
           d2ftxsgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2ftxsg_text(ctx,obj,val) \
           d2ftxsgt_GetTextProp(ctx,obj,D2FP_TEXT,val)

#define d2ftxss_font_nam(ctx,obj,val) \
           d2ftxsst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2ftxss_font_siz(ctx,obj,val) \
           d2ftxssn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2ftxss_font_spcing(ctx,obj,val) \
           d2ftxssn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2ftxss_font_sty(ctx,obj,val) \
           d2ftxssn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2ftxss_font_wght(ctx,obj,val) \
           d2ftxssn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2ftxss_fore_color(ctx,obj,val) \
           d2ftxsst_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2ftxss_name(ctx,obj,val) \
           d2ftxsst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2ftxss_text(ctx,obj,val) \
           d2ftxsst_SetTextProp(ctx,obj,D2FP_TEXT,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FTXS */

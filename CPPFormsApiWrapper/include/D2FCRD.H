/*
 * $Header: d2fcrd.h@@/main/TOOLS_DEV2K_994/1 \
 * Checked in on Thu Aug 12 09:35:17 PDT 1999 by vobadm \
 * Copyright (c) 1999 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 1999.  All Rights Reserved. */

/*
   NAME
    D2FCRD.H -- Dev2K Forms API CooRDinate system declarations

   DESCRIPTION
    Contains the public declarations for the Forms API CooRDinate system

   PUBLIC FUNCTIONS
    d2fcrdcr_Create          - Cover for d2fobcr_Create
    d2fcrdde_Destroy         - Cover for d2fobde_Destroy
    d2fcrddu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fcrdex_Extract         - 
    d2fcrdap_Apply           - 
    d2fcrdg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fcrds?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fcrdhp_HasProp         - Cover for d2fobhp_HasProp

    d2fobcs_CharSize
    d2fobss_StringSize
*/

#ifndef D2FCRD
#define D2FCRD

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
*/
ORA_RETTYPE(d2fstatus) d2fcrdcr_Create( d2fctx *pd2fctx, d2fcrd **ppd2fcrd );
ORA_RETTYPE(d2fstatus) d2fcrdde_Destroy( d2fctx *pd2fctx, d2fcrd *pd2fcrd );
ORA_RETTYPE(d2fstatus) d2fcrddu_Duplicate( d2fctx *pd2fctx,
                                           d2fcrd *pd2fcrd_src,
                                           d2fcrd **ppd2fcrd_dst );
ORA_RETTYPE(d2fstatus) d2fcrdex_Extract( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                         d2ffmd *pd2ffmd );
ORA_RETTYPE(d2fstatus) d2fcrdap_Apply( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                       d2ffmd *pd2ffmd );
ORA_RETTYPE(d2fstatus) d2fcrdgb_GetBoolProp( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fcrdgn_GetNumProp( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fcrdgt_GetTextProp( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fcrdgo_GetObjProp( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fcrdgp_GetBlobProp( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fcrdsb_SetBoolProp( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fcrdsn_SetNumProp( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fcrdst_SetTextProp( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fcrdso_SetObjProp( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fcrdsp_SetBlobProp( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fcrdhp_HasProp( d2fctx *pd2fctx, d2fcrd *pd2fcrd,
                                         ub2 pnum );

/*
** These will eventually move to d2fob.h
*/
ORA_RETTYPE(d2fstatus) d2fobss_StringSize( d2fctx *pd2fctx,
                                           text *str,
                                           d2ffnt *pd2ffnt,
                                           d2fcrd *pd2fcrd,
                                           number *width,
                                           number *height );
ORA_RETTYPE(d2fstatus) d2fobcs_CharSize( d2fctx *pd2fctx,
                                         number width,
                                         number height,
                                         d2ffnt *pd2ffnt,
                                         d2fcrd *pd2fcrd,
                                         number *char_width,
                                         number *char_height );



/* Begin convenience macros  */
#define d2fcrdg_char_cell_hgt(ctx,obj,val) \
           d2fcrdgn_GetNumProp(ctx,obj,D2FP_CHAR_CELL_HGT,val)
#define d2fcrdg_char_cell_wid(ctx,obj,val) \
           d2fcrdgn_GetNumProp(ctx,obj,D2FP_CHAR_CELL_WID,val)
#define d2fcrdg_coord_sys(ctx,obj,val) \
           d2fcrdgn_GetNumProp(ctx,obj,D2FP_COORD_SYS,val)
#define d2fcrdg_dflt_fnt_scaling(ctx,obj,val) \
           d2fcrdgb_GetBoolProp(ctx,obj,D2FP_DFLT_FNT_SCALING,val)
#define d2fcrdg_real_unit(ctx,obj,val) \
           d2fcrdgn_GetNumProp(ctx,obj,D2FP_REAL_UNIT,val)

#define d2fcrds_char_cell_hgt(ctx,obj,val) \
           d2fcrdsn_SetNumProp(ctx,obj,D2FP_CHAR_CELL_HGT,val)
#define d2fcrds_char_cell_wid(ctx,obj,val) \
           d2fcrdsn_SetNumProp(ctx,obj,D2FP_CHAR_CELL_WID,val)
#define d2fcrds_coord_sys(ctx,obj,val) \
           d2fcrdsn_SetNumProp(ctx,obj,D2FP_COORD_SYS,val)
#define d2fcrds_dflt_fnt_scaling(ctx,obj,val) \
           d2fcrdsb_SetBoolProp(ctx,obj,D2FP_DFLT_FNT_SCALING,val)
#define d2fcrds_real_unit(ctx,obj,val) \
           d2fcrdsn_SetNumProp(ctx,obj,D2FP_REAL_UNIT,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FCRD */

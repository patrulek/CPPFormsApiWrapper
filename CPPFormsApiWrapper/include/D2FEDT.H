/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FEDT.H -- Dev2K Forms API EDiTor declarations

   DESCRIPTION
    Contains the public declarations for the Forms API EDiTor object

   PUBLIC FUNCTIONS
    d2fedtcr_Create          - Cover for d2fobcr_Create
    d2fedtde_Destroy         - Cover for d2fobde_Destroy
    d2fedtdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fedtsc_Subclass        - Cover for d2fobsc_Subclass
    d2fedtg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fedts?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fedthp_HasProp         - Cover for d2fobhp_HasProp
    d2fedtip_InheritProp     - Cover for d2fobip_InheritProp
    d2fedtii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fedtid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fedtis_IsSubclassed    - Cover for d2fobis_IsSubclassed

*/

#ifndef D2FEDT
#define D2FEDT

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
** Object: Editor
**  
*/
ORA_RETTYPE(d2fstatus) d2fedtcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fedt **ppd2fedt, text *name  );
ORA_RETTYPE(d2fstatus) d2fedtde_Destroy( d2fctx *pd2fctx, d2fedt *pd2fedt );
ORA_RETTYPE(d2fstatus) d2fedtdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fedt *pd2fedt_src,
                                           d2fedt **ppd2fedt_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2fedtsc_SubClass( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fedtgb_GetBoolProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fedtgn_GetNumProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fedtgt_GetTextProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fedtgo_GetObjProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fedtgp_GetBlobProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fedtsb_SetBoolProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fedtsn_SetNumProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fedtst_SetTextProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fedtso_SetObjProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fedtsp_SetBlobProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fedthp_HasProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fedtip_InheritProp( d2fctx *pd2fctx, d2fedt *pd2fedt,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fedtii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fedt *pd2fedt, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fedtid_IspropDefault( d2fctx *pd2fctx,
                                               d2fedt *pd2fedt, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fedtis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fedt *pd2fedt);


/* Begin convenience macros  */
#define d2fedtg_back_color(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fedtg_btm_ttl(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_BTM_TTL,val)
#define d2fedtg_client_info(ctx,obj,val) \
           d2fedtgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fedtg_comment(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fedtg_fill_pat(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fedtg_font_nam(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fedtg_font_siz(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fedtg_font_spcing(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fedtg_font_sty(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fedtg_font_wght(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fedtg_fore_color(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fedtg_height(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fedtg_module(ctx,obj,val) \
           d2fedtgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fedtg_name(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fedtg_next(ctx,obj,val) \
           d2fedtgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fedtg_owner(ctx,obj,val) \
           d2fedtgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fedtg_par_flnam(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fedtg_par_flpath(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fedtg_par_modstr(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fedtg_par_modtyp(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fedtg_par_module(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fedtg_par_nam(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fedtg_par_typ(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fedtg_persist_client_info(ctx,obj,val) \
           d2fedtgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fedtg_persist_clt_inf_len(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fedtg_previous(ctx,obj,val) \
           d2fedtgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fedtg_show_horz_scrlbr(ctx,obj,val) \
           d2fedtgb_GetBoolProp(ctx,obj,D2FP_SHOW_HORZ_SCRLBR,val)
#define d2fedtg_show_vert_scrlbr(ctx,obj,val) \
           d2fedtgb_GetBoolProp(ctx,obj,D2FP_SHOW_VERT_SCRLBR,val)
#define d2fedtg_source(ctx,obj,val) \
           d2fedtgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2fedtg_title(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2fedtg_vat_nam(ctx,obj,val) \
           d2fedtgt_GetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fedtg_vat_obj(ctx,obj,val) \
           d2fedtgo_GetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fedtg_white_on_black(ctx,obj,val) \
           d2fedtgb_GetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2fedtg_width(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fedtg_wrap_sty(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_WRAP_STY,val)
#define d2fedtg_x_pos(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fedtg_y_pos(ctx,obj,val) \
           d2fedtgn_GetNumProp(ctx,obj,D2FP_Y_POS,val)

#define d2fedts_back_color(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fedts_btm_ttl(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_BTM_TTL,val)
#define d2fedts_client_info(ctx,obj,val) \
           d2fedtsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fedts_comment(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fedts_fill_pat(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fedts_font_nam(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fedts_font_siz(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fedts_font_spcing(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fedts_font_sty(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fedts_font_wght(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fedts_fore_color(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fedts_height(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fedts_name(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fedts_par_flnam(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fedts_par_flpath(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fedts_par_modstr(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fedts_par_modtyp(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fedts_par_module(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fedts_par_nam(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fedts_par_typ(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fedts_persist_client_info(ctx,obj,val) \
           d2fedtsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fedts_persist_clt_inf_len(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fedts_show_horz_scrlbr(ctx,obj,val) \
           d2fedtsb_SetBoolProp(ctx,obj,D2FP_SHOW_HORZ_SCRLBR,val)
#define d2fedts_show_vert_scrlbr(ctx,obj,val) \
           d2fedtsb_SetBoolProp(ctx,obj,D2FP_SHOW_VERT_SCRLBR,val)
#define d2fedts_title(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2fedts_vat_nam(ctx,obj,val) \
           d2fedtst_SetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fedts_vat_obj(ctx,obj,val) \
           d2fedtso_SetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fedts_white_on_black(ctx,obj,val) \
           d2fedtsb_SetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2fedts_width(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fedts_wrap_sty(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_WRAP_STY,val)
#define d2fedts_x_pos(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fedts_y_pos(ctx,obj,val) \
           d2fedtsn_SetNumProp(ctx,obj,D2FP_Y_POS,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
               
#endif /* D2FEDT */

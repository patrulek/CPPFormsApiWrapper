/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FCNV.H -- Dev2K Forms API CaNVas declarations

   DESCRIPTION
    Contains the public declarations for the Forms API CaNVas object

   PUBLIC FUNCTIONS
    d2fcnvcr_Create          - Cover for d2fobcr_Create
    d2fcnvde_Destroy         - Cover for d2fobde_Destroy
    d2fcnvdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fcnvsc_Subclass        - Cover for d2fobsc_Subclass
    d2fcnvg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fcnvs?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fcnvhp_HasProp         - Cover for d2fobhp_HasProp
    d2fcnvip_InheritProp     - Cover for d2fobip_InheritProp
    d2fcnvii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fcnvid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fcnvis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FCNV
#define D2FCNV

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
** Object: Canvas
**  
*/
ORA_RETTYPE(d2fstatus) d2fcnvcr_Create( d2fctx *pd2fctx, d2fob *parent,
                                        d2fcnv **ppd2fcnv, text *name  );
ORA_RETTYPE(d2fstatus) d2fcnvde_Destroy( d2fctx *pd2fctx, d2fcnv *pd2fcnv );
ORA_RETTYPE(d2fstatus) d2fcnvdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fcnv *pd2fcnv_src,
                                           d2fcnv **ppd2fcnv_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2fcnvsc_SubClass( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fcnvgb_GetBoolProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fcnvgn_GetNumProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fcnvgt_GetTextProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fcnvgo_GetObjProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fcnvgp_GetBlobProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fcnvsb_SetBoolProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fcnvsn_SetNumProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fcnvst_SetTextProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fcnvso_SetObjProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fcnvsp_SetBlobProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fcnvhp_HasProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fcnvip_InheritProp( d2fctx *pd2fctx, d2fcnv *pd2fcnv,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fcnvii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fcnv *pd2fcnv, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fcnvid_IspropDefault( d2fctx *pd2fctx,
                                               d2fcnv *pd2fcnv, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fcnvis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fcnv *pd2fcnv);


/* Begin convenience macros  */
#define d2fcnvg_back_color(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fcnvg_bevel(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_BEVEL,val)
#define d2fcnvg_client_info(ctx,obj,val) \
           d2fcnvgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fcnvg_cnv_typ(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_CNV_TYP,val)
#define d2fcnvg_comment(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fcnvg_fill_pat(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fcnvg_font_nam(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fcnvg_font_siz(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fcnvg_font_spcing(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fcnvg_font_sty(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fcnvg_font_wght(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fcnvg_fore_color(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fcnvg_graphic(ctx,obj,val) \
           d2fcnvgo_GetObjProp(ctx,obj,D2FP_GRAPHIC,val)
#define d2fcnvg_height(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fcnvg_help_book_topic(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_HELP_BOOK_TOPIC,val)
#define d2fcnvg_lang_dir(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fcnvg_module(ctx,obj,val) \
           d2fcnvgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fcnvg_name(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fcnvg_next(ctx,obj,val) \
           d2fcnvgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fcnvg_owner(ctx,obj,val) \
           d2fcnvgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fcnvg_par_flnam(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fcnvg_par_flpath(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fcnvg_par_modstr(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fcnvg_par_modtyp(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fcnvg_par_module(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fcnvg_par_nam(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fcnvg_par_typ(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fcnvg_persist_client_info(ctx,obj,val) \
           d2fcnvgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fcnvg_persist_clt_inf_len(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fcnvg_popup_mnu_nam(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_POPUP_MNU_NAM,val)
#define d2fcnvg_popup_mnu_obj(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_POPUP_MNU_OBJ,val)
#define d2fcnvg_previous(ctx,obj,val) \
           d2fcnvgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fcnvg_raise_on_ent(ctx,obj,val) \
           d2fcnvgb_GetBoolProp(ctx,obj,D2FP_RAISE_ON_ENT,val)
#define d2fcnvg_show_horz_scrlbr(ctx,obj,val) \
           d2fcnvgb_GetBoolProp(ctx,obj,D2FP_SHOW_HORZ_SCRLBR,val)
#define d2fcnvg_show_vert_scrlbr(ctx,obj,val) \
           d2fcnvgb_GetBoolProp(ctx,obj,D2FP_SHOW_VERT_SCRLBR,val)
#define d2fcnvg_source(ctx,obj,val) \
           d2fcnvgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2fcnvg_tab_act_sty(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_TAB_ACT_STY,val)
#define d2fcnvg_tab_att_edge(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_TAB_ATT_EDGE,val)
#define d2fcnvg_tab_page(ctx,obj,val) \
           d2fcnvgo_GetObjProp(ctx,obj,D2FP_TAB_PAGE,val)
#define d2fcnvg_tab_sty(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_TAB_STY,val)
#define d2fcnvg_tab_wid_sty(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_TAB_WID_STY,val)
#define d2fcnvg_vat_nam(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fcnvg_vat_obj(ctx,obj,val) \
           d2fcnvgo_GetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fcnvg_visible(ctx,obj,val) \
           d2fcnvgb_GetBoolProp(ctx,obj,D2FP_VISIBLE,val)
#define d2fcnvg_vprt_hgt(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_VPRT_HGT,val)
#define d2fcnvg_vprt_wid(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_VPRT_WID,val)
#define d2fcnvg_vprt_x_pos(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_VPRT_X_POS,val)
#define d2fcnvg_vprt_x_pos_on_cnv(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_VPRT_X_POS_ON_CNV,val)
#define d2fcnvg_vprt_y_pos(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_VPRT_Y_POS,val)
#define d2fcnvg_vprt_y_pos_on_cnv(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_VPRT_Y_POS_ON_CNV,val)
#define d2fcnvg_white_on_black(ctx,obj,val) \
           d2fcnvgb_GetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2fcnvg_width(ctx,obj,val) \
           d2fcnvgn_GetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fcnvg_wnd_nam(ctx,obj,val) \
           d2fcnvgt_GetTextProp(ctx,obj,D2FP_WND_NAM,val)
#define d2fcnvg_wnd_obj(ctx,obj,val) \
           d2fcnvgo_GetObjProp(ctx,obj,D2FP_WND_OBJ,val)

#define d2fcnvs_back_color(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fcnvs_bevel(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_BEVEL,val)
#define d2fcnvs_client_info(ctx,obj,val) \
           d2fcnvsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fcnvs_cnv_typ(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_CNV_TYP,val)
#define d2fcnvs_comment(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fcnvs_fill_pat(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fcnvs_font_nam(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fcnvs_font_siz(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fcnvs_font_spcing(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fcnvs_font_sty(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fcnvs_font_wght(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fcnvs_fore_color(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fcnvs_height(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fcnvs_help_book_topic(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_HELP_BOOK_TOPIC,val)
#define d2fcnvs_lang_dir(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fcnvs_name(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fcnvs_par_flnam(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fcnvs_par_flpath(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fcnvs_par_modstr(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fcnvs_par_modtyp(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fcnvs_par_module(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fcnvs_par_nam(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fcnvs_par_typ(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fcnvs_persist_client_info(ctx,obj,val) \
           d2fcnvsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fcnvs_persist_clt_inf_len(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fcnvs_popup_mnu_nam(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_POPUP_MNU_NAM,val)
#define d2fcnvs_popup_mnu_obj(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_POPUP_MNU_OBJ,val)
#define d2fcnvs_raise_on_ent(ctx,obj,val) \
           d2fcnvsb_SetBoolProp(ctx,obj,D2FP_RAISE_ON_ENT,val)
#define d2fcnvs_show_horz_scrlbr(ctx,obj,val) \
           d2fcnvsb_SetBoolProp(ctx,obj,D2FP_SHOW_HORZ_SCRLBR,val)
#define d2fcnvs_show_vert_scrlbr(ctx,obj,val) \
           d2fcnvsb_SetBoolProp(ctx,obj,D2FP_SHOW_VERT_SCRLBR,val)
#define d2fcnvs_tab_act_sty(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_TAB_ACT_STY,val)
#define d2fcnvs_tab_att_edge(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_TAB_ATT_EDGE,val)
#define d2fcnvs_tab_sty(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_TAB_STY,val)
#define d2fcnvs_tab_wid_sty(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_TAB_WID_STY,val)
#define d2fcnvs_vat_nam(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fcnvs_vat_obj(ctx,obj,val) \
           d2fcnvso_SetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fcnvs_visible(ctx,obj,val) \
           d2fcnvsb_SetBoolProp(ctx,obj,D2FP_VISIBLE,val)
#define d2fcnvs_vprt_hgt(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_VPRT_HGT,val)
#define d2fcnvs_vprt_wid(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_VPRT_WID,val)
#define d2fcnvs_vprt_x_pos(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_VPRT_X_POS,val)
#define d2fcnvs_vprt_x_pos_on_cnv(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_VPRT_X_POS_ON_CNV,val)
#define d2fcnvs_vprt_y_pos(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_VPRT_Y_POS,val)
#define d2fcnvs_vprt_y_pos_on_cnv(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_VPRT_Y_POS_ON_CNV,val)
#define d2fcnvs_white_on_black(ctx,obj,val) \
           d2fcnvsb_SetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2fcnvs_width(ctx,obj,val) \
           d2fcnvsn_SetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fcnvs_wnd_nam(ctx,obj,val) \
           d2fcnvst_SetTextProp(ctx,obj,D2FP_WND_NAM,val)
#define d2fcnvs_wnd_obj(ctx,obj,val) \
           d2fcnvso_SetObjProp(ctx,obj,D2FP_WND_OBJ,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FCNV */

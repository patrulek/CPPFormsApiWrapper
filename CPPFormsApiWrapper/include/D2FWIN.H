/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FWIN.H -- Dev2K Forms API WINdow declarations

   DESCRIPTION
    Contains the public declarations for the Forms API WINdow object

   PUBLIC FUNCTIONS
    d2fwincr_Create          - Cover for d2fobcr_Create
    d2fwinde_Destroy         - Cover for d2fobde_Destroy
    d2fwindu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fwinsc_Subclass        - Cover for d2fobsc_Subclass
    d2fwing?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fwins?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fwinhp_HasProp         - Cover for d2fobhp_HasProp
    d2fwinip_InheritProp     - Cover for d2fobip_InheritProp
    d2fwinii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fwinid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fwinis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FWIN
#define D2FWIN

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
** Object: Window
**  
*/
ORA_RETTYPE(d2fstatus) d2fwincr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fwin **ppd2fwin, text *name  );
ORA_RETTYPE(d2fstatus) d2fwinde_Destroy( d2fctx *pd2fctx, d2fwin *pd2fwin );
ORA_RETTYPE(d2fstatus) d2fwindu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fwin *pd2fwin_src,
                                           d2fwin **ppd2fwin_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2fwinsc_SubClass( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fwingb_GetBoolProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fwingn_GetNumProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fwingt_GetTextProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fwingo_GetObjProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fwingp_GetBlobProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fwinsb_SetBoolProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fwinsn_SetNumProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fwinst_SetTextProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fwinso_SetObjProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fwinsp_SetBlobProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fwinhp_HasProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fwinip_InheritProp( d2fctx *pd2fctx, d2fwin *pd2fwin,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fwinii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fwin *pd2fwin, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fwinid_IspropDefault( d2fctx *pd2fctx,
                                               d2fwin *pd2fwin, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fwinis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fwin *pd2fwin);


/* Begin convenience macros  */
#define d2fwing_back_color(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fwing_bevel(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_BEVEL,val)
#define d2fwing_client_info(ctx,obj,val) \
           d2fwingp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fwing_cls_allowed(ctx,obj,val) \
           d2fwingb_GetBoolProp(ctx,obj,D2FP_CLS_ALLOWED,val)
#define d2fwing_comment(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fwing_fill_pat(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fwing_font_nam(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fwing_font_siz(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fwing_font_spcing(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fwing_font_sty(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fwing_font_wght(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fwing_fore_color(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fwing_height(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fwing_help_book_topic(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_HELP_BOOK_TOPIC,val)
#define d2fwing_hide_on_exit(ctx,obj,val) \
           d2fwingb_GetBoolProp(ctx,obj,D2FP_HIDE_ON_EXIT,val)
#define d2fwing_htb_cnv_name(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_HTB_CNV_NAME,val)
#define d2fwing_icon_flnam(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_ICON_FLNAM,val)
#define d2fwing_inhrt_mnu(ctx,obj,val) \
           d2fwingb_GetBoolProp(ctx,obj,D2FP_INHRT_MNU,val)
#define d2fwing_lang_dir(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fwing_maximize_allowed(ctx,obj,val) \
           d2fwingb_GetBoolProp(ctx,obj,D2FP_MAXIMIZE_ALLOWED,val)
#define d2fwing_minimize_allowed(ctx,obj,val) \
           d2fwingb_GetBoolProp(ctx,obj,D2FP_MINIMIZE_ALLOWED,val)
#define d2fwing_minimize_ttl(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_MINIMIZE_TTL,val)
#define d2fwing_modal(ctx,obj,val) \
           d2fwingb_GetBoolProp(ctx,obj,D2FP_MODAL,val)
#define d2fwing_module(ctx,obj,val) \
           d2fwingo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fwing_mv_allowed(ctx,obj,val) \
           d2fwingb_GetBoolProp(ctx,obj,D2FP_MV_ALLOWED,val)
#define d2fwing_name(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fwing_next(ctx,obj,val) \
           d2fwingo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fwing_owner(ctx,obj,val) \
           d2fwingo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fwing_par_flnam(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fwing_par_flpath(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fwing_par_modstr(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fwing_par_modtyp(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fwing_par_module(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fwing_par_nam(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fwing_par_typ(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fwing_persist_client_info(ctx,obj,val) \
           d2fwingp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fwing_persist_clt_inf_len(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fwing_previous(ctx,obj,val) \
           d2fwingo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fwing_prmry_cnv(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_PRMRY_CNV,val)
#define d2fwing_resize_allowed(ctx,obj,val) \
           d2fwingb_GetBoolProp(ctx,obj,D2FP_RESIZE_ALLOWED,val)
#define d2fwing_show_horz_scrlbr(ctx,obj,val) \
           d2fwingb_GetBoolProp(ctx,obj,D2FP_SHOW_HORZ_SCRLBR,val)
#define d2fwing_show_vert_scrlbr(ctx,obj,val) \
           d2fwingb_GetBoolProp(ctx,obj,D2FP_SHOW_VERT_SCRLBR,val)
#define d2fwing_source(ctx,obj,val) \
           d2fwingo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2fwing_title(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2fwing_vat_nam(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fwing_vat_obj(ctx,obj,val) \
           d2fwingo_GetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fwing_vtb_cnv_name(ctx,obj,val) \
           d2fwingt_GetTextProp(ctx,obj,D2FP_VTB_CNV_NAME,val)
#define d2fwing_white_on_black(ctx,obj,val) \
           d2fwingb_GetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2fwing_width(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fwing_win_sty(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_WIN_STY,val)
#define d2fwing_x_pos(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fwing_y_pos(ctx,obj,val) \
           d2fwingn_GetNumProp(ctx,obj,D2FP_Y_POS,val)

#define d2fwins_back_color(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fwins_bevel(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_BEVEL,val)
#define d2fwins_client_info(ctx,obj,val) \
           d2fwinsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fwins_cls_allowed(ctx,obj,val) \
           d2fwinsb_SetBoolProp(ctx,obj,D2FP_CLS_ALLOWED,val)
#define d2fwins_comment(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fwins_fill_pat(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fwins_font_nam(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fwins_font_siz(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fwins_font_spcing(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fwins_font_sty(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fwins_font_wght(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fwins_fore_color(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fwins_height(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fwins_help_book_topic(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_HELP_BOOK_TOPIC,val)
#define d2fwins_hide_on_exit(ctx,obj,val) \
           d2fwinsb_SetBoolProp(ctx,obj,D2FP_HIDE_ON_EXIT,val)
#define d2fwins_htb_cnv_name(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_HTB_CNV_NAME,val)
#define d2fwins_icon_flnam(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_ICON_FLNAM,val)
#define d2fwins_inhrt_mnu(ctx,obj,val) \
           d2fwinsb_SetBoolProp(ctx,obj,D2FP_INHRT_MNU,val)
#define d2fwins_lang_dir(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fwins_maximize_allowed(ctx,obj,val) \
           d2fwinsb_SetBoolProp(ctx,obj,D2FP_MAXIMIZE_ALLOWED,val)
#define d2fwins_minimize_allowed(ctx,obj,val) \
           d2fwinsb_SetBoolProp(ctx,obj,D2FP_MINIMIZE_ALLOWED,val)
#define d2fwins_minimize_ttl(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_MINIMIZE_TTL,val)
#define d2fwins_modal(ctx,obj,val) \
           d2fwinsb_SetBoolProp(ctx,obj,D2FP_MODAL,val)
#define d2fwins_mv_allowed(ctx,obj,val) \
           d2fwinsb_SetBoolProp(ctx,obj,D2FP_MV_ALLOWED,val)
#define d2fwins_name(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fwins_par_flnam(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fwins_par_flpath(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fwins_par_modstr(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fwins_par_modtyp(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fwins_par_module(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fwins_par_nam(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fwins_par_typ(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fwins_persist_client_info(ctx,obj,val) \
           d2fwinsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fwins_persist_clt_inf_len(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fwins_prmry_cnv(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_PRMRY_CNV,val)
#define d2fwins_resize_allowed(ctx,obj,val) \
           d2fwinsb_SetBoolProp(ctx,obj,D2FP_RESIZE_ALLOWED,val)
#define d2fwins_show_horz_scrlbr(ctx,obj,val) \
           d2fwinsb_SetBoolProp(ctx,obj,D2FP_SHOW_HORZ_SCRLBR,val)
#define d2fwins_show_vert_scrlbr(ctx,obj,val) \
           d2fwinsb_SetBoolProp(ctx,obj,D2FP_SHOW_VERT_SCRLBR,val)
#define d2fwins_title(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2fwins_vat_nam(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fwins_vat_obj(ctx,obj,val) \
           d2fwinso_SetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fwins_vtb_cnv_name(ctx,obj,val) \
           d2fwinst_SetTextProp(ctx,obj,D2FP_VTB_CNV_NAME,val)
#define d2fwins_white_on_black(ctx,obj,val) \
           d2fwinsb_SetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2fwins_width(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fwins_win_sty(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_WIN_STY,val)
#define d2fwins_x_pos(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fwins_y_pos(ctx,obj,val) \
           d2fwinsn_SetNumProp(ctx,obj,D2FP_Y_POS,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FWIN */

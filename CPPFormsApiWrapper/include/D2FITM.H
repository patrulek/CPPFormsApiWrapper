/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FITM.H -- Dev2K Forms API ITeM declarations

   DESCRIPTION
    Contains the public declarations for the Forms API ITeM object

   PUBLIC FUNCTIONS
    d2fitmcr_Create          - Cover for d2fobcr_Create
    d2fitmde_Destroy         - Cover for d2fobde_Destroy
    d2fitmdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fitmsc_Subclass        - Cover for d2fobsc_Subclass
    d2fitmco_CompileObj      - Compile PL/SQL in the item object
    d2fitmile_InsertListElem - Insert a new list element
    d2fitmdle_DeleteListElem - Delete an existing list element
    d2fitmgle_GetListElem    - Get the label and value of a list element
    d2fitmg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fitms?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fitmhp_HasProp         - Cover for d2fobhp_HasProp
    d2fitmip_InheritProp     - Cover for d2fobip_InheritProp
    d2fitmii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fitmid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fitmis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FITM
#define D2FITM

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
** Object: Item
**  
**  d2fitmile_InsertListElem - If the item is a list item, then this
**                             function will insert a new list element
**                             in the "List Values" property.  Both a 
**                             label and value are required.
**
**  d2fitmdle_DeleteListElem - Remove the specified list element from
**                             the list item.
**                             
**  d2fitmgle_GetListElem    - Returns the label and value for the 
**                             specified list element.
**                             
*/
ORA_RETTYPE(d2fstatus) d2fitmcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fitm **ppd2fitm, text *name  );
ORA_RETTYPE(d2fstatus) d2fitmde_Destroy( d2fctx *pd2fctx, d2fitm *pd2fitm );
ORA_RETTYPE(d2fstatus) d2fitmdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fitm *pd2fitm_src,
                                           d2fitm **ppd2fitm_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2fitmsc_SubClass( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fitmco_CompileObj( d2fctx *pd2fctx,
                                               d2fitm *pd2fitm );
ORA_RETTYPE(d2fstatus) d2fitmile_InsertListElem( d2fctx *pd2fctx,
                                                 d2fitm *pd2fitm,
                                                 number index,
                                                 text *label,
                                                 text *value );
ORA_RETTYPE(d2fstatus) d2fitmdle_DeleteListElem( d2fctx *pd2fctx,
                                                 d2fitm *pd2fitm,
                                                 number index );
ORA_RETTYPE(d2fstatus) d2fitmgle_GetListElem( d2fctx *pd2fctx,
                                              d2fitm *pd2fitm,
                                              number index,
                                              text **label,
                                              text **value );
ORA_RETTYPE(d2fstatus) d2fitmgb_GetBoolProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fitmgn_GetNumProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fitmgt_GetTextProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fitmgo_GetObjProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fitmgp_GetBlobProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fitmsb_SetBoolProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fitmsn_SetNumProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fitmst_SetTextProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fitmso_SetObjProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fitmsp_SetBlobProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fitmhp_HasProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fitmip_InheritProp( d2fctx *pd2fctx, d2fitm *pd2fitm,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fitmii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fitm *pd2fitm, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fitmid_IspropDefault( d2fctx *pd2fctx,
                                               d2fitm *pd2fitm, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fitmis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fitm *pd2fitm);


/* Begin convenience macros  */
#define d2fitmg_access_key(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_ACCESS_KEY,val)
#define d2fitmg_audio_chnnls(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_AUDIO_CHNNLS,val)
#define d2fitmg_auto_hint(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_AUTO_HINT,val)
#define d2fitmg_auto_skp(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_AUTO_SKP,val)
#define d2fitmg_back_color(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fitmg_bevel(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_BEVEL,val)
#define d2fitmg_calc_mode(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_CALC_MODE,val)
#define d2fitmg_case_insensitive_qry(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_CASE_INSENSITIVE_QRY,val)
#define d2fitmg_case_rstrction(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_CASE_RSTRCTION,val)
#define d2fitmg_chk_bx_other_vals(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_CHK_BX_OTHER_VALS,val)
#define d2fitmg_chked_val(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_CHKED_VAL,val)
#define d2fitmg_client_info(ctx,obj,val) \
           d2fitmgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fitmg_cmprssion_qlty(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_CMPRSSION_QLTY,val)
#define d2fitmg_cnv_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_CNV_NAM,val)
#define d2fitmg_cnv_obj(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_CNV_OBJ,val)
#define d2fitmg_col_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_COL_NAM,val)
#define d2fitmg_comm_mode(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_COMM_MODE,val)
#define d2fitmg_comment(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fitmg_compress(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_COMPRESS,val)
#define d2fitmg_conceal_data(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_CONCEAL_DATA,val)
#define d2fitmg_copy_val_from_itm(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_COPY_VAL_FROM_ITM,val)
#define d2fitmg_dat_src_blk(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_DAT_SRC_BLK,val)
#define d2fitmg_dat_src_x_axs(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_DAT_SRC_X_AXS,val)
#define d2fitmg_dat_src_y_axs(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_DAT_SRC_Y_AXS,val)
#define d2fitmg_dat_typ(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_DAT_TYP,val)
#define d2fitmg_db_itm(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_DB_ITM,val)
#define d2fitmg_dflt_btn(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_DFLT_BTN,val)
#define d2fitmg_disp_qlty(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_DISP_QLTY,val)
#define d2fitmg_dist_btwn_recs(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_DIST_BTWN_RECS,val)
#define d2fitmg_edt_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_EDT_NAM,val)
#define d2fitmg_edt_obj(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_EDT_OBJ,val)
#define d2fitmg_edt_x_pos(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_EDT_X_POS,val)
#define d2fitmg_edt_y_pos(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_EDT_Y_POS,val)
#define d2fitmg_enabled(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_ENABLED,val)
#define d2fitmg_exec_mode(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_EXEC_MODE,val)
#define d2fitmg_fill_pat(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fitmg_fixed_len(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_FIXED_LEN,val)
#define d2fitmg_flnam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_FLNAM,val)
#define d2fitmg_fmt_msk(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_FMT_MSK,val)
#define d2fitmg_font_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fitmg_font_siz(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fitmg_font_spcing(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fitmg_font_sty(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fitmg_font_wght(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fitmg_fore_color(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fitmg_formula(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_FORMULA,val)
#define d2fitmg_height(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fitmg_help_book_topic(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_HELP_BOOK_TOPIC,val)
#define d2fitmg_highest_allowed_val(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_HIGHEST_ALLOWED_VAL,val)
#define d2fitmg_hint(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_HINT,val)
#define d2fitmg_icon_flnam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_ICON_FLNAM,val)
#define d2fitmg_iconic(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_ICONIC,val)
#define d2fitmg_img_dpth(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_IMG_DPTH,val)
#define d2fitmg_img_fmt(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_IMG_FMT,val)
#define d2fitmg_impl_class(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_IMPL_CLASS,val)
#define d2fitmg_init_kbrd_dir(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_INIT_KBRD_DIR,val)
#define d2fitmg_init_val(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_INIT_VAL,val)
#define d2fitmg_insrt_allowed(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_INSRT_ALLOWED,val)
#define d2fitmg_itm_typ(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_ITM_TYP,val)
#define d2fitmg_itms_disp(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_ITMS_DISP,val)
#define d2fitmg_justification(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_JUSTIFICATION,val)
#define d2fitmg_kbrd_navigable(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_KBRD_NAVIGABLE,val)
#define d2fitmg_kbrd_state(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_KBRD_STATE,val)
#define d2fitmg_keep_crsr_pos(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_KEEP_CRSR_POS,val)
#define d2fitmg_label(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2fitmg_lang_dir(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fitmg_lock_rec(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_LOCK_REC,val)
#define d2fitmg_lov_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_LOV_NAM,val)
#define d2fitmg_lov_obj(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_LOV_OBJ,val)
#define d2fitmg_lov_x_pos(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_LOV_X_POS,val)
#define d2fitmg_lov_y_pos(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_LOV_Y_POS,val)
#define d2fitmg_lowest_allowed_val(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_LOWEST_ALLOWED_VAL,val)
#define d2fitmg_lst_element_count(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_LST_ELEMENT_COUNT,val)
#define d2fitmg_lst_sty(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_LST_STY,val)
#define d2fitmg_max_len(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_MAX_LEN,val)
#define d2fitmg_mlt_lin(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_MLT_LIN,val)
#define d2fitmg_module(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fitmg_mouse_navigate(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_MOUSE_NAVIGATE,val)
#define d2fitmg_name(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fitmg_next(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fitmg_nxt_navigation_itm_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_NXT_NAVIGATION_ITM_NAM,val)
#define d2fitmg_nxt_navigation_itm_obj(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_NXT_NAVIGATION_ITM_OBJ,val)
#define d2fitmg_ole_act_sty(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_OLE_ACT_STY,val)
#define d2fitmg_ole_class(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_OLE_CLASS,val)
#define d2fitmg_ole_in_place_act(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_OLE_IN_PLACE_ACT,val)
#define d2fitmg_ole_insd_out_support(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_OLE_INSD_OUT_SUPPORT,val)
#define d2fitmg_ole_popup_mnu_itms(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_OLE_POPUP_MNU_ITMS,val)
#define d2fitmg_ole_resiz_sty(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_OLE_RESIZ_STY,val)
#define d2fitmg_ole_show_popup_mnu(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_OLE_SHOW_POPUP_MNU,val)
#define d2fitmg_ole_show_tnnt_typ(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_OLE_SHOW_TNNT_TYP,val)
#define d2fitmg_ole_tnnt_aspct(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_OLE_TNNT_ASPCT,val)
#define d2fitmg_ole_tnnt_typ(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_OLE_TNNT_TYP,val)
#define d2fitmg_other_vals(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_OTHER_VALS,val)
#define d2fitmg_owner(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fitmg_par_flnam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fitmg_par_flpath(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fitmg_par_modstr(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fitmg_par_modtyp(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fitmg_par_module(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fitmg_par_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fitmg_par_sl1obj_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PAR_SL1OBJ_NAM,val)
#define d2fitmg_par_sl1obj_typ(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PAR_SL1OBJ_TYP,val)
#define d2fitmg_par_typ(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fitmg_persist_client_info(ctx,obj,val) \
           d2fitmgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fitmg_persist_clt_inf_len(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fitmg_popup_mnu_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_POPUP_MNU_NAM,val)
#define d2fitmg_popup_mnu_obj(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_POPUP_MNU_OBJ,val)
#define d2fitmg_popup_va_obj(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_POPUP_VA_OBJ,val)
#define d2fitmg_prev_navigation_itm_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PREV_NAVIGATION_ITM_NAM,val)
#define d2fitmg_prev_navigation_itm_obj(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_PREV_NAVIGATION_ITM_OBJ,val)
#define d2fitmg_previous(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fitmg_prmpt(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PRMPT,val)
#define d2fitmg_prmpt_align(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PRMPT_ALIGN,val)
#define d2fitmg_prmpt_align_ofst(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PRMPT_ALIGN_OFST,val)
#define d2fitmg_prmpt_att_edge(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PRMPT_ATT_EDGE,val)
#define d2fitmg_prmpt_att_ofst(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PRMPT_ATT_OFST,val)
#define d2fitmg_prmpt_back_color(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PRMPT_BACK_COLOR,val)
#define d2fitmg_prmpt_disp_sty(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PRMPT_DISP_STY,val)
#define d2fitmg_prmpt_fill_pat(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PRMPT_FILL_PAT,val)
#define d2fitmg_prmpt_font_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PRMPT_FONT_NAM,val)
#define d2fitmg_prmpt_font_siz(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_SIZ,val)
#define d2fitmg_prmpt_font_spcing(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_SPCING,val)
#define d2fitmg_prmpt_font_sty(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_STY,val)
#define d2fitmg_prmpt_font_wght(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_WGHT,val)
#define d2fitmg_prmpt_fore_color(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PRMPT_FORE_COLOR,val)
#define d2fitmg_prmpt_jst(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PRMPT_JST,val)
#define d2fitmg_prmpt_reading_ordr(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_PRMPT_READING_ORDR,val)
#define d2fitmg_prmpt_vat_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_PRMPT_VAT_NAM,val)
#define d2fitmg_prmpt_vat_obj(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_PRMPT_VAT_OBJ,val)
#define d2fitmg_prmry_key(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_PRMRY_KEY,val)
#define d2fitmg_qry_allowed(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_QRY_ALLOWED,val)
#define d2fitmg_qry_len(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_QRY_LEN,val)
#define d2fitmg_qry_only(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_QRY_ONLY,val)
#define d2fitmg_rad_but(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_RAD_BUT,val)
#define d2fitmg_reading_ordr(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_READING_ORDR,val)
#define d2fitmg_rec_vat_grp_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_REC_VAT_GRP_NAM,val)
#define d2fitmg_rec_vat_grp_obj(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_REC_VAT_GRP_OBJ,val)
#define d2fitmg_rendered(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_RENDERED,val)
#define d2fitmg_required(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_REQUIRED,val)
#define d2fitmg_show_fast_fwd(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_SHOW_FAST_FWD,val)
#define d2fitmg_show_horz_scrlbr(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_SHOW_HORZ_SCRLBR,val)
#define d2fitmg_show_palette(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_SHOW_PALETTE,val)
#define d2fitmg_show_play(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_SHOW_PLAY,val)
#define d2fitmg_show_rec(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_SHOW_REC,val)
#define d2fitmg_show_rewind(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_SHOW_REWIND,val)
#define d2fitmg_show_slider(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_SHOW_SLIDER,val)
#define d2fitmg_show_time(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_SHOW_TIME,val)
#define d2fitmg_show_vert_scrlbr(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_SHOW_VERT_SCRLBR,val)
#define d2fitmg_show_volume(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_SHOW_VOLUME,val)
#define d2fitmg_sizing_sty(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_SIZING_STY,val)
#define d2fitmg_snd_fmt(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_SND_FMT,val)
#define d2fitmg_snd_qlty(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_SND_QLTY,val)
#define d2fitmg_source(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2fitmg_summ_blk_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_SUMM_BLK_NAM,val)
#define d2fitmg_summ_func(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_SUMM_FUNC,val)
#define d2fitmg_summ_itm_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_SUMM_ITM_NAM,val)
#define d2fitmg_sync_itm_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_SYNC_ITM_NAM,val)
#define d2fitmg_sync_itm_obj(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_SYNC_ITM_OBJ,val)
#define d2fitmg_tbp_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_TBP_NAM,val)
#define d2fitmg_tbp_obj(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_TBP_OBJ,val)
#define d2fitmg_tooltip(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_TOOLTIP,val)
#define d2fitmg_tooltip_vat_grp(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_TOOLTIP_VAT_GRP,val)
#define d2fitmg_tre_allw_emp_branch(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_TRE_ALLW_EMP_BRANCH,val)
#define d2fitmg_tre_data_qry(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_TRE_DATA_QRY,val)
#define d2fitmg_tre_multi_select(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_TRE_MULTI_SELECT,val)
#define d2fitmg_tre_rec_grp(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_TRE_REC_GRP,val)
#define d2fitmg_tre_show_lines(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_TRE_SHOW_LINES,val)
#define d2fitmg_tre_show_symbol(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_TRE_SHOW_SYMBOL,val)
#define d2fitmg_trigger(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_TRIGGER,val)
#define d2fitmg_unchked_val(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_UNCHKED_VAL,val)
#define d2fitmg_updt_allowed(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_UPDT_ALLOWED,val)
#define d2fitmg_updt_commit(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_UPDT_COMMIT,val)
#define d2fitmg_updt_if_null(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_UPDT_IF_NULL,val)
#define d2fitmg_updt_qry(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_UPDT_QRY,val)
#define d2fitmg_validate_from_lst(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_VALIDATE_FROM_LST,val)
#define d2fitmg_vat_nam(ctx,obj,val) \
           d2fitmgt_GetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fitmg_vat_obj(ctx,obj,val) \
           d2fitmgo_GetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fitmg_visible(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_VISIBLE,val)
#define d2fitmg_white_on_black(ctx,obj,val) \
           d2fitmgb_GetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2fitmg_width(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fitmg_wrap_sty(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_WRAP_STY,val)
#define d2fitmg_x_pos(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fitmg_y_pos(ctx,obj,val) \
           d2fitmgn_GetNumProp(ctx,obj,D2FP_Y_POS,val)

#define d2fitms_access_key(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_ACCESS_KEY,val)
#define d2fitms_audio_chnnls(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_AUDIO_CHNNLS,val)
#define d2fitms_auto_hint(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_AUTO_HINT,val)
#define d2fitms_auto_skp(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_AUTO_SKP,val)
#define d2fitms_back_color(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fitms_bevel(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_BEVEL,val)
#define d2fitms_calc_mode(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_CALC_MODE,val)
#define d2fitms_case_insensitive_qry(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_CASE_INSENSITIVE_QRY,val)
#define d2fitms_case_rstrction(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_CASE_RSTRCTION,val)
#define d2fitms_chk_bx_other_vals(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_CHK_BX_OTHER_VALS,val)
#define d2fitms_chked_val(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_CHKED_VAL,val)
#define d2fitms_client_info(ctx,obj,val) \
           d2fitmsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fitms_cmprssion_qlty(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_CMPRSSION_QLTY,val)
#define d2fitms_cnv_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_CNV_NAM,val)
#define d2fitms_cnv_obj(ctx,obj,val) \
           d2fitmso_SetObjProp(ctx,obj,D2FP_CNV_OBJ,val)
#define d2fitms_col_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_COL_NAM,val)
#define d2fitms_comm_mode(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_COMM_MODE,val)
#define d2fitms_comment(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fitms_compress(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_COMPRESS,val)
#define d2fitms_conceal_data(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_CONCEAL_DATA,val)
#define d2fitms_copy_val_from_itm(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_COPY_VAL_FROM_ITM,val)
#define d2fitms_dat_src_blk(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_DAT_SRC_BLK,val)
#define d2fitms_dat_src_x_axs(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_DAT_SRC_X_AXS,val)
#define d2fitms_dat_src_y_axs(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_DAT_SRC_Y_AXS,val)
#define d2fitms_dat_typ(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_DAT_TYP,val)
#define d2fitms_db_itm(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_DB_ITM,val)
#define d2fitms_dflt_btn(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_DFLT_BTN,val)
#define d2fitms_disp_qlty(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_DISP_QLTY,val)
#define d2fitms_dist_btwn_recs(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_DIST_BTWN_RECS,val)
#define d2fitms_edt_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_EDT_NAM,val)
#define d2fitms_edt_obj(ctx,obj,val) \
           d2fitmso_SetObjProp(ctx,obj,D2FP_EDT_OBJ,val)
#define d2fitms_edt_x_pos(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_EDT_X_POS,val)
#define d2fitms_edt_y_pos(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_EDT_Y_POS,val)
#define d2fitms_enabled(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_ENABLED,val)
#define d2fitms_exec_mode(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_EXEC_MODE,val)
#define d2fitms_fill_pat(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fitms_fixed_len(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_FIXED_LEN,val)
#define d2fitms_flnam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_FLNAM,val)
#define d2fitms_fmt_msk(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_FMT_MSK,val)
#define d2fitms_font_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fitms_font_siz(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fitms_font_spcing(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fitms_font_sty(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fitms_font_wght(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fitms_fore_color(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fitms_formula(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_FORMULA,val)
#define d2fitms_height(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fitms_help_book_topic(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_HELP_BOOK_TOPIC,val)
#define d2fitms_highest_allowed_val(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_HIGHEST_ALLOWED_VAL,val)
#define d2fitms_hint(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_HINT,val)
#define d2fitms_icon_flnam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_ICON_FLNAM,val)
#define d2fitms_iconic(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_ICONIC,val)
#define d2fitms_img_dpth(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_IMG_DPTH,val)
#define d2fitms_img_fmt(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_IMG_FMT,val)
#define d2fitms_impl_class(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_IMPL_CLASS,val)
#define d2fitms_init_kbrd_dir(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_INIT_KBRD_DIR,val)
#define d2fitms_init_val(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_INIT_VAL,val)
#define d2fitms_insrt_allowed(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_INSRT_ALLOWED,val)
#define d2fitms_itm_typ(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_ITM_TYP,val)
#define d2fitms_itms_disp(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_ITMS_DISP,val)
#define d2fitms_justification(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_JUSTIFICATION,val)
#define d2fitms_kbrd_navigable(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_KBRD_NAVIGABLE,val)
#define d2fitms_kbrd_state(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_KBRD_STATE,val)
#define d2fitms_keep_crsr_pos(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_KEEP_CRSR_POS,val)
#define d2fitms_label(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2fitms_lang_dir(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fitms_lock_rec(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_LOCK_REC,val)
#define d2fitms_lov_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_LOV_NAM,val)
#define d2fitms_lov_obj(ctx,obj,val) \
           d2fitmso_SetObjProp(ctx,obj,D2FP_LOV_OBJ,val)
#define d2fitms_lov_x_pos(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_LOV_X_POS,val)
#define d2fitms_lov_y_pos(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_LOV_Y_POS,val)
#define d2fitms_lowest_allowed_val(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_LOWEST_ALLOWED_VAL,val)
#define d2fitms_lst_sty(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_LST_STY,val)
#define d2fitms_max_len(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_MAX_LEN,val)
#define d2fitms_mlt_lin(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_MLT_LIN,val)
#define d2fitms_mouse_navigate(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_MOUSE_NAVIGATE,val)
#define d2fitms_name(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fitms_nxt_navigation_itm_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_NXT_NAVIGATION_ITM_NAM,val)
#define d2fitms_nxt_navigation_itm_obj(ctx,obj,val) \
           d2fitmso_SetObjProp(ctx,obj,D2FP_NXT_NAVIGATION_ITM_OBJ,val)
#define d2fitms_ole_act_sty(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_OLE_ACT_STY,val)
#define d2fitms_ole_class(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_OLE_CLASS,val)
#define d2fitms_ole_in_place_act(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_OLE_IN_PLACE_ACT,val)
#define d2fitms_ole_insd_out_support(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_OLE_INSD_OUT_SUPPORT,val)
#define d2fitms_ole_popup_mnu_itms(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_OLE_POPUP_MNU_ITMS,val)
#define d2fitms_ole_resiz_sty(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_OLE_RESIZ_STY,val)
#define d2fitms_ole_show_popup_mnu(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_OLE_SHOW_POPUP_MNU,val)
#define d2fitms_ole_show_tnnt_typ(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_OLE_SHOW_TNNT_TYP,val)
#define d2fitms_ole_tnnt_aspct(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_OLE_TNNT_ASPCT,val)
#define d2fitms_ole_tnnt_typ(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_OLE_TNNT_TYP,val)
#define d2fitms_other_vals(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_OTHER_VALS,val)
#define d2fitms_par_flnam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fitms_par_flpath(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fitms_par_modstr(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fitms_par_modtyp(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fitms_par_module(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fitms_par_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fitms_par_sl1obj_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PAR_SL1OBJ_NAM,val)
#define d2fitms_par_sl1obj_typ(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PAR_SL1OBJ_TYP,val)
#define d2fitms_par_typ(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fitms_persist_client_info(ctx,obj,val) \
           d2fitmsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fitms_persist_clt_inf_len(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fitms_popup_mnu_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_POPUP_MNU_NAM,val)
#define d2fitms_popup_mnu_obj(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_POPUP_MNU_OBJ,val)
#define d2fitms_popup_va_obj(ctx,obj,val) \
           d2fitmso_SetObjProp(ctx,obj,D2FP_POPUP_VA_OBJ,val)
#define d2fitms_prev_navigation_itm_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PREV_NAVIGATION_ITM_NAM,val)
#define d2fitms_prev_navigation_itm_obj(ctx,obj,val) \
           d2fitmso_SetObjProp(ctx,obj,D2FP_PREV_NAVIGATION_ITM_OBJ,val)
#define d2fitms_prmpt(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PRMPT,val)
#define d2fitms_prmpt_align(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PRMPT_ALIGN,val)
#define d2fitms_prmpt_align_ofst(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PRMPT_ALIGN_OFST,val)
#define d2fitms_prmpt_att_edge(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PRMPT_ATT_EDGE,val)
#define d2fitms_prmpt_att_ofst(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PRMPT_ATT_OFST,val)
#define d2fitms_prmpt_back_color(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PRMPT_BACK_COLOR,val)
#define d2fitms_prmpt_disp_sty(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PRMPT_DISP_STY,val)
#define d2fitms_prmpt_fill_pat(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PRMPT_FILL_PAT,val)
#define d2fitms_prmpt_font_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PRMPT_FONT_NAM,val)
#define d2fitms_prmpt_font_siz(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_SIZ,val)
#define d2fitms_prmpt_font_spcing(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_SPCING,val)
#define d2fitms_prmpt_font_sty(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_STY,val)
#define d2fitms_prmpt_font_wght(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_WGHT,val)
#define d2fitms_prmpt_fore_color(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PRMPT_FORE_COLOR,val)
#define d2fitms_prmpt_jst(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PRMPT_JST,val)
#define d2fitms_prmpt_reading_ordr(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_PRMPT_READING_ORDR,val)
#define d2fitms_prmpt_vat_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_PRMPT_VAT_NAM,val)
#define d2fitms_prmpt_vat_obj(ctx,obj,val) \
           d2fitmso_SetObjProp(ctx,obj,D2FP_PRMPT_VAT_OBJ,val)
#define d2fitms_prmry_key(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_PRMRY_KEY,val)
#define d2fitms_qry_allowed(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_QRY_ALLOWED,val)
#define d2fitms_qry_len(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_QRY_LEN,val)
#define d2fitms_qry_only(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_QRY_ONLY,val)
#define d2fitms_reading_ordr(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_READING_ORDR,val)
#define d2fitms_rec_vat_grp_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_REC_VAT_GRP_NAM,val)
#define d2fitms_rec_vat_grp_obj(ctx,obj,val) \
           d2fitmso_SetObjProp(ctx,obj,D2FP_REC_VAT_GRP_OBJ,val)
#define d2fitms_rendered(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_RENDERED,val)
#define d2fitms_required(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_REQUIRED,val)
#define d2fitms_show_fast_fwd(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_SHOW_FAST_FWD,val)
#define d2fitms_show_horz_scrlbr(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_SHOW_HORZ_SCRLBR,val)
#define d2fitms_show_palette(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_SHOW_PALETTE,val)
#define d2fitms_show_play(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_SHOW_PLAY,val)
#define d2fitms_show_rec(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_SHOW_REC,val)
#define d2fitms_show_rewind(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_SHOW_REWIND,val)
#define d2fitms_show_slider(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_SHOW_SLIDER,val)
#define d2fitms_show_time(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_SHOW_TIME,val)
#define d2fitms_show_vert_scrlbr(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_SHOW_VERT_SCRLBR,val)
#define d2fitms_show_volume(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_SHOW_VOLUME,val)
#define d2fitms_sizing_sty(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_SIZING_STY,val)
#define d2fitms_snd_fmt(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_SND_FMT,val)
#define d2fitms_snd_qlty(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_SND_QLTY,val)
#define d2fitms_summ_blk_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_SUMM_BLK_NAM,val)
#define d2fitms_summ_func(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_SUMM_FUNC,val)
#define d2fitms_summ_itm_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_SUMM_ITM_NAM,val)
#define d2fitms_sync_itm_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_SYNC_ITM_NAM,val)
#define d2fitms_sync_itm_obj(ctx,obj,val) \
           d2fitmso_SetObjProp(ctx,obj,D2FP_SYNC_ITM_OBJ,val)
#define d2fitms_tbp_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_TBP_NAM,val)
#define d2fitms_tbp_obj(ctx,obj,val) \
           d2fitmso_SetObjProp(ctx,obj,D2FP_TBP_OBJ,val)
#define d2fitms_tooltip(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_TOOLTIP,val)
#define d2fitms_tooltip_vat_grp(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_TOOLTIP_VAT_GRP,val)
#define d2fitms_tre_allw_emp_branch(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_TRE_ALLW_EMP_BRANCH,val)
#define d2fitms_tre_data_qry(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_TRE_DATA_QRY,val)
#define d2fitms_tre_multi_select(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_TRE_MULTI_SELECT,val)
#define d2fitms_tre_rec_grp(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_TRE_REC_GRP,val)
#define d2fitms_tre_show_lines(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_TRE_SHOW_LINES,val)
#define d2fitms_tre_show_symbol(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_TRE_SHOW_SYMBOL,val)
#define d2fitms_unchked_val(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_UNCHKED_VAL,val)
#define d2fitms_updt_allowed(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_UPDT_ALLOWED,val)
#define d2fitms_updt_commit(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_UPDT_COMMIT,val)
#define d2fitms_updt_if_null(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_UPDT_IF_NULL,val)
#define d2fitms_updt_qry(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_UPDT_QRY,val)
#define d2fitms_validate_from_lst(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_VALIDATE_FROM_LST,val)
#define d2fitms_vat_nam(ctx,obj,val) \
           d2fitmst_SetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fitms_vat_obj(ctx,obj,val) \
           d2fitmso_SetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fitms_visible(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_VISIBLE,val)
#define d2fitms_white_on_black(ctx,obj,val) \
           d2fitmsb_SetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2fitms_width(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fitms_wrap_sty(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_WRAP_STY,val)
#define d2fitms_x_pos(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fitms_y_pos(ctx,obj,val) \
           d2fitmsn_SetNumProp(ctx,obj,D2FP_Y_POS,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FITM */

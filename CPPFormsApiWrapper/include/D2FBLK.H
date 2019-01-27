/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/* 
   NAME
    D2FBLK.H -- Dev2K Forms API BLocK declarations

   DESCRIPTION
    Contains the public declarations for the Forms API BLocK object

   PUBLIC FUNCTIONS
    d2fblkcr_Create          - Cover for d2fobcr_Create
    d2fblkde_Destroy         - Cover for d2fobde_Destroy
    d2fblkdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fblksc_Subclass        - Cover for d2fobsc_Subclass
    d2fblkco_CompileObj      - 
    d2fblkg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fblks?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fblkhp_HasProp         - Cover for d2fobhp_HasProp
    d2fblkip_InheritProp     - Cover for d2fobip_InheritProp
    d2fblkii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fblkid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fblkis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FBLK
#define D2FBLK

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
** Object: Block
**  
*/
ORA_RETTYPE(d2fstatus) d2fblkcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fblk **ppd2fblk, text *name  );
ORA_RETTYPE(d2fstatus) d2fblkde_Destroy( d2fctx *pd2fctx, d2fblk *pd2fblk );
ORA_RETTYPE(d2fstatus) d2fblkdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fblk *pd2fblk_src,
                                           d2fblk **ppd2fblk_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2fblksc_SubClass( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fblkco_CompileObj( d2fctx *pd2fctx,
                                               d2fblk *pd2fblk );
ORA_RETTYPE(d2fstatus) d2fblkgb_GetBoolProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fblkgn_GetNumProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fblkgt_GetTextProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fblkgo_GetObjProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fblkgp_GetBlobProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fblksb_SetBoolProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fblksn_SetNumProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fblkst_SetTextProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fblkso_SetObjProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fblksp_SetBlobProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fblkhp_HasProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fblkip_InheritProp( d2fctx *pd2fctx, d2fblk *pd2fblk,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fblkii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fblk *pd2fblk, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fblkid_IspropDefault( d2fctx *pd2fctx,
                                               d2fblk *pd2fblk, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fblkis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fblk *pd2fblk);


/* Begin convenience macros  */
#define d2fblkg_alias(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_ALIAS,val)
#define d2fblkg_back_color(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fblkg_blk_description(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_BLK_DESCRIPTION,val)
#define d2fblkg_client_info(ctx,obj,val) \
           d2fblkgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fblkg_comment(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fblkg_db_blk(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_DB_BLK,val)
#define d2fblkg_del_allowed(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_DEL_ALLOWED,val)
#define d2fblkg_del_dat_src_arg(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_DEL_DAT_SRC_ARG,val)
#define d2fblkg_del_dat_src_col(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_DEL_DAT_SRC_COL,val)
#define d2fblkg_del_proc_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_DEL_PROC_NAM,val)
#define d2fblkg_dml_ary_siz(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_DML_ARY_SIZ,val)
#define d2fblkg_dml_dat_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_DML_DAT_NAM,val)
#define d2fblkg_dml_dat_typ(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_DML_DAT_TYP,val)
#define d2fblkg_dml_ret_val(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_DML_RET_VAL,val)
#define d2fblkg_enfrc_col_security(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_ENFRC_COL_SECURITY,val)
#define d2fblkg_enfrc_prmry_key(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_ENFRC_PRMRY_KEY,val)
#define d2fblkg_fill_pat(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fblkg_font_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fblkg_font_siz(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fblkg_font_spcing(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fblkg_font_sty(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fblkg_font_wght(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fblkg_fore_color(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fblkg_include_refitem(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_INCLUDE_REFITEM,val)
#define d2fblkg_ins_dat_src_arg(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_INS_DAT_SRC_ARG,val)
#define d2fblkg_ins_dat_src_col(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_INS_DAT_SRC_COL,val)
#define d2fblkg_insrt_allowed(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_INSRT_ALLOWED,val)
#define d2fblkg_insrt_proc_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_INSRT_PROC_NAM,val)
#define d2fblkg_item(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_ITEM,val)
#define d2fblkg_key_mode(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_KEY_MODE,val)
#define d2fblkg_lang_dir(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fblkg_lock_dat_src_arg(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_LOCK_DAT_SRC_ARG,val)
#define d2fblkg_lock_dat_src_col(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_LOCK_DAT_SRC_COL,val)
#define d2fblkg_lock_mode(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_LOCK_MODE,val)
#define d2fblkg_lock_proc_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_LOCK_PROC_NAM,val)
#define d2fblkg_lst_in_blk_mnu(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_LST_IN_BLK_MNU,val)
#define d2fblkg_max_qry_time(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_MAX_QRY_TIME,val)
#define d2fblkg_max_recs_fetched(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_MAX_RECS_FETCHED,val)
#define d2fblkg_module(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fblkg_name(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fblkg_navigation_sty(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_NAVIGATION_STY,val)
#define d2fblkg_next(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fblkg_nxt_navigation_blk_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_NXT_NAVIGATION_BLK_NAM,val)
#define d2fblkg_nxt_navigation_blk_obj(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_NXT_NAVIGATION_BLK_OBJ,val)
#define d2fblkg_opt_hint(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_OPT_HINT,val)
#define d2fblkg_ordr_by_clause(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_ORDR_BY_CLAUSE,val)
#define d2fblkg_owner(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fblkg_par_flnam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fblkg_par_flpath(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fblkg_par_modstr(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fblkg_par_modtyp(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fblkg_par_module(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fblkg_par_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fblkg_par_typ(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fblkg_persist_client_info(ctx,obj,val) \
           d2fblkgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fblkg_persist_clt_inf_len(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fblkg_precomp_summ(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_PRECOMP_SUMM,val)
#define d2fblkg_prev_navigation_blk_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_PREV_NAVIGATION_BLK_NAM,val)
#define d2fblkg_prev_navigation_blk_obj(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_PREV_NAVIGATION_BLK_OBJ,val)
#define d2fblkg_previous(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fblkg_qry_all_recs(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_QRY_ALL_RECS,val)
#define d2fblkg_qry_allowed(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_QRY_ALLOWED,val)
#define d2fblkg_qry_dat_src_arg(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_QRY_DAT_SRC_ARG,val)
#define d2fblkg_qry_dat_src_col(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_QRY_DAT_SRC_COL,val)
#define d2fblkg_qry_dat_src_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_QRY_DAT_SRC_NAM,val)
#define d2fblkg_qry_dat_src_typ(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_QRY_DAT_SRC_TYP,val)
#define d2fblkg_rec_ornt(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_REC_ORNT,val)
#define d2fblkg_rec_vat_grp_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_REC_VAT_GRP_NAM,val)
#define d2fblkg_rec_vat_grp_obj(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_REC_VAT_GRP_OBJ,val)
#define d2fblkg_recs_buffered_count(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_RECS_BUFFERED_COUNT,val)
#define d2fblkg_recs_disp_count(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_RECS_DISP_COUNT,val)
#define d2fblkg_recs_fetched_count(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_RECS_FETCHED_COUNT,val)
#define d2fblkg_rel(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_REL,val)
#define d2fblkg_rev_dir(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_REV_DIR,val)
#define d2fblkg_scrlbr_cnv_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_SCRLBR_CNV_NAM,val)
#define d2fblkg_scrlbr_cnv_obj(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_SCRLBR_CNV_OBJ,val)
#define d2fblkg_scrlbr_len(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_SCRLBR_LEN,val)
#define d2fblkg_scrlbr_ornt(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_SCRLBR_ORNT,val)
#define d2fblkg_scrlbr_tbp_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_SCRLBR_TBP_NAM,val)
#define d2fblkg_scrlbr_tbp_obj(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_SCRLBR_TBP_OBJ,val)
#define d2fblkg_scrlbr_wid(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_SCRLBR_WID,val)
#define d2fblkg_scrlbr_x_pos(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_SCRLBR_X_POS,val)
#define d2fblkg_scrlbr_y_pos(ctx,obj,val) \
           d2fblkgn_GetNumProp(ctx,obj,D2FP_SCRLBR_Y_POS,val)
#define d2fblkg_show_scrlbr(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_SHOW_SCRLBR,val)
#define d2fblkg_sngl_rec(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_SNGL_REC,val)
#define d2fblkg_source(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2fblkg_trigger(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_TRIGGER,val)
#define d2fblkg_upd_dat_src_arg(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_UPD_DAT_SRC_ARG,val)
#define d2fblkg_upd_dat_src_col(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_UPD_DAT_SRC_COL,val)
#define d2fblkg_updt_allowed(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_UPDT_ALLOWED,val)
#define d2fblkg_updt_changed_cols(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_UPDT_CHANGED_COLS,val)
#define d2fblkg_updt_proc_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_UPDT_PROC_NAM,val)
#define d2fblkg_vat_nam(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fblkg_vat_obj(ctx,obj,val) \
           d2fblkgo_GetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fblkg_where_clause(ctx,obj,val) \
           d2fblkgt_GetTextProp(ctx,obj,D2FP_WHERE_CLAUSE,val)
#define d2fblkg_white_on_black(ctx,obj,val) \
           d2fblkgb_GetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)

#define d2fblks_alias(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_ALIAS,val)
#define d2fblks_back_color(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fblks_blk_description(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_BLK_DESCRIPTION,val)
#define d2fblks_client_info(ctx,obj,val) \
           d2fblksp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fblks_comment(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fblks_db_blk(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_DB_BLK,val)
#define d2fblks_del_allowed(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_DEL_ALLOWED,val)
#define d2fblks_del_proc_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_DEL_PROC_NAM,val)
#define d2fblks_dml_ary_siz(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_DML_ARY_SIZ,val)
#define d2fblks_dml_dat_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_DML_DAT_NAM,val)
#define d2fblks_dml_dat_typ(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_DML_DAT_TYP,val)
#define d2fblks_dml_ret_val(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_DML_RET_VAL,val)
#define d2fblks_enfrc_col_security(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_ENFRC_COL_SECURITY,val)
#define d2fblks_enfrc_prmry_key(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_ENFRC_PRMRY_KEY,val)
#define d2fblks_fill_pat(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fblks_font_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fblks_font_siz(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fblks_font_spcing(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fblks_font_sty(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fblks_font_wght(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fblks_fore_color(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fblks_include_refitem(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_INCLUDE_REFITEM,val)
#define d2fblks_insrt_allowed(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_INSRT_ALLOWED,val)
#define d2fblks_insrt_proc_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_INSRT_PROC_NAM,val)
#define d2fblks_key_mode(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_KEY_MODE,val)
#define d2fblks_lang_dir(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fblks_lock_mode(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_LOCK_MODE,val)
#define d2fblks_lock_proc_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_LOCK_PROC_NAM,val)
#define d2fblks_lst_in_blk_mnu(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_LST_IN_BLK_MNU,val)
#define d2fblks_max_qry_time(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_MAX_QRY_TIME,val)
#define d2fblks_max_recs_fetched(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_MAX_RECS_FETCHED,val)
#define d2fblks_name(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fblks_navigation_sty(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_NAVIGATION_STY,val)
#define d2fblks_nxt_navigation_blk_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_NXT_NAVIGATION_BLK_NAM,val)
#define d2fblks_nxt_navigation_blk_obj(ctx,obj,val) \
           d2fblkso_SetObjProp(ctx,obj,D2FP_NXT_NAVIGATION_BLK_OBJ,val)
#define d2fblks_opt_hint(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_OPT_HINT,val)
#define d2fblks_ordr_by_clause(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_ORDR_BY_CLAUSE,val)
#define d2fblks_par_flnam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fblks_par_flpath(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fblks_par_modstr(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fblks_par_modtyp(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fblks_par_module(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fblks_par_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fblks_par_typ(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fblks_persist_client_info(ctx,obj,val) \
           d2fblksp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fblks_persist_clt_inf_len(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fblks_precomp_summ(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_PRECOMP_SUMM,val)
#define d2fblks_prev_navigation_blk_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_PREV_NAVIGATION_BLK_NAM,val)
#define d2fblks_prev_navigation_blk_obj(ctx,obj,val) \
           d2fblkso_SetObjProp(ctx,obj,D2FP_PREV_NAVIGATION_BLK_OBJ,val)
#define d2fblks_qry_all_recs(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_QRY_ALL_RECS,val)
#define d2fblks_qry_allowed(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_QRY_ALLOWED,val)
#define d2fblks_qry_dat_src_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_QRY_DAT_SRC_NAM,val)
#define d2fblks_qry_dat_src_typ(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_QRY_DAT_SRC_TYP,val)
#define d2fblks_rec_ornt(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_REC_ORNT,val)
#define d2fblks_rec_vat_grp_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_REC_VAT_GRP_NAM,val)
#define d2fblks_rec_vat_grp_obj(ctx,obj,val) \
           d2fblkso_SetObjProp(ctx,obj,D2FP_REC_VAT_GRP_OBJ,val)
#define d2fblks_recs_buffered_count(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_RECS_BUFFERED_COUNT,val)
#define d2fblks_recs_disp_count(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_RECS_DISP_COUNT,val)
#define d2fblks_recs_fetched_count(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_RECS_FETCHED_COUNT,val)
#define d2fblks_rev_dir(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_REV_DIR,val)
#define d2fblks_scrlbr_cnv_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_SCRLBR_CNV_NAM,val)
#define d2fblks_scrlbr_cnv_obj(ctx,obj,val) \
           d2fblkso_SetObjProp(ctx,obj,D2FP_SCRLBR_CNV_OBJ,val)
#define d2fblks_scrlbr_len(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_SCRLBR_LEN,val)
#define d2fblks_scrlbr_ornt(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_SCRLBR_ORNT,val)
#define d2fblks_scrlbr_tbp_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_SCRLBR_TBP_NAM,val)
#define d2fblks_scrlbr_tbp_obj(ctx,obj,val) \
           d2fblkso_SetObjProp(ctx,obj,D2FP_SCRLBR_TBP_OBJ,val)
#define d2fblks_scrlbr_wid(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_SCRLBR_WID,val)
#define d2fblks_scrlbr_x_pos(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_SCRLBR_X_POS,val)
#define d2fblks_scrlbr_y_pos(ctx,obj,val) \
           d2fblksn_SetNumProp(ctx,obj,D2FP_SCRLBR_Y_POS,val)
#define d2fblks_show_scrlbr(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_SHOW_SCRLBR,val)
#define d2fblks_sngl_rec(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_SNGL_REC,val)
#define d2fblks_updt_allowed(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_UPDT_ALLOWED,val)
#define d2fblks_updt_changed_cols(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_UPDT_CHANGED_COLS,val)
#define d2fblks_updt_proc_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_UPDT_PROC_NAM,val)
#define d2fblks_vat_nam(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fblks_vat_obj(ctx,obj,val) \
           d2fblkso_SetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fblks_where_clause(ctx,obj,val) \
           d2fblkst_SetTextProp(ctx,obj,D2FP_WHERE_CLAUSE,val)
#define d2fblks_white_on_black(ctx,obj,val) \
           d2fblksb_SetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FBLK */




/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FLOV.H -- Dev2K Forms API LOV (list of values) declarations

   DESCRIPTION
    Contains the public declarations for the Forms API LOV object

   PUBLIC FUNCTIONS
    d2flovcr_Create          - Cover for d2fobcr_Create
    d2flovde_Destroy         - Cover for d2fobde_Destroy
    d2flovdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2flovsc_Subclass        - Cover for d2fobsc_Subclass
    d2flovg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2flovs?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2flovhp_HasProp         - Cover for d2fobhp_HasProp
    d2flovip_InheritProp     - Cover for d2fobip_InheritProp
    d2flovii_IspropInherited - Cover for d2fobii_IspropInherited
    d2flovid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2flovis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FLOV
#define D2FLOV

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
** Object: LOV
**  
*/
ORA_RETTYPE(d2fstatus) d2flovcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2flov **ppd2flov, text *name );
ORA_RETTYPE(d2fstatus) d2flovde_Destroy( d2fctx *pd2fctx, d2flov *pd2flov );
ORA_RETTYPE(d2fstatus) d2flovdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2flov *pd2flov_src,
                                           d2flov **ppd2flov_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2flovsc_SubClass( d2fctx *pd2fctx, d2flov *pd2flov,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2flovgb_GetBoolProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2flovgn_GetNumProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2flovgt_GetTextProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2flovgo_GetObjProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2flovgp_GetBlobProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2flovsb_SetBoolProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2flovsn_SetNumProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2flovst_SetTextProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2flovso_SetObjProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2flovsp_SetBlobProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2flovhp_HasProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2flovip_InheritProp( d2fctx *pd2fctx, d2flov *pd2flov,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2flovii_IspropInherited( d2fctx *pd2fctx,
                                                 d2flov *pd2flov, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2flovid_IspropDefault( d2fctx *pd2fctx,
                                               d2flov *pd2flov, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2flovis_IsSubclassed( d2fctx *pd2fctx,
                                              d2flov *pd2flov);


/* Begin convenience macros  */
#define d2flovg_auto_col_wid(ctx,obj,val) \
           d2flovgb_GetBoolProp(ctx,obj,D2FP_AUTO_COL_WID,val)
#define d2flovg_auto_disp(ctx,obj,val) \
           d2flovgb_GetBoolProp(ctx,obj,D2FP_AUTO_DISP,val)
#define d2flovg_auto_pos(ctx,obj,val) \
           d2flovgb_GetBoolProp(ctx,obj,D2FP_AUTO_POS,val)
#define d2flovg_auto_rfrsh(ctx,obj,val) \
           d2flovgb_GetBoolProp(ctx,obj,D2FP_AUTO_RFRSH,val)
#define d2flovg_auto_skp(ctx,obj,val) \
           d2flovgb_GetBoolProp(ctx,obj,D2FP_AUTO_SKP,val)
#define d2flovg_auto_slct(ctx,obj,val) \
           d2flovgb_GetBoolProp(ctx,obj,D2FP_AUTO_SLCT,val)
#define d2flovg_back_color(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2flovg_client_info(ctx,obj,val) \
           d2flovgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2flovg_col_map(ctx,obj,val) \
           d2flovgo_GetObjProp(ctx,obj,D2FP_COL_MAP,val)
#define d2flovg_comment(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2flovg_fill_pat(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2flovg_fltr_before_disp(ctx,obj,val) \
           d2flovgb_GetBoolProp(ctx,obj,D2FP_FLTR_BEFORE_DISP,val)
#define d2flovg_font_nam(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2flovg_font_siz(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2flovg_font_spcing(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2flovg_font_sty(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2flovg_font_wght(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2flovg_fore_color(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2flovg_height(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2flovg_lang_dir(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2flovg_lst_typ(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_LST_TYP,val)
#define d2flovg_module(ctx,obj,val) \
           d2flovgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2flovg_name(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2flovg_next(ctx,obj,val) \
           d2flovgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2flovg_old_lov_txt(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_OLD_LOV_TXT,val)
#define d2flovg_owner(ctx,obj,val) \
           d2flovgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2flovg_par_flnam(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2flovg_par_flpath(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2flovg_par_modstr(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2flovg_par_modtyp(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2flovg_par_module(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2flovg_par_nam(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2flovg_par_typ(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2flovg_persist_client_info(ctx,obj,val) \
           d2flovgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2flovg_persist_clt_inf_len(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2flovg_previous(ctx,obj,val) \
           d2flovgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2flovg_rec_grp_nam(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_REC_GRP_NAM,val)
#define d2flovg_rec_grp_obj(ctx,obj,val) \
           d2flovgo_GetObjProp(ctx,obj,D2FP_REC_GRP_OBJ,val)
#define d2flovg_source(ctx,obj,val) \
           d2flovgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2flovg_title(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2flovg_vat_nam(ctx,obj,val) \
           d2flovgt_GetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2flovg_vat_obj(ctx,obj,val) \
           d2flovgo_GetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2flovg_white_on_black(ctx,obj,val) \
           d2flovgb_GetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2flovg_width(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2flovg_x_pos(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2flovg_y_pos(ctx,obj,val) \
           d2flovgn_GetNumProp(ctx,obj,D2FP_Y_POS,val)

#define d2flovs_auto_col_wid(ctx,obj,val) \
           d2flovsb_SetBoolProp(ctx,obj,D2FP_AUTO_COL_WID,val)
#define d2flovs_auto_disp(ctx,obj,val) \
           d2flovsb_SetBoolProp(ctx,obj,D2FP_AUTO_DISP,val)
#define d2flovs_auto_pos(ctx,obj,val) \
           d2flovsb_SetBoolProp(ctx,obj,D2FP_AUTO_POS,val)
#define d2flovs_auto_rfrsh(ctx,obj,val) \
           d2flovsb_SetBoolProp(ctx,obj,D2FP_AUTO_RFRSH,val)
#define d2flovs_auto_skp(ctx,obj,val) \
           d2flovsb_SetBoolProp(ctx,obj,D2FP_AUTO_SKP,val)
#define d2flovs_auto_slct(ctx,obj,val) \
           d2flovsb_SetBoolProp(ctx,obj,D2FP_AUTO_SLCT,val)
#define d2flovs_back_color(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2flovs_client_info(ctx,obj,val) \
           d2flovsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2flovs_comment(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2flovs_fill_pat(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2flovs_fltr_before_disp(ctx,obj,val) \
           d2flovsb_SetBoolProp(ctx,obj,D2FP_FLTR_BEFORE_DISP,val)
#define d2flovs_font_nam(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2flovs_font_siz(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2flovs_font_spcing(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2flovs_font_sty(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2flovs_font_wght(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2flovs_fore_color(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2flovs_height(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2flovs_lang_dir(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2flovs_lst_typ(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_LST_TYP,val)
#define d2flovs_name(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2flovs_old_lov_txt(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_OLD_LOV_TXT,val)
#define d2flovs_par_flnam(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2flovs_par_flpath(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2flovs_par_modstr(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2flovs_par_modtyp(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2flovs_par_module(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2flovs_par_nam(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2flovs_par_typ(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2flovs_persist_client_info(ctx,obj,val) \
           d2flovsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2flovs_persist_clt_inf_len(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2flovs_rec_grp_nam(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_REC_GRP_NAM,val)
#define d2flovs_rec_grp_obj(ctx,obj,val) \
           d2flovso_SetObjProp(ctx,obj,D2FP_REC_GRP_OBJ,val)
#define d2flovs_title(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2flovs_vat_nam(ctx,obj,val) \
           d2flovst_SetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2flovs_vat_obj(ctx,obj,val) \
           d2flovso_SetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2flovs_white_on_black(ctx,obj,val) \
           d2flovsb_SetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2flovs_width(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2flovs_x_pos(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2flovs_y_pos(ctx,obj,val) \
           d2flovsn_SetNumProp(ctx,obj,D2FP_Y_POS,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
               
#endif /* D2FLOV */

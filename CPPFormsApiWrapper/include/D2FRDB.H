/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FRDB.H -- Dev2K Forms API RaDio Button declarations

   DESCRIPTION
    Contains the public declarations for the Forms API radio button object

   PUBLIC FUNCTIONS
    d2frdbcr_Create          - Cover for d2fobcr_Create
    d2frdbde_Destroy         - Cover for d2fobde_Destroy
    d2frdbdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2frdbsc_Subclass        - Cover for d2fobsc_Subclass
    d2frdbg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2frdbs?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2frdbhp_HasProp         - Cover for d2fobhp_HasProp
    d2frdbip_InheritProp     - Cover for d2fobip_InheritProp
    d2frdbii_IspropInherited - Cover for d2fobii_IspropInherited
    d2frdbid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2frdbis_IsSubclassed    - Cover for d2fobis_IsSubclassed

*/

#ifndef D2FRDB
#define D2FRDB

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
** Object: Radio Button
**  
*/
ORA_RETTYPE(d2fstatus) d2frdbcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2frdb **ppd2frdb, text *name  );
ORA_RETTYPE(d2fstatus) d2frdbde_Destroy( d2fctx *pd2fctx, d2frdb *pd2frdb );
ORA_RETTYPE(d2fstatus) d2frdbdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2frdb *pd2frdb_src,
                                           d2frdb **ppd2frdb_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2frdbsc_SubClass( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2frdbgb_GetBoolProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2frdbgn_GetNumProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2frdbgt_GetTextProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2frdbgo_GetObjProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2frdbgp_GetBlobProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
					    ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2frdbsb_SetBoolProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2frdbsn_SetNumProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2frdbst_SetTextProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2frdbso_SetObjProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2frdbsp_SetBlobProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                             ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2frdbhp_HasProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frdbip_InheritProp( d2fctx *pd2fctx, d2frdb *pd2frdb,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frdbii_IspropInherited( d2fctx *pd2fctx,
                                                 d2frdb *pd2frdb, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frdbid_IspropDefault( d2fctx *pd2fctx,
                                               d2frdb *pd2frdb, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2frdbis_IsSubclassed( d2fctx *pd2fctx,
                                              d2frdb *pd2frdb);


/* Begin convenience macros  */
#define d2frdbg_access_key(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_ACCESS_KEY,val)
#define d2frdbg_back_color(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2frdbg_client_info(ctx,obj,val) \
           d2frdbgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2frdbg_comment(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2frdbg_dist_btwn_recs(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_DIST_BTWN_RECS,val)
#define d2frdbg_enabled(ctx,obj,val) \
           d2frdbgb_GetBoolProp(ctx,obj,D2FP_ENABLED,val)
#define d2frdbg_fill_pat(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2frdbg_font_nam(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2frdbg_font_siz(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2frdbg_font_spcing(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2frdbg_font_sty(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2frdbg_font_wght(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2frdbg_fore_color(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2frdbg_height(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2frdbg_label(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2frdbg_module(ctx,obj,val) \
           d2frdbgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2frdbg_name(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2frdbg_next(ctx,obj,val) \
           d2frdbgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2frdbg_owner(ctx,obj,val) \
           d2frdbgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2frdbg_par_flnam(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2frdbg_par_flpath(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2frdbg_par_modstr(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2frdbg_par_modtyp(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2frdbg_par_module(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2frdbg_par_nam(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2frdbg_par_sl1obj_nam(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PAR_SL1OBJ_NAM,val)
#define d2frdbg_par_sl1obj_typ(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PAR_SL1OBJ_TYP,val)
#define d2frdbg_par_sl2obj_nam(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PAR_SL2OBJ_NAM,val)
#define d2frdbg_par_sl2obj_typ(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PAR_SL2OBJ_TYP,val)
#define d2frdbg_par_typ(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2frdbg_persist_client_info(ctx,obj,val) \
           d2frdbgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2frdbg_persist_clt_inf_len(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2frdbg_previous(ctx,obj,val) \
           d2frdbgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2frdbg_prmpt(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PRMPT,val)
#define d2frdbg_prmpt_align(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PRMPT_ALIGN,val)
#define d2frdbg_prmpt_align_ofst(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PRMPT_ALIGN_OFST,val)
#define d2frdbg_prmpt_att_edge(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PRMPT_ATT_EDGE,val)
#define d2frdbg_prmpt_att_ofst(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PRMPT_ATT_OFST,val)
#define d2frdbg_prmpt_back_color(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PRMPT_BACK_COLOR,val)
#define d2frdbg_prmpt_disp_sty(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PRMPT_DISP_STY,val)
#define d2frdbg_prmpt_fill_pat(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PRMPT_FILL_PAT,val)
#define d2frdbg_prmpt_font_nam(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PRMPT_FONT_NAM,val)
#define d2frdbg_prmpt_font_siz(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_SIZ,val)
#define d2frdbg_prmpt_font_spcing(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_SPCING,val)
#define d2frdbg_prmpt_font_sty(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_STY,val)
#define d2frdbg_prmpt_font_wght(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_WGHT,val)
#define d2frdbg_prmpt_fore_color(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PRMPT_FORE_COLOR,val)
#define d2frdbg_prmpt_jst(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PRMPT_JST,val)
#define d2frdbg_prmpt_reading_ordr(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_PRMPT_READING_ORDR,val)
#define d2frdbg_prmpt_vat_nam(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_PRMPT_VAT_NAM,val)
#define d2frdbg_prmpt_vat_obj(ctx,obj,val) \
           d2frdbgo_GetObjProp(ctx,obj,D2FP_PRMPT_VAT_OBJ,val)
#define d2frdbg_rdb_val(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_RDB_VAL,val)
#define d2frdbg_source(ctx,obj,val) \
           d2frdbgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2frdbg_vat_nam(ctx,obj,val) \
           d2frdbgt_GetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2frdbg_vat_obj(ctx,obj,val) \
           d2frdbgo_GetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2frdbg_visible(ctx,obj,val) \
           d2frdbgb_GetBoolProp(ctx,obj,D2FP_VISIBLE,val)
#define d2frdbg_white_on_black(ctx,obj,val) \
           d2frdbgb_GetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2frdbg_width(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2frdbg_x_pos(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2frdbg_y_pos(ctx,obj,val) \
           d2frdbgn_GetNumProp(ctx,obj,D2FP_Y_POS,val)

#define d2frdbs_access_key(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_ACCESS_KEY,val)
#define d2frdbs_back_color(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2frdbs_client_info(ctx,obj,val) \
           d2frdbsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2frdbs_comment(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2frdbs_dist_btwn_recs(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_DIST_BTWN_RECS,val)
#define d2frdbs_enabled(ctx,obj,val) \
           d2frdbsb_SetBoolProp(ctx,obj,D2FP_ENABLED,val)
#define d2frdbs_fill_pat(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2frdbs_font_nam(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2frdbs_font_siz(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2frdbs_font_spcing(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2frdbs_font_sty(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2frdbs_font_wght(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2frdbs_fore_color(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2frdbs_height(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2frdbs_label(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2frdbs_name(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2frdbs_par_flnam(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2frdbs_par_flpath(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2frdbs_par_modstr(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2frdbs_par_modtyp(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2frdbs_par_module(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2frdbs_par_nam(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2frdbs_par_sl1obj_nam(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PAR_SL1OBJ_NAM,val)
#define d2frdbs_par_sl1obj_typ(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PAR_SL1OBJ_TYP,val)
#define d2frdbs_par_sl2obj_nam(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PAR_SL2OBJ_NAM,val)
#define d2frdbs_par_sl2obj_typ(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PAR_SL2OBJ_TYP,val)
#define d2frdbs_par_typ(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2frdbs_persist_client_info(ctx,obj,val) \
           d2frdbsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2frdbs_persist_clt_inf_len(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2frdbs_prmpt(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PRMPT,val)
#define d2frdbs_prmpt_align(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PRMPT_ALIGN,val)
#define d2frdbs_prmpt_align_ofst(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PRMPT_ALIGN_OFST,val)
#define d2frdbs_prmpt_att_edge(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PRMPT_ATT_EDGE,val)
#define d2frdbs_prmpt_att_ofst(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PRMPT_ATT_OFST,val)
#define d2frdbs_prmpt_back_color(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PRMPT_BACK_COLOR,val)
#define d2frdbs_prmpt_disp_sty(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PRMPT_DISP_STY,val)
#define d2frdbs_prmpt_fill_pat(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PRMPT_FILL_PAT,val)
#define d2frdbs_prmpt_font_nam(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PRMPT_FONT_NAM,val)
#define d2frdbs_prmpt_font_siz(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_SIZ,val)
#define d2frdbs_prmpt_font_spcing(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_SPCING,val)
#define d2frdbs_prmpt_font_sty(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_STY,val)
#define d2frdbs_prmpt_font_wght(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_WGHT,val)
#define d2frdbs_prmpt_fore_color(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PRMPT_FORE_COLOR,val)
#define d2frdbs_prmpt_jst(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PRMPT_JST,val)
#define d2frdbs_prmpt_reading_ordr(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_PRMPT_READING_ORDR,val)
#define d2frdbs_prmpt_vat_nam(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_PRMPT_VAT_NAM,val)
#define d2frdbs_prmpt_vat_obj(ctx,obj,val) \
           d2frdbso_SetObjProp(ctx,obj,D2FP_PRMPT_VAT_OBJ,val)
#define d2frdbs_rdb_val(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_RDB_VAL,val)
#define d2frdbs_vat_nam(ctx,obj,val) \
           d2frdbst_SetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2frdbs_vat_obj(ctx,obj,val) \
           d2frdbso_SetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2frdbs_visible(ctx,obj,val) \
           d2frdbsb_SetBoolProp(ctx,obj,D2FP_VISIBLE,val)
#define d2frdbs_white_on_black(ctx,obj,val) \
           d2frdbsb_SetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2frdbs_width(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2frdbs_x_pos(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2frdbs_y_pos(ctx,obj,val) \
           d2frdbsn_SetNumProp(ctx,obj,D2FP_Y_POS,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
               
#endif /* D2FRDB */





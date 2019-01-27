/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FALT.H -- Dev2K Forms API ALerT declarations

   DESCRIPTION
    Contains the public declarations for the Forms API ALerT object

   PUBLIC FUNCTIONS
    d2faltcr_Create          - Cover for d2fobcr_Create
    d2faltde_Destroy         - Cover for d2fobde_Destroy
    d2faltdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2faltsc_Subclass        - Cover for d2fobsc_Subclass
    d2faltg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2falts?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2falthp_HasProp         - Cover for d2fobhp_HasProp
    d2faltip_InheritProp     - Cover for d2fobip_InheritProp
    d2faltii_IspropInherited - Cover for d2fobii_IspropInherited
    d2faltid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2faltis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FALT
#define D2FALT

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
** Object: Alert Object
**  
*/
ORA_RETTYPE(d2fstatus) d2faltcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2falt **ppd2falt, text *name  );
ORA_RETTYPE(d2fstatus) d2faltde_Destroy( d2fctx *pd2fctx, d2falt *pd2falt );
ORA_RETTYPE(d2fstatus) d2faltdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2falt *pd2falt_src,
                                           d2falt **ppd2falt_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2faltsc_SubClass( d2fctx *pd2fctx, d2falt *pd2falt,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2faltgb_GetBoolProp( d2fctx *pd2fctx, d2falt *pd2falt,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2faltgn_GetNumProp( d2fctx *pd2fctx, d2falt *pd2falt,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2faltgt_GetTextProp( d2fctx *pd2fctx, d2falt *pd2falt,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2faltgo_GetObjProp( d2fctx *pd2fctx, d2falt *pd2falt,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2faltgp_GetBlobProp( d2fctx *pd2fctx, d2falt *pd2falt,
					    ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2faltsb_SetBoolProp( d2fctx *pd2fctx, d2falt *pd2falt,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2faltsn_SetNumProp( d2fctx *pd2fctx, d2falt *pd2falt,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2faltst_SetTextProp( d2fctx *pd2fctx, d2falt *pd2falt,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2faltso_SetObjProp( d2fctx *pd2fctx, d2falt *pd2falt,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2faltsp_SetBlobProp( d2fctx *pd2fctx, d2falt *pd2falt,
                                             ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2falthp_HasProp( d2fctx *pd2fctx, d2falt *pd2falt,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2faltip_InheritProp( d2fctx *pd2fctx, d2falt *pd2falt,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2faltii_IspropInherited( d2fctx *pd2fctx,
                                                 d2falt *pd2falt, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2faltid_IspropDefault( d2fctx *pd2fctx,
                                               d2falt *pd2falt, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2faltis_IsSubclassed( d2fctx *pd2fctx,
                                              d2falt *pd2falt);


/* Begin convenience macros  */
#define d2faltg_alt_msg(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_ALT_MSG,val)
#define d2faltg_alt_sty(ctx,obj,val) \
           d2faltgn_GetNumProp(ctx,obj,D2FP_ALT_STY,val)
#define d2faltg_back_color(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2faltg_btn_1_lbl(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_BTN_1_LBL,val)
#define d2faltg_btn_2_lbl(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_BTN_2_LBL,val)
#define d2faltg_btn_3_lbl(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_BTN_3_LBL,val)
#define d2faltg_client_info(ctx,obj,val) \
           d2faltgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2faltg_comment(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2faltg_dflt_alt_btn(ctx,obj,val) \
           d2faltgn_GetNumProp(ctx,obj,D2FP_DFLT_ALT_BTN,val)
#define d2faltg_fill_pat(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2faltg_font_nam(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2faltg_font_siz(ctx,obj,val) \
           d2faltgn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2faltg_font_spcing(ctx,obj,val) \
           d2faltgn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2faltg_font_sty(ctx,obj,val) \
           d2faltgn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2faltg_font_wght(ctx,obj,val) \
           d2faltgn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2faltg_fore_color(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2faltg_lang_dir(ctx,obj,val) \
           d2faltgn_GetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2faltg_module(ctx,obj,val) \
           d2faltgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2faltg_name(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2faltg_next(ctx,obj,val) \
           d2faltgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2faltg_owner(ctx,obj,val) \
           d2faltgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2faltg_par_flnam(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2faltg_par_flpath(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2faltg_par_modstr(ctx,obj,val) \
           d2faltgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2faltg_par_modtyp(ctx,obj,val) \
           d2faltgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2faltg_par_module(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2faltg_par_nam(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2faltg_par_typ(ctx,obj,val) \
           d2faltgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2faltg_persist_client_info(ctx,obj,val) \
           d2faltgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2faltg_persist_clt_inf_len(ctx,obj,val) \
           d2faltgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2faltg_previous(ctx,obj,val) \
           d2faltgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2faltg_source(ctx,obj,val) \
           d2faltgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2faltg_title(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2faltg_vat_nam(ctx,obj,val) \
           d2faltgt_GetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2faltg_vat_obj(ctx,obj,val) \
           d2faltgo_GetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2faltg_white_on_black(ctx,obj,val) \
           d2faltgb_GetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)

#define d2falts_alt_msg(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_ALT_MSG,val)
#define d2falts_alt_sty(ctx,obj,val) \
           d2faltsn_SetNumProp(ctx,obj,D2FP_ALT_STY,val)
#define d2falts_back_color(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2falts_btn_1_lbl(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_BTN_1_LBL,val)
#define d2falts_btn_2_lbl(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_BTN_2_LBL,val)
#define d2falts_btn_3_lbl(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_BTN_3_LBL,val)
#define d2falts_client_info(ctx,obj,val) \
           d2faltsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2falts_comment(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2falts_dflt_alt_btn(ctx,obj,val) \
           d2faltsn_SetNumProp(ctx,obj,D2FP_DFLT_ALT_BTN,val)
#define d2falts_fill_pat(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2falts_font_nam(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2falts_font_siz(ctx,obj,val) \
           d2faltsn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2falts_font_spcing(ctx,obj,val) \
           d2faltsn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2falts_font_sty(ctx,obj,val) \
           d2faltsn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2falts_font_wght(ctx,obj,val) \
           d2faltsn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2falts_fore_color(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2falts_lang_dir(ctx,obj,val) \
           d2faltsn_SetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2falts_name(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2falts_par_flnam(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2falts_par_flpath(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2falts_par_modstr(ctx,obj,val) \
           d2faltsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2falts_par_modtyp(ctx,obj,val) \
           d2faltsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2falts_par_module(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2falts_par_nam(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2falts_par_typ(ctx,obj,val) \
           d2faltsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2falts_persist_client_info(ctx,obj,val) \
           d2faltsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2falts_persist_clt_inf_len(ctx,obj,val) \
           d2faltsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2falts_title(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2falts_vat_nam(ctx,obj,val) \
           d2faltst_SetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2falts_vat_obj(ctx,obj,val) \
           d2faltso_SetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2falts_white_on_black(ctx,obj,val) \
           d2faltsb_SetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
/* End convenience macros  */


/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FALT */


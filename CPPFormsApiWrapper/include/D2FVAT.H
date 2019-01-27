/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FVAT.H -- Dev2K Forms API Visual ATtribute declarations

   DESCRIPTION
    Contains the public declarations for the Forms API visual attribute object

   PUBLIC FUNCTIONS
    d2fvatcr_Create          - Cover for d2fobcr_Create
    d2fvatde_Destroy         - Cover for d2fobde_Destroy
    d2fvatdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fvatsc_Subclass        - Cover for d2fobsc_Subclass
    d2fvatg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fvats?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fvathp_HasProp         - Cover for d2fobhp_HasProp
    d2fvatip_InheritProp     - Cover for d2fobip_InheritProp
    d2fvatii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fvatid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fvatis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FVAT
#define D2FVAT

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
** Object: Visual Attribute
**  
*/
ORA_RETTYPE(d2fstatus) d2fvatcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fvat **ppd2fvat, text *name  );
ORA_RETTYPE(d2fstatus) d2fvatde_Destroy( d2fctx *pd2fctx, d2fvat *pd2fvat );
ORA_RETTYPE(d2fstatus) d2fvatdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fvat *pd2fvat_src,
                                           d2fvat **ppd2fvat_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2fvatsc_SubClass( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fvatgb_GetBoolProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fvatgn_GetNumProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fvatgt_GetTextProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fvatgo_GetObjProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fvatgp_GetBlobProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fvatsb_SetBoolProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fvatsn_SetNumProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fvatst_SetTextProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fvatso_SetObjProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fvatsp_SetBlobProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fvathp_HasProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fvatip_InheritProp( d2fctx *pd2fctx, d2fvat *pd2fvat,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fvatii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fvat *pd2fvat, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fvatid_IspropDefault( d2fctx *pd2fctx,
                                               d2fvat *pd2fvat, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fvatis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fvat *pd2fvat);


/* Begin convenience macros  */
#define d2fvatg_back_color(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fvatg_client_info(ctx,obj,val) \
           d2fvatgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fvatg_comment(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fvatg_fill_pat(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fvatg_font_nam(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fvatg_font_siz(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fvatg_font_spcing(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fvatg_font_sty(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fvatg_font_wght(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fvatg_fore_color(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fvatg_module(ctx,obj,val) \
           d2fvatgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fvatg_name(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fvatg_next(ctx,obj,val) \
           d2fvatgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fvatg_owner(ctx,obj,val) \
           d2fvatgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fvatg_par_flnam(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fvatg_par_flpath(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fvatg_par_modstr(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fvatg_par_modtyp(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fvatg_par_module(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fvatg_par_nam(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fvatg_par_typ(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fvatg_persist_client_info(ctx,obj,val) \
           d2fvatgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fvatg_persist_clt_inf_len(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fvatg_previous(ctx,obj,val) \
           d2fvatgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fvatg_prmpt_back_color(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_PRMPT_BACK_COLOR,val)
#define d2fvatg_prmpt_fill_pat(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_PRMPT_FILL_PAT,val)
#define d2fvatg_prmpt_font_nam(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_PRMPT_FONT_NAM,val)
#define d2fvatg_prmpt_font_siz(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_SIZ,val)
#define d2fvatg_prmpt_font_spcing(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_SPCING,val)
#define d2fvatg_prmpt_font_sty(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_STY,val)
#define d2fvatg_prmpt_font_wght(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_WGHT,val)
#define d2fvatg_prmpt_fore_color(ctx,obj,val) \
           d2fvatgt_GetTextProp(ctx,obj,D2FP_PRMPT_FORE_COLOR,val)
#define d2fvatg_source(ctx,obj,val) \
           d2fvatgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2fvatg_vat_typ(ctx,obj,val) \
           d2fvatgn_GetNumProp(ctx,obj,D2FP_VAT_TYP,val)
#define d2fvatg_white_on_black(ctx,obj,val) \
           d2fvatgb_GetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)

#define d2fvats_back_color(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fvats_client_info(ctx,obj,val) \
           d2fvatsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fvats_comment(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fvats_fill_pat(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fvats_font_nam(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fvats_font_siz(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fvats_font_spcing(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fvats_font_sty(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fvats_font_wght(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fvats_fore_color(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fvats_name(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fvats_par_flnam(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fvats_par_flpath(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fvats_par_modstr(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fvats_par_modtyp(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fvats_par_module(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fvats_par_nam(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fvats_par_typ(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fvats_persist_client_info(ctx,obj,val) \
           d2fvatsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fvats_persist_clt_inf_len(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fvats_prmpt_back_color(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_PRMPT_BACK_COLOR,val)
#define d2fvats_prmpt_fill_pat(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_PRMPT_FILL_PAT,val)
#define d2fvats_prmpt_font_nam(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_PRMPT_FONT_NAM,val)
#define d2fvats_prmpt_font_siz(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_SIZ,val)
#define d2fvats_prmpt_font_spcing(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_SPCING,val)
#define d2fvats_prmpt_font_sty(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_STY,val)
#define d2fvats_prmpt_font_wght(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_WGHT,val)
#define d2fvats_prmpt_fore_color(ctx,obj,val) \
           d2fvatst_SetTextProp(ctx,obj,D2FP_PRMPT_FORE_COLOR,val)
#define d2fvats_vat_typ(ctx,obj,val) \
           d2fvatsn_SetNumProp(ctx,obj,D2FP_VAT_TYP,val)
#define d2fvats_white_on_black(ctx,obj,val) \
           d2fvatsb_SetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
               
#endif /* D2FVAT */

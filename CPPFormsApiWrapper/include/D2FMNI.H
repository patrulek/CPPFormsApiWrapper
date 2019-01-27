/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FMNI.H -- Dev2K Forms API MeNu Item declarations

   DESCRIPTION
    Contains the public declarations for the Forms API menu item object

   PUBLIC FUNCTIONS
    d2fmnicr_Create          - Cover for d2fobcr_Create
    d2fmnide_Destroy         - Cover for d2fobde_Destroy
    d2fmnidu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fmnisc_Subclass        - Cover for d2fobsc_Subclass
    d2fmnico_CompileObj      - Compile the PL/SQL code in the menu item
    d2fmniar_AddRole         - Insert a new menu role value by index
    d2fmnirr_RemoveRole      - Remove the specified menu role
    d2fmnigr_GetRole         - Get the value of a role specified by index
    d2fmnig?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fmnis?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fmnihp_HasProp         - Cover for d2fobhp_HasProp
    d2fmniip_InheritProp     - Cover for d2fobip_InheritProp
    d2fmniii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fmniid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fmniis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FMNI
#define D2FMNI

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
** Object: Menu Item 
**  
*/
ORA_RETTYPE(d2fstatus) d2fmnicr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fmni **ppd2fmni, text *name  );
ORA_RETTYPE(d2fstatus) d2fmnide_Destroy( d2fctx *pd2fctx, d2fmni *pd2fmni );
ORA_RETTYPE(d2fstatus) d2fmnidu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fmni *pd2fmni_src,
                                           d2fmni **ppd2fmni_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2fmnisc_SubClass( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fmnico_CompileObj( d2fctx *pd2fctx,
                                               d2fmni *pd2fmni );
ORA_RETTYPE(d2fstatus) d2fmniar_AddRole( d2fctx *pd2fctx,
                                         d2fmni *pd2fmni,
                                         number index,
                                         text *role_name );
ORA_RETTYPE(d2fstatus) d2fmnirr_RemoveRole( d2fctx *pd2fctx,
                                            d2fmni *pd2fmni,
                                            number index );
ORA_RETTYPE(d2fstatus) d2fmnigr_GetRole( d2fctx *pd2fctx,
                                         d2fmni *pd2fmni,
                                         number index,
                                         text **role_name);
ORA_RETTYPE(d2fstatus) d2fmnigb_GetBoolProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fmnign_GetNumProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fmnigt_GetTextProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fmnigo_GetObjProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fmnigp_GetBlobProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fmnisb_SetBoolProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fmnisn_SetNumProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fmnist_SetTextProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fmniso_SetObjProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fmnisp_SetBlobProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fmnihp_HasProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmniip_InheritProp( d2fctx *pd2fctx, d2fmni *pd2fmni,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmniii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fmni *pd2fmni, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmniid_IspropDefault( d2fctx *pd2fctx,
                                               d2fmni *pd2fmni, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fmniis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fmni *pd2fmni);


/* Begin convenience macros  */
#define d2fmnig_client_info(ctx,obj,val) \
           d2fmnigp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fmnig_com_txt(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_COM_TXT,val)
#define d2fmnig_com_typ(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_COM_TYP,val)
#define d2fmnig_comment(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fmnig_disp_no_priv(ctx,obj,val) \
           d2fmnigb_GetBoolProp(ctx,obj,D2FP_DISP_NO_PRIV,val)
#define d2fmnig_enabled(ctx,obj,val) \
           d2fmnigb_GetBoolProp(ctx,obj,D2FP_ENABLED,val)
#define d2fmnig_font_nam(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fmnig_font_siz(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fmnig_font_spcing(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fmnig_font_sty(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fmnig_font_wght(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fmnig_hint(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_HINT,val)
#define d2fmnig_hlp_description(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_HLP_DESCRIPTION,val)
#define d2fmnig_icon_flnam(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_ICON_FLNAM,val)
#define d2fmnig_icon_in_mnu(ctx,obj,val) \
           d2fmnigb_GetBoolProp(ctx,obj,D2FP_ICON_IN_MNU,val)
#define d2fmnig_kbrd_acc(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_KBRD_ACC,val)
#define d2fmnig_label(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2fmnig_magic_itm(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_MAGIC_ITM,val)
#define d2fmnig_mnu_itm_code(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_MNU_ITM_CODE,val)
#define d2fmnig_mnu_itm_rad_grp(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_MNU_ITM_RAD_GRP,val)
#define d2fmnig_mnu_itm_typ(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_MNU_ITM_TYP,val)
#define d2fmnig_module(ctx,obj,val) \
           d2fmnigo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fmnig_name(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fmnig_next(ctx,obj,val) \
           d2fmnigo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fmnig_owner(ctx,obj,val) \
           d2fmnigo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fmnig_par_flnam(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fmnig_par_flpath(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fmnig_par_modstr(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fmnig_par_modtyp(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fmnig_par_module(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fmnig_par_nam(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fmnig_par_sl1obj_nam(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_PAR_SL1OBJ_NAM,val)
#define d2fmnig_par_sl1obj_typ(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_PAR_SL1OBJ_TYP,val)
#define d2fmnig_par_typ(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fmnig_persist_client_info(ctx,obj,val) \
           d2fmnigp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fmnig_persist_clt_inf_len(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fmnig_previous(ctx,obj,val) \
           d2fmnigo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fmnig_role_count(ctx,obj,val) \
           d2fmnign_GetNumProp(ctx,obj,D2FP_ROLE_COUNT,val)
#define d2fmnig_source(ctx,obj,val) \
           d2fmnigo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2fmnig_sub_mnu_nam(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_SUB_MNU_NAM,val)
#define d2fmnig_sub_mnu_obj(ctx,obj,val) \
           d2fmnigo_GetObjProp(ctx,obj,D2FP_SUB_MNU_OBJ,val)
#define d2fmnig_vat_nam(ctx,obj,val) \
           d2fmnigt_GetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fmnig_vat_obj(ctx,obj,val) \
           d2fmnigo_GetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fmnig_visible(ctx,obj,val) \
           d2fmnigb_GetBoolProp(ctx,obj,D2FP_VISIBLE,val)
#define d2fmnig_vsbl_in_horz_mnu_tlbr(ctx,obj,val) \
           d2fmnigb_GetBoolProp(ctx,obj,D2FP_VSBL_IN_HORZ_MNU_TLBR,val)
#define d2fmnig_vsbl_in_menu(ctx,obj,val) \
           d2fmnigb_GetBoolProp(ctx,obj,D2FP_VSBL_IN_MENU,val)
#define d2fmnig_vsbl_in_vert_mnu_tlbr(ctx,obj,val) \
           d2fmnigb_GetBoolProp(ctx,obj,D2FP_VSBL_IN_VERT_MNU_TLBR,val)

#define d2fmnis_client_info(ctx,obj,val) \
           d2fmnisp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fmnis_com_txt(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_COM_TXT,val)
#define d2fmnis_com_typ(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_COM_TYP,val)
#define d2fmnis_comment(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fmnis_disp_no_priv(ctx,obj,val) \
           d2fmnisb_SetBoolProp(ctx,obj,D2FP_DISP_NO_PRIV,val)
#define d2fmnis_enabled(ctx,obj,val) \
           d2fmnisb_SetBoolProp(ctx,obj,D2FP_ENABLED,val)
#define d2fmnis_font_nam(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fmnis_font_siz(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fmnis_font_spcing(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fmnis_font_sty(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fmnis_font_wght(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fmnis_hint(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_HINT,val)
#define d2fmnis_hlp_description(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_HLP_DESCRIPTION,val)
#define d2fmnis_icon_flnam(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_ICON_FLNAM,val)
#define d2fmnis_icon_in_mnu(ctx,obj,val) \
           d2fmnisb_SetBoolProp(ctx,obj,D2FP_ICON_IN_MNU,val)
#define d2fmnis_kbrd_acc(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_KBRD_ACC,val)
#define d2fmnis_label(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2fmnis_magic_itm(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_MAGIC_ITM,val)
#define d2fmnis_mnu_itm_code(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_MNU_ITM_CODE,val)
#define d2fmnis_mnu_itm_rad_grp(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_MNU_ITM_RAD_GRP,val)
#define d2fmnis_mnu_itm_typ(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_MNU_ITM_TYP,val)
#define d2fmnis_name(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fmnis_par_flnam(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fmnis_par_flpath(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fmnis_par_modstr(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fmnis_par_modtyp(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fmnis_par_module(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fmnis_par_nam(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fmnis_par_sl1obj_nam(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_PAR_SL1OBJ_NAM,val)
#define d2fmnis_par_sl1obj_typ(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_PAR_SL1OBJ_TYP,val)
#define d2fmnis_par_typ(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fmnis_persist_client_info(ctx,obj,val) \
           d2fmnisp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fmnis_persist_clt_inf_len(ctx,obj,val) \
           d2fmnisn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fmnis_sub_mnu_nam(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_SUB_MNU_NAM,val)
#define d2fmnis_sub_mnu_obj(ctx,obj,val) \
           d2fmniso_SetObjProp(ctx,obj,D2FP_SUB_MNU_OBJ,val)
#define d2fmnis_vat_nam(ctx,obj,val) \
           d2fmnist_SetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fmnis_vat_obj(ctx,obj,val) \
           d2fmniso_SetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fmnis_visible(ctx,obj,val) \
           d2fmnisb_SetBoolProp(ctx,obj,D2FP_VISIBLE,val)
#define d2fmnis_vsbl_in_horz_mnu_tlbr(ctx,obj,val) \
           d2fmnisb_SetBoolProp(ctx,obj,D2FP_VSBL_IN_HORZ_MNU_TLBR,val)
#define d2fmnis_vsbl_in_menu(ctx,obj,val) \
           d2fmnisb_SetBoolProp(ctx,obj,D2FP_VSBL_IN_MENU,val)
#define d2fmnis_vsbl_in_vert_mnu_tlbr(ctx,obj,val) \
           d2fmnisb_SetBoolProp(ctx,obj,D2FP_VSBL_IN_VERT_MNU_TLBR,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
               
#endif /* D2FMNI */

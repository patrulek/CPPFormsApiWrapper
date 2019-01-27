/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FFMD.H -- Dev2K Forms API Form MoDule declarations

   DESCRIPTION
    Contains the public declarations for the Forms API Form MoDule object

   PUBLIC FUNCTIONS
    d2ffmdcr_Create          - Cover for d2fobcr_Create
    d2ffmdde_Destroy         - Cover for d2fobde_Destroy
    d2ffmddl_Delete          - Delete the module from the database
    d2ffmddu_Duplicate       - Cover for d2fobdu_Duplicate
    d2ffmdsc_Subclass        - Cover for d2fobsc_Subclass
    d2ffmdco_CompileObj      - Compile PL/SQL in the form module
    d2ffmdcf_CompileFile     - Compile the form module, creating an .fmx
    d2ffmdld_Load            - Load a form module into memory
    d2ffmdsv_Save            - Save a form module to disk
    d2ffmdfv_FileVersion     - Return the version number of the module
    d2ffmdg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2ffmds?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2ffmdhp_HasProp         - Cover for d2fobhp_HasProp
    d2ffmdip_InheritProp     - Cover for d2fobip_InheritProp
    d2ffmdii_IspropInherited - Cover for d2fobii_IspropInherited
    d2ffmdid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2ffmdis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FFMD
#define D2FFMD

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
** Object: Form Module
**  
*/
ORA_RETTYPE(d2fstatus) d2ffmdcr_Create( d2fctx *pd2fctx, d2ffmd **ppd2ffmd,  
                                        text *name );
ORA_RETTYPE(d2fstatus) d2ffmdde_Destroy( d2fctx *pd2fctx, d2ffmd *pd2ffmd );
ORA_RETTYPE(d2fstatus) d2ffmddl_Delete( d2fctx *pd2fctx, text *name,
                                        boolean db);
ORA_RETTYPE(d2fstatus) d2ffmddu_Duplicate( d2fctx *pd2fctx,
                                           d2ffmd *pd2ffmd_src,
                                           d2ffmd **ppd2ffmd_dst,
                                           text *new_name   );
ORA_RETTYPE(d2fstatus) d2ffmdsc_SubClass( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2ffmdco_CompileObj( d2fctx *pd2fctx,
                                               d2ffmd *pd2ffmd );
ORA_RETTYPE(d2fstatus) d2ffmdcf_CompileFile( d2fctx *pd2fctx,
                                             d2ffmd *pd2ffmd );
ORA_RETTYPE(d2fstatus) d2ffmdld_Load( d2fctx *pd2fctx, d2ffmd **ppd2ffmd,
                                      text *formname, boolean db);
ORA_RETTYPE(d2fstatus) d2ffmdsv_Save( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                      text *formname, boolean db);
ORA_RETTYPE(d2fstatus) d2ffmdfv_FileVersion( d2fctx *pd2fctx, text *formname,
                                             boolean db, number *version );
ORA_RETTYPE(d2fstatus) d2ffmdgb_GetBoolProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2ffmdgn_GetNumProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2ffmdgt_GetTextProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2ffmdgo_GetObjProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ffmdgp_GetBlobProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ffmdsb_SetBoolProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2ffmdsn_SetNumProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2ffmdst_SetTextProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2ffmdso_SetObjProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ffmdsp_SetBlobProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ffmdhp_HasProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ffmdip_InheritProp( d2fctx *pd2fctx, d2ffmd *pd2ffmd,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ffmdii_IspropInherited( d2fctx *pd2fctx,
                                                 d2ffmd *pd2ffmd, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ffmdid_IspropDefault( d2fctx *pd2fctx,
                                               d2ffmd *pd2ffmd, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2ffmdis_IsSubclassed( d2fctx *pd2fctx,
                                              d2ffmd *pd2ffmd);



/* Begin convenience macros  */
#define d2ffmdg_alert(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_ALERT,val)
#define d2ffmdg_att_lib(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_ATT_LIB,val)
#define d2ffmdg_block(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_BLOCK,val)
#define d2ffmdg_canvas(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_CANVAS,val)
#define d2ffmdg_client_info(ctx,obj,val) \
           d2ffmdgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2ffmdg_comment(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2ffmdg_console_win(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_CONSOLE_WIN,val)
#define d2ffmdg_crsr_mode(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_CRSR_MODE,val)
#define d2ffmdg_defer_req_enf(ctx,obj,val) \
           d2ffmdgb_GetBoolProp(ctx,obj,D2FP_DEFER_REQ_ENF,val)
#define d2ffmdg_editor(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_EDITOR,val)
#define d2ffmdg_form_param(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_FORM_PARAM,val)
#define d2ffmdg_frst_navigation_blk_nam(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_FRST_NAVIGATION_BLK_NAM,val)
#define d2ffmdg_frst_navigation_blk_obj(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_FRST_NAVIGATION_BLK_OBJ,val)
#define d2ffmdg_help_book_title(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_HELP_BOOK_TITLE,val)
#define d2ffmdg_horz_tlbr_cnv(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_HORZ_TLBR_CNV,val)
#define d2ffmdg_init_mnu(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_INIT_MNU,val)
#define d2ffmdg_interaction_mode(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_INTERACTION_MODE,val)
#define d2ffmdg_isolation_mode(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_ISOLATION_MODE,val)
#define d2ffmdg_lang_dir(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2ffmdg_lov(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_LOV,val)
#define d2ffmdg_max_qry_time(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_MAX_QRY_TIME,val)
#define d2ffmdg_max_recs_fetched(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_MAX_RECS_FETCHED,val)
#define d2ffmdg_menu(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_MENU,val)
#define d2ffmdg_mnu_mod(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_MNU_MOD,val)
#define d2ffmdg_mnu_role(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_MNU_ROLE,val)
#define d2ffmdg_mnu_src(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_MNU_SRC,val)
#define d2ffmdg_mnu_sty(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_MNU_STY,val)
#define d2ffmdg_mouse_navigation_lmt(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_MOUSE_NAVIGATION_LMT,val)
#define d2ffmdg_name(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2ffmdg_next(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2ffmdg_obj_grp(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_OBJ_GRP,val)
#define d2ffmdg_persist_client_info(ctx,obj,val) \
           d2ffmdgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2ffmdg_persist_clt_inf_len(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2ffmdg_previous(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2ffmdg_prog_unit(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_PROG_UNIT,val)
#define d2ffmdg_prop_class(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_PROP_CLASS,val)
#define d2ffmdg_rec_grp(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_REC_GRP,val)
#define d2ffmdg_rec_vat_grp_nam(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_REC_VAT_GRP_NAM,val)
#define d2ffmdg_rec_vat_grp_obj(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_REC_VAT_GRP_OBJ,val)
#define d2ffmdg_report(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_REPORT,val)
#define d2ffmdg_runtime_comp(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_RUNTIME_COMP,val)
#define d2ffmdg_svpnt_mode(ctx,obj,val) \
           d2ffmdgb_GetBoolProp(ctx,obj,D2FP_SVPNT_MODE,val)
#define d2ffmdg_title(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2ffmdg_trigger(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_TRIGGER,val)
#define d2ffmdg_use_3d_cntrls(ctx,obj,val) \
           d2ffmdgb_GetBoolProp(ctx,obj,D2FP_USE_3D_CNTRLS,val)
#define d2ffmdg_validation_unit(ctx,obj,val) \
           d2ffmdgn_GetNumProp(ctx,obj,D2FP_VALIDATION_UNIT,val)
#define d2ffmdg_vert_tlbr_cnv(ctx,obj,val) \
           d2ffmdgt_GetTextProp(ctx,obj,D2FP_VERT_TLBR_CNV,val)
#define d2ffmdg_vis_attr(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_VIS_ATTR,val)
#define d2ffmdg_window(ctx,obj,val) \
           d2ffmdgo_GetObjProp(ctx,obj,D2FP_WINDOW,val)

#define d2ffmds_client_info(ctx,obj,val) \
           d2ffmdsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2ffmds_comment(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2ffmds_console_win(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_CONSOLE_WIN,val)
#define d2ffmds_defer_req_enf(ctx,obj,val) \
           d2ffmdsb_SetBoolProp(ctx,obj,D2FP_DEFER_REQ_ENF,val)
#define d2ffmds_frst_navigation_blk_nam(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_FRST_NAVIGATION_BLK_NAM,val)
#define d2ffmds_frst_navigation_blk_obj(ctx,obj,val) \
           d2ffmdso_SetObjProp(ctx,obj,D2FP_FRST_NAVIGATION_BLK_OBJ,val)
#define d2ffmds_help_book_title(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_HELP_BOOK_TITLE,val)
#define d2ffmds_horz_tlbr_cnv(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_HORZ_TLBR_CNV,val)
#define d2ffmds_init_mnu(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_INIT_MNU,val)
#define d2ffmds_interaction_mode(ctx,obj,val) \
           d2ffmdsn_SetNumProp(ctx,obj,D2FP_INTERACTION_MODE,val)
#define d2ffmds_isolation_mode(ctx,obj,val) \
           d2ffmdsn_SetNumProp(ctx,obj,D2FP_ISOLATION_MODE,val)
#define d2ffmds_lang_dir(ctx,obj,val) \
           d2ffmdsn_SetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2ffmds_max_qry_time(ctx,obj,val) \
           d2ffmdsn_SetNumProp(ctx,obj,D2FP_MAX_QRY_TIME,val)
#define d2ffmds_max_recs_fetched(ctx,obj,val) \
           d2ffmdsn_SetNumProp(ctx,obj,D2FP_MAX_RECS_FETCHED,val)
#define d2ffmds_mnu_mod(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_MNU_MOD,val)
#define d2ffmds_mnu_role(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_MNU_ROLE,val)
#define d2ffmds_mnu_src(ctx,obj,val) \
           d2ffmdsn_SetNumProp(ctx,obj,D2FP_MNU_SRC,val)
#define d2ffmds_mnu_sty(ctx,obj,val) \
           d2ffmdsn_SetNumProp(ctx,obj,D2FP_MNU_STY,val)
#define d2ffmds_mouse_navigation_lmt(ctx,obj,val) \
           d2ffmdsn_SetNumProp(ctx,obj,D2FP_MOUSE_NAVIGATION_LMT,val)
#define d2ffmds_name(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2ffmds_persist_client_info(ctx,obj,val) \
           d2ffmdsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2ffmds_persist_clt_inf_len(ctx,obj,val) \
           d2ffmdsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2ffmds_rec_vat_grp_nam(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_REC_VAT_GRP_NAM,val)
#define d2ffmds_rec_vat_grp_obj(ctx,obj,val) \
           d2ffmdso_SetObjProp(ctx,obj,D2FP_REC_VAT_GRP_OBJ,val)
#define d2ffmds_runtime_comp(ctx,obj,val) \
           d2ffmdsn_SetNumProp(ctx,obj,D2FP_RUNTIME_COMP,val)
#define d2ffmds_title(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2ffmds_use_3d_cntrls(ctx,obj,val) \
           d2ffmdsb_SetBoolProp(ctx,obj,D2FP_USE_3D_CNTRLS,val)
#define d2ffmds_validation_unit(ctx,obj,val) \
           d2ffmdsn_SetNumProp(ctx,obj,D2FP_VALIDATION_UNIT,val)
#define d2ffmds_vert_tlbr_cnv(ctx,obj,val) \
           d2ffmdst_SetTextProp(ctx,obj,D2FP_VERT_TLBR_CNV,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

               
#endif /* D2FFMD */

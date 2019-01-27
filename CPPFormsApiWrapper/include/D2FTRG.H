/*
 * $Header: d2ftrg.h@@/main/TOOLS_DEV2K_994/4 \
 * Checked in on Thu Apr 27 08:42:14 PDT 2000 by vobadm \
 * Copyright (c) 2000 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 2000.  All Rights Reserved. */

/*
   NAME
    D2FTRG.H -- Dev2K Forms API TRiGger declarations

   DESCRIPTION
    Contains the public declarations for the Forms API trigger object

   PUBLIC FUNCTIONS
    d2ftrgcr_Create          - Cover for d2fobcr_Create
    d2ftrgde_Destroy         - Cover for d2fobde_Destroy
    d2ftrgdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2ftrgsc_Subclass        - Cover for d2fobsc_Subclass
    d2ftrgco_CompileObj      - Compile the object's PL/SQL code
    d2ftrgg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2ftrgs?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2ftrghp_HasProp         - Cover for d2fobhp_HasProp
    d2ftrgip_InheritProp     - Cover for d2fobip_InheritProp
    d2ftrgii_IspropInherited - Cover for d2fobii_IspropInherited
    d2ftrgid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2ftrgis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FTRG
#define D2FTRG

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
** Object: Trigger
**  
*/
ORA_RETTYPE(d2fstatus) d2ftrgcr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2ftrg **ppd2ftrg, text *name  );
ORA_RETTYPE(d2fstatus) d2ftrgde_Destroy( d2fctx *pd2fctx, d2ftrg *pd2ftrg );
ORA_RETTYPE(d2fstatus) d2ftrgdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2ftrg *pd2ftrg_src,
                                           d2ftrg **ppd2ftrg_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2ftrgsc_SubClass( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2ftrgco_CompileObj( d2fctx *pd2fctx,
                                               d2ftrg *pd2ftrg );
ORA_RETTYPE(d2fstatus) d2ftrggb_GetBoolProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2ftrggn_GetNumProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2ftrggt_GetTextProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2ftrggo_GetObjProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ftrggp_GetBlobProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2ftrgsb_SetBoolProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2ftrgsn_SetNumProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2ftrgst_SetTextProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2ftrgso_SetObjProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ftrgsp_SetBlobProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2ftrghp_HasProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ftrgip_InheritProp( d2fctx *pd2fctx, d2ftrg *pd2ftrg,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ftrgii_IspropInherited( d2fctx *pd2fctx,
                                                 d2ftrg *pd2ftrg, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2ftrgid_IspropDefault( d2fctx *pd2fctx,
                                               d2ftrg *pd2ftrg, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2ftrgis_IsSubclassed( d2fctx *pd2fctx,
                                              d2ftrg *pd2ftrg);


/* Begin convenience macros  */
#define d2ftrgg_client_info(ctx,obj,val) \
           d2ftrggp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2ftrgg_comment(ctx,obj,val) \
           d2ftrggt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2ftrgg_disp_in_kbrd_hlp(ctx,obj,val) \
           d2ftrggb_GetBoolProp(ctx,obj,D2FP_DISP_IN_KBRD_HLP,val)
#define d2ftrgg_exec_hierarchy(ctx,obj,val) \
           d2ftrggn_GetNumProp(ctx,obj,D2FP_EXEC_HIERARCHY,val)
#define d2ftrgg_fire_in_qry(ctx,obj,val) \
           d2ftrggb_GetBoolProp(ctx,obj,D2FP_FIRE_IN_QRY,val)
#define d2ftrgg_hide(ctx,obj,val) \
           d2ftrggb_GetBoolProp(ctx,obj,D2FP_HIDE,val)
#define d2ftrgg_kbrd_hlp_txt(ctx,obj,val) \
           d2ftrggt_GetTextProp(ctx,obj,D2FP_KBRD_HLP_TXT,val)
#define d2ftrgg_module(ctx,obj,val) \
           d2ftrggo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2ftrgg_name(ctx,obj,val) \
           d2ftrggt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2ftrgg_next(ctx,obj,val) \
           d2ftrggo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2ftrgg_owner(ctx,obj,val) \
           d2ftrggo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2ftrgg_par_flnam(ctx,obj,val) \
           d2ftrggt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2ftrgg_par_flpath(ctx,obj,val) \
           d2ftrggt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2ftrgg_par_modstr(ctx,obj,val) \
           d2ftrggn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2ftrgg_par_modtyp(ctx,obj,val) \
           d2ftrggn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2ftrgg_par_module(ctx,obj,val) \
           d2ftrggt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2ftrgg_par_nam(ctx,obj,val) \
           d2ftrggt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2ftrgg_par_sl1obj_nam(ctx,obj,val) \
           d2ftrggt_GetTextProp(ctx,obj,D2FP_PAR_SL1OBJ_NAM,val)
#define d2ftrgg_par_sl1obj_typ(ctx,obj,val) \
           d2ftrggn_GetNumProp(ctx,obj,D2FP_PAR_SL1OBJ_TYP,val)
#define d2ftrgg_par_sl2obj_nam(ctx,obj,val) \
           d2ftrggt_GetTextProp(ctx,obj,D2FP_PAR_SL2OBJ_NAM,val)
#define d2ftrgg_par_sl2obj_typ(ctx,obj,val) \
           d2ftrggn_GetNumProp(ctx,obj,D2FP_PAR_SL2OBJ_TYP,val)
#define d2ftrgg_par_typ(ctx,obj,val) \
           d2ftrggn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2ftrgg_persist_client_info(ctx,obj,val) \
           d2ftrggp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2ftrgg_persist_clt_inf_len(ctx,obj,val) \
           d2ftrggn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2ftrgg_previous(ctx,obj,val) \
           d2ftrggo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2ftrgg_source(ctx,obj,val) \
           d2ftrggo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2ftrgg_trg_internal_typ(ctx,obj,val) \
           d2ftrggn_GetNumProp(ctx,obj,D2FP_TRG_INTERNAL_TYP,val)
#define d2ftrgg_trg_sty(ctx,obj,val) \
           d2ftrggn_GetNumProp(ctx,obj,D2FP_TRG_STY,val)
#define d2ftrgg_trg_txt(ctx,obj,val) \
           d2ftrggt_GetTextProp(ctx,obj,D2FP_TRG_TXT,val)
#define d2ftrgg_trig_step(ctx,obj,val) \
           d2ftrggo_GetObjProp(ctx,obj,D2FP_TRIG_STEP,val)

#define d2ftrgs_client_info(ctx,obj,val) \
           d2ftrgsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2ftrgs_comment(ctx,obj,val) \
           d2ftrgst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2ftrgs_disp_in_kbrd_hlp(ctx,obj,val) \
           d2ftrgsb_SetBoolProp(ctx,obj,D2FP_DISP_IN_KBRD_HLP,val)
#define d2ftrgs_exec_hierarchy(ctx,obj,val) \
           d2ftrgsn_SetNumProp(ctx,obj,D2FP_EXEC_HIERARCHY,val)
#define d2ftrgs_fire_in_qry(ctx,obj,val) \
           d2ftrgsb_SetBoolProp(ctx,obj,D2FP_FIRE_IN_QRY,val)
#define d2ftrgs_hide(ctx,obj,val) \
           d2ftrgsb_SetBoolProp(ctx,obj,D2FP_HIDE,val)
#define d2ftrgs_kbrd_hlp_txt(ctx,obj,val) \
           d2ftrgst_SetTextProp(ctx,obj,D2FP_KBRD_HLP_TXT,val)
#define d2ftrgs_name(ctx,obj,val) \
           d2ftrgst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2ftrgs_par_flnam(ctx,obj,val) \
           d2ftrgst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2ftrgs_par_flpath(ctx,obj,val) \
           d2ftrgst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2ftrgs_par_modstr(ctx,obj,val) \
           d2ftrgsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2ftrgs_par_modtyp(ctx,obj,val) \
           d2ftrgsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2ftrgs_par_module(ctx,obj,val) \
           d2ftrgst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2ftrgs_par_nam(ctx,obj,val) \
           d2ftrgst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2ftrgs_par_sl1obj_nam(ctx,obj,val) \
           d2ftrgst_SetTextProp(ctx,obj,D2FP_PAR_SL1OBJ_NAM,val)
#define d2ftrgs_par_sl1obj_typ(ctx,obj,val) \
           d2ftrgsn_SetNumProp(ctx,obj,D2FP_PAR_SL1OBJ_TYP,val)
#define d2ftrgs_par_sl2obj_nam(ctx,obj,val) \
           d2ftrgst_SetTextProp(ctx,obj,D2FP_PAR_SL2OBJ_NAM,val)
#define d2ftrgs_par_sl2obj_typ(ctx,obj,val) \
           d2ftrgsn_SetNumProp(ctx,obj,D2FP_PAR_SL2OBJ_TYP,val)
#define d2ftrgs_par_typ(ctx,obj,val) \
           d2ftrgsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2ftrgs_persist_client_info(ctx,obj,val) \
           d2ftrgsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2ftrgs_persist_clt_inf_len(ctx,obj,val) \
           d2ftrgsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2ftrgs_trg_internal_typ(ctx,obj,val) \
           d2ftrgsn_SetNumProp(ctx,obj,D2FP_TRG_INTERNAL_TYP,val)
#define d2ftrgs_trg_sty(ctx,obj,val) \
           d2ftrgsn_SetNumProp(ctx,obj,D2FP_TRG_STY,val)
#define d2ftrgs_trg_txt(ctx,obj,val) \
           d2ftrgst_SetTextProp(ctx,obj,D2FP_TRG_TXT,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FTRG */

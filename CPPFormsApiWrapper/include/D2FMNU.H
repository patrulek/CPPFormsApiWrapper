/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FMNU.H -- Dev2K Forms API MeNU declarations

   DESCRIPTION
    Contains the public declarations for the Forms API MeNU object

   PUBLIC FUNCTIONS
    d2fmnucr_Create          - Cover for d2fobcr_Create
    d2fmnude_Destroy         - Cover for d2fobde_Destroy
    d2fmnudu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fmnusc_Subclass        - Cover for d2fobsc_Subclass
    d2fmnug?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fmnus?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fmnuhp_HasProp         - Cover for d2fobhp_HasProp
    d2fmnuip_InheritProp     - Cover for d2fobip_InheritProp
    d2fmnuii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fmnuid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fmnuis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FMNU
#define D2FMNU

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
** Object: Menu (Individual Menus within a menu module
**  
*/
ORA_RETTYPE(d2fstatus) d2fmnucr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fmnu **ppd2fmnu, text *name  );
ORA_RETTYPE(d2fstatus) d2fmnude_Destroy( d2fctx *pd2fctx, d2fmnu *pd2fmnu );
ORA_RETTYPE(d2fstatus) d2fmnudu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fmnu *pd2fmnu_src,
                                           d2fmnu **ppd2fmnu_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2fmnusc_SubClass( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fmnugb_GetBoolProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fmnugn_GetNumProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fmnugt_GetTextProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fmnugo_GetObjProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fmnugp_GetBlobProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fmnusb_SetBoolProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fmnusn_SetNumProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fmnust_SetTextProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fmnuso_SetObjProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fmnusp_SetBlobProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fmnuhp_HasProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmnuip_InheritProp( d2fctx *pd2fctx, d2fmnu *pd2fmnu,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmnuii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fmnu *pd2fmnu, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fmnuid_IspropDefault( d2fctx *pd2fctx,
                                               d2fmnu *pd2fmnu, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fmnuis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fmnu *pd2fmnu);


/* Begin convenience macros  */
#define d2fmnug_btm_ttl(ctx,obj,val) \
           d2fmnugt_GetTextProp(ctx,obj,D2FP_BTM_TTL,val)
#define d2fmnug_client_info(ctx,obj,val) \
           d2fmnugp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fmnug_comment(ctx,obj,val) \
           d2fmnugt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fmnug_mnu_itm(ctx,obj,val) \
           d2fmnugo_GetObjProp(ctx,obj,D2FP_MNU_ITM,val)
#define d2fmnug_module(ctx,obj,val) \
           d2fmnugo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fmnug_name(ctx,obj,val) \
           d2fmnugt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fmnug_next(ctx,obj,val) \
           d2fmnugo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fmnug_owner(ctx,obj,val) \
           d2fmnugo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fmnug_par_flnam(ctx,obj,val) \
           d2fmnugt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fmnug_par_flpath(ctx,obj,val) \
           d2fmnugt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fmnug_par_modstr(ctx,obj,val) \
           d2fmnugn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fmnug_par_modtyp(ctx,obj,val) \
           d2fmnugn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fmnug_par_module(ctx,obj,val) \
           d2fmnugt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fmnug_par_nam(ctx,obj,val) \
           d2fmnugt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fmnug_par_typ(ctx,obj,val) \
           d2fmnugn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fmnug_persist_client_info(ctx,obj,val) \
           d2fmnugp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fmnug_persist_clt_inf_len(ctx,obj,val) \
           d2fmnugn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fmnug_previous(ctx,obj,val) \
           d2fmnugo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fmnug_source(ctx,obj,val) \
           d2fmnugo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2fmnug_sub_ttl(ctx,obj,val) \
           d2fmnugt_GetTextProp(ctx,obj,D2FP_SUB_TTL,val)
#define d2fmnug_tear_off_mnu(ctx,obj,val) \
           d2fmnugb_GetBoolProp(ctx,obj,D2FP_TEAR_OFF_MNU,val)
#define d2fmnug_title(ctx,obj,val) \
           d2fmnugt_GetTextProp(ctx,obj,D2FP_TITLE,val)

#define d2fmnus_btm_ttl(ctx,obj,val) \
           d2fmnust_SetTextProp(ctx,obj,D2FP_BTM_TTL,val)
#define d2fmnus_client_info(ctx,obj,val) \
           d2fmnusp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fmnus_comment(ctx,obj,val) \
           d2fmnust_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fmnus_name(ctx,obj,val) \
           d2fmnust_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fmnus_par_flnam(ctx,obj,val) \
           d2fmnust_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fmnus_par_flpath(ctx,obj,val) \
           d2fmnust_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fmnus_par_modstr(ctx,obj,val) \
           d2fmnusn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fmnus_par_modtyp(ctx,obj,val) \
           d2fmnusn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fmnus_par_module(ctx,obj,val) \
           d2fmnust_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fmnus_par_nam(ctx,obj,val) \
           d2fmnust_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fmnus_par_typ(ctx,obj,val) \
           d2fmnusn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fmnus_persist_client_info(ctx,obj,val) \
           d2fmnusp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fmnus_persist_clt_inf_len(ctx,obj,val) \
           d2fmnusn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fmnus_sub_ttl(ctx,obj,val) \
           d2fmnust_SetTextProp(ctx,obj,D2FP_SUB_TTL,val)
#define d2fmnus_tear_off_mnu(ctx,obj,val) \
           d2fmnusb_SetBoolProp(ctx,obj,D2FP_TEAR_OFF_MNU,val)
#define d2fmnus_title(ctx,obj,val) \
           d2fmnust_SetTextProp(ctx,obj,D2FP_TITLE,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
               
#endif /* D2FMNU */

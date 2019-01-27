/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FPGU.H -- Dev2K Forms API ProGram Unit declarations

   DESCRIPTION
    Contains the public declarations for the Forms API program unit object

   PUBLIC FUNCTIONS
    d2fpgucr_Create          - Cover for d2fobcr_Create
    d2fpgude_Destroy         - Cover for d2fobde_Destroy
    d2fpgudu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fpgusc_Subclass        - Cover for d2fobsc_Subclass
    d2fpguco_CompileObj      - Compile the object's PL/SQL code
    d2fpgug?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fpgus?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fpguhp_HasProp         - Cover for d2fobhp_HasProp
    d2fpguip_InheritProp     - Cover for d2fobip_InheritProp
    d2fpguii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fpguid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fpguis_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FPGU
#define D2FPGU

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
** Object: Program Unit
**  
*/
ORA_RETTYPE(d2fstatus) d2fpgucr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fpgu **ppd2fpgu, text *name  );
ORA_RETTYPE(d2fstatus) d2fpgude_Destroy( d2fctx *pd2fctx, d2fpgu *pd2fpgu );
ORA_RETTYPE(d2fstatus) d2fpgudu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fpgu *pd2fpgu_src,
                                           d2fpgu **ppd2fpgu_dst,
                                           text *new_name  );
ORA_RETTYPE(d2fstatus) d2fpgusc_SubClass( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fpguco_CompileObj( d2fctx *pd2fctx,
                                               d2fpgu *pd2fpgu );
ORA_RETTYPE(d2fstatus) d2fpgugb_GetBoolProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fpgugn_GetNumProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fpgugt_GetTextProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fpgugo_GetObjProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fpgugp_GetBlobProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
					    ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fpgusb_SetBoolProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fpgusn_SetNumProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fpgust_SetTextProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fpguso_SetObjProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fpgusp_SetBlobProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                             ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fpguhp_HasProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fpguip_InheritProp( d2fctx *pd2fctx, d2fpgu *pd2fpgu,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fpguii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fpgu *pd2fpgu, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fpguid_IspropDefault( d2fctx *pd2fctx,
                                               d2fpgu *pd2fpgu, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fpguis_IsSubclassed( d2fctx *pd2fctx,
                                              d2fpgu *pd2fpgu);



/* Begin convenience macros  */
#define d2fpgug_client_info(ctx,obj,val) \
           d2fpgugp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fpgug_comment(ctx,obj,val) \
           d2fpgugt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fpgug_module(ctx,obj,val) \
           d2fpgugo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fpgug_name(ctx,obj,val) \
           d2fpgugt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fpgug_next(ctx,obj,val) \
           d2fpgugo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fpgug_owner(ctx,obj,val) \
           d2fpgugo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fpgug_par_flnam(ctx,obj,val) \
           d2fpgugt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fpgug_par_flpath(ctx,obj,val) \
           d2fpgugt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fpgug_par_modstr(ctx,obj,val) \
           d2fpgugn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fpgug_par_modtyp(ctx,obj,val) \
           d2fpgugn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fpgug_par_module(ctx,obj,val) \
           d2fpgugt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fpgug_par_nam(ctx,obj,val) \
           d2fpgugt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fpgug_par_typ(ctx,obj,val) \
           d2fpgugn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fpgug_persist_client_info(ctx,obj,val) \
           d2fpgugp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fpgug_persist_clt_inf_len(ctx,obj,val) \
           d2fpgugn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fpgug_pgu_txt(ctx,obj,val) \
           d2fpgugt_GetTextProp(ctx,obj,D2FP_PGU_TXT,val)
#define d2fpgug_pgu_typ(ctx,obj,val) \
           d2fpgugn_GetNumProp(ctx,obj,D2FP_PGU_TYP,val)
#define d2fpgug_previous(ctx,obj,val) \
           d2fpgugo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fpgug_source(ctx,obj,val) \
           d2fpgugo_GetObjProp(ctx,obj,D2FP_SOURCE,val)

#define d2fpgus_client_info(ctx,obj,val) \
           d2fpgusp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fpgus_comment(ctx,obj,val) \
           d2fpgust_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fpgus_par_flnam(ctx,obj,val) \
           d2fpgust_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fpgus_par_flpath(ctx,obj,val) \
           d2fpgust_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fpgus_par_modstr(ctx,obj,val) \
           d2fpgusn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fpgus_par_modtyp(ctx,obj,val) \
           d2fpgusn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fpgus_par_module(ctx,obj,val) \
           d2fpgust_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fpgus_par_nam(ctx,obj,val) \
           d2fpgust_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fpgus_par_typ(ctx,obj,val) \
           d2fpgusn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fpgus_persist_client_info(ctx,obj,val) \
           d2fpgusp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fpgus_persist_clt_inf_len(ctx,obj,val) \
           d2fpgusn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fpgus_pgu_txt(ctx,obj,val) \
           d2fpgust_SetTextProp(ctx,obj,D2FP_PGU_TXT,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FPGU */

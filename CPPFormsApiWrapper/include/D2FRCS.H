/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/* 
   NAME
    D2FRCS.H -- Dev2K Forms API Record Group Column Spec public definitions
 
   DESCRIPTION
    Contains the public declarations for the Forms API RG col spec objects
 
   PUBLIC FUNCTIONS
    d2frcscr_Create          - Cover for d2fobcr_Create
    d2frcsde_Destroy         - Cover for d2fobde_Destroy
    d2frcsdu_Duplicate       - Cover for d2fobdu_Duplicate
    d2frcsg?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2frcss?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2frcshp_HasProp         - Cover for d2fobhp_HasProp
    d2frcsip_InheritProp     - Cover for d2fobip_InheritProp
    d2frcsii_IspropInherited - Cover for d2fobii_IspropInherited
    d2frcsid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2frcsir_InsertRow       -
    d2frcsif_InsertFmtRow    -
    d2frcsdr_DeleteRow       -
    d2frcsgr_GetRow          -
*/

#ifndef D2FRCS
#define D2FRCS

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
** Object: Record group Column Spec
**  
*/
ORA_RETTYPE(d2fstatus) d2frcscr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2frcs **ppd2frcs, text *name );
ORA_RETTYPE(d2fstatus) d2frcsde_Destroy( d2fctx *pd2fctx, d2frcs *pd2frcs );
ORA_RETTYPE(d2fstatus) d2frcsdu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2frcs *pd2frcs_src,
                                           d2frcs **ppd2frcs_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2frcsir_InsertRow_Int( d2fctx *pd2fctx,
                                               d2frcs *pd2frcs, number index,
                                               text *dat, text *fmt_mask );
ORA_RETTYPE(d2fstatus) d2frcsdr_DeleteRow( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                           number index );
ORA_RETTYPE(d2fstatus) d2frcsgr_GetRow( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                        number index,  text **dat);
ORA_RETTYPE(d2fstatus) d2frcsgb_GetBoolProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2frcsgn_GetNumProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2frcsgt_GetTextProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2frcsgo_GetObjProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2frcsgp_GetBlobProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2frcssb_SetBoolProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2frcssn_SetNumProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2frcsst_SetTextProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2frcsso_SetObjProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2frcssp_SetBlobProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                            ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2frcshp_HasProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frcsip_InheritProp( d2fctx *pd2fctx, d2frcs *pd2frcs,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frcsii_IspropInherited( d2fctx *pd2fctx,
                                                 d2frcs *pd2frcs, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2frcsid_IspropDefault( d2fctx *pd2fctx,
                                               d2frcs *pd2frcs, ub2 pnum);

/*
** These macros were added to fix bug #(646952) - Data values in a
** specificied format cannot be inserted into a record group column.
*/
/* Insert data into a record group column using the default format mask */
#define d2frcsir_InsertRow(ctx, obj, idx, data) \
           d2frcsir_InsertRow_Int(ctx, obj, idx, data, (text *)0)

/* Insert data into a record group column using the specified format mask */
#define d2frcsif_InsertFmtRow(ctx, obj, idx, data, fmt) \
           d2frcsir_InsertRow_Int(ctx, obj, idx, data, fmt)



/* Begin convenience macros  */
#define d2frcsg_client_info(ctx,obj,val) \
           d2frcsgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2frcsg_col_dat_typ(ctx,obj,val) \
           d2frcsgn_GetNumProp(ctx,obj,D2FP_COL_DAT_TYP,val)
#define d2frcsg_col_vals_count(ctx,obj,val) \
           d2frcsgn_GetNumProp(ctx,obj,D2FP_COL_VALS_COUNT,val)
#define d2frcsg_column_value(ctx,obj,val) \
           d2frcsgo_GetObjProp(ctx,obj,D2FP_COLUMN_VALUE,val)
#define d2frcsg_max_len(ctx,obj,val) \
           d2frcsgn_GetNumProp(ctx,obj,D2FP_MAX_LEN,val)
#define d2frcsg_name(ctx,obj,val) \
           d2frcsgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2frcsg_next(ctx,obj,val) \
           d2frcsgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2frcsg_persist_client_info(ctx,obj,val) \
           d2frcsgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2frcsg_persist_clt_inf_len(ctx,obj,val) \
           d2frcsgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2frcsg_previous(ctx,obj,val) \
           d2frcsgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)

#define d2frcss_client_info(ctx,obj,val) \
           d2frcssp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2frcss_col_dat_typ(ctx,obj,val) \
           d2frcssn_SetNumProp(ctx,obj,D2FP_COL_DAT_TYP,val)
#define d2frcss_max_len(ctx,obj,val) \
           d2frcssn_SetNumProp(ctx,obj,D2FP_MAX_LEN,val)
#define d2frcss_name(ctx,obj,val) \
           d2frcsst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2frcss_persist_client_info(ctx,obj,val) \
           d2frcssp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2frcss_persist_clt_inf_len(ctx,obj,val) \
           d2frcssn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
               
#endif /* D2FRCS */

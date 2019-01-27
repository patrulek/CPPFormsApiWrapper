/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FLIB.H -- Dev2K Forms API LIBrary module declarations

   DESCRIPTION
    Contains the public declarations for the Forms API LIBrary module

   PUBLIC FUNCTIONS
    d2flibde_Destroy         - Cover for d2fobde_Destroy
    d2flibld_Load            - Load a libary module into memory
    d2flibg?_Get*Prop        - Cover for d2fobg?_Get*Prop
*/

#ifndef D2FLIB
#define D2FLIB

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
** Object: Library Module
**  
*/
ORA_RETTYPE(d2fstatus) d2flibld_Load( d2fctx *pd2fctx, d2flib **ppd2flib,
                                      text *libname, boolean db);
ORA_RETTYPE(d2fstatus) d2flibde_Destroy( d2fctx *pd2fctx, d2flib *pd2flib );
ORA_RETTYPE(d2fstatus) d2flibgb_GetBoolProp( d2fctx *pd2fctx, d2flib *pd2flib,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2flibgn_GetNumProp( d2fctx *pd2fctx, d2flib *pd2flib,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2flibgt_GetTextProp( d2fctx *pd2fctx, d2flib *pd2flib,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2flibgo_GetObjProp( d2fctx *pd2fctx, d2flib *pd2flib,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2flibgp_GetBlobProp( d2fctx *pd2fctx, d2flib *pd2flib,
                                            ub2 pnum, dvoid **pprp );



/* Begin convenience macros  */
#define d2flibg_att_lib(ctx,obj,val) \
           d2flibgo_GetObjProp(ctx,obj,D2FP_ATT_LIB,val)
#define d2flibg_lib_loc(ctx,obj,val) \
           d2flibgt_GetTextProp(ctx,obj,D2FP_LIB_LOC,val)
#define d2flibg_lib_prog_unit(ctx,obj,val) \
           d2flibgo_GetObjProp(ctx,obj,D2FP_LIB_PROG_UNIT,val)
#define d2flibg_lib_src(ctx,obj,val) \
           d2flibgn_GetNumProp(ctx,obj,D2FP_LIB_SRC,val)
#define d2flibg_next(ctx,obj,val) \
           d2flibgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2flibg_previous(ctx,obj,val) \
           d2flibgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

               
#endif /* D2FLIB */

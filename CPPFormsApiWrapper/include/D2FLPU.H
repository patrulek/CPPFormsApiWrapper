/* Copyright (c) Oracle Corporation 1998.  All Rights Reserved. */

/*
   NAME
    D2FLPU.H -- Dev2K Forms API Library Program Unit declarations

   DESCRIPTION
    Contains the public declarations for the Forms API Library PUs

   PUBLIC FUNCTIONS
    d2flpug?_Get*Prop        - Cover for d2fobg?_Get*Prop

*/

#ifndef D2FLPU
#define D2FLPU

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
** Object: Library Program Unit
**  
*/
ORA_RETTYPE(d2fstatus) d2flpugb_GetBoolProp( d2fctx *pd2fctx, d2flpu *pd2flpu,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2flpugn_GetNumProp( d2fctx *pd2fctx, d2flpu *pd2flpu,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2flpugt_GetTextProp( d2fctx *pd2fctx, d2flpu *pd2flpu,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2flpugo_GetObjProp( d2fctx *pd2fctx, d2flpu *pd2flpu,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2flpugp_GetBlobProp( d2fctx *pd2fctx, d2flpu *pd2flpu,
                                            ub2 pnum, dvoid **pprp );



/* Begin convenience macros  */
#define d2flpug_name(ctx,obj,val) \
           d2flpugt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2flpug_next(ctx,obj,val) \
           d2flpugo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2flpug_pgu_txt(ctx,obj,val) \
           d2flpugt_GetTextProp(ctx,obj,D2FP_PGU_TXT,val)
#define d2flpug_pgu_typ(ctx,obj,val) \
           d2flpugn_GetNumProp(ctx,obj,D2FP_PGU_TYP,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

               
#endif /* D2FLPU */

/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FPR.H -- Dev2K Forms API PRoperty utilities

   DESCRIPTION
    Contains the public declarations for the Forms API property utilities

   PUBLIC FUNCTIONS
    d2fprgt_GetType          - Get property Type
    d2fprgn_GetName          - Get property name (a printable string)
    d2fprgcn_GetConstName    - Get property Constant Name
    d2fprgcv_GetConstValue   - Get property Constant (Give the constant Name)
    d2fprgvn_GetValueName    - Get property Value Name for choice-list props
*/

#ifndef D2FPR
#define D2FPR

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
** Property types
*/
#define D2FP_TYP_UNKNOWN        0
#define D2FP_TYP_BOOLEAN        1
#define D2FP_TYP_NUMBER         2
#define D2FP_TYP_TEXT           3
#define D2FP_TYP_OBJECT         4


/*
**  Property misc. services
**
**  Examples using Alert Style property:
**
**    d2fprgt_GetType(d2fctx, D2FP_ALT_STY)
**    returns D2FP_TYP_NUMBER.
**
**    d2fprgn_GetName(d2fctx, D2FP_ALT_STY, &pname)
**    returns "Alert Style" in the pname [OUT] parameter.
**
**    d2fprgvn_GetValueName(d2fctx, D2FP_ALT_STY, D2FC_ALST_CAUTION, &vname)
**    returns "Caution" in the vname [OUT] parameter.
**
**    d2fprgcv_GetConstValue(d2fctx, "ALT_STY", &pnum)
**    returns D2FP_ALT_STY in the pnum [OUT] parameter.
**
**    d2fprgcn_GetConstName(d2fctx, D2FP_ALT_STY, &pcname)
**    returns "ALT_STY" in the pcname [OUT] parameter.
*/
ORA_RETTYPE(d2fptyp)   d2fprgt_GetType( d2fctx *pd2fctx, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fprgn_GetName( d2fctx *pd2fctx, ub2 pnum,
                                        text **pname );
ORA_RETTYPE(d2fstatus) d2fprgvn_GetValueName(d2fctx *pd2fctx, ub2 pnum,
                                             number val, text **vname);
ORA_RETTYPE(d2fstatus) d2fprgcv_GetConstValue( d2fctx *pd2fctx, text *pcname,
                                               ub2 *pnum);
ORA_RETTYPE(d2fstatus) d2fprgcn_GetConstName( d2fctx *pd2fctx, ub2 pnum ,
                                              text **pcname);


/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FPR */


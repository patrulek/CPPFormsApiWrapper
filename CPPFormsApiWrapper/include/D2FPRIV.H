/*
 * $Header: d2fpriv.h@@/main/TOOLS_DEV2K_994/6 \
 * Checked in on Mon Jul  2 10:09:54 PDT 2001 by vobadm \
 * Copyright (c) 2001 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 2001.  All Rights Reserved. */

/*
   NAME
    D2FPRIV.H -- Dev2K Forms API private structures

   DESCRIPTION
    This file is for internal use only.
*/

#ifndef D2FPRIV
#define D2FPRIV

#ifndef ORATYPES
# include <oratypes.h>
#endif

#ifndef D2FERR
# include <d2ferr.h>
#endif


#ifndef D2FDEF
# include <d2fdef.h>
#endif

/* C++ Support */
#ifdef __cplusplus
extern "C"
{
#endif

typedef struct d2fctx d2fctx;

typedef dvoid *(* d2fmalc) (d2fctx *context, size_t size);
typedef dvoid *(* d2fmrlc) (d2fctx *context, dvoid *ptr, size_t newsize);
typedef void   (* d2fmfre) (d2fctx *context, dvoid *ptr);


struct d2fctx
{
    dvoid      *pidgc_d2fctx;                            /* Builder context */
    dvoid      *cdata_d2fctx;                                /* Client Data */
    d2fmalc     d2fmalc_d2fctx;                   /* Client provided malloc */
    d2fmfre     d2fmfre_d2fctx;                     /* Client provided free */
    d2fmrlc     d2fmrlc_d2fctx;                 /* Client provieded realloc */
};


#ifdef WIN32COMMON
#  ifdef ORA_APIDLL
#    define ORA_RETTYPE(type)  type
#  else
#    define ORA_RETTYPE(type)  type
#  endif
#else
# define ORA_RETTYPE(type)  type
#endif


#define d2fctxgpidgc(pd2fctx)   ((pd2fctx)->pidgc_d2fctx)

typedef ub4     number;
typedef ub2     d2fotyp;
typedef ub1     d2fptyp;
typedef ub2     d2fpnum;
typedef sword   d2fstatus;

typedef  dvoid   d2fob;
typedef  dvoid   d2falb;
typedef  dvoid   d2falt;
typedef  dvoid   d2fblk;
typedef  dvoid   d2fcte;
typedef  dvoid   d2fcnv;
typedef  dvoid   d2fcrd;
typedef  dvoid   d2fdsa;
typedef  dvoid   d2fdsc;
typedef  dvoid   d2fedt;
typedef  dvoid   d2ffmd;
typedef  dvoid   d2ffnt;
typedef  dvoid   d2ffpm;
typedef  dvoid   d2fgra;
typedef  dvoid   d2fitm;
typedef  dvoid   d2flib;
typedef  dvoid   d2flcm;
typedef  dvoid   d2flov;
typedef  dvoid   d2flpu;
typedef  dvoid   d2fmmd;
typedef  dvoid   d2fmni;
typedef  dvoid   d2fmnu;
typedef  dvoid   d2fmpm;
typedef  dvoid   d2fobg;
typedef  dvoid   d2fogc;
typedef  dvoid   d2folb;
typedef  dvoid   d2folt;
typedef  dvoid   d2fpgu;
typedef  dvoid   d2fpnt;
typedef  dvoid   d2fppc;
typedef  dvoid   d2frdb;
typedef  dvoid   d2frcg;
typedef  dvoid   d2frcs;
typedef  dvoid   d2frcv;
typedef  dvoid   d2frel;
typedef  dvoid   d2frpt;
typedef  dvoid   d2ftbp;
typedef  dvoid   d2ftrg;
typedef  dvoid   d2ftsp;
typedef  dvoid   d2ftxs;
typedef  dvoid   d2fvat;
typedef  dvoid   d2fwin;

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FPRIV */






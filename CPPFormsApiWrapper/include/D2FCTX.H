/*
 * $Header: d2fctx.h@@/main/TOOLS_DEV2K_994/6 \
 * Checked in on Tue Nov 27 17:20:38 PST 2001 by vobadm \
 * Copyright (c) 2001 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 2001.  All Rights Reserved. */

/*
   NAME
    D2FCTX.H -- Dev2K Forms API ConTeXt declarations

   DESCRIPTION
    Contains the public declarations for the Forms API ConTeXt

   NOTES
    The Forms API context (d2fctx) is required before any FAPI 
    function can be called.  It's typically the first argument
    passed to any FAPI function.  Creating the FAPI context 
    initializes all the internal subsystems for the Forms API.

   PUBLIC FUNCTIONS
    d2fctxcr_Create          - Create and initialize the FAPI context
    d2fctxde_Destroy         - Destroy the FAPI context and perform cleanup
    d2fctxga_GetAttributes  -- Get the specified attributes from the FAPI ctx
    d2fctxsa_SetAttributes  -- Set the specified attributes in  the FAPI ctx
    d2fctxcn_Connect         - Connect to a database
    d2fctxdc_Disconnect      - Disconnect from the current database
    d2fctxbv_BuilderVersion  - Returns the FAPI version number
    d2fctxcf_ConvertFile     - Converts a file between text <-> binary
    d2fctxbi_BuiltIns        - returns a 2D-arr of builtin names, by package

   MODIFIED   (MM/DD/YY)
    hmoston    09/27/01 - #(1891574) - Add Flag D2FCTXANOATTDEL
*/

#ifndef D2FCTX
#define D2FCTX

#ifndef ORATYPES
# include <oratypes.h>
#endif

#ifndef D2FPRIV
# include <d2fpriv.h>
#endif

/* C++ Support */
#ifdef __cplusplus
extern "C"
{
#endif


/*
** Attribute masks for the mask_d2fctxa field of the d2fctxa structure.
** Setting an attribute mask means that the corresponding field of the
** d2fctxa structure contains data that should be processed in the 
** function call.  For example:
**   
**  {
**    d2fctxa  attr;
**
**    attr.mask_d2fctxa = ( D2FCTXACDATA | D2FCTXAMCALLS );
**    attr.cdata_d2fctxa = clientdata;
**    attr.d2fmalc_d2fctxa = mymalloc;
**    attr.d2fmfre_d2fctxa = myfree;
**    attr.d2fmrlc_d2fctxa = myrealloc;
**
**    d2fctxcr_Create(&ctx, &attr);
**  }
**
** Something similar can be done for Set and Get attributes.
**
*/
#define D2FCTXACDATA          0x00000001L                    /* client data */
#define D2FCTXAMCALLS         0x00000002L               /* Memory Callbacks */

/*
** This flag puts the API into a special "translation" mode used by
** Oracle OTM and other 3rd party localization tools.  No other clients
** should set this flag - it will cause serious data corruption.
*/
#define D2FCTXATRNSMODE       0x80000000L          /* Translation Mode */
#define D2FCTXANODECODE       0x40000000L          /* Disable Encode/Decode */
#define D2FCTXANOATTDEL       0x20000000L          /* Retain Lib Att info */

typedef struct d2fctxa
{
    ub4         mask_d2fctxa;
    dvoid      *cdata_d2fctxa;                                     /* [CSG] */
    d2fmalc     d2fmalc_d2fctxa;                                   /* [C  ] */
    d2fmfre     d2fmfre_d2fctxa;                                   /* [C  ] */
    d2fmrlc     d2fmrlc_d2fctxa;                                   /* [C  ] */
} d2fctxa;



/*
** File conversion direction, used in converting fmb<->fmt conversion
** (used in d2fctxcf_ConvertFile)
*/
#define BINTOTEXT       1
#define TEXTTOBIN       2
    

/*
** Functions:
**
** d2fctxcr_Create - Create the Forms API context given an attribute
**   mask structure.  This is typically the first function call in a
**   FAPI program.
**
** d2fctxde_Destroy - Destroy the Forms API context.  This is typically
**   the final call in a FAPI program.  After this call, no further 
**   FAPI calls are possible.
**
** d2fctxsa_SetAttributes - Set attributes in the FAPI context after
**   the context has already been created.  Not all FAPI attributes
**   are settable (only those marked with 'S' in the comments above).
**
** d2fctxga_GetAttributes - Get attributes from the FAPI context after
**   the context has already been created.  Not all FAPI attributes
**   are gettable (only those marked with 'G' in the comments above).
**
** d2fctxcn_Connect - Establish a database connection given a connect
**   string (username/password@database).  Alternatively, you may 
**   directly supply an Oracle 'hstdef' pointer for the connection.
**
** d2fctxdc_Disconnect - Disconnect from the current database if one
**   has been established.
**
** d2fctxbv_BuilderVersion - Return the version of the Forms API
**   currently running.  The format of the version number is a decimal
**   number of the form 12334455, where 1 is the first digit, 2 is the
**   second digit, 33 is the third digit, 4 is the fourth digit, and 5
**   is the fifth digit.  For example, a return value of 60052902 means
**   version 6.0.5.29.2.  This is the same version number shown in the
**   Form Builder's "about box".
**
** d2fctxcf_ConvertFile - Convert an .fmb file to an .fmt file or vice-
**   versa.  The filename is the filename on disk, the modtyp is one of
**   the module types (e.g. D2FFO_FORM_MODULE), and the direction is 
**   either BINTOTEXT or TEXTTOBIN (defined above).
**
** d2fctxbi_BuiltIns - Allocates and returns an array of an array of
**   strings listing each of the PL/SQL Built-in functions, organized
**   by package name.  Each row of the array is an array of strings;
**   the first string in each row is the package name, and the rest of
**   the strings in that row are the PL/SQL Built-ins in that package.
**   This routine allocates memory for each string, so it should only
**   be called once in order to avoid memory leaks.
**
*/
ORA_RETTYPE(d2fstatus) d2fctxcr_Create( d2fctx **ppd2fctx,
                                        d2fctxa *d2fctx_attr );
ORA_RETTYPE(d2fstatus) d2fctxde_Destroy( d2fctx *pd2fctx );
ORA_RETTYPE(d2fstatus) d2fctxsa_SetAttributes( d2fctx *pd2fctx,
                                               d2fctxa *pd2fct_attr );
ORA_RETTYPE(d2fstatus) d2fctxga_GetAttributes( d2fctx *pd2fctx,
                                               d2fctxa *pd2fct_attr );
ORA_RETTYPE(d2fstatus) d2fctxcn_Connect( d2fctx *pd2fctx, text *con_str,
                                         dvoid *phstdef);
ORA_RETTYPE(d2fstatus) d2fctxdc_Disconnect( d2fctx *pd2fctx );
ORA_RETTYPE(d2fstatus) d2fctxbv_BuilderVersion( d2fctx *pd2fctx,
                                                number *version );
ORA_RETTYPE(d2fstatus) d2fctxcf_ConvertFile( d2fctx *pd2fctx,
                                             text *filename,
                                             d2fotyp modtyp,
                                             number direction );
ORA_RETTYPE(d2fstatus) d2fctxbi_BuiltIns(d2fctx *pd2fctx, text ****pparr);


/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FCTX */





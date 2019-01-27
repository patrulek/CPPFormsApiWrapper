/*
 * $Header: d2ferr.h@@/main/TOOLS_DEV2K_994/6 \
 * Checked in on Thu Mar 29 15:14:52 PST 2001 by vobadm \
 * Copyright (c) 2001 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 2001.  All Rights Reserved. */

/*
   NAME
    D2FERR.H -- Dev2K Forms API ERRor code declarations

   DESCRIPTION
    Contains the public declarations for the Forms API error codes
*/

#ifndef D2FERR
#define D2FERR

#ifndef ORATYPES
# include <oratypes.h>
#endif

/* C++ Support */
#ifdef __cplusplus
extern "C"
{
#endif

/*
** Operation Succeeded
*/
#define D2FS_SUCCESS            ((d2fstatus)0)

/*
** Operation Failed
*/
#define D2FS_FAIL               ((d2fstatus)1)

/*
**Operation reuturned YES
*/
#define D2FS_YES                ((d2fstatus)2)

/*
** Operation reuturned NO
*/
#define D2FS_NO                 ((d2fstatus)3)

/*
** Bad context provided
*/
#define D2FS_BADCONTEXT         ((d2fstatus)4)

/*
** Bad property
*/
#define D2FS_BADPROP            ((d2fstatus)5)

/*
** One of the args is wrong
*/
#define D2FS_BADARG             ((d2fstatus)6)

/*
** Object type is unknown
*/
#define D2FS_BADTYPE            ((d2fstatus)7)

/*
** Unexpected object
*/
#define D2FS_WRONGOBJ           ((d2fstatus)8)

/*
** Unexpected parent
*/
#define D2FS_WRONGPARENT        ((d2fstatus)9)

/*
** Null object passed
*/
#define D2FS_NULLOBJ            ((d2fstatus)10)

/*
** Null pointer to object
*/
#define D2FS_NULLCONTAINER      ((d2fstatus)11)

/*
** Null property
*/
#define D2FS_NULLPROP           ((d2fstatus)12)

/*
** Not connected to DB
*/
#define D2FS_NOTCONNECTED       ((d2fstatus)13)

/*
** Out of memory
*/
#define D2FS_NOMEMORY           ((d2fstatus)14)

/*
** Message file not found
*/
#define D2FS_NOMSGFILE          ((d2fstatus)15)

/*
** Generation failed
*/
#define D2FS_GENFAILED          ((d2fstatus)16)

/*
** Not implemented yet
*/
#define D2FS_NOTIMPLEMENTED     ((d2fstatus)17)

/*
** Passed in type does not match the actual object
*/
#define D2FS_TYPEMISMATCH       ((d2fstatus)18)  

/*
** The operation failed partially, but the error was not fatal
*/
#define D2FS_WARN               ((d2fstatus)19)  

/*
** Null Data Passed in 
*/
#define D2FS_NULLDATA           ((d2fstatus)20)  

/*
** Data Passed in is invalid
*/
#define D2FS_INVALIDDATA        ((d2fstatus)21)

/*
** Index in is invalid
*/
#define D2FS_INVALIDINDEX       ((d2fstatus)22)

/*
** The Object does not have the given property
*/
#define D2FS_DONTHAVE           ((d2fstatus)23)

/*
** Initialization failed because a NULL Instance Handle passed
** (Applies to Windows only)
*/
#define D2FS_NOINSTANCEHANDLE   ((d2fstatus)24)
    
/*
** The operation failed because the object being created/placed was not
** not unique. An object with this name already exists
*/
#define D2FS_OBJNOTUNIQUE       ((d2fstatus)25)

/*
** The Object was not found
*/
#define D2FS_OBJNOTFOUND        ((d2fstatus)26)

/*
** Function can only be called in translation mode
*/
#define D2FS_NOTTRANSMODE       ((d2fstatus)27)

/*
** The database context passed in is invalid
*/
#define D2FS_BADDBCTX          ((d2fstatus)28)
   
/*
** A subclassed module could not be found during loading
*/
#define D2FS_MISSINGSUBCLMOD   ((d2fstatus)29)

/*
** Duplicate String ID (This slot in the string table has already been used).
*/
#define D2FS_DUPSTRID          ((d2fstatus)30)

/*
** A supplied value parameter was out of the legal range
*/
#define D2FS_VALUEOUTOFRANGE   ((d2fstatus)31)

/*
** The specified file was not found
*/
#define D2FS_FILENOTFOUND      ((d2fstatus)32)

/*
** An attached library could not be found
*/
#define D2FS_MISSINGLIBMOD     ((d2fstatus)33)




/* C++ Support */
#ifdef __cplusplus
}
#endif

    
#endif /* D2FERR */




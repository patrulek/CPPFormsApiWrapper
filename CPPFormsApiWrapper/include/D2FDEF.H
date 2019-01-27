/*
 * $Header: d2fdef.h@@/main/TOOLS_DEV2K_994/19 \
 * Checked in on Wed Feb  6 11:30:32 PST 2002 by vobadm \
 * Copyright (c) 2002 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 2002.  All Rights Reserved. */

/*
   NAME
    D2FDEF.H -- Dev2K Forms API property public DEFinitions

   DESCRIPTION
    Contains the public declarations for the Forms API properties,
    including:
      D2FC_*  - enumerated property values
      D2FP_*  - property type constants
      D2FFO_* - object type constants
*/

#ifndef D2FDEF
#define D2FDEF

#ifndef ORATYPES
# include <oratypes.h>
#endif

/* C++ Support */
#ifdef __cplusplus
extern "C"
{
#endif

/*
** Undefined list value
*/
#define D2FC_UNDEFINED           255


/*
** Default Alert Button (D2FP_DFLT_ALT_BTN)
** [ADF]
*/
#define D2FC_DFAL_BTN1              0
#define D2FC_DFAL_BTN2              1
#define D2FC_DFAL_BTN3              2


/*
** Justification
**
** (D2FP_JUSTIFICATION)
** (D2FP_FRAME_TTL_ALIGN)
** [ALS]
*/
#define D2FC_JUST_LEFT            0
#define D2FC_JUST_RIGHT           1
#define D2FC_JUST_CENTER          2
#define D2FC_JUST_START           3
#define D2FC_JUST_END             4


/*
** Alert style (D2FP_ALT_STY)
** [ALT]
*/
#define D2FC_ALST_STOP            0
#define D2FC_ALST_CAUTION         1
#define D2FC_ALST_NOTE            2


/*
** Data Source Argument Mode (D2FP_DSA_MODE)
** [AMO]
*/
#define D2FC_DSMO_IN              0
#define D2FC_DSMO_OUT             1
#define D2FC_DSMO_IN_OUT          2


/*
** Arrow Style (D2FP_ARROW_STY)
** [ARS]
*/
#define D2FC_ARST_NONE            0
#define D2FC_ARST_START           1
#define D2FC_ARST_END             2
#define D2FC_ARST_BOTH            3
#define D2FC_ARST_MDLTOSTRT       4                      /* Middle to Start */
#define D2FC_ARST_MDLTOEND        5                        /* Middle to End */


/*
** Graphics Type (D2FP_GRAPHICS_TYP)
** [BPT]
*/
#define D2FC_GRTY_ARC              0                                 /* Arc */
#define D2FC_GRTY_IMAGE            1                               /* Image */
#define D2FC_GRTY_LINE             2                                /* Line */
#define D2FC_GRTY_POLY             3                             /* Polygon */
#define D2FC_GRTY_RECT             4                           /* Rectangle */
#define D2FC_GRTY_RREC             5                   /* Rounded Rectangle */
#define D2FC_GRTY_TEXT             6                                /* Text */
#define D2FC_GRTY_GROUP            7                               /* Group */
#define D2FC_GRTY_FRAME            8                               /* Frame */


/*
** BeveL Style (D2FP_BEVEL) [0,1,2]
** [BVL]
*/
#define D2FC_BEST_RAISED          0
#define D2FC_BEST_LOWERED         1
#define D2FC_BEST_NONE            2
#define D2FC_BEST_NSET            3
#define D2FC_BEST_OUTSET          4
#define D2FC_BEST_PLAIN           5


/*
** Data source Column/Argument Type
** (D2FP_DSA_TYP)
** (D2FP_DSC_TYP)
** [CAT]
*/
#define D2FC_DSTY_VARCHAR2        0
#define D2FC_DSTY_NUMBER          1
#define D2FC_DSTY_LONG            2
#define D2FC_DSTY_ROWID           3
#define D2FC_DSTY_DATE            4
#define D2FC_DSTY_RAW             5
#define D2FC_DSTY_LONG_RAW        6
#define D2FC_DSTY_CHAR            7
#define D2FC_DSTY_MLSLABEL        8
#define D2FC_DSTY_TABLE           9
#define D2FC_DSTY_RECORD          10
#define D2FC_DSTY_REFCURSOR       11
#define D2FC_DSTY_NAMEDTYPE       12
#define D2FC_DSTY_OBJECTREF       13
#define D2FC_DSTY_VARRAY          14
#define D2FC_DSTY_NESTEDTAB       15
#define D2FC_DSTY_BLOB            16
#define D2FC_DSTY_CLOB            17
#define D2FC_DSTY_BFILE           18
#define D2FC_DSTY_CFILE           19

#define D2FC_DSTY_UNKNOWN         99


/*
** Communication Mode (D2FP_COMM_MODE)
** [CMM]
*/
#define D2FC_COMO_SYNCH           0
#define D2FC_COMO_ASYNCH          1


/*
** Coordinate System (D2FP_COORD_SYS)
** [COS]
*/
#define D2FC_COSY_CHARACTER       0
#define D2FC_COSY_REAL            1


/*
** Data source Query Type (D2FP_QRY_DAT_SRC_TYP)
** [DQT]
*/
#define D2FC_QRDA_NONE            0
#define D2FC_QRDA_TABLE           1
#define D2FC_QRDA_PROCEDURE       2
#define D2FC_QRDA_TRANS_TRIG      3
#define D2FC_QRDA_FRM_CLS_QUERY   4


/*
** Data source DML Type (D2FP_DML_DAT_TYP)
** [DDT]
*/
#define D2FC_DMDA_NONE            0
#define D2FC_DMDA_TABLE           1
#define D2FC_DMDA_PROCEDURE       2
#define D2FC_DMDA_TRANS_TRIG      3


/*
** Edge Atachment Type (D2FP_PRMPT_ATT_EDGE)
** [EAT]
*/
#define D2FC_PRAT_START           0
#define D2FC_PRAT_END             1
#define D2FC_PRAT_TOP             2
#define D2FC_PRAT_BOTTOM          3


/*
** Execution Mode (D2FP_EXEC_MODE)
** [EXM]
*/
#define D2FC_EXMO_BATCH           0
#define D2FC_EXMO_RUNTIME         1


/*
** Library Source (D2FP_LIB_SRC)
** [LBS]
*/
#define D2FC_LISR_FS           0                              /* Filesystem */
#define D2FC_LISR_DB           1                                /* Database */


/*
** Layout Mode   (D2FP_UPDT_LAYOUT)
** [LMO]
*/
#define D2FC_UPLA_MANUAL          0
#define D2FC_UPLA_AUTO            1
#define D2FC_UPLA_LOCKED          2


/*
** IteM Type (D2FP_ITM_TYP)
** [ITM]
*/
#define D2FC_ITTY_CA              0                           /* Chart area */
#define D2FC_ITTY_CB              1                            /* Check Box */
#define D2FC_ITTY_DI              2                         /* Display Item */
#define D2FC_ITTY_IM              3                                /* Image */
#define D2FC_ITTY_LS              4                            /* List Item */
#define D2FC_ITTY_ACT             5                      /* ActiveX Control */
#define D2FC_ITTY_OLE             6                        /* OLE Container */
#define D2FC_ITTY_PB              7                          /* Push Button */
#define D2FC_ITTY_RD              8                          /* Radio Group */
#define D2FC_ITTY_SN              9                                /* Sound */
#define D2FC_ITTY_TI              10                           /* Text Item */
#define D2FC_ITTY_UA              11                           /* User Area */
#define D2FC_ITTY_VBX             12                         /* VBX Control */
#define D2FC_ITTY_TRE             13                   /* Hierarchical Tree */
#define D2FC_ITTY_BA              14                           /* Bean area */
#define D2FC_ITTY_MAX             14

/*
** OLE Activation Style (D2FP_OLE_ACT_STY)
** [OAS]
*/
#define D2FC_OLAC_DOUBLECLICK     0
#define D2FC_OLAC_MANUAL          1
#define D2FC_OLAC_FOCUS           2


/*
** Prompt Display style (D2FP_PRMPT_DISP_STY)
** [PRD]
*/
#define D2FC_PRDI_HIDDEN          0                               /* Hidden */
#define D2FC_PRDI_FIRST           1                         /* First Record */
#define D2FC_PRDI_EACH            2                          /* All Records */


/*
** Program Unit type (D2FP_PGU_TYP)
** [PUT]
*/
#define D2FC_PGTY_UNKNOWN            0
#define D2FC_PGTY_PROCEDURE          1
#define D2FC_PGTY_FUNCTION           2
#define D2FC_PGTY_PACKAGESPEC        3
#define D2FC_PGTY_PACKAGEBODY        4


/*
** Real Unit (D2FP_REAL_UNIT)
** [RUN]
*/
#define D2FC_REUN_PIXEL           0
#define D2FC_REUN_CENTIMETER      1
#define D2FC_REUN_INCH            2
#define D2FC_REUN_POINT           3
#define D2FC_REUN_DECIPOINT       4


/*
** Relation Type (D2FP_REL_TYPE)
** [RTY]
*/
#define D2FC_RELT_JOIN            0
#define D2FC_RELT_REF             1


/*
** Runtime Compatibility Mode (D2FP_RUNTIME_COMP)
** [RCM]
*/
#define D2FC_RUCO_45              0
#define D2FC_RUCO_50              1


/*
** Tab Edge  (D2FP_TAB_ATT_EDGE)
** [TBE]
*/
#define D2FC_TAAT_TOP             0
#define D2FC_TAAT_BOTTOM          1
#define D2FC_TAAT_LEFT            2
#define D2FC_TAAT_RIGHT           3
#define D2FC_TAAT_START           4
#define D2FC_TAAT_END             5


/*
** Tab Style (D2FP_TAB_STY)
** [TBS]
*/
#define D2FC_TAST_CHAMFERED       0
#define D2FC_TAST_SQUARE          1
#define D2FC_TAST_ROUNDED         2


/*
** Visual Attribute Type (D2FP_VAT_TYP)
** [VAT]
*/
#define D2FC_VATY_COMMON          0
#define D2FC_VATY_PROMPT          1
#define D2FC_VATY_TITLE           2



/*
** Column Data type (D2FP_COL_DAT_TYP)
** [CD]
*/
#define D2FC_CODA_CHAR             0
#define D2FC_CODA_NUMBER           1
#define D2FC_CODA_DATE             2
#define D2FC_CODA_LONG             3
#define D2FC_CODA_REF              4


/*
** Sound Channels (D2FP_AUDIO_CHNNLS)
** [CH]
*/
#define D2FC_AUCH_AUTO             0
#define D2FC_AUCH_MONO             1
#define D2FC_AUCH_STEREO           2


/*
** Calculation Mode (D2FP_CALC_MODE)
** [CL]
*/
#define D2FC_CAMO_NONE             0
#define D2FC_CAMO_FORMULA          1
#define D2FC_CAMO_SUMMARY          2


/*
** Cursor Mode (D2FP_CRSR_MODE)
** [CM]
*/
#define D2FC_CRMO_OPEN             0
#define D2FC_CRMO_CLOSE            1


/*
** Cap style (D2FP_CAP_STY)
** [CP]
*/
#define D2FC_CAST_BUTT             0
#define D2FC_CAST_ROUND            1
#define D2FC_CAST_PROJECT          2                          /* Projecting */


/*
** Compression Quality (D2FP_CMPRSSION_QLTY)
** [CQ]
*/
#define D2FC_CMQL_NONE             0
#define D2FC_CMQL_MIN              1
#define D2FC_CMQL_LOW              2
#define D2FC_CMQL_MED              3
#define D2FC_CMQL_HIGH             4
#define D2FC_CMQL_MAX              5


/*
** Case Restriction (D2FP_CASE_RSTRCTION)
** [CR]
*/
#define D2FC_CARS_MIXED            0
#define D2FC_CARS_UPPER            1
#define D2FC_CARS_LOWER            2


/*
** Canvas Style  (D2FP_CNV_TYP)
** [CS]
*/
#define D2FC_CNTY_CONTENT          0
#define D2FC_CNTY_STACKED          1
#define D2FC_CNTY_VTOOLBAR         2
#define D2FC_CNTY_HTOOLBAR         3
#define D2FC_CNTY_TAB              4


/*
** Checkbox other Values (D2FP_CHK_BX_OTHER_VALS)
** [CV]
*/
#define D2FC_CHBX_ILLEGAL          0
#define D2FC_CHBX_CHECKED          1
#define D2FC_CHBX_UNCHECKED        2


/*
** Language Direction Values (D2FP_LANG_DIR)
** [DI]
*/
#define D2FC_LADI_DEFAULT          0
#define D2FC_LADI_TORIGHT          1                       /* Left to Right */
#define D2FC_LADI_TOLEFT           2                       /* Right to Left */


/*
** Initial Keyboard Direction (D2FP_INIT_KBRD_DIR)
** [DL]
*/
#define D2FC_INKB_DEFAULT          0
#define D2FC_INKB_ROMAN            1
#define D2FC_INKB_NATIVE           2                               /* Local */


/*
** Image Depth (D2FP_IMG_DPTH)
** [DP]
*/
#define D2FC_IMDP_ORIG             0
#define D2FC_IMDP_MONO             1
#define D2FC_IMDP_GRAY             2
#define D2FC_IMDP_LUT              3
#define D2FC_IMDP_RGB              4


/*
** Dash style (D2FP_DASH_STY)
** [DS]
*/
#define D2FC_DAST_SOLID            0                               /* Solid */
#define D2FC_DAST_DOT              1                              /* Dotted */
#define D2FC_DAST_DASH             2                              /* Dashed */
#define D2FC_DAST_DASHDOT          3                            /* Dash Dot */
#define D2FC_DAST_DOUBDOT          4                          /* Double Dot */
#define D2FC_DAST_LONGDASH         5                           /* Long Dash */
#define D2FC_DAST_DASHDOUBDOT      6                     /* Dash Double Dot */


/*
** Execution Hierarchy (D2FP_EXEC_HIERARCHY)
** [EX]
*/
#define D2FC_EXHI_OVERRIDE         0
#define D2FC_EXHI_BEFORE           1
#define D2FC_EXHI_AFTER            2


/*
** Frame Alignment (D2FP_FRAME_ALIGN)
** [FA]
*/
#define D2FC_FRAL_START            0
#define D2FC_FRAL_END              1
#define D2FC_FRAL_CENTER           2
#define D2FC_FRAL_FILL             3
#define D2FC_FRAL_COLUMN           4


/*
** Font Spacing
**
**  (D2FP_FONT_SPCING)
**  (D2FP_PRMPT_FONT_SPCING)
**  (D2FP_FRAME_TTL_FONT_SPCING)
**  (D2FP_GRA_FONT_SPCING)
**  [FD]
*/
#define D2FC_FOSP_ULTRADENSE       0
#define D2FC_FOSP_EXTRADENSE       1
#define D2FC_FOSP_DENSE            2
#define D2FC_FOSP_SEMIDENSE        3
#define D2FC_FOSP_NORMAL           4
#define D2FC_FOSP_SEMIEXPAND       5
#define D2FC_FOSP_EXPAND           6
#define D2FC_FOSP_EXTRAEXPAND      7
#define D2FC_FOSP_ULTRAEXPAND      8


/*
** Font Style
**
** (D2FP_FONT_STY)
** (D2FP_PRMPT_FONT_STY)
** (D2FP_FRAME_TTL_FONT_STY)
** [FS]
*/
#define D2FC_FOST_PLAIN            0
#define D2FC_FOST_ITALIC           1
#define D2FC_FOST_OBLIQUE          2
#define D2FC_FOST_UNDERLINE        3
#define D2FC_FOST_OUTLINE          4
#define D2FC_FOST_SHADOW           5
#define D2FC_FOST_INVERTED         6
#define D2FC_FOST_OVERSTRIKE       7
#define D2FC_FOST_BLINK            8


/*
** Font Weight
**
** (D2FP_FONT_WGHT)
** (D2FP_PRMPT_FONT_WGHT)
** (D2FP_FRAME_TTL_FONT_WGHT)
** (D2FP_GRA_FONT_WGHT)
** [FW]
*/
#define D2FC_FOWG_ULTRALIGHT       0
#define D2FC_FOWG_EXTRALIGHT       1
#define D2FC_FOWG_LIGHT            2
#define D2FC_FOWG_DEMILIGHT        3
#define D2FC_FOWG_MEDIUM           4
#define D2FC_FOWG_DEMIBOLD         5
#define D2FC_FOWG_BOLD             6
#define D2FC_FOWG_EXTRABOLD        7
#define D2FC_FOWG_ULTRABOLD        8


/*
** Layout style  (D2FP_LAYOUT_STY)
** [FY]
*/
#define D2FC_LAST_FORM             0
#define D2FC_LAST_TABULAR          1


/*
** Horizontal Origin (D2FP_HORZ_ORGN)
** [HA]
*/
#define D2FC_HOOR_LEFT             0
#define D2FC_HOOR_RIGHT            1
#define D2FC_HOOR_CENTER           2


/*
** Horizontal Justification Style
**
** (D2FP_HORZ_JST)
** (D2FP_PRMPT_JST)
** [HJ]
*/
#define D2FC_HOJU_LEFT             0
#define D2FC_HOJU_RIGHT            1
#define D2FC_HOJU_CENTER           2
#define D2FC_HOJU_START            3
#define D2FC_HOJU_END              4


/*
** Item Data type (D2FP_DAT_TYP)
** [ID]
*/
#define D2FC_DATY_CHAR             0                              /* - CHAR */
#define D2FC_DATY_NUMBER           1                            /* - NUMBER */
#define D2FC_DATY_DATE             2                              /* - DATE */
#define D2FC_DATY_ALPHA            3                             /* - ALPHA */
#define D2FC_DATY_INTEGER          4                               /* - INT */
#define D2FC_DATY_DATETIME         5                          /* - DATETIME */
#define D2FC_DATY_LONG             6                              /* - LONG */
#define D2FC_DATY_RNUMBER          7                              /* - RNUM */
#define D2FC_DATY_JDATE            8                             /* - JDATE */
#define D2FC_DATY_EDATE            9                             /* - EDATE */
#define D2FC_DATY_TIME             10                             /* - TIME */
#define D2FC_DATY_RINTEGER         11                             /* - RINT */
#define D2FC_DATY_MONEY            12                            /* - MONEY */
#define D2FC_DATY_RMONEY           13                           /* - RMONEY */
#define D2FC_DATY_OBJECTREF        14                        /* - OBJECTREF */
#define D2FC_DATY_LOB              15                              /* - LOB */
#define D2FC_DATY_FILE             16                             /* - FILE */



/*
** Image storage Format (D2FP_IMG_FMT)
** [IF]
*/
#define D2FC_IMFM_BMP              0
#define D2FC_IMFM_CALS             1
#define D2FC_IMFM_GIF              2
#define D2FC_IMFM_JFIF             3
#define D2FC_IMFM_PICT             4
#define D2FC_IMFM_RAS              5
#define D2FC_IMFM_TIFF             6
#define D2FC_IMFM_TPIC             7


/*
** Display Quality levels (D2FP_DISP_QLTY)
** [IQ]
*/
#define D2FC_DIQL_HIGH             0
#define D2FC_DIQL_MEDIUM           1
#define D2FC_DIQL_LOW              2


/*
** Image Sizing style (D2FP_SIZING_STY)
** [IS]
*/
#define D2FC_SIST_CROP             0
#define D2FC_SIST_ADJUST           1


/*
** Join style (D2FP_JOIN_STY)
** [JO]
*/
#define D2FC_JOST_MITRE            0
#define D2FC_JOST_BEVEL            1
#define D2FC_JOST_ROUND            2


/*
** Key Mode (D2FP_KEY_MODE)
** [KM]
*/
#define D2FC_KEMO_UNIQUE           0                              /* Unique */
#define D2FC_KEMO_UPDATEABLE       1                          /* Updateable */
#define D2FC_KEMO_NUPDATEABLE      2                      /* Non-updateable */
#define D2FC_KEMO_AUTO             3                           /* Automatic */


/*
** Alignment
**
** (D2FP_PRMPT_ALIGN)
** (D2FP_SNGL_OBJ_ALIGN)
** (D2FP_STRT_PRMPT_ALIGN)
** (D2FP_TOP_PRMPT_ALIGN)
** [LE]
*/
#define D2FC_ALIG_START            0
#define D2FC_ALIG_END              1
#define D2FC_ALIG_CENTER           2


/*
** INTeraction mode (D2FP_INTERACTION_MODE)
** [INT]
**
*/
#define D2FC_INMO_BLOCKING         0
#define D2FC_INMO_NONBLOCKING      1


/*
** ISOlation Mode (D2FP_ISOLATION_MODE)
** [ISO]
*/
#define D2FC_ISMO_READ            0
#define D2FC_ISMO_SERIAL          1


/*
** Lock Mode (D2FP_LOCK_MODE)
** [LM]
*/
#define D2FC_LOMO_IMMEDIATE        0
#define D2FC_LOMO_DELAYED          1
#define D2FC_LOMO_AUTO             2


/*
** List Style (D2FP_LST_STY)
** [LS]
*/
#define D2FC_LSST_POPLIST          0
#define D2FC_LSST_TLIST            1
#define D2FC_LSST_COMBO            2


/*
** LOV type (D2FP_LST_TYP)
** [LV]
*/
#define D2FC_LSTY_RECORDGROUP      0
#define D2FC_LSTY_OLD              1


/*
** Menu Command type (D2FP_COM_TYP)
** [MC]
*/
#define D2FC_COTY_NULL             0
#define D2FC_COTY_MENU             1
#define D2FC_COTY_PLSQL            2
#define D2FC_COTY_PLUS             3
#define D2FC_COTY_FORM             4
#define D2FC_COTY_MACRO            5


/*
** Master Deletes (D2FP_DEL_REC)
** [MD]
*/
#define D2FC_DERE_CASCADING        0
#define D2FC_DERE_ISOLATED         1
#define D2FC_DERE_NON_ISOLATED     2


/*
** Magic Menu item type (D2FP_MAGIC_ITM)
** [MM]
*/
#define D2FC_MAIT_NONE             0
#define D2FC_MAIT_CUT              1
#define D2FC_MAIT_COPY             2
#define D2FC_MAIT_PASTE            3
#define D2FC_MAIT_CLEAR            4
#define D2FC_MAIT_UNDO             5
#define D2FC_MAIT_HELP             6
#define D2FC_MAIT_ABOUT            7
#define D2FC_MAIT_QUIT             8
#define D2FC_MAIT_WINDOW           9
#define D2FC_MAIT_PAGESETUP        10

/*
** Mouse Navigation limit (D2FP_MOUSE_NAVIGATION_LMT)
** [MN]
*/
#define D2FC_MONA_FORM             0
#define D2FC_MONA_BLOCK            1
#define D2FC_MONA_RECORD           2
#define D2FC_MONA_ITEM             3


/*
** Menu Style (D2FP_MNU_STY)
** [MS]
*/
#define D2FC_MNST_PULLDOWN         0
#define D2FC_MNST_FULLSCREEN       1


/*
** MeNu Source (D2FP_MNU_SRC)
** [MNS]
*/
#define D2FC_MNSR_FILE            0
#define D2FC_MNSR_DB              1


/*
** Menu item Type (D2FP_MNU_ITM_TYP)
** [MT]
*/
#define D2FC_MNIT_PLAIN            0
#define D2FC_MNIT_CHECK            1
#define D2FC_MNIT_RADIO            2
#define D2FC_MNIT_SEPARATOR        3
#define D2FC_MNIT_MAGIC            4


/*
** Navigational Style (D2FP_NAVIGATION_STY)
** [NS]
*/
#define D2FC_NAST_SAMERECORD       0
#define D2FC_NAST_CHANGERECORD     1
#define D2FC_NAST_CHANGEBLOCK      2


/*
** Parent Objec's Module Storage Type (D2FP_PAR_MODSTR)
** [FLC]
*/
#define D2FC_PAMO_FILESYSTEM       0
#define D2FC_PAMO_DATABASE         1



/*
** Record Orientation (D2FP_REC_ORNT)
** [OR]
*/
#define D2FC_REOR_VERTICAL         0
#define D2FC_REOR_HORIZONTAL       1


/*
** OLE Tenant Types (D2FP_OLE_TNNT_TYP)
** [OT]
*/
#define D2FC_OLTN_ANY              0
#define D2FC_OLTN_NONE             1
#define D2FC_OLTN_STATIC           2
#define D2FC_OLTN_LINKED           3
#define D2FC_OLTN_EMBEDDED         4
#define D2FC_OLTN_CONTROL          5


/*
** Parameter Data type (D2FP_PARAM_DAT_TYP)
** [PD]
*/
#define D2FC_PADA_CHAR             0
#define D2FC_PADA_NUMBER           1
#define D2FC_PADA_DATE             2


/*
** Record Group type (D2FP_REC_GRP_TYP)
** [RG]
*/
#define D2FC_REGR_QUERY            0
#define D2FC_REGR_STATIC           1


/*
** Reading Order Values
**
** (D2FP_READING_ORDR)
** (D2FP_PRMPT_READING_ORDR)
** (D2FP_TTL_READING_ORDR)
** [RO]
*/
#define D2FC_READ_DEFAULT          0
#define D2FC_READ_TORIGHT          1
#define D2FC_READ_TOLEFT           2


/*
** Report Destination Type (D2FP_RPT_DESTINATION_TYP)
** [RDT]
*/
#define D2FC_RPDE_PREVIEW           0
#define D2FC_RPDE_FILE              1
#define D2FC_RPDE_PRINTER           2
#define D2FC_RPDE_MAIL              3
#define D2FC_RPDE_CACHE             4
#define D2FC_RPDE_SCREEN            5


/*
** OLE Resize Style (D2FP_OLE_RESIZ_STY)
** [RS]
*/
#define D2FC_OLRE_CLIP             0
#define D2FC_OLRE_SCALE            1
#define D2FC_OLRE_INITIAL          2
#define D2FC_OLRE_DYNAMIC          3

/*
** Sound Compression (D2FP_COMPRESS)
** [SC]
*/
#define D2FC_COMP_AUTO             0
#define D2FC_COMP_OFF              1
#define D2FC_COMP_ON               2


/*
** Sound Format (D2FP_SND_FMT)
** [SF]
*/
#define D2FC_SNFM_AU               0
#define D2FC_SNFM_AIFF             1
#define D2FC_SNFM_AIFF_C           2
#define D2FC_SNFM_WAVE             3


/*
** Sound Quality (D2FP_SND_QLTY)
** [SQ]
*/
#define D2FC_SNQL_AUTO             0
#define D2FC_SNQL_HIGHEST          1
#define D2FC_SNQL_HIGH             2
#define D2FC_SNQL_MEDIUM           3
#define D2FC_SNQL_LOW              4
#define D2FC_SNQL_LOWEST           5


/*
** Scrollbar Orientation (D2FP_SCRLBR_ORNT)
** [SR]
*/
#define D2FC_SCOR_VERTICAL         0
#define D2FC_SCOR_HORIZONTAL       1


/*
** Scroll Bar Alignment (D2FP_SCRLBR_ALIGN)
** [SBA]
**
*/
#define D2FC_SCAL_START           0
#define D2FC_SCAL_END             1


/*
** Line Spacing  (D2FP_LIN_SPCING)
** [SS]
*/
#define D2FC_LISP_SINGLE           0
#define D2FC_LISP_ONEHALF          1
#define D2FC_LISP_DOUBLE           2
#define D2FC_LISP_CUSTOM           3


/*
** Summary Function (D2FP_SUMM_FUNC)
** [ST]
*/
#define D2FC_SUFU_NONE             0
#define D2FC_SUFU_AVG              1
#define D2FC_SUFU_COUNT            2
#define D2FC_SUFU_MAX              3
#define D2FC_SUFU_MIN              4
#define D2FC_SUFU_STDDEV           5
#define D2FC_SUFU_SUM              6
#define D2FC_SUFU_VAR              7


/*
** OLE Tenant Aspect (D2FP_OLE_TNNT_ASPCT)
** [TA]
*/
#define D2FC_OLET_CONTENT          0
#define D2FC_OLET_ICON             1
#define D2FC_OLET_THUMBNAIL        2


/*
** Trigger Style (D2FP_TRG_STY)
** [TS]
*/
#define D2FC_TRST_PLSQL            0
#define D2FC_TRST_V2               1


/*
** Trigger Type ()
** [TT]
*/
#define D2FC_TRTY_BUILTIN          0
#define D2FC_TRTY_USERNAMED        1


/*
** Vertical Origin (D2FP_VERT_ORGN)
** [VA]
*/
#define D2FC_VEOR_TOP              0
#define D2FC_VEOR_CENTER           1
#define D2FC_VEOR_BOTTOM           2


/*
** Vertical Justification Style (D2FP_VERT_JST)
** [VJ]
*/
#define D2FC_VEJU_TOP              0
#define D2FC_VEJU_CENTER           1
#define D2FC_VEJU_BOTTOM           2

/*
** Keyboard State (D2FP_KBRD_STATE)
** [VL]
*/
#define D2FC_KBST_ANY                0
#define D2FC_KBST_ROMAN              1
#define D2FC_KBST_NATIVE             2


/*
** Validation unit (D2FP_VALIDATION_UNIT)
** [VU]
*/
#define D2FC_VAUN_DEFAULT          0
#define D2FC_VAUN_FORM             1
#define D2FC_VAUN_BLOCK            2
#define D2FC_VAUN_RECORD           3
#define D2FC_VAUN_ITEM             4


/*
** Wrap Style (D2FP_WRAP_STY)
** [WR]
*/
#define D2FC_WRST_NONE             0
#define D2FC_WRST_CHARACTER        1
#define D2FC_WRST_WORD             2


/*
** Window Style (D2FP_WIN_STY)
** [WS]
*/
#define D2FC_WIST_DOCUMENT         0
#define D2FC_WIST_DIALOG           1



#define D2FFO_MIN                       0
#define D2FFO_MAX                       41
#define D2FFO_UNDEFINED                 255

/* B_Objects */
#define D2FFO_ANY                       0
#define D2FFO_ALERT                     1
#define D2FFO_ATT_LIB                   2
#define D2FFO_BLOCK                     3
#define D2FFO_CANVAS                    4
#define D2FFO_COLUMN_VALUE              37
#define D2FFO_CMPTXT                    40
#define D2FFO_COORD                     5
#define D2FFO_DAT_SRC_ARG               6
#define D2FFO_DAT_SRC_COL               7
#define D2FFO_EDITOR                    8
#define D2FFO_FONT                      9
#define D2FFO_FORM_MODULE               10
#define D2FFO_FORM_PARAM                11
#define D2FFO_GRAPHIC                   12
#define D2FFO_ITEM                      13
#define D2FFO_LIB_PROG_UNIT             36
#define D2FFO_LIBRARY_MODULE            14
#define D2FFO_LOV                       15
#define D2FFO_LV_COLMAP                 16
#define D2FFO_MENU                      17
#define D2FFO_MENU_ITEM                 18
#define D2FFO_MENU_MODULE               19
#define D2FFO_MENU_PARAM                20
#define D2FFO_OBJ_GROUP                 21
#define D2FFO_OBG_CHILD                 22
#define D2FFO_OBJ_LIB                   23
#define D2FFO_OBJ_LIB_TAB               24
#define D2FFO_POINT                     39
#define D2FFO_PROG_UNIT                 25
#define D2FFO_PROP_CLASS                26
#define D2FFO_RADIO_BUTTON              27
#define D2FFO_REC_GROUP                 28
#define D2FFO_RELATION                  29
#define D2FFO_REPORT                    30
#define D2FFO_RG_COLSPEC                31
#define D2FFO_TAB_PAGE                  32
#define D2FFO_TEXT_SEG                  41
#define D2FFO_TRIGGER                   33
#define D2FFO_TRIG_STEP                 38
#define D2FFO_VIS_ATTR                  34
#define D2FFO_WINDOW                    35

/* E_Objects */


#define D2FP_UNDEFINED         9000
/* B_Properties */

#define D2FP_MIN                           0

#define D2FP_NONE                          0
#define D2FP_ACCESS_KEY                    1
#define D2FP_ACCESS_KEY_STRID              2
#define D2FP_ALERT                         3
#define D2FP_ALIAS                         4
#define D2FP_ALLOW_EXPANSION               5
#define D2FP_ALLOW_MLT_LIN_PRMPTS          6
#define D2FP_ALLOW_STRT_ATT_PRMPTS         7
#define D2FP_ALLOW_TOP_ATT_PRMPTS          8
#define D2FP_ALT_MSG                       9
#define D2FP_ALT_MSG_STRID                 10
#define D2FP_ALT_STY                       11
#define D2FP_ARROW_STY                     12
#define D2FP_ASSOC_MENUS_COUNT             13
#define D2FP_ASSOC_MNUS                    14
#define D2FP_ATT_LIB                       15
#define D2FP_AUDIO_CHNNLS                  16
#define D2FP_AUTO_COL_WID                  17
#define D2FP_AUTO_DISP                     18
#define D2FP_AUTO_HINT                     19
#define D2FP_AUTO_POS                      20
#define D2FP_AUTO_QRY                      21
#define D2FP_AUTO_RFRSH                    22
#define D2FP_AUTO_SKP                      23
#define D2FP_AUTO_SLCT                     24
#define D2FP_BACK_COLOR                    25
#define D2FP_BEVEL                         26
#define D2FP_BLK_DESCRIPTION               27
#define D2FP_BLK_DSCRP_STRID               28
#define D2FP_BLOCK                         29
#define D2FP_BOUNDING_BX_SCALABLE          30
#define D2FP_BTM_TTL                       31
#define D2FP_BTM_TTL_STRID                 32
#define D2FP_BTN_1_LBL                     33
#define D2FP_BTN_1_LBL_STRID               34
#define D2FP_BTN_2_LBL                     35
#define D2FP_BTN_2_LBL_STRID               36
#define D2FP_BTN_3_LBL                     37
#define D2FP_BTN_3_LBL_STRID               38
#define D2FP_CALC_MODE                     39
#define D2FP_CANVAS                        40
#define D2FP_CAP_STY                       41
#define D2FP_CASE_INSENSITIVE_QRY          42
#define D2FP_CASE_RSTRCTION                43
#define D2FP_CHAR_CELL_HGT                 44
#define D2FP_CHAR_CELL_WID                 45
#define D2FP_CHKED_VAL                     46
#define D2FP_CHK_BX_OTHER_VALS             47
#define D2FP_CLIENT_INFO                   48
#define D2FP_CLIP_HGT                      49
#define D2FP_CLIP_WID                      50
#define D2FP_CLIP_X_POS                    51
#define D2FP_CLIP_Y_POS                    52
#define D2FP_CLOSED                        53
#define D2FP_CLS_ALLOWED                   54
#define D2FP_CMPRSSION_QLTY                55
#define D2FP_CMPTXT                        56
#define D2FP_CNV_NAM                       57
#define D2FP_CNV_OBJ                       58
#define D2FP_CNV_TYP                       59
#define D2FP_COL_DAT_TYP                   60
#define D2FP_COL_MAP                       61
#define D2FP_COL_NAM                       62
#define D2FP_COL_SPEC                      63
#define D2FP_COL_VALS_COUNT                64
#define D2FP_COMMENT                       65
#define D2FP_COMM_MODE                     66
#define D2FP_COMPRESS                      67
#define D2FP_COM_TXT                       68
#define D2FP_COM_TYP                       69
#define D2FP_CONCEAL_DATA                  70
#define D2FP_CONSOLE_WIN                   71
#define D2FP_COORD_SYS                     72
#define D2FP_COPY_VAL_FROM_ITM             73
#define D2FP_CORNER_RADIUS_X               74
#define D2FP_CORNER_RADIUS_Y               75
#define D2FP_CRSR_MODE                     76
#define D2FP_CSTM_SPCING                   77
#define D2FP_DASH_STY                      78
#define D2FP_DAT_SRC_BLK                   79
#define D2FP_DAT_SRC_X_AXS                 80
#define D2FP_DAT_SRC_Y_AXS                 81
#define D2FP_DAT_TYP                       82
#define D2FP_DB_BLK                        83
#define D2FP_DB_ITM                        84
#define D2FP_DEFERRED                      85
#define D2FP_DEFER_REQ_ENF                 86
#define D2FP_DEL_ALLOWED                   87
#define D2FP_DEL_DAT_SRC_ARG               88
#define D2FP_DEL_DAT_SRC_COL               89
#define D2FP_DEL_PROC_NAM                  90
#define D2FP_DEL_REC                       91
#define D2FP_DETAIL_BLK                    92
#define D2FP_DETAIL_ITEMREF                93
#define D2FP_DFLT_ALT_BTN                  94
#define D2FP_DFLT_BTN                      95
#define D2FP_DFLT_FNT_SCALING              96
#define D2FP_DIRTY_INFO                    97
#define D2FP_DISP_IN_KBRD_HLP              98
#define D2FP_DISP_NO_PRIV                  99
#define D2FP_DISP_QLTY                     100
#define D2FP_DISP_WID                      101
#define D2FP_DIST_BTWN_RECS                102
#define D2FP_DITHER                        103
#define D2FP_DML_ARY_SIZ                   104
#define D2FP_DML_DAT_NAM                   105
#define D2FP_DML_DAT_TYP                   106
#define D2FP_DML_RET_VAL                   107
#define D2FP_DSA_MODE                      108
#define D2FP_DSA_NAM                       109
#define D2FP_DSA_TYP                       110
#define D2FP_DSA_TYP_NAM                   111
#define D2FP_DSA_VAL                       112
#define D2FP_DSC_LEN                       113
#define D2FP_DSC_MANDATORY                 114
#define D2FP_DSC_NAM                       115
#define D2FP_DSC_NOCHILDREN                116
#define D2FP_DSC_PARENT_NAME               117
#define D2FP_DSC_PRECISION                 118
#define D2FP_DSC_SCALE                     119
#define D2FP_DSC_TYP                       120
#define D2FP_DSC_TYPE_NAME                 121
#define D2FP_DS_DEL_ARG_LIST               122
#define D2FP_DS_DEL_COL_LIST               123
#define D2FP_DS_INS_ARG_LIST               124
#define D2FP_DS_INS_COL_LIST               125
#define D2FP_DS_LOK_ARG_LIST               126
#define D2FP_DS_LOK_COL_LIST               127
#define D2FP_DS_QRY_ARG_LIST               128
#define D2FP_DS_QRY_COL_LIST               129
#define D2FP_DS_UPD_ARG_LIST               130
#define D2FP_DS_UPD_COL_LIST               131
#define D2FP_EDGE_BACK_COLOR               132
#define D2FP_EDGE_FORE_COLOR               133
#define D2FP_EDGE_PAT                      134
#define D2FP_EDITOR                        135
#define D2FP_EDT_NAM                       136
#define D2FP_EDT_OBJ                       137
#define D2FP_EDT_X_POS                     138
#define D2FP_EDT_Y_POS                     139
#define D2FP_ENABLED                       140
#define D2FP_ENFRC_COL_SECURITY            141
#define D2FP_ENFRC_PRMRY_KEY               142
#define D2FP_EXEC_HIERARCHY                143
#define D2FP_EXEC_MODE                     144
#define D2FP_FAIL_MSG_STRID                145
#define D2FP_FILL_PAT                      146
#define D2FP_FIRE_IN_QRY                   147
#define D2FP_FIXED_BOUNDING_BX             148
#define D2FP_FIXED_LEN                     149
#define D2FP_FLNAM                         150
#define D2FP_FLTR_BEFORE_DISP              151
#define D2FP_FMT_MSK                       152
#define D2FP_FONT_NAM                      153
#define D2FP_FONT_SCALEABLE                154
#define D2FP_FONT_SIZ                      155
#define D2FP_FONT_SPCING                   156
#define D2FP_FONT_STY                      157
#define D2FP_FONT_WGHT                     158
#define D2FP_FORE_COLOR                    159
#define D2FP_FORMULA                       160
#define D2FP_FORM_PARAM                    161
#define D2FP_FRAME_ALIGN                   162
#define D2FP_FRAME_TTL                     163
#define D2FP_FRAME_TTL_ALIGN               164
#define D2FP_FRAME_TTL_BACK_COLOR          165
#define D2FP_FRAME_TTL_FILL_PAT            166
#define D2FP_FRAME_TTL_FONT_NAM            167
#define D2FP_FRAME_TTL_FONT_SIZ            168
#define D2FP_FRAME_TTL_FONT_SPCING         169
#define D2FP_FRAME_TTL_FONT_STY            170
#define D2FP_FRAME_TTL_FONT_WGHT           171
#define D2FP_FRAME_TTL_FORE_COLOR          172
#define D2FP_FRAME_TTL_OFST                173
#define D2FP_FRAME_TTL_SPCING              174
#define D2FP_FRAME_TTL_STRID               175
#define D2FP_FRAME_TTL_VAT_NAM             176
#define D2FP_FRAME_TTL_VAT_OBJ             177
#define D2FP_FRST_NAVIGATION_BLK_NAM       178
#define D2FP_FRST_NAVIGATION_BLK_OBJ       179
#define D2FP_GRAPHIC                       180
#define D2FP_GRAPHICS_TYP                  181
#define D2FP_GRA_FONT_COLOR                182
#define D2FP_GRA_FONT_COLOR_CODE           183
#define D2FP_GRA_FONT_NAM                  184
#define D2FP_GRA_FONT_SIZ                  185
#define D2FP_GRA_FONT_SPCING               186
#define D2FP_GRA_FONT_STY                  187
#define D2FP_GRA_FONT_WGHT                 188
#define D2FP_GRA_TEXT                      189
#define D2FP_HEIGHT                        190
#define D2FP_HELP_BOOK_TITLE               191
#define D2FP_HELP_BOOK_TOPIC               192
#define D2FP_HIDE                          193
#define D2FP_HIDE_ON_EXIT                  194
#define D2FP_HIGHEST_ALLOWED_VAL           195
#define D2FP_HIGHEST_VAL_STRID             196
#define D2FP_HINT                          197
#define D2FP_HINT_STRID                    198
#define D2FP_HLP_DESCRIPTION               199
#define D2FP_HLP_DSCRP_STRID               200
#define D2FP_HORZ_JST                      201
#define D2FP_HORZ_MARGN                    202
#define D2FP_HORZ_OBJ_OFST                 203
#define D2FP_HORZ_ORGN                     204
#define D2FP_HORZ_TLBR_CNV                 205
#define D2FP_HTB_CNV_NAME                  206
#define D2FP_ICONIC                        207
#define D2FP_ICON_FLNAM                    208
#define D2FP_ICON_IN_MNU                   209
#define D2FP_IMG_DPTH                      210
#define D2FP_IMG_FMT                       211
#define D2FP_IMPL_CLASS                    212
#define D2FP_INCLUDE_REFITEM               213
#define D2FP_INHRT_MNU                     214
#define D2FP_INIT_KBRD_DIR                 215
#define D2FP_INIT_MNU                      216
#define D2FP_INIT_VAL                      217
#define D2FP_INIT_VAL_STRID                218
#define D2FP_INSRT_ALLOWED                 219
#define D2FP_INSRT_PROC_NAM                220
#define D2FP_INS_DAT_SRC_ARG               221
#define D2FP_INS_DAT_SRC_COL               222
#define D2FP_INTERACTION_MODE              223
#define D2FP_INTERNAL_END_ANGLE            224
#define D2FP_INTERNAL_LIN_WID              225
#define D2FP_INTERNAL_ROTATION_ANGLE       226
#define D2FP_INTERNAL_STRT_ANGLE           227
#define D2FP_ISOLATION_MODE                228
#define D2FP_ITEM                          229
#define D2FP_ITMS_DISP                     230
#define D2FP_ITM_TYP                       231
#define D2FP_JOIN_COND                     232
#define D2FP_JOIN_STY                      233
#define D2FP_JUSTIFICATION                 234
#define D2FP_KBRD_ACC                      235
#define D2FP_KBRD_ACC_STRID                236
#define D2FP_KBRD_HLP_TXT                  237
#define D2FP_KBRD_HLP_TXT_STRID            238
#define D2FP_KBRD_NAVIGABLE                239
#define D2FP_KBRD_STATE                    240
#define D2FP_KEEP_CRSR_POS                 241
#define D2FP_KEY_MODE                      242
#define D2FP_LABEL                         243
#define D2FP_LABEL_STRID                   244
#define D2FP_LANG                          245
#define D2FP_LANG_DIR                      246
#define D2FP_LAYOUT_DATA_BLK_NAM           247
#define D2FP_LAYOUT_STY                    248
#define D2FP_LIB_LOC                       249
#define D2FP_LIB_PROG_UNIT                 250
#define D2FP_LIB_SRC                       251
#define D2FP_LIN_SPCING                    252
#define D2FP_LIST_ELEM                     253
#define D2FP_LOCK_DAT_SRC_ARG              254
#define D2FP_LOCK_DAT_SRC_COL              255
#define D2FP_LOCK_MODE                     256
#define D2FP_LOCK_PROC_NAM                 257
#define D2FP_LOCK_REC                      258
#define D2FP_LOV                           259
#define D2FP_LOV_NAM                       260
#define D2FP_LOV_OBJ                       261
#define D2FP_LOV_X_POS                     262
#define D2FP_LOV_Y_POS                     263
#define D2FP_LOWEST_ALLOWED_VAL            264
#define D2FP_LOWEST_VAL_STRID              265
#define D2FP_LST_ELEMENT_COUNT             266
#define D2FP_LST_IN_BLK_MNU                267
#define D2FP_LST_STY                       268
#define D2FP_LST_TYP                       269
#define D2FP_MAGIC_ITM                     270
#define D2FP_MAIN_MNU                      271
#define D2FP_MAXIMIZE_ALLOWED              272
#define D2FP_MAX_LEN                       273
#define D2FP_MAX_OBJS                      274
#define D2FP_MAX_QRY_TIME                  275
#define D2FP_MAX_RECS_FETCHED              276
#define D2FP_MENU                          277
#define D2FP_MINIMIZE_ALLOWED              278
#define D2FP_MINIMIZE_TTL                  279
#define D2FP_MINIMIZE_TTL_STRID            280
#define D2FP_MLT_LIN                       281
#define D2FP_MNU_DRCTRY                    282
#define D2FP_MNU_FLNAM                     283
#define D2FP_MNU_ITM                       284
#define D2FP_MNU_ITM_CODE                  285
#define D2FP_MNU_ITM_RAD_GRP               286
#define D2FP_MNU_ITM_TYP                   287
#define D2FP_MNU_MOD                       288
#define D2FP_MNU_PARAM                     289
#define D2FP_MNU_PARAM_INIT_VAL            290
#define D2FP_MNU_PARAM_INIT_VAL_STRID      291
#define D2FP_MNU_ROLE                      292
#define D2FP_MNU_SRC                       293
#define D2FP_MNU_STY                       294
#define D2FP_MODAL                         295
#define D2FP_MODULE                        296
#define D2FP_MOUSE_NAVIGATE                297
#define D2FP_MOUSE_NAVIGATION_LMT          298
#define D2FP_MV_ALLOWED                    299
#define D2FP_NAME                          300
#define D2FP_NAVIGATION_STY                301
#define D2FP_NEXT                          302
#define D2FP_NXT_NAVIGATION_BLK_NAM        303
#define D2FP_NXT_NAVIGATION_BLK_OBJ        304
#define D2FP_NXT_NAVIGATION_ITM_NAM        305
#define D2FP_NXT_NAVIGATION_ITM_OBJ        306
#define D2FP_OBJ_COUNT                     307
#define D2FP_OBJ_GRP                       308
#define D2FP_OBJ_GRP_CHILD_REAL_OBJ        309
#define D2FP_OBJ_LIB_TAB                   310
#define D2FP_OG_CHILD                      311
#define D2FP_OLD_LOV_TXT                   312
#define D2FP_OLE_ACT_STY                   313
#define D2FP_OLE_CLASS                     314
#define D2FP_OLE_INSD_OUT_SUPPORT          315
#define D2FP_OLE_IN_PLACE_ACT              316
#define D2FP_OLE_POPUP_MNU_ITMS            317
#define D2FP_OLE_RESIZ_STY                 318
#define D2FP_OLE_SHOW_POPUP_MNU            319
#define D2FP_OLE_SHOW_TNNT_TYP             320
#define D2FP_OLE_TNNT_ASPCT                321
#define D2FP_OLE_TNNT_TYP                  322
#define D2FP_OPT_HINT                      323
#define D2FP_ORDR_BY_CLAUSE                324
#define D2FP_OTHER_VALS                    325
#define D2FP_OWNER                         326
#define D2FP_PARAM_DAT_TYP                 327
#define D2FP_PARAM_INIT_VAL                328
#define D2FP_PARAM_INIT_VAL_STRID          329
#define D2FP_PAR_FLNAM                     330
#define D2FP_PAR_FLPATH                    331
#define D2FP_PAR_MODSTR                    332
#define D2FP_PAR_MODTYP                    333
#define D2FP_PAR_MODULE                    334
#define D2FP_PAR_NAM                       335
#define D2FP_PAR_SL1OBJ_NAM                336
#define D2FP_PAR_SL1OBJ_TYP                337
#define D2FP_PAR_SL2OBJ_NAM                338
#define D2FP_PAR_SL2OBJ_TYP                339
#define D2FP_PAR_TYP                       340
#define D2FP_PERSIST_CLIENT_INFO           341
#define D2FP_PERSIST_CLT_INF_LEN           342
#define D2FP_PGU_TXT                       343
#define D2FP_PGU_TYP                       344
#define D2FP_POINT                         345
#define D2FP_POPUP_MNU_NAM                 346
#define D2FP_POPUP_MNU_OBJ                 347
#define D2FP_POPUP_VA_OBJ                  348
#define D2FP_PRECOMP_SUMM                  349
#define D2FP_PREVIOUS                      350
#define D2FP_PREV_NAVIGATION_BLK_NAM       351
#define D2FP_PREV_NAVIGATION_BLK_OBJ       352
#define D2FP_PREV_NAVIGATION_ITM_NAM       353
#define D2FP_PREV_NAVIGATION_ITM_OBJ       354
#define D2FP_PRMPT                         355
#define D2FP_PRMPT_ALIGN                   356
#define D2FP_PRMPT_ALIGN_OFST              357
#define D2FP_PRMPT_ATT_EDGE                358
#define D2FP_PRMPT_ATT_OFST                359
#define D2FP_PRMPT_BACK_COLOR              360
#define D2FP_PRMPT_DISP_STY                361
#define D2FP_PRMPT_FILL_PAT                362
#define D2FP_PRMPT_FONT_NAM                363
#define D2FP_PRMPT_FONT_SIZ                364
#define D2FP_PRMPT_FONT_SPCING             365
#define D2FP_PRMPT_FONT_STY                366
#define D2FP_PRMPT_FONT_WGHT               367
#define D2FP_PRMPT_FORE_COLOR              368
#define D2FP_PRMPT_JST                     369
#define D2FP_PRMPT_READING_ORDR            370
#define D2FP_PRMPT_STRID                   371
#define D2FP_PRMPT_VAT_NAM                 372
#define D2FP_PRMPT_VAT_OBJ                 373
#define D2FP_PRMRY_CNV                     374
#define D2FP_PRMRY_KEY                     375
#define D2FP_PROG_UNIT                     376
#define D2FP_PROP_CLASS                    377
#define D2FP_PRVNT_MSTRLESS_OPS            378
#define D2FP_QRY_ALLOWED                   379
#define D2FP_QRY_ALL_RECS                  380
#define D2FP_QRY_DAT_SRC_ARG               381
#define D2FP_QRY_DAT_SRC_COL               382
#define D2FP_QRY_DAT_SRC_NAM               383
#define D2FP_QRY_DAT_SRC_TYP               384
#define D2FP_QRY_LEN                       385
#define D2FP_QRY_ONLY                      386
#define D2FP_RAD_BUT                       387
#define D2FP_RAISE_ON_ENT                  388
#define D2FP_RDB_VAL                       389
#define D2FP_READING_ORDR                  390
#define D2FP_REAL_UNIT                     391
#define D2FP_RECS_BUFFERED_COUNT           392
#define D2FP_RECS_DISP_COUNT               393
#define D2FP_RECS_FETCHED_COUNT            394
#define D2FP_REC_GRP                       395
#define D2FP_REC_GRP_FETCH_SIZ             396
#define D2FP_REC_GRP_NAM                   397
#define D2FP_REC_GRP_OBJ                   398
#define D2FP_REC_GRP_QRY                   399
#define D2FP_REC_GRP_TYP                   400
#define D2FP_REC_ORNT                      401
#define D2FP_REC_VAT_GRP_NAM               402
#define D2FP_REC_VAT_GRP_OBJ               403
#define D2FP_REL                           404
#define D2FP_REL_TYPE                      405
#define D2FP_RENDERED                      406
#define D2FP_REPORT                        407
#define D2FP_REQUIRED                      408
#define D2FP_RESIZE_ALLOWED                409
#define D2FP_REV_DIR                       410
#define D2FP_ROLE_COUNT                    411
#define D2FP_RPT_DESTINATION_FMT           412
#define D2FP_RPT_DESTINATION_NAM           413
#define D2FP_RPT_DESTINATION_TYP           414
#define D2FP_RPT_PARAMS                    415
#define D2FP_RPT_SRVR                      416
#define D2FP_RTRN_ITM                      417
#define D2FP_RUNTIME_COMP                  418
#define D2FP_SCRLBR_ALIGN                  419
#define D2FP_SCRLBR_CNV_NAM                420
#define D2FP_SCRLBR_CNV_OBJ                421
#define D2FP_SCRLBR_LEN                    422
#define D2FP_SCRLBR_ORNT                   423
#define D2FP_SCRLBR_TBP_NAM                424
#define D2FP_SCRLBR_TBP_OBJ                425
#define D2FP_SCRLBR_WID                    426
#define D2FP_SCRLBR_X_POS                  427
#define D2FP_SCRLBR_Y_POS                  428
#define D2FP_SHARE_LIB                     429
#define D2FP_SHOW_FAST_FWD                 430
#define D2FP_SHOW_HORZ_SCRLBR              431
#define D2FP_SHOW_PALETTE                  432
#define D2FP_SHOW_PLAY                     433
#define D2FP_SHOW_REC                      434
#define D2FP_SHOW_REWIND                   435
#define D2FP_SHOW_SCRLBR                   436
#define D2FP_SHOW_SLIDER                   437
#define D2FP_SHOW_TIME                     438
#define D2FP_SHOW_VERT_SCRLBR              439
#define D2FP_SHOW_VOLUME                   440
#define D2FP_SHRINKWRAP                    441
#define D2FP_SIZING_STY                    442
#define D2FP_SND_FMT                       443
#define D2FP_SND_QLTY                      444
#define D2FP_SNGL_OBJ_ALIGN                445
#define D2FP_SNGL_REC                      446
#define D2FP_SOURCE                        447
#define D2FP_STRTUP_CODE                   448
#define D2FP_STRT_PRMPT_ALIGN              449
#define D2FP_STRT_PRMPT_OFST               450
#define D2FP_SUBCL_OBJGRP                  451
#define D2FP_SUBCL_SUBOBJ                  452
#define D2FP_SUB_MNU_NAM                   453
#define D2FP_SUB_MNU_OBJ                   454
#define D2FP_SUB_TTL                       455
#define D2FP_SUB_TTL_STRID                 456
#define D2FP_SUMM_BLK_NAM                  457
#define D2FP_SUMM_FUNC                     458
#define D2FP_SUMM_ITM_NAM                  459
#define D2FP_SVPNT_MODE                    460
#define D2FP_SYNC_ITM_NAM                  461
#define D2FP_SYNC_ITM_OBJ                  462
#define D2FP_TAB_ACT_STY                   463
#define D2FP_TAB_ATT_EDGE                  464
#define D2FP_TAB_PAGE                      465
#define D2FP_TAB_STY                       466
#define D2FP_TAB_WID_STY                   467
#define D2FP_TBP_NAM                       468
#define D2FP_TBP_OBJ                       469
#define D2FP_TEAR_OFF_MNU                  470
#define D2FP_TEXT                          471
#define D2FP_TEXT_SEG                      472
#define D2FP_TEXT_STRID                    473
#define D2FP_TITLE                         474
#define D2FP_TITLE_STRID                   475
#define D2FP_TOOLTIP                       476
#define D2FP_TOOLTIP_STRID                 477
#define D2FP_TOOLTIP_VAT_GRP               478
#define D2FP_TOP_PRMPT_ALIGN               479
#define D2FP_TOP_PRMPT_OFST                480
#define D2FP_TRE_ALLW_EMP_BRANCH           481
#define D2FP_TRE_DATA_QRY                  482
#define D2FP_TRE_MULTI_SELECT              483
#define D2FP_TRE_REC_GRP                   484
#define D2FP_TRE_SHOW_LINES                485
#define D2FP_TRE_SHOW_SYMBOL               486
#define D2FP_TRG_INTERNAL_TYP              487
#define D2FP_TRG_STY                       488
#define D2FP_TRG_TXT                       489
#define D2FP_TRIGGER                       490
#define D2FP_TTL_READING_ORDR              491
#define D2FP_UNCHKED_VAL                   492
#define D2FP_UPDT_ALLOWED                  493
#define D2FP_UPDT_CHANGED_COLS             494
#define D2FP_UPDT_COMMIT                   495
#define D2FP_UPDT_IF_NULL                  496
#define D2FP_UPDT_LAYOUT                   497
#define D2FP_UPDT_PROC_NAM                 498
#define D2FP_UPDT_QRY                      499
#define D2FP_UPD_DAT_SRC_ARG               500
#define D2FP_UPD_DAT_SRC_COL               501
#define D2FP_USE_3D_CNTRLS                 502
#define D2FP_USE_SECURITY                  503
#define D2FP_VALIDATE_FROM_LST             504
#define D2FP_VALIDATION_UNIT               505
#define D2FP_VAT_NAM                       506
#define D2FP_VAT_OBJ                       507
#define D2FP_VAT_TYP                       508
#define D2FP_VERT_FILL                     509
#define D2FP_VERT_JST                      510
#define D2FP_VERT_MARGN                    511
#define D2FP_VERT_OBJ_OFST                 512
#define D2FP_VERT_ORGN                     513
#define D2FP_VERT_TLBR_CNV                 514
#define D2FP_VISIBLE                       515
#define D2FP_VIS_ATTR                      516
#define D2FP_VPRT_HGT                      517
#define D2FP_VPRT_WID                      518
#define D2FP_VPRT_X_POS                    519
#define D2FP_VPRT_X_POS_ON_CNV             520
#define D2FP_VPRT_Y_POS                    521
#define D2FP_VPRT_Y_POS_ON_CNV             522
#define D2FP_VSBL_IN_HORZ_MNU_TLBR         523
#define D2FP_VSBL_IN_MENU                  524
#define D2FP_VSBL_IN_VERT_MNU_TLBR         525
#define D2FP_VTB_CNV_NAME                  526
#define D2FP_WHERE_CLAUSE                  527
#define D2FP_WHITE_ON_BLACK                528
#define D2FP_WIDTH                         529
#define D2FP_WINDOW                        530
#define D2FP_WIN_STY                       531
#define D2FP_WND_NAM                       532
#define D2FP_WND_OBJ                       533
#define D2FP_WRAP_STY                      534
#define D2FP_WRAP_TXT                      535
#define D2FP_X_POS                         536
#define D2FP_Y_POS                         537
#define D2FP_COLUMN_VALUE                  538
#define D2FP_GRA_TEXT_STRID                539
#define D2FP_NEWDEFER_REQ_ENF              540
#define D2FP_CHAR_MODE_LOGICAL_ATTR        541
#define D2FP_ABORT_FAIL                    542
#define D2FP_FAIL_LABEL                    543
#define D2FP_FAIL_MSG                      544
#define D2FP_NEW_CURSOR                    545
#define D2FP_REV_RET                       546
#define D2FP_SUCC_ABORT                    547
#define D2FP_SUCC_LABEL                    548
#define D2FP_TRIG_STEP_TXT                 549
#define D2FP_TRIG_STEP                     550
#define D2FP_QRY_NAME                      551

#define D2FP_MAX                           551

/* E_Properties */

/* C++ Support */
#ifdef __cplusplus
}
#endif


#endif /* D2FDEF */






































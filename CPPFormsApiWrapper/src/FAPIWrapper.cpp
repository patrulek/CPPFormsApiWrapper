#include "FAPIWrapper.h"

#include "d2fctx.h"

#include "FAPIContext.h"
#include "FAPIModule.h"
#include "Exceptions.h"

#include <algorithm>

#include "FAPILogger.h"

namespace CPPFAPIWrapper {
   using namespace std;

   string getLibVersion() {
      return "1.0.0";
   }

   unique_ptr<FAPIContext> createContext(const string & _connstring) { TRACE_FNC(_connstring)
      auto ctx = make_unique<FAPIContext>();

      if( _connstring != "" )
         ctx->connectContextToDB(_connstring);

      return ctx;
   }

   int typeNameToID(const string & _type_name) { TRACE_FNC(_type_name)
      auto ret = find(obj_types.begin(), obj_types.end(), _type_name) - obj_types.begin();
      FAPILogger::debug(to_string(ret));

      if( ret > obj_types.size() )
         throw FAPIException(Reason::OTHER, __FILE__, __LINE__, _type_name);

      return ret;
   }

   bool isIrrelevantProperty(const int _prop_num) { TRACE_FNC(to_string(_prop_num))
      return _prop_num == D2FP_FRST_NAVIGATION_BLK_OBJ || _prop_num == D2FP_NXT_NAVIGATION_BLK_OBJ
            || _prop_num == D2FP_PREV_NAVIGATION_BLK_OBJ || _prop_num == D2FP_OBJ_GRP_CHILD_REAL_OBJ
            || _prop_num == D2FP_OG_CHILD || _prop_num == D2FP_SOURCE || _prop_num == D2FP_DIRTY_INFO
            || _prop_num == D2FP_ACCESS_KEY_STRID || _prop_num == D2FP_ALT_MSG_STRID
            || _prop_num == D2FP_BLK_DSCRP_STRID || _prop_num == D2FP_BTM_TTL_STRID
            || _prop_num == D2FP_BTN_1_LBL_STRID || _prop_num == D2FP_BTN_2_LBL_STRID
            || _prop_num == D2FP_BTN_3_LBL_STRID || _prop_num == D2FP_FAIL_MSG_STRID
            || _prop_num == D2FP_FRAME_TTL_STRID || _prop_num == D2FP_HIGHEST_VAL_STRID
            || _prop_num == D2FP_HINT_STRID || _prop_num == D2FP_HLP_DSCRP_STRID || _prop_num == D2FP_INIT_VAL_STRID
            || _prop_num == D2FP_KBRD_ACC_STRID || _prop_num == D2FP_KBRD_HLP_TXT_STRID
            || _prop_num == D2FP_LABEL_STRID || _prop_num == D2FP_LOWEST_VAL_STRID || _prop_num == D2FP_MINIMIZE_TTL_STRID
            || _prop_num == D2FP_MNU_PARAM_INIT_VAL_STRID || _prop_num == D2FP_PARAM_INIT_VAL_STRID
            || _prop_num == D2FP_PRMPT_STRID || _prop_num == D2FP_SUB_TTL_STRID || _prop_num == D2FP_TEXT_STRID
            || _prop_num == D2FP_TITLE_STRID || _prop_num == D2FP_TOOLTIP_STRID || _prop_num == D2FP_PERSIST_CLIENT_INFO
            || _prop_num == D2FP_SUBCL_SUBOBJ ||_prop_num == D2FP_SUBCL_OBJGRP;
   }

   bool isNonInheritableProperty(const int _prop_num) { TRACE_FNC(to_string(_prop_num))
      return _prop_num == D2FP_NAME || _prop_num == D2FP_PAR_FLNAM || _prop_num == D2FP_PAR_FLPATH
            || _prop_num == D2FP_PAR_MODSTR || _prop_num == D2FP_PAR_MODTYP || _prop_num == D2FP_PAR_MODULE
            || _prop_num == D2FP_PAR_NAM || _prop_num == D2FP_PAR_SL1OBJ_NAM || _prop_num == D2FP_PAR_SL1OBJ_TYP
            || _prop_num == D2FP_PAR_SL2OBJ_NAM || _prop_num == D2FP_PAR_SL2OBJ_TYP || _prop_num == D2FP_PAR_TYP;
   }

   // TODO
   unordered_map<int, vector<int>> type_hierarchy = {
      { D2FFO_FORM_MODULE, {D2FFO_TRIGGER, D2FFO_ALERT, D2FFO_ATT_LIB, D2FFO_BLOCK, D2FFO_CANVAS, D2FFO_EDITOR, D2FFO_LOV, D2FFO_OBJ_GROUP, D2FFO_FORM_PARAM, D2FFO_MENU, D2FFO_PROG_UNIT, D2FFO_PROP_CLASS, D2FFO_REC_GROUP, D2FFO_REPORT, D2FFO_VIS_ATTR, D2FFO_WINDOW, D2FFO_COORD } },
      { D2FFO_ATT_LIB, { D2FFO_LIB_PROG_UNIT } },
      { D2FFO_BLOCK, { D2FFO_ITEM, D2FFO_TRIGGER, D2FFO_RELATION } },
      { D2FFO_ITEM, { D2FFO_TRIGGER, D2FFO_RADIO_BUTTON } },
      { D2FFO_CANVAS, { D2FFO_GRAPHIC } },
      { D2FFO_GRAPHIC, { D2FFO_GRAPHIC, D2FFO_CMPTXT } },
      { D2FFO_CMPTXT, { D2FFO_TEXT_SEG } } ,
      { D2FFO_LOV, { D2FFO_LV_COLMAP } },
      { D2FFO_OBJ_GROUP, { D2FFO_OBG_CHILD } },
      { D2FFO_MENU, { D2FFO_MENU_ITEM } },
      { D2FFO_PROP_CLASS, { D2FFO_TRIGGER } },
      { D2FFO_REC_GROUP, { D2FFO_RG_COLSPEC } }
   };

   const vector<string> errors = {
      "Operation succeded",
      "Operation failed",
      "Operation returned YES",
      "Operation returned NO",
      "Bad context provided",
      "Bad property",
      "One of the args is wrong",
      "Object type is unknown",
      "Unexpected object",
      "Unexpected parent",
      "Null object passed",
      "Null pointer to object",
      "Null property",
      "Not connected to DB",
      "Out of memory",
      "Message file not found",
      "Generation failed",
      "Not implemented yet",
      "Passed in type does not match the actual object",
      "The operation failed partially, but the error was not fatal",
      "Null data passed in",
      "Data passed in is invalid",
      "Index in is invalid",
      "The object does not have the given property",
      "Initialization failed because a NULL Instance Handle passed (Applies to Windows only)",
      "The operation failed because the object being created/places was not unique. An object with this name already exists",
      "The object was not found",
      "Function can only be called in translation mode",
      "The database context passed in is invalid",
      "A subclassed module could not be found during loading",
      "Duplicate String ID (This slot in the string table has already been used)",
      "A supplied value parameter was out of the legal range",
      "The specified file was not found",
      "An attached library could not be found"
   };

   const vector<string> obj_types = {
      "ANY",
      "ALERT",
      "ATT_LIB",
      "BLOCK",
      "CANVAS",
      "COORD",
      "DAT_SRC_ARG",
      "DAT_SRC_COL",
      "EDITOR",
      "FONT",
      "FORM_MODULE",
      "FORM_PARAM",
      "GRAPHIC",
      "ITEM",
      "LIBRARY_MODULE",
      "LOV",
      "LV_COLMAP",
      "MENU",
      "MENU_ITEM",
      "MENU_MODULE",
      "MENU_PARAM",
      "OBJ_GROUP",
      "OBG_CHILD",
      "OBJ_LIB",
      "OBJ_LIB_TAB",
      "PROG_UNIT",
      "PROP_CLASS",
      "RADIO_BUTTON",
      "REC_GROUP",
      "RELATION",
      "REPORT",
      "RG_COLSPEC",
      "TAB_PAGE",
      "TRIGGER",
      "VIS_ATTR",
      "WINDOW",
      "LIB_PROG_UNIT",
      "COLUMN_VALUE",
      "TRIG_STEP",
      "TRIG_STEP",
      "NONE",
      "ACCESS_KEY"
   };

   const vector<string> prop_consts = {
      "NONE",
      "ACCESS_KEY",
      "ACCESS_KEY_STRID",
      "ALERT",
      "ALIAS",
      "ALLOW_EXPANSION",
      "ALLOW_MLT_LIN_PRMPTS",
      "ALLOW_STRT_ATT_PRMPTS",
      "ALLOW_TOP_ATT_PRMPTS",
      "ALT_MSG",
      "ALT_MSG_STRID",
      "ALT_STY",
      "ARROW_STY",
      "ASSOC_MENUS_COUNT",
      "ASSOC_MNUS",
      "ATT_LIB",
      "AUDIO_CHNNLS",
      "AUTO_COL_WID",
      "AUTO_DISP",
      "AUTO_HINT",
      "AUTO_POS",
      "AUTO_QRY",
      "AUTO_RFRSH",
      "AUTO_SKP",
      "AUTO_SLCT",
      "BACK_COLOR",
      "BEVEL",
      "BLK_DESCRIPTION",
      "BLK_DSCRP_STRID",
      "BLOCK",
      "BOUNDING_BX_SCALABLE",
      "BTM_TTL",
      "BTM_TTL_STRID",
      "BTN_1_LBL",
      "BTN_1_LBL_STRID",
      "BTN_2_LBL",
      "BTN_2_LBL_STRID",
      "BTN_3_LBL",
      "BTN_3_LBL_STRID",
      "CALC_MODE",
      "CANVAS",
      "CAP_STY",
      "CASE_INSENSITIVE_QRY",
      "CASE_RSTRCTION",
      "CHAR_CELL_HGT",
      "CHAR_CELL_WID",
      "CHKED_VAL",
      "CHK_BX_OTHER_VALS",
      "CLIENT_INFO",
      "CLIP_HGT",
      "CLIP_WID",
      "CLIP_X_POS",
      "CLIP_Y_POS",
      "CLOSED",
      "CLS_ALLOWED",
      "CMPRSSION_QLTY",
      "CMPTXT",
      "CNV_NAM",
      "CNV_OBJ",
      "CNV_TYP",
      "COL_DAT_TYP",
      "COL_MAP",
      "COL_NAM",
      "COL_SPEC",
      "COL_VALS_COUNT",
      "COMMENT",
      "COMM_MODE",
      "COMPRESS",
      "COM_TXT",
      "COM_TYP",
      "CONCEAL_DATA",
      "CONSOLE_WIN",
      "COORD_SYS",
      "COPY_VAL_FROM_ITM",
      "CORNER_RADIUS_X",
      "CORNER_RADIUS_Y",
      "CRSR_MODE",
      "CSTM_SPCING",
      "DASH_STY",
      "DAT_SRC_BLK",
      "DAT_SRC_X_AXS",
      "DAT_SRC_Y_AXS",
      "DAT_TYP",
      "DB_BLK",
      "DB_ITM",
      "DEFERRED",
      "DEFER_REQ_ENF",
      "DEL_ALLOWED",
      "DEL_DAT_SRC_ARG",
      "DEL_DAT_SRC_COL",
      "DEL_PROC_NAM",
      "DEL_REC",
      "DETAIL_BLK",
      "DETAIL_ITEMREF",
      "DFLT_ALT_BTN",
      "DFLT_BTN",
      "DFLT_FNT_SCALING",
      "DIRTY_INFO",
      "DISP_IN_KBRD_HLP",
      "DISP_NO_PRIV",
      "DISP_QLTY",
      "DISP_WID",
      "DIST_BTWN_RECS",
      "DITHER",
      "DML_ARY_SIZ",
      "DML_DAT_NAM",
      "DML_DAT_TYP",
      "DML_RET_VAL",
      "DSA_MODE",
      "DSA_NAM",
      "DSA_TYP",
      "DSA_TYP_NAM",
      "DSA_VAL",
      "DSC_LEN",
      "DSC_MANDATORY",
      "DSC_NAM",
      "DSC_NO_CHILDREN",
      "DSC_PARENT_NAME",
      "DSC_PRECISION",
      "DSC_SCALE",
      "DSC_TYP",
      "DSC_TYPE_NAME",
      "DS_DEL_ARG_LIST",
      "DS_DEL_COL_LIST",
      "DS_INS_ARG_LIST",
      "DS_INS_COL_LIST",
      "DS_LOK_ARG_LIST",
      "DS_LOK_COL_LIST",
      "DS_QRY_ARG_LIST",
      "DS_QRY_COL_LIST",
      "DS_UPD_ARG_LIST",
      "DS_UPD_COL_LIST",
      "EDGE_BACK_COLOR",
      "EDGE_FORE_COLOR",
      "EDGE_PAT",
      "EDITOR",
      "EDT_NAM",
      "EDT_OBJ",
      "EDT_X_POS",
      "EDT_Y_POS",
      "ENABLED",
      "ENFRC_COL_SECURITY",
      "ENFRC_PRMRY_KEY",
      "EXEC_HIERARCHY",
      "EXEC_MODE",
      "FAIL_MSG_STRID",
      "FILL_PAT",
      "FIRE_IN_QRY",
      "FIXED_BOUNDING_BX",
      "FIXED_LEN",
      "FLNAM",
      "FLTR_BEFORE_DISP",
      "FMT_MSK",
      "FONT_NAM",
      "FONT_SCALEABLE",
      "FONT_SIZ",
      "FONT_SPCING",
      "FONT_STY",
      "FONT_WGHT",
      "FORE_COLOR",
      "FORMULA",
      "FORM_PARAM",
      "FRAME_ALIGN",
      "FRAME_TTL",
      "FRAME_TTL_ALIGN",
      "FRAME_TTL_BACK_COLOR",
      "FRAME_TTL_FILL_PAT",
      "FRAME_TTL_FONT_NAM",
      "FRAME_TTL_FONT_SIZ",
      "FRAME_TTL_FONT_SPCING",
      "FRAME_TTL_FONT_STY",
      "FRAME_TTL_FONT_WGHT",
      "FRAME_TTL_FORE_COLOR",
      "FRAME_TTL_OFST",
      "FRAME_TTL_SPCING",
      "FRAME_TTL_STRID",
      "FRAME_TTL_VAT_NAM",
      "FRAME_TTL_VAT_OBJ",
      "FRST_NAVIGATION_BLK_NAM",
      "FRST_NAVIGATION_BLK_OBJ",
      "GRAPHIC",
      "GRAPHICS_TYP",
      "GRA_FONT_COLOR",
      "GRA_FONT_COLOR_CODE",
      "GRA_FONT_NAM",
      "GRA_FONT_SIZ",
      "GRA_FONT_SPCING",
      "GRA_FONT_STY",
      "GRA_FONT_WGHT",
      "GRA_TEXT",
      "HEIGHT",
      "HELP_BOOK_TITLE",
      "HELP_BOOK_TOPIC",
      "HIDE",
      "HIDE_ON_EXIT",
      "HIGHEST_ALLOWED_VAL",
      "HIGHEST_VAL_STRID",
      "HINT",
      "HINT_STRID",
      "HLP_DESCRIPTION",
      "HLP_DSCRP_STRID",
      "HORZ_JST",
      "HORZ_MARGN",
      "HORZ_OBJ_OFST",
      "HORZ_ORGN",
      "HORZ_TLBR_CNV",
      "HTB_CNV_NAME",
      "ICONIC",
      "ICON_FLNAM",
      "ICON_IN_MNU",
      "IMG_DPTH",
      "IMG_FMT",
      "IMPL_CLASS",
      "INCLUDE_REFITEM",
      "INHRT_MNU",
      "INIT_KBRD_DIR",
      "INIT_MNU",
      "INIT_VAL",
      "INIT_VAL_STRID",
      "INSRT_ALLOWED",
      "INSRT_PROC_NAM",
      "INS_DAT_SRC_ARG",
      "INS_DAT_SRC_COL",
      "INTERACTION_MODE",
      "INTERNAL_END_ANGLE",
      "INTERNAL_LIN_WID",
      "INTERNAL_ROTATION_ANGLE",
      "INTERNAL_STRT_ANGLE",
      "ISOLATION_MODE",
      "ITEM",
      "ITMS_DISP",
      "ITM_TYP",
      "JOIN_COND",
      "JOIN_STY",
      "JUSTIFICATION",
      "KBRD_ACC",
      "KBRD_ACC_STRID",
      "KBRD_HLP_TXT",
      "KBRD_HLP_TXT_STRID",
      "KBRD_NAVIGABLE",
      "KBRD_STATE",
      "KEEP_CRSR_POS",
      "KEY_MODE",
      "LABEL",
      "LABEL_STRID",
      "LANG",
      "LANG_DIR",
      "LAYOUT_DATA_BLK_NAM",
      "LAYOUT_STY",
      "LIB_LOC",
      "LIB_PROG_UNIT",
      "LIB_SRC",
      "LIN_SPCING",
      "LIST_ELEM",
      "LOCK_DAT_SRC_ARG",
      "LOCK_DAT_SRC_COL",
      "LOCK_MODE",
      "LOCK_PROC_NAM",
      "LOCK_REC",
      "LOV",
      "LOV_NAM",
      "LOV_OBJ",
      "LOV_X_POS",
      "LOV_Y_POS",
      "LOWEST_ALLOWED_VAL",
      "LOWEST_VAL_STRID",
      "LST_ELEMENT_COUNT",
      "LST_IN_BLK_MNU",
      "LST_STY",
      "LST_TYP",
      "MAGIC_ITM",
      "MAIN_MNU",
      "MAXIMIZE_ALLOWED",
      "MAX_LEN",
      "MAX_OBJS",
      "MAX_QRY_TIME",
      "MAX_RECS_FETCHED",
      "MENU",
      "MINIMIZE_ALLOWED",
      "MINIMIZE_TTL",
      "MINIMIZE_TTL_STRID",
      "MLT_LIN",
      "MNU_DRCTRY",
      "MNU_FLNAM",
      "MNU_ITM",
      "MNU_ITM_CODE",
      "MNU_ITM_RAD_GRP",
      "MNU_ITM_TYP",
      "MNU_MOD",
      "MNU_PARAM",
      "MNU_PARAM_INIT_VAL",
      "MNU_PARAM_INIT_VAL_STRID",
      "MNU_ROLE",
      "MNU_SRC",
      "MNU_STY",
      "MODAL",
      "MODULE",
      "MOUSE_NAVIGATE",
      "MOUSE_NAVIGATION_LMT",
      "MV_ALLOWED",
      "NAME",
      "NAVIGATION_STY",
      "NEXT",
      "NXT_NAVIGATION_BLK_NAM",
      "NXT_NAVIGATION_BLK_OBJ",
      "NXT_NAVIGATION_ITM_NAM",
      "NXT_NAVIGATION_ITM_OBJ",
      "OBJ_COUNT",
      "OBJ_GRP",
      "OBJ_GRP_CHILD_REAL_OBJ",
      "OBJ_LIB_TAB",
      "OG_CHILD",
      "OLD_LOV_TXT",
      "OLE_ACT_STY",
      "OLE_CLASS",
      "OLE_INSD_OUT_SUPPORT",
      "OLE_IN_PLACE_ACT",
      "OLE_POPUP_MNU_ITMS",
      "OLE_RESIZ_STY",
      "OLE_SHOW_POPUP_MNU",
      "OLE_SHOW_TNNT_TYP",
      "OLE_TNNT_ASPCT",
      "OLE_TNNT_TYP",
      "OPT_HINT",
      "ORDR_BY_CLAUSE",
      "OTHER_VALS",
      "OWNER",
      "PARAM_DAT_TYP",
      "PARAM_INIT_VAL",
      "PARAM_INIT_VAL_STRID",
      "PAR_FLNAM",
      "PAR_FLPATH",
      "PAR_MODSTR",
      "PAR_MODTYP",
      "PAR_MODULE",
      "PAR_NAM",
      "PAR_SL1OBJ_NAM",
      "PAR_SL1OBJ_TYP",
      "PAR_SL2OBJ_NAM",
      "PAR_SL2OBJ_TYP",
      "PAR_TYP",
      "PERSIST_CLIENT_INFO",
      "PERSIST_CLT_INF_LEN",
      "PGU_TXT",
      "PGU_TYP",
      "POINT",
      "POPUP_MNU_NAM",
      "POPUP_MNU_OBJ",
      "POPUP_VA_OBJ",
      "PRECOMP_SUMM",
      "PREVIOUS",
      "PREV_NAVIGATION_BLK_NAM",
      "PREV_NAVIGATION_BLK_OBJ",
      "PREV_NAVIGATION_ITM_NAM",
      "PREV_NAVIGATION_ITM_OBJ",
      "PRMPT",
      "PRMPT_ALIGN",
      "PRMPT_ALIGN_OFST",
      "PRMPT_ATT_EDGE",
      "PRMPT_ATT_OFST",
      "PRMPT_BACK_COLOR",
      "PRMPT_DISP_STY",
      "PRMPT_FILL_PAT",
      "PRMPT_FONT_NAM",
      "PRMPT_FONT_SIZ",
      "PRMPT_FONT_SPCING",
      "PRMPT_FONT_STY",
      "PRMPT_FONT_WGHT",
      "PRMPT_FORE_COLOR",
      "PRMPT_JST",
      "PRMPT_READING_ORDR",
      "PRMPT_STRID",
      "PRMPT_VAT_NAM",
      "PRMPT_VAT_OBJ",
      "PRMRY_CNV",
      "PRMRY_KEY",
      "PROG_UNIT",
      "PROP_CLASS",
      "PRVNT_MSTRLESS_OPS",
      "QRY_ALLOWED",
      "QRY_ALL_RECS",
      "QRY_DAT_SRC_ARG",
      "QRY_DAT_SRC_COL",
      "QRY_DAT_SRC_NAM",
      "QRY_DAT_SRC_TYP",
      "QRY_LEN",
      "QRY_ONLY",
      "RAD_BUT",
      "RAISE_ON_ENT",
      "RDB_VAL",
      "READING_ORDR",
      "REAL_UNIT",
      "RECS_BUFFERED_COUNT",
      "RECS_DISP_COUNT",
      "RECS_FETCHED_COUNT",
      "REC_GRP",
      "REC_GRP_FETCH_SIZ",
      "REC_GRP_NAM",
      "REC_GRP_OBJ",
      "REC_GRP_QRY",
      "REC_GRP_TYP",
      "REC_ORNT",
      "REC_VAT_GRP_NAM",
      "REC_VAT_GRP_OBJ",
      "REL",
      "REL_TYPE",
      "RENDERED",
      "REPORT",
      "REQUIRED",
      "RESIZE_ALLOWED",
      "REV_DIR",
      "ROLE_COUNT",
      "RPT_DESTINATION_FMT",
      "RPT_DESTINATION_NAM",
      "RPT_DESTINATION_TYP",
      "RPT_PARAMS",
      "RPT_SRVR",
      "RTRN_ITM",
      "RUNTIME_COMP",
      "SCRLBR_ALIGN",
      "SCRLBR_CNV_NAM",
      "SCRLBR_CNV_OBJ",
      "SCRLBR_LEN",
      "SCRLBR_ORNT",
      "SCRLBR_TBP_NAM",
      "SCRLBR_TBP_OBJ",
      "SCRLBR_WID",
      "SCRLBR_X_POS",
      "SCRLBR_Y_POS",
      "SHARE_LIB",
      "SHOW_FAST_FWD",
      "SHOW_HORZ_SCRLBR",
      "SHOW_PALETTE",
      "SHOW_PLAY",
      "SHOW_REC",
      "SHOW_REWIND",
      "SHOW_SCRLBR",
      "SHOW_SLIDER",
      "SHOW_TIME",
      "SHOW_VERT_SCRLBR",
      "SHOW_VOLUME",
      "SHRINKWRAP",
      "SIZING_STY",
      "SND_FMT",
      "SND_QLTY",
      "SNGL_OBJ_ALIGN",
      "SNGL_REC",
      "SOURCE",
      "STRTUP_CODE",
      "STRT_PRMPT_ALIGN",
      "STRT_PRMPT_OFST",
      "SUBCL_OBJGRP",
      "SUBCL_SUBOBJ",
      "SUB_MNU_NAM",
      "SUB_MNU_OBJ",
      "SUB_TTL",
      "SUB_TTL_STRID",
      "SUMM_BLK_NAM",
      "SUMM_FUNC",
      "SUMM_ITM_NAM",
      "SVPNT_MODE",
      "SYNC_ITM_NAM",
      "SYNC_ITM_OBJ",
      "TAB_ACT_STY",
      "TAB_ATT_EDGE",
      "TAB_PAGE",
      "TAB_STY",
      "TAB_WID_STY",
      "TBP_NAM",
      "TBP_OBJ",
      "TEAR_OFF_MNU",
      "TEXT",
      "TEXT_SEG",
      "TEXT_STRID",
      "TITLE",
      "TITLE_STRID",
      "TOOLTIP",
      "TOOLTIP_STRID",
      "TOOLTIP_VAT_GRP",
      "TOP_PRMPT_ALIGN",
      "TOP_PRMPT_OFST",
      "TRE_ALLW_EMP_BRANCH",
      "TRE_DATA_QRY",
      "TRE_MULTI_SELECT",
      "TRE_REC_GRP",
      "TRE_SHOW_LINES",
      "TRE_SHOW_SYMBOL",
      "TRG_INTERNAL_TYP",
      "TRG_STY",
      "TRG_TXT",
      "TRIGGER",
      "TTL_READING_ORDR",
      "UNCHKED_VAL",
      "UPDT_ALLOWED",
      "UPDT_CHANGED_COLS",
      "UPDT_COMMIT",
      "UPDT_IF_NULL",
      "UPDT_LAYOUT",
      "UPDT_PROC_NAM",
      "UPDT_QRY",
      "UPD_DAT_SRC_ARG",
      "UPD_DAT_SRC_COL",
      "USE_3D_CNTRLS",
      "USE_SECURITY",
      "VALIDATE_FROM_LST",
      "VALIDATION_UNIT",
      "VAT_NAM",
      "VAT_OBJ",
      "VAT_TYP",
      "VERT_FILL",
      "VERT_JST",
      "VERT_MARGN",
      "VERT_OBJ_OFST",
      "VERT_ORGN",
      "VERT_TLBR_CNV",
      "VISIBLE",
      "VIS_ATTR",
      "VPRT_HGT",
      "VPRT_WID",
      "VPRT_X_POS",
      "VPRT_X_POS_ON_CNV",
      "VPRT_Y_POS",
      "VPRT_Y_POS_ON_CNV",
      "VSBL_IN_HORZ_MNU_TLBR",
      "VSBL_IN_MENU",
      "VSBL_IN_VERT_MNU_TLBR",
      "VTB_CNV_NAME",
      "WHERE_CLAUSE",
      "WHITE_ON_BLACK",
      "WIDTH",
      "WINDOW",
      "WIN_STY",
      "WND_NAM",
      "WND_OBJ",
      "WRAP_STY",
      "WRAP_TXT",
      "X_POS",
      "Y_POS",
      "COLUMN_VALUE",
      "GRA_TEXT_STRID",
      "NEWDEFER_REQ_ENF",
      "CHAR_MODE_LOGICAL_ATTR",
      "ABORT_FAIL",
      "FAIL_LABEL",
      "FAIL_MSG",
      "NEW_CURSOR",
      "REV_RET",
      "SUCC_ABORT",
      "SUCC_LABEL",
      "TRIG_STEP_TXT",
      "QRY_NAME"
   };

   #ifdef PL_LANG
      const vector<string> prop_names = {
         "Brak",
         "Klawisz skrótu",
         "ID napisu klucza dostępu",
         "Alert Object",
         "Alias",
         "Powiększanie dozwolone",
         "Etykiety wieloliniowe dozwolone",
         "Etykiety dołączone do początku dozwolone",
         "Etykiety dołączone u góry dozwolone",
         "Komunikat",
         "ID napisu komunikatu",
         "Styl alertu",
         "Styl strzałki",
         "Liczba powiązanych menu",
         "Powiązane menu",
         "Attached Library",
         "Kanały audio",
         "Automatyczna szerokość kolumn",
         "Automatyczne wyświetlanie",
         "Automatyczne wyświetlanie podpowiedzi",
         "Automatyczna pozycja",
         "Automatyczne zapytanie",
         "Automatyczne odświeżanie",
         "Automatyczne przejście",
         "Automatyczny wybór",
         "Kolor tła",
         "Kant",
         "Opis bloku danych",
         "ID napisu opisu bloku danych",
         "Data Block Object",
         "Skalowalne pole ograniczające",
         "Tytuł dolny",
         "ID napisu dolnego tytułu",
         "Etykieta przycisku 1",
         "ID napisu etykiety przycisku 1",
         "Etykieta przycisku 2",
         "ID napisu etykiety przycisku 2",
         "Etykieta przycisku 3",
         "ID napisu etykiety przycisku 3",
         "Rodzaj obliczenia",
         "Canvas Object",
         "Styl zakończenia",
         "Zapytania niewrażliwe na wielkość liter",
         "Ograniczenie wielkości liter",
         "Wysokość komórki znaku",
         "Szerokość komórki znaku",
         "Wartość zaznaczonego pola",
         "Odwzorowanie innych wartości w polu wyboru",
         "Case Info",
         "Wysokość wycinka",
         "Szerokość wycinka",
         "Pozycja X wycinka",
         "Pozycja Y wycinka",
         "Zamknięty",
         "Zamykanie dozwolone",
         "Jakość kompresji",
         "Compound Text Object",
         "Kanwa",
         "Canvas Object Pointer",
         "Typ kanwy",
         "Typ danych w kolumnie",
         "Column Mapping Object",
         "Nazwa kolumny",
         "Column Specification Object",
         "Liczba elementów danych w kolumnie",
         "Komentarz",
         "Tryb komunikacji",
         "Kompresja",
         "Tekst polecenia",
         "Typ polecenia",
         "Ukrywanie danych",
         "Okno konsoli",
         "System współrzędnych",
         "Wartość kopiowana z elementu",
         "Promień X rogu",
         "Promień Y rogu",
         "Tryb kursora",
         "Inny odstęp",
         "Styl kreski",
         "Źródłowy blok danych",
         "Oś X w źródle danych",
         "Oś Y w źródle danych",
         "Typ danych",
         "Blok bazy danych",
         "Element bazy danych",
         "Odroczona",
         "Odrocz wymagane wymuszenie",
         "Usuwanie dozwolone",
         "Delete Argument Object",
         "Delete Column Object",
         "Procedura usuwająca - nazwa",
         "Usuwanie rekordu nadrzędnego",
         "Podrzędny blok danych",
         "Element odwołania podrzędnego",
         "Domyślny przycisk alertu",
         "Przycisk domyślny",
         "Skalowanie wg domyślnej czcionki",
         "Dirty info",
         "Wyświetlany w oknie \'Klawisze\'",
         "Wyświetlany mimo braku uprawnień",
         "Jakość wyświetlania",
         "Szerokość wyświetlania",
         "Odległość między rekordami",
         "Opcja symulacji kolorów (dithering)",
         "DML - rozmiar tablicy",
         "DML - nazwa celu dla danych",
         "DML - typ celu dla danych",
         "Zwracana wartość DML",
         "Tryb argumentu",
         "Nazwa argumentu",
         "Typ argumentu",
         "Nazwa typu argumentu",
         "Wartość argumentu",
         "Długość",
         "Wymagany",
         "Nazwa kolumny",
         "No children",
         "Kolumna nadrzędna",
         "Precyzja",
         "Skala",
         "Typ kolumny",
         "Nazwa typu kolumny",
         "Procedura usuwająca - argumenty",
         "Procedura usuwająca - kolumny zbioru wynikowego",
         "Procedura wstawiająca - argumenty",
         "Procedura wstawiająca - kolumny zbioru wynikowego",
         "Procedura blokująca - argumenty",
         "Procedura blokująca - kolumny zbioru wynikowego",
         "Zapytania - argumenty źródła danych",
         "Zapytania - kolumny źródła danych",
         "Procedura modyfikująca - argumenty",
         "Procedura modyfikująca - kolumny zbioru wynikowego",
         "Kolor tła krawędzi",
         "Kolor pierwszego planu krawędzi",
         "Wzór krawędzi",
         "Editor Object",
         "Edytor",
         "Editor Object Pointer",
         "Pozycja X edytora",
         "Pozycja Y edytora",
         "Obiekt włączony",
         "Zabezpieczenie kolumn",
         "Wymuszanie klucza głównego",
         "Hierarchia wykonywania",
         "Tryb wykonywania",
         "ID napisu komunikatu niepowodzenia",
         "Wzór wypełnienia",
         "Uruchamiany w trybie wprowadzania zapytania",
         "Ustalone pole ograniczające",
         "Stała długość",
         "Nazwa pliku",
         "Filtrowanie przed wyświetleniem",
         "Maska formatu",
         "Nazwa czcionki",
         "Skalowalna czcionka",
         "Rozmiar czcionki",
         "Odstęp czcionki",
         "Styl czcionki",
         "Grubość czcionki",
         "Kolor pierwszego planu",
         "Formuła",
         "Form Parameter Object",
         "Wyrównanie obiektów w ramce",
         "Tytuł ramki",
         "Wyrównanie tytułu ramki",
         "Kolor tła tytułu ramki",
         "Wzór wypełnienia tytułu ramki",
         "Nazwa czcionki tytułu ramki",
         "Rozmiar czcionki tytułu ramki",
         "Odstęp czcionki tytułu ramki",
         "Styl czcionki tytułu ramki",
         "Grubość czcionki tytułu ramki",
         "Kolor tytułu ramki",
         "Przesunięcie tytułu ramki",
         "Odstęp wokół tytułu ramki",
         "ID napisu tytułu ramki",
         "Grupa atrybutów wizualnych tytułu ramki",
         "Title VA Object",
         "Pierwszy blok danych w nawigacji",
         "First Data Block Object",
         "Boilerplate Object",
         "Typ grafiki",
         "Kolor tekstu grafiki",
         "Kod koloru tekstu grafiki",
         "Nazwa czcionki obiektu graficznego",
         "Rozmiar czcionki obiektu graficznego",
         "Graphic Font Spacing",
         "Styl czcionki obiektu graficznego",
         "Graphic Font Weight",
         "Tekst obiektu graficznego",
         "Wysokość",
         "Tytuł Pomocy",
         "Temat Pomocy",
         "Hide Object",
         "Ukrywane przy wyjściu",
         "Najwyższa dozwolona wartość",
         "ID napisu wysokiej wartości",
         "Podpowiedź",
         "ID napisu wskazówki",
         "Opis pomocy",
         "ID napisu opisu pomocy",
         "Wyrównania tekstu w poziomie",
         "Margines poziomy",
         "Pozioma odległość między obiektami",
         "Poziomy punkt początkowy",
         "Kanwa poziomego paska narzędzi",
         "Kanwa poziomego paska narzędzi",
         "Ikona",
         "Nazwa pliku ikony",
         "Ikona w menu",
         "Głębokość obrazu",
         "Format obrazu",
         "Klasa implementacji",
         "Uwzględnij element REF",
         "Dziedziczenie menu",
         "Początkowy stan klawiatury",
         "Początkowe menu",
         "Wartość początkowa",
         "ID napisu wartości początkowej elementu",
         "Wstawianie dozwolone",
         "Procedura wstawiająca - nazwa",
         "Insert Argument Object",
         "Insert Column Object",
         "Tryb współdziałania",
         "Kąt końca",
         "Szerokość linii",
         "Kąt obrotu",
         "Kąt początku",
         "Tryb izolacji",
         "Item Object",
         "Liczba wyświetlanych elementów",
         "Typ elementu",
         "Warunek złączenia",
         "Styl złączenia",
         "Wyrównanie tekstu",
         "Akcelerator klawiatury",
         "ID napisu akceleratora klawiatury",
         "Tekst w oknie \'Klawisze\'",
         "ID napisu tekstu \'Pomoc klawiatury\'",
         "Nawigacja za pomocą klawiatury",
         "Stan klawiatury",
         "Zachowywanie pozycji kursora",
         "Tryb klucza",
         "Etykieta",
         "ID napisu etykiety",
         "Language Object",
         "Kierunek",
         "Blok danych układu",
         "Styl układu",
         "Lokalizacja biblioteki PL/SQL",
         "Jednostka programu biblioteki PL/SQL",
         "Źródło biblioteki PL/SQL",
         "Odstęp między liniami",
         "List Element Object",
         "Lock Argument Object",
         "Lock Column Object",
         "Tryb blokowania",
         "Procedura blokująca - nazwa",
         "Blokowanie rekordu",
         "LOV Object",
         "Lista wartości",
         "LOV Object Pointer",
         "Pozycja X listy",
         "Pozycja Y listy",
         "Najniższa dozwolona wartość",
         "ID napisu niskiej wartości",
         "Liczba elementów w liście",
         "Włączony do menu bloków danych",
         "Styl listy",
         "Typ listy",
         "Element specjalny",
         "Menu główne",
         "Maksymalizacja dozwolona",
         "Maksymalna długość",
         "Maksymalna liczba obiektów w linii",
         "Maksymalny czas zapytania",
         "Maksymalna liczba pobieranych rekordów",
         "Menu Object",
         "Minimalizacja dozwolona",
         "Tytuł zminimalizowanego okna",
         "ID napisu tytułu ikony",
         "Wieloliniowy",
         "Katalog menu",
         "Nazwa pliku menu",
         "Menu Item Object",
         "Kod elementu menu",
         "Grupa radiowych elementów menu",
         "Typ elementu menu",
         "Moduł menu",
         "Menu Parameter Object",
         "Początkowa wartość parametru menu",
         "ID napisu wartości początkowej parametru manu",
         "Rola menu",
         "Źródło menu",
         "Menu Style",
         "Modalne",
         "Owning Module",
         "Nawigacja za pomocą myszy",
         "Ograniczenie nawigacji myszą",
         "Przesuwanie dozwolone",
         "Nazwa",
         "Styl nawigacji",
         "Next Object",
         "Następny blok danych w nawigacji",
         "Next Data Block Object",
         "Następny element w nawigacji",
         "Next Item Object",
         "Licznik obiektów",
         "Object Group Object",
         "Rzeczywisty obiekt wskazany przez podrzędny element grupy obiektów",
         "Object Library Tab",
         "Object Group Child Object",
         "Tekst listy wartości starego typu",
         "OLE - styl uaktywniania",
         "OLE - klasa",
         "OLE - obsługa uaktywniania typu \'inside-out\'",
         "OLE - uaktywnianie w miejscu",
         "OLE - elementy menu podręcznego",
         "OLE - styl zmiany rozmiaru",
         "OLE - pokaż menu podręczne",
         "OLE - pokaż typ wstawionego obiektu (tenant)",
         "OLE - wyświetlana postać obiektów (tenant)",
         "OLE - typ wstawianych obiektów (tenant)",
         "Wskazówka dla optymalizatora",
         "Klauzula ORDER BY",
         "Odwzorowanie innych wartości",
         "Owning Object",
         "Typ danych parametru",
         "Wartość początkowa parametru",
         "ID napisu wartości początkowej parametru",
         "Nazwa pliku nadrzędnego obiektu",
         "îcieżka pliku nadrzędnego obiektu",
         "Typ składowania modułu nadrzędnego obiektu",
         "Typ modułu nadrzędnego obiektu",
         "Moduł nadrzędnego obiektu",
         "Nazwa nadrzędnego obiektu",
         "Nazwa właściciela pierwszego poziomu obiektu nadrzędnego",
         "Typ właściciela pierwszego poziomu obiektu nadrzędnego",
         "Nazwa właściciela drugiego poziomu obiektu nadrzędnego",
         "Typ właściciela drugiego poziomu obiektu nadrzędnego",
         "Typ obiektu nadrzędnego",
         "Persistent Client Info Storage",
         "Persistent Client Info storage length",
         "Tekst jednostki programu",
         "Typ jednostki programu",
         "Point Object",
         "Menu podręczne",
         "Popup Menu Object",
         "Tooltip VA Object",
         "Wcześniejsze obliczanie podsumowań",
         "Previous Object",
         "Poprzedni blok danych w nawigacji",
         "Previous Data Block Object",
         "Poprzedni element w nawigacji",
         "Previous Item Object",
         "Etykieta",
         "Wyrównanie etykiety",
         "Przesunięcie wyrównania etykiety",
         "Krawędź dołączenia etykiety",
         "Przesunięcie dołączenia etykiety",
         "Prompt Background Color",
         "Styl wyświetlania etykiety",
         "Prompt Fill Pattern",
         "Nazwa czcionki dla etykiety",
         "Rozmiar czcionki etykiety",
         "Odstęp czcionki etykiety",
         "Styl czcionki etykiety",
         "Grubość czcionki etykiety",
         "Kolor etykiety",
         "Wyrównanie tekstu etykiety",
         "Kierunek czytania etykiety",
         "ID napisu zachęty",
         "Grupa atrybutów wizualnych etykiety",
         "Prompt VA Object",
         "Główna kanwa",
         "Klucz główny",
         "Program Unit Object",
         "Property Class Object",
         "Operacje bez rekordu nadrzędnego zabronione",
         "Zapytania dozwolone",
         "Pobieranie wszystkich rekordów",
         "Query Argument Object",
         "Query Column Object",
         "Zapytania - nazwa źródła danych",
         "Zapytania - typ źródła danych",
         "Długość w zapytaniu",
         "Tylko w zapytaniu",
         "Radio Button Object",
         "Przenoszona na przód przy wejściu",
         "Wartość przycisku radiowego",
         "Kierunek czytania",
         "Jednostka rzeczywista",
         "Liczba buforowanych rekordów",
         "Liczba wyświetlanych rekordów",
         "Zapytania - rozmiar tablicy",
         "Record Group Object",
         "Liczba rekordów pobieranych do grupy",
         "Grupa rekordów",
         "Record Group Object Pointer",
         "Zapytanie dla grupy rekordów",
         "Typ grupy rekordów",
         "Ułożenie rekordów",
         "Grupa atrybutów wizualnych bieżącego rekordu",
         "Current Record VA Pointer",
         "Relation Object",
         "Typ relacji",
         "Symulowany",
         "Report Object",
         "Wymagany",
         "Zmiana rozmiaru dozwolona",
         "Odwrotny kierunek przewijania",
         "Licznik ról",
         "Docelowy format raportu",
         "Nazwa miejsca docelowego raportu",
         "Miejsce docelowe raportu",
         "Inne parametry raportu",
         "Serwer raportów",
         "Element zwracany",
         "Tryb kompatybilności czasu wykonywania",
         "Wyrównanie paska przewijania",
         "Kanwa paska przewijania",
         "Scrollbar Canvas Object Pointer",
         "Długość paska przewijania",
         "Ułożenie paska przewijania",
         "Karta paska przewijania",
         "Scrollbar Tab Object",
         "Szerokość paska przewijania",
         "Pozycja X paska przewijania",
         "Pozycja Y paska przewijania",
         "Współdzielenie bibliotek z formularzem",
         "Pokaż przycisk \'Do przodu\'",
         "Poziomy pasek przewijania",
         "Paleta",
         "Pokaż przycisk \'Odtwarzanie\'",
         "Pokaż przycisk \'Nagrywanie\'",
         "Pokaż przycisk \'Cofanie\'",
         "Pasek przewijania",
         "Pokaż suwak",
         "Pokaż wskaźnik czasu",
         "Pionowy pasek przewijania",
         "Pokaż regulator siły dźwięku",
         "Obkurczanie",
         "Styl dopasowania rozmiaru",
         "Format dźwięku",
         "Jakość dźwięku",
         "Wyrównanie pojedynczego obiektu",
         "Pojedynczy rekord",
         "Source Object",
         "Kod startowy",
         "Etykieta dołączona do początku - wyrównanie",
         "Etykieta dołączona do początku - przesunięcie",
         "Subclass Object Group",
         "Subclass Subobject",
         "Nazwa podmenu",
         "Submenu Object",
         "Podtytuł",
         "ID napisu podtytułu",
         "Podsumowywany blok",
         "Funkcja podsumowująca",
         "Podsumowywany element",
         "Tryb punktu zachowania",
         "Synchronizowany z elementem",
         "Mirror Item Object",
         "Styl uaktywnienia",
         "Krawędź dołączenia etykiet kart",
         "Tab Page",
         "Styl narożnika",
         "Styl zmiany rozmiaru",
         "Karta",
         "Tab Page Name",
         "Menu odrywalne",
         "Wartość elementu listy",
         "Simple Text Object",
         "ID napisu graficznego",
         "Tytuł",
         "ID napisu tytułu",
         "Podpowiedź w dymku",
         "ID napisu wskazówki narzędzi",
         "Grupa atrybutów wizualnych podpowiedzi w dymku",
         "Etykieta dołączona u góry - wyrównanie",
         "Etykieta dołączona u góry - przesunięcie",
         "Zezwól na tworzenie pustych gałęzi",
         "Zapytanie",
         "Wybieranie wielu elementów",
         "Grupa rekordów",
         "Wyświetlaj linie",
         "Wyświetlaj symbole",
         "Trigger Internal Type",
         "Styl wyzwalacza",
         "Tekst wyzwalacza",
         "Trigger Object",
         "Kierunek czytania tytułu ramki",
         "Wartość nie zaznaczonego pola",
         "Modyfikacja dozwolona",
         "Modyfikacja tylko zmienionych kolumn",
         "Aktualizacja po zatwierdzeniu",
         "Modyfikacja wartości NULL dozwolona",
         "Uaktualnianie układu",
         "Procedura modyfikująca - nazwa",
         "Aktualizacja po zapytaniu",
         "Update Argument Object",
         "Update Column Object",
         "Trójwymiarowe elementy",
         "Zabezpieczone",
         "Walidacja za pomocą listy",
         "Jednostka walidacji",
         "Grupa atrybutów wizualnych",
         "VA Object",
         "Typ atrybutu wizualnego",
         "Rozproszenie w pionie",
         "Wyrównanie tekstu w pionie",
         "Margines pionowy",
         "Pionowa odległość między obiektami",
         "Pionowy punkt początkowy",
         "Kanwa pionowego paska narzędzi",
         "Obiekt widoczny",
         "Visual Attribute Object",
         "Wysokość widoku",
         "Szerokość widoku",
         "Pozycja X widoku",
         "Pozycja X widoku na kanwie",
         "Pozycja Y widoku",
         "Pozycja Y widoku na kanwie",
         "Widoczny w poziomym pasku narzędzi menu",
         "Widoczny w menu",
         "Widoczny w pionowym pasku narzędzi menu",
         "Kanwa pionowego paska narzędzi",
         "Klauzula WHERE",
         "Białe na czarnym",
         "Szerokość",
         "Window Object",
         "Styl okna",
         "Okno",
         "Window Object Pointer",
         "Styl zawijania",
         "Zawijanie tekstu",
         "Pozycja X",
         "Pozycja Y",
         "Wartość kolumny",
         "Tekst grafiki - StringID",
         "Odrocz wymagane wymuszenie",
         "Logiczny atrybut trybu znakowego",
         "Przerwij przy niepowodzeniu",
         "Etykieta niepowodzenia",
         "Komunikat o niepowodzeniu",
         "Nowy kursor",
         "Odwrócony kod powrotu",
         "Powodzenie przy przerwaniu",
         "Etykieta powodzenia",
         "Tekst kroku wyzwalacza",
         "Trigger Step Object"
      };
   #else
      const vector<string> prop_names = {
         ""
      };
   #endif
}
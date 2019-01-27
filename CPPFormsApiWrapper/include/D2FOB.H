/*
 * $Header: d2fob.h@@/main/TOOLS_DEV2K_994/9 \
 * Checked in on Mon Jul  2 10:09:50 PDT 2001 by vobadm \
 * Copyright (c) 2001 by Oracle Corporation. All Rights Reserved. \
 * $
 */
/* Copyright (c) Oracle Corporation 1996, 2001.  All Rights Reserved. */

/*
   NAME
    D2FOB.H -- Dev2K Forms API generic OBject declarations

   DESCRIPTION
    Contains the public declarations for the generic Forms API object

   PUBLIC FUNCTIONS
    d2fobcr_Create          -
    d2fobde_Destroy         -
    d2fobdu_Duplicate       -
    d2fobsc_SubClass        -
    d2fobfo_FindObj         -
    d2fobmv_Move            -
    d2fobqt_QueryType       -
    d2fobg?_Get*Prop        -
    d2fobs?_Set*Prop        -
    d2fobhp_HasProp         -
    d2fobip_InheritProp     -
    d2fobii_IspropInherited -
    d2fobid_IspropDefault   -
    d2fobis_IsSubclassed    -
    d2fobgcv_GetConstValue  -
    d2fobgcn_GetConstName   -
    d2fobre_Replicate       -
    d2fobra_Reattach        -

*/

#ifndef D2FOB
#define D2FOB

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
** Object: Generic Object
**  This object represents a Generic Object.  Any object can be cast
**  to a generic object.  The generic object is useful when you have
**  a heterogeneous collection of objects.  However, using the type-
**  specific macros offers stricter type-checking, property-checking,
**  etc.
**
** Return codes:
**  Each of these functions returns a D2FS_* return code.
**
** Functions:
**  d2fobcr_Create - Creates and returns a new object of the specified
**                   type, with the specified owner object, and with
**                   the specified name.  For example, you could call
**                   this function with d2fobcr_Create(ctx, pd2fblk,
**                   &pd2fitm, (text *)"NEWITEM", D2FFO_ITEM).
**
**  d2fobde_Destroy - Destroys the specified object and all the proper-
**                   ties of that object.  The object is detached from
**                   its owner object and ceases to exist.
**
**  d2fobdu_Duplicate - Creates a new object with a the given name and given
**                   owning object.  The new object is the same as the
**                   original object in that it has the same property
**                   values.  However, the sublassing info is discarded,
**                   and the inherited property values "flattened" into
**                   local values in the new object.  Compare this to
**                   the Replicate() function which preserves the subclass
**                   source and inheritance pointers.
**
**  d2fobsc_SubClass - Change the subclassing parent of an object to the
**                   specified parent object.  Note that this will cause
**                   local property values in the child object to be
**                   removed for all properties which are defined on the
**                   parent object.  The keep_path argument indicates
**                   whether the system should refer to the parent object's
**                   module by filename along or by path+filename.  The
**                   recommended choice is FALSE for this argument in most
**                   cases.
**
**  d2fobfo_FindObj - Finds and object by name given an owner and type.
**                   For example, d2fobfo_FindObj(ctx, pd2fblk,
**                   (text *)"NEWITEM", D2FFO_ITEM, &pd2fitm) will find
**                   the item called NEWITEM belonging to the block.
**
**  d2fobmv_Move  -  Change the ordering of the object with respect to
**                   its siblings.  This is similar to dragging and
**                   dropping the object in the Form Builder Object
**                   Navigator.  The object retains the same owner.
**                   Use pd2fob_nxt = (d2fob *)0 to put the object at
**                   the end of the list.
**
**  d2fobqt_QueryType - Returns the type of the object, one of the D2FFO_*
**                   constants.
**
**  d2fobgb_GetBoolProp
**  d2fobgn_GetNumProp
**  d2fobgt_GetTextProp
**  d2fobgo_GetObjProp
**  d2fobgp_GetBlobProp - These functions are used to retrieve property
**                   values.  They are identical except for the 'type'
**                   of the value returned.  The Get routines will do
**                   basic validation to make sure that the object
**                   indeed has a property of the requested property
**                   number.  The property number is one of the D2FP_*
**                   constants.  For enumerated-valued properties, the
**                   return value will be one of the D2FC_* constants.
**
**  d2fobgb_SetBoolProp
**  d2fobgn_SetNumProp
**  d2fobgt_SetTextProp
**  d2fobgo_SetObjProp
**  d2fobgp_SetBlobProp - These functions are used to set the value of
**                   a property in an object.  Like the Get() methods
**                   above, they are identical except for the 'type'
**                   of the value argument.  Each of these routines
**                   does basic validation to ensure that the property
**                   is being set legally, and that the object is
**                   able to have properties of the given property
**                   number.  Use a D2FP_* constant to specify the
**                   property number, and a D2FC_* constant to pass in
**                   enumerated-valued properties where appropriate.
**
**  d2fobhp_HasProp - Returns D2FS_YES or D2FS_NO indicating whether the
**                   specified property number 'applies' to the given
**                   object.  In other words, it tells whether the
**                   property can be assigned to the given object.  For
**                   example, d2fobhp_HasProp(ctx, pd2falt, D2FP_ALT_STY)
**                   returns D2FS_YES, but d2fobhp_HasProp(ctx, pd2falt,
**                   D2FP_DML_ARY_SIZ) would return D2FS_NO.
**
**  d2fobip_InheritProp - Remove any local value for the specified
**                   property, effectively forcing the object to inherit
**                   the property value from its subclassing source, if
**                   it has one.
**
**  d2fobii_IspropInherited - Returns D2FS_YES or D2FS_NO depending on
**                   whether the given object is inheriting the specified
**                   property from a subclassing source object.  This is
**                   different than d2fobid_IspropDefault() because this
**                   function only returns YES when the given object has
**                   no local value, but is inheriting a non-default value
**                   from its subclassing source.
**
**  d2fobid_IspropDefault - Returns D2FS_YES or D2FS_NO depending on whether
**                   the object has a LOCAL value for the specified
**                   property.  If the object has a local value, then the
**                   function returns D2FS_NO since the property is not
**                   default-valued.  If the object has no local value,
**                   which means the object is either inheriting a value,
**                   or picking up the system default value, then this
**                   function returns D2FS_YES.
**
**  d2fobis_IsSubclassed - Returns D2FS_YES or D2FS_NO depending on whether
**                   the object has a subclassing source object from which
**                   it may inherit property values.
**
**  d2fobgcv_GetConstValue - Returns the D2FFO_*  object type constant
**                   in the 'objtyp' argument that corresponds with the
**                   specified type name string.  For example, calling
**                   d2fobgcv_GetConstValue(ctx, "CANVAS", &objtyp)
**                   sets objtyp to D2FFO_CANVAS.
**
**  d2fobgcn_GetConstName - The inverse of d2fobgcv_GetConstValue(), this
**                   function returns a descriptive string corresponding
**                   to the given object type.  The string does not have
**                   to be freed, as it is a static string in a static
**                   internal table.
**
**  d2fobre_Replicate - Creates a new object with a the given name and given
**                   owning object.  The new object is an exact copy of the
**                   original object, with all the same property values, and
**                   all the same subclassing relations.  Returns D2FS_FAIL
**                   if the system is unable to duplicate the entire object.
**                   Compare to the Duplicate() function which flattens the
**                   property values so that everything becomes local to the
**                   new object.
**
**  d2fobra_Reattach - This function resets the source of the given object
**                   to match its internal source info.  This is intended
**                   for hooking up subclassing relations after the source
**                   info has been directly modified.  This is primarily an
**                   internal function, but may have external uses in some
**                   cases.
**
*/
ORA_RETTYPE(d2fstatus) d2fobcr_Create( d2fctx *pd2fctx, d2fob *owner,
                                        d2fob **ppd2fob,
                                        text *name, d2fotyp objtyp );
ORA_RETTYPE(d2fstatus) d2fobde_Destroy( d2fctx *pd2fctx, d2fob *pd2fob );
ORA_RETTYPE(d2fstatus) d2fobfo_FindObj(d2fctx *pd2fctx, d2fob *owner,
                                       text *name, d2fotyp objtyp,
                                       d2fob **ppd2fob );
ORA_RETTYPE(d2fstatus) d2fobdu_Duplicate( d2fctx *pd2fctx, d2fob *new_owner,
                                          d2fob *pd2fob_src,
                                          d2fob **ppd2fob_dst,
                                          text *new_name );
ORA_RETTYPE(d2fstatus) d2fobmv_Move(d2fctx *pd2fctx, d2fob *pd2fob,
                                    d2fob *pd2fob_nxt);
ORA_RETTYPE(d2fstatus) d2fobsc_SubClass( d2fctx *pd2fctx, d2fob *pd2fob,
                                          d2fob *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fobgb_GetBoolProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                            ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fobgn_GetNumProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                           ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fobgt_GetTextProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                            ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fobgo_GetObjProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                           ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fobgp_GetBlobProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                           ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fobsb_SetBoolProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                            ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fobsn_SetNumProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                           ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fobst_SetTextProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                            ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fobso_SetObjProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                           ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fobsp_SetBlobProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                           ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fobhp_HasProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                        ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fobqt_QueryType( d2fctx  *pd2fctx,
                                          d2fob   *pd2fob,
                                          d2fotyp *objtyp);
ORA_RETTYPE(d2fstatus) d2fobip_InheritProp( d2fctx *pd2fctx, d2fob *pd2fob,
                                            ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fobii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fob *pd2fob,
                                                 ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fobid_IspropDefault( d2fctx *pd2fctx,
                                               d2fob *pd2fob,
                                               ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fobis_IsSubclassed( d2fctx *pd2fctx,
                                             d2fob *pd2fob);
ORA_RETTYPE(d2fstatus) d2fobgcv_GetConstValue( d2fctx *pd2fctx, text *ocname,
                                               d2fotyp *objtyp);
ORA_RETTYPE(d2fstatus) d2fobgcn_GetConstName( d2fctx *pd2fctx, d2fotyp objtyp,
                                              text **ocname);
ORA_RETTYPE(d2fstatus) d2fobre_Replicate( d2fctx *pd2fctx, d2fob *new_parent,
                                          d2fob *pd2fob_src,
                                          d2fob **ppd2fob_dst,
                                          text *new_name  );
ORA_RETTYPE(d2fstatus) d2fobra_Reattach( d2fctx *pd2fctx, d2fob *pd2fob );


/* Begin convenience macros  */
#define d2fobg_access_key(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_ACCESS_KEY,val)
#define d2fobg_alert(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_ALERT,val)
#define d2fobg_alias(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_ALIAS,val)
#define d2fobg_allow_expansion(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_ALLOW_EXPANSION,val)
#define d2fobg_allow_mlt_lin_prmpts(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_ALLOW_MLT_LIN_PRMPTS,val)
#define d2fobg_allow_strt_att_prmpts(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_ALLOW_STRT_ATT_PRMPTS,val)
#define d2fobg_allow_top_att_prmpts(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_ALLOW_TOP_ATT_PRMPTS,val)
#define d2fobg_alt_msg(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_ALT_MSG,val)
#define d2fobg_alt_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_ALT_STY,val)
#define d2fobg_arrow_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_ARROW_STY,val)
#define d2fobg_assoc_menus_count(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_ASSOC_MENUS_COUNT,val)
#define d2fobg_assoc_mnus(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_ASSOC_MNUS,val)
#define d2fobg_att_lib(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_ATT_LIB,val)
#define d2fobg_audio_chnnls(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_AUDIO_CHNNLS,val)
#define d2fobg_auto_col_wid(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_AUTO_COL_WID,val)
#define d2fobg_auto_disp(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_AUTO_DISP,val)
#define d2fobg_auto_hint(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_AUTO_HINT,val)
#define d2fobg_auto_pos(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_AUTO_POS,val)
#define d2fobg_auto_qry(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_AUTO_QRY,val)
#define d2fobg_auto_rfrsh(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_AUTO_RFRSH,val)
#define d2fobg_auto_skp(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_AUTO_SKP,val)
#define d2fobg_auto_slct(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_AUTO_SLCT,val)
#define d2fobg_back_color(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fobg_bevel(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_BEVEL,val)
#define d2fobg_blk_description(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_BLK_DESCRIPTION,val)
#define d2fobg_block(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_BLOCK,val)
#define d2fobg_bounding_bx_scalable(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_BOUNDING_BX_SCALABLE,val)
#define d2fobg_btm_ttl(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_BTM_TTL,val)
#define d2fobg_btn_1_lbl(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_BTN_1_LBL,val)
#define d2fobg_btn_2_lbl(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_BTN_2_LBL,val)
#define d2fobg_btn_3_lbl(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_BTN_3_LBL,val)
#define d2fobg_calc_mode(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CALC_MODE,val)
#define d2fobg_canvas(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_CANVAS,val)
#define d2fobg_cap_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CAP_STY,val)
#define d2fobg_case_insensitive_qry(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_CASE_INSENSITIVE_QRY,val)
#define d2fobg_case_rstrction(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CASE_RSTRCTION,val)
#define d2fobg_char_mode_logical_attr(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_CHAR_MODE_LOGICAL_ATTR,val)
#define d2fobg_chk_bx_other_vals(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CHK_BX_OTHER_VALS,val)
#define d2fobg_chked_val(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_CHKED_VAL,val)
#define d2fobg_client_info(ctx,obj,val) \
           d2fobgp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fobg_clip_hgt(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CLIP_HGT,val)
#define d2fobg_clip_wid(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CLIP_WID,val)
#define d2fobg_clip_x_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CLIP_X_POS,val)
#define d2fobg_clip_y_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CLIP_Y_POS,val)
#define d2fobg_closed(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_CLOSED,val)
#define d2fobg_cls_allowed(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_CLS_ALLOWED,val)
#define d2fobg_cmprssion_qlty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CMPRSSION_QLTY,val)
#define d2fobg_cnv_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_CNV_NAM,val)
#define d2fobg_cnv_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_CNV_OBJ,val)
#define d2fobg_cnv_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CNV_TYP,val)
#define d2fobg_col_dat_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_COL_DAT_TYP,val)
#define d2fobg_col_map(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_COL_MAP,val)
#define d2fobg_col_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_COL_NAM,val)
#define d2fobg_col_spec(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_COL_SPEC,val)
#define d2fobg_col_vals_count(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_COL_VALS_COUNT,val)
#define d2fobg_column_value(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_COLUMN_VALUE,val)
#define d2fobg_com_txt(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_COM_TXT,val)
#define d2fobg_com_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_COM_TYP,val)
#define d2fobg_comm_mode(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_COMM_MODE,val)
#define d2fobg_comment(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fobg_compress(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_COMPRESS,val)
#define d2fobg_conceal_data(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_CONCEAL_DATA,val)
#define d2fobg_console_win(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_CONSOLE_WIN,val)
#define d2fobg_copy_val_from_itm(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_COPY_VAL_FROM_ITM,val)
#define d2fobg_corner_radius_x(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CORNER_RADIUS_X,val)
#define d2fobg_corner_radius_y(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CORNER_RADIUS_Y,val)
#define d2fobg_crsr_mode(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CRSR_MODE,val)
#define d2fobg_cstm_spcing(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_CSTM_SPCING,val)
#define d2fobg_dash_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DASH_STY,val)
#define d2fobg_dat_src_blk(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DAT_SRC_BLK,val)
#define d2fobg_dat_src_x_axs(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DAT_SRC_X_AXS,val)
#define d2fobg_dat_src_y_axs(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DAT_SRC_Y_AXS,val)
#define d2fobg_dat_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DAT_TYP,val)
#define d2fobg_db_blk(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DB_BLK,val)
#define d2fobg_db_itm(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DB_ITM,val)
#define d2fobg_deferred(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DEFERRED,val)
#define d2fobg_del_allowed(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DEL_ALLOWED,val)
#define d2fobg_del_proc_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DEL_PROC_NAM,val)
#define d2fobg_del_rec(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DEL_REC,val)
#define d2fobg_detail_blk(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DETAIL_BLK,val)
#define d2fobg_detail_itemref(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DETAIL_ITEMREF,val)
#define d2fobg_dflt_alt_btn(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DFLT_ALT_BTN,val)
#define d2fobg_dflt_btn(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DFLT_BTN,val)
#define d2fobg_dirty_info(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DIRTY_INFO,val)
#define d2fobg_disp_in_kbrd_hlp(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DISP_IN_KBRD_HLP,val)
#define d2fobg_disp_no_priv(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DISP_NO_PRIV,val)
#define d2fobg_disp_qlty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DISP_QLTY,val)
#define d2fobg_disp_wid(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DISP_WID,val)
#define d2fobg_dist_btwn_recs(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DIST_BTWN_RECS,val)
#define d2fobg_dither(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DITHER,val)
#define d2fobg_dml_ary_siz(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DML_ARY_SIZ,val)
#define d2fobg_dml_dat_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DML_DAT_NAM,val)
#define d2fobg_dml_dat_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DML_DAT_TYP,val)
#define d2fobg_dml_ret_val(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DML_RET_VAL,val)
#define d2fobg_dsa_mode(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DSA_MODE,val)
#define d2fobg_dsa_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DSA_NAM,val)
#define d2fobg_dsa_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DSA_TYP,val)
#define d2fobg_dsa_typ_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DSA_TYP_NAM,val)
#define d2fobg_dsa_val(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DSA_VAL,val)
#define d2fobg_dsc_len(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DSC_LEN,val)
#define d2fobg_dsc_mandatory(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DSC_MANDATORY,val)
#define d2fobg_dsc_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DSC_NAM,val)
#define d2fobg_dsc_nochildren(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_DSC_NOCHILDREN,val)
#define d2fobg_dsc_parent_name(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DSC_PARENT_NAME,val)
#define d2fobg_dsc_precision(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DSC_PRECISION,val)
#define d2fobg_dsc_scale(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DSC_SCALE,val)
#define d2fobg_dsc_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_DSC_TYP,val)
#define d2fobg_dsc_type_name(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_DSC_TYPE_NAME,val)
#define d2fobg_edge_back_color(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_EDGE_BACK_COLOR,val)
#define d2fobg_edge_fore_color(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_EDGE_FORE_COLOR,val)
#define d2fobg_editor(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_EDITOR,val)
#define d2fobg_edt_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_EDT_NAM,val)
#define d2fobg_edt_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_EDT_OBJ,val)
#define d2fobg_edt_x_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_EDT_X_POS,val)
#define d2fobg_edt_y_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_EDT_Y_POS,val)
#define d2fobg_enabled(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_ENABLED,val)
#define d2fobg_enfrc_col_security(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_ENFRC_COL_SECURITY,val)
#define d2fobg_enfrc_prmry_key(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_ENFRC_PRMRY_KEY,val)
#define d2fobg_exec_hierarchy(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_EXEC_HIERARCHY,val)
#define d2fobg_exec_mode(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_EXEC_MODE,val)
#define d2fobg_fill_pat(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fobg_fire_in_qry(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_FIRE_IN_QRY,val)
#define d2fobg_fixed_bounding_bx(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_FIXED_BOUNDING_BX,val)
#define d2fobg_fixed_len(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_FIXED_LEN,val)
#define d2fobg_flnam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FLNAM,val)
#define d2fobg_fltr_before_disp(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_FLTR_BEFORE_DISP,val)
#define d2fobg_fmt_msk(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FMT_MSK,val)
#define d2fobg_font_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fobg_font_scaleable(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_FONT_SCALEABLE,val)
#define d2fobg_font_siz(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fobg_font_spcing(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fobg_font_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fobg_font_wght(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fobg_fore_color(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fobg_form_param(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_FORM_PARAM,val)
#define d2fobg_formula(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FORMULA,val)
#define d2fobg_frame_align(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FRAME_ALIGN,val)
#define d2fobg_frame_ttl(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FRAME_TTL,val)
#define d2fobg_frame_ttl_align(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_ALIGN,val)
#define d2fobg_frame_ttl_back_color(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FRAME_TTL_BACK_COLOR,val)
#define d2fobg_frame_ttl_fill_pat(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FRAME_TTL_FILL_PAT,val)
#define d2fobg_frame_ttl_font_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FRAME_TTL_FONT_NAM,val)
#define d2fobg_frame_ttl_font_siz(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_SIZ,val)
#define d2fobg_frame_ttl_font_spcing(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_SPCING,val)
#define d2fobg_frame_ttl_font_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_STY,val)
#define d2fobg_frame_ttl_font_wght(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_WGHT,val)
#define d2fobg_frame_ttl_fore_color(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FRAME_TTL_FORE_COLOR,val)
#define d2fobg_frame_ttl_ofst(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_OFST,val)
#define d2fobg_frame_ttl_spcing(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_SPCING,val)
#define d2fobg_frame_ttl_vat_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FRAME_TTL_VAT_NAM,val)
#define d2fobg_frame_ttl_vat_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_FRAME_TTL_VAT_OBJ,val)
#define d2fobg_frst_navigation_blk_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_FRST_NAVIGATION_BLK_NAM,val)
#define d2fobg_frst_navigation_blk_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_FRST_NAVIGATION_BLK_OBJ,val)
#define d2fobg_gra_font_color(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_GRA_FONT_COLOR,val)
#define d2fobg_gra_font_color_code(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_GRA_FONT_COLOR_CODE,val)
#define d2fobg_gra_font_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_GRA_FONT_NAM,val)
#define d2fobg_gra_font_siz(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_GRA_FONT_SIZ,val)
#define d2fobg_gra_font_spcing(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_GRA_FONT_SPCING,val)
#define d2fobg_gra_font_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_GRA_FONT_STY,val)
#define d2fobg_gra_font_wght(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_GRA_FONT_WGHT,val)
#define d2fobg_gra_text(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_GRA_TEXT,val)
#define d2fobg_graphic(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_GRAPHIC,val)
#define d2fobg_graphics_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_GRAPHICS_TYP,val)
#define d2fobg_height(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fobg_help_book_title(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_HELP_BOOK_TITLE,val)
#define d2fobg_help_book_topic(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_HELP_BOOK_TOPIC,val)
#define d2fobg_hide(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_HIDE,val)
#define d2fobg_hide_on_exit(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_HIDE_ON_EXIT,val)
#define d2fobg_highest_allowed_val(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_HIGHEST_ALLOWED_VAL,val)
#define d2fobg_hint(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_HINT,val)
#define d2fobg_hlp_description(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_HLP_DESCRIPTION,val)
#define d2fobg_horz_jst(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_HORZ_JST,val)
#define d2fobg_horz_margn(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_HORZ_MARGN,val)
#define d2fobg_horz_obj_ofst(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_HORZ_OBJ_OFST,val)
#define d2fobg_horz_orgn(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_HORZ_ORGN,val)
#define d2fobg_horz_tlbr_cnv(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_HORZ_TLBR_CNV,val)
#define d2fobg_htb_cnv_name(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_HTB_CNV_NAME,val)
#define d2fobg_icon_flnam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_ICON_FLNAM,val)
#define d2fobg_icon_in_mnu(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_ICON_IN_MNU,val)
#define d2fobg_iconic(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_ICONIC,val)
#define d2fobg_img_dpth(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_IMG_DPTH,val)
#define d2fobg_img_fmt(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_IMG_FMT,val)
#define d2fobg_impl_class(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_IMPL_CLASS,val)
#define d2fobg_inhrt_mnu(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_INHRT_MNU,val)
#define d2fobg_init_kbrd_dir(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_INIT_KBRD_DIR,val)
#define d2fobg_init_mnu(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_INIT_MNU,val)
#define d2fobg_init_val(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_INIT_VAL,val)
#define d2fobg_insrt_allowed(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_INSRT_ALLOWED,val)
#define d2fobg_insrt_proc_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_INSRT_PROC_NAM,val)
#define d2fobg_interaction_mode(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_INTERACTION_MODE,val)
#define d2fobg_internal_end_angle(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_INTERNAL_END_ANGLE,val)
#define d2fobg_internal_lin_wid(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_INTERNAL_LIN_WID,val)
#define d2fobg_internal_rotation_angle(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_INTERNAL_ROTATION_ANGLE,val)
#define d2fobg_internal_strt_angle(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_INTERNAL_STRT_ANGLE,val)
#define d2fobg_isolation_mode(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_ISOLATION_MODE,val)
#define d2fobg_item(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_ITEM,val)
#define d2fobg_itm_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_ITM_TYP,val)
#define d2fobg_itms_disp(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_ITMS_DISP,val)
#define d2fobg_join_cond(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_JOIN_COND,val)
#define d2fobg_join_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_JOIN_STY,val)
#define d2fobg_justification(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_JUSTIFICATION,val)
#define d2fobg_kbrd_acc(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_KBRD_ACC,val)
#define d2fobg_kbrd_hlp_txt(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_KBRD_HLP_TXT,val)
#define d2fobg_kbrd_navigable(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_KBRD_NAVIGABLE,val)
#define d2fobg_kbrd_state(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_KBRD_STATE,val)
#define d2fobg_keep_crsr_pos(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_KEEP_CRSR_POS,val)
#define d2fobg_key_mode(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_KEY_MODE,val)
#define d2fobg_label(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2fobg_lang_dir(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fobg_layout_data_blk_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_LAYOUT_DATA_BLK_NAM,val)
#define d2fobg_layout_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_LAYOUT_STY,val)
#define d2fobg_lib_loc(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_LIB_LOC,val)
#define d2fobg_lib_src(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_LIB_SRC,val)
#define d2fobg_lin_spcing(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_LIN_SPCING,val)
#define d2fobg_lock_mode(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_LOCK_MODE,val)
#define d2fobg_lock_proc_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_LOCK_PROC_NAM,val)
#define d2fobg_lock_rec(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_LOCK_REC,val)
#define d2fobg_lov(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_LOV,val)
#define d2fobg_lov_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_LOV_NAM,val)
#define d2fobg_lov_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_LOV_OBJ,val)
#define d2fobg_lov_x_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_LOV_X_POS,val)
#define d2fobg_lov_y_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_LOV_Y_POS,val)
#define d2fobg_lowest_allowed_val(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_LOWEST_ALLOWED_VAL,val)
#define d2fobg_lst_element_count(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_LST_ELEMENT_COUNT,val)
#define d2fobg_lst_in_blk_mnu(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_LST_IN_BLK_MNU,val)
#define d2fobg_lst_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_LST_STY,val)
#define d2fobg_lst_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_LST_TYP,val)
#define d2fobg_magic_itm(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_MAGIC_ITM,val)
#define d2fobg_main_mnu(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_MAIN_MNU,val)
#define d2fobg_max_len(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_MAX_LEN,val)
#define d2fobg_max_objs(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_MAX_OBJS,val)
#define d2fobg_max_qry_time(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_MAX_QRY_TIME,val)
#define d2fobg_max_recs_fetched(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_MAX_RECS_FETCHED,val)
#define d2fobg_maximize_allowed(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_MAXIMIZE_ALLOWED,val)
#define d2fobg_menu(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_MENU,val)
#define d2fobg_minimize_allowed(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_MINIMIZE_ALLOWED,val)
#define d2fobg_minimize_ttl(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_MINIMIZE_TTL,val)
#define d2fobg_mlt_lin(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_MLT_LIN,val)
#define d2fobg_mnu_drctry(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_MNU_DRCTRY,val)
#define d2fobg_mnu_flnam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_MNU_FLNAM,val)
#define d2fobg_mnu_itm(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_MNU_ITM,val)
#define d2fobg_mnu_itm_code(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_MNU_ITM_CODE,val)
#define d2fobg_mnu_itm_rad_grp(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_MNU_ITM_RAD_GRP,val)
#define d2fobg_mnu_itm_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_MNU_ITM_TYP,val)
#define d2fobg_mnu_mod(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_MNU_MOD,val)
#define d2fobg_mnu_param(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_MNU_PARAM,val)
#define d2fobg_mnu_param_init_val(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_MNU_PARAM_INIT_VAL,val)
#define d2fobg_mnu_role(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_MNU_ROLE,val)
#define d2fobg_mnu_src(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_MNU_SRC,val)
#define d2fobg_mnu_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_MNU_STY,val)
#define d2fobg_modal(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_MODAL,val)
#define d2fobg_module(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fobg_mouse_navigate(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_MOUSE_NAVIGATE,val)
#define d2fobg_mouse_navigation_lmt(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_MOUSE_NAVIGATION_LMT,val)
#define d2fobg_mv_allowed(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_MV_ALLOWED,val)
#define d2fobg_name(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fobg_navigation_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_NAVIGATION_STY,val)
#define d2fobg_newdefer_req_enf(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_NEWDEFER_REQ_ENF,val)
#define d2fobg_next(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fobg_nxt_navigation_blk_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_NXT_NAVIGATION_BLK_NAM,val)
#define d2fobg_nxt_navigation_blk_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_NXT_NAVIGATION_BLK_OBJ,val)
#define d2fobg_nxt_navigation_itm_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_NXT_NAVIGATION_ITM_NAM,val)
#define d2fobg_nxt_navigation_itm_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_NXT_NAVIGATION_ITM_OBJ,val)
#define d2fobg_obj_grp(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_OBJ_GRP,val)
#define d2fobg_obj_grp_child_real_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_OBJ_GRP_CHILD_REAL_OBJ,val)
#define d2fobg_og_child(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_OG_CHILD,val)
#define d2fobg_old_lov_txt(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_OLD_LOV_TXT,val)
#define d2fobg_ole_act_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_OLE_ACT_STY,val)
#define d2fobg_ole_class(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_OLE_CLASS,val)
#define d2fobg_ole_in_place_act(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_OLE_IN_PLACE_ACT,val)
#define d2fobg_ole_insd_out_support(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_OLE_INSD_OUT_SUPPORT,val)
#define d2fobg_ole_popup_mnu_itms(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_OLE_POPUP_MNU_ITMS,val)
#define d2fobg_ole_resiz_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_OLE_RESIZ_STY,val)
#define d2fobg_ole_show_popup_mnu(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_OLE_SHOW_POPUP_MNU,val)
#define d2fobg_ole_show_tnnt_typ(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_OLE_SHOW_TNNT_TYP,val)
#define d2fobg_ole_tnnt_aspct(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_OLE_TNNT_ASPCT,val)
#define d2fobg_ole_tnnt_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_OLE_TNNT_TYP,val)
#define d2fobg_opt_hint(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_OPT_HINT,val)
#define d2fobg_ordr_by_clause(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_ORDR_BY_CLAUSE,val)
#define d2fobg_other_vals(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_OTHER_VALS,val)
#define d2fobg_owner(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fobg_par_flnam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fobg_par_flpath(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fobg_par_modstr(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fobg_par_modtyp(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fobg_par_module(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fobg_par_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fobg_par_sl1obj_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PAR_SL1OBJ_NAM,val)
#define d2fobg_par_sl1obj_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PAR_SL1OBJ_TYP,val)
#define d2fobg_par_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fobg_param_dat_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PARAM_DAT_TYP,val)
#define d2fobg_param_init_val(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PARAM_INIT_VAL,val)
#define d2fobg_persist_client_info(ctx,obj,val) \
           d2fobgp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fobg_persist_clt_inf_len(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fobg_pgu_txt(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PGU_TXT,val)
#define d2fobg_popup_mnu_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_POPUP_MNU_NAM,val)
#define d2fobg_popup_mnu_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_POPUP_MNU_OBJ,val)
#define d2fobg_popup_va_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_POPUP_VA_OBJ,val)
#define d2fobg_precomp_summ(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_PRECOMP_SUMM,val)
#define d2fobg_prev_navigation_blk_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PREV_NAVIGATION_BLK_NAM,val)
#define d2fobg_prev_navigation_blk_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_PREV_NAVIGATION_BLK_OBJ,val)
#define d2fobg_prev_navigation_itm_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PREV_NAVIGATION_ITM_NAM,val)
#define d2fobg_prev_navigation_itm_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_PREV_NAVIGATION_ITM_OBJ,val)
#define d2fobg_previous(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fobg_prmpt(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PRMPT,val)
#define d2fobg_prmpt_align(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PRMPT_ALIGN,val)
#define d2fobg_prmpt_align_ofst(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PRMPT_ALIGN_OFST,val)
#define d2fobg_prmpt_att_edge(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PRMPT_ATT_EDGE,val)
#define d2fobg_prmpt_att_ofst(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PRMPT_ATT_OFST,val)
#define d2fobg_prmpt_back_color(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PRMPT_BACK_COLOR,val)
#define d2fobg_prmpt_disp_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PRMPT_DISP_STY,val)
#define d2fobg_prmpt_fill_pat(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PRMPT_FILL_PAT,val)
#define d2fobg_prmpt_font_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PRMPT_FONT_NAM,val)
#define d2fobg_prmpt_font_siz(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_SIZ,val)
#define d2fobg_prmpt_font_spcing(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_SPCING,val)
#define d2fobg_prmpt_font_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_STY,val)
#define d2fobg_prmpt_font_wght(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PRMPT_FONT_WGHT,val)
#define d2fobg_prmpt_fore_color(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PRMPT_FORE_COLOR,val)
#define d2fobg_prmpt_jst(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PRMPT_JST,val)
#define d2fobg_prmpt_reading_ordr(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_PRMPT_READING_ORDR,val)
#define d2fobg_prmpt_vat_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PRMPT_VAT_NAM,val)
#define d2fobg_prmpt_vat_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_PRMPT_VAT_OBJ,val)
#define d2fobg_prmry_cnv(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_PRMRY_CNV,val)
#define d2fobg_prmry_key(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_PRMRY_KEY,val)
#define d2fobg_prog_unit(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_PROG_UNIT,val)
#define d2fobg_prop_class(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_PROP_CLASS,val)
#define d2fobg_prvnt_mstrless_ops(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_PRVNT_MSTRLESS_OPS,val)
#define d2fobg_qry_all_recs(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_QRY_ALL_RECS,val)
#define d2fobg_qry_allowed(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_QRY_ALLOWED,val)
#define d2fobg_qry_dat_src_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_QRY_DAT_SRC_NAM,val)
#define d2fobg_qry_dat_src_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_QRY_DAT_SRC_TYP,val)
#define d2fobg_qry_len(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_QRY_LEN,val)
#define d2fobg_qry_only(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_QRY_ONLY,val)
#define d2fobg_rad_but(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_RAD_BUT,val)
#define d2fobg_raise_on_ent(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_RAISE_ON_ENT,val)
#define d2fobg_rdb_val(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_RDB_VAL,val)
#define d2fobg_reading_ordr(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_READING_ORDR,val)
#define d2fobg_rec_grp(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_REC_GRP,val)
#define d2fobg_rec_grp_fetch_siz(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_REC_GRP_FETCH_SIZ,val)
#define d2fobg_rec_grp_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_REC_GRP_NAM,val)
#define d2fobg_rec_grp_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_REC_GRP_OBJ,val)
#define d2fobg_rec_grp_qry(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_REC_GRP_QRY,val)
#define d2fobg_rec_grp_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_REC_GRP_TYP,val)
#define d2fobg_rec_ornt(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_REC_ORNT,val)
#define d2fobg_rec_vat_grp_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_REC_VAT_GRP_NAM,val)
#define d2fobg_rec_vat_grp_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_REC_VAT_GRP_OBJ,val)
#define d2fobg_recs_buffered_count(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_RECS_BUFFERED_COUNT,val)
#define d2fobg_recs_disp_count(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_RECS_DISP_COUNT,val)
#define d2fobg_recs_fetched_count(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_RECS_FETCHED_COUNT,val)
#define d2fobg_rel(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_REL,val)
#define d2fobg_rel_type(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_REL_TYPE,val)
#define d2fobg_rendered(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_RENDERED,val)
#define d2fobg_report(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_REPORT,val)
#define d2fobg_required(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_REQUIRED,val)
#define d2fobg_resize_allowed(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_RESIZE_ALLOWED,val)
#define d2fobg_rev_dir(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_REV_DIR,val)
#define d2fobg_rpt_destination_fmt(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_RPT_DESTINATION_FMT,val)
#define d2fobg_rpt_destination_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_RPT_DESTINATION_NAM,val)
#define d2fobg_rpt_destination_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_RPT_DESTINATION_TYP,val)
#define d2fobg_rpt_params(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_RPT_PARAMS,val)
#define d2fobg_rpt_srvr(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_RPT_SRVR,val)
#define d2fobg_rtrn_itm(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_RTRN_ITM,val)
#define d2fobg_runtime_comp(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_RUNTIME_COMP,val)
#define d2fobg_scrlbr_align(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_SCRLBR_ALIGN,val)
#define d2fobg_scrlbr_cnv_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_SCRLBR_CNV_NAM,val)
#define d2fobg_scrlbr_cnv_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_SCRLBR_CNV_OBJ,val)
#define d2fobg_scrlbr_len(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_SCRLBR_LEN,val)
#define d2fobg_scrlbr_ornt(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_SCRLBR_ORNT,val)
#define d2fobg_scrlbr_tbp_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_SCRLBR_TBP_NAM,val)
#define d2fobg_scrlbr_tbp_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_SCRLBR_TBP_OBJ,val)
#define d2fobg_scrlbr_wid(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_SCRLBR_WID,val)
#define d2fobg_scrlbr_x_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_SCRLBR_X_POS,val)
#define d2fobg_scrlbr_y_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_SCRLBR_Y_POS,val)
#define d2fobg_share_lib(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHARE_LIB,val)
#define d2fobg_show_fast_fwd(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHOW_FAST_FWD,val)
#define d2fobg_show_horz_scrlbr(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHOW_HORZ_SCRLBR,val)
#define d2fobg_show_palette(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHOW_PALETTE,val)
#define d2fobg_show_play(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHOW_PLAY,val)
#define d2fobg_show_rec(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHOW_REC,val)
#define d2fobg_show_rewind(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHOW_REWIND,val)
#define d2fobg_show_scrlbr(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHOW_SCRLBR,val)
#define d2fobg_show_slider(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHOW_SLIDER,val)
#define d2fobg_show_time(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHOW_TIME,val)
#define d2fobg_show_vert_scrlbr(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHOW_VERT_SCRLBR,val)
#define d2fobg_show_volume(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHOW_VOLUME,val)
#define d2fobg_shrinkwrap(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SHRINKWRAP,val)
#define d2fobg_sizing_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_SIZING_STY,val)
#define d2fobg_snd_fmt(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_SND_FMT,val)
#define d2fobg_snd_qlty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_SND_QLTY,val)
#define d2fobg_sngl_obj_align(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_SNGL_OBJ_ALIGN,val)
#define d2fobg_sngl_rec(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SNGL_REC,val)
#define d2fobg_source(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2fobg_strt_prmpt_align(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_STRT_PRMPT_ALIGN,val)
#define d2fobg_strt_prmpt_ofst(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_STRT_PRMPT_OFST,val)
#define d2fobg_strtup_code(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_STRTUP_CODE,val)
#define d2fobg_sub_mnu_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_SUB_MNU_NAM,val)
#define d2fobg_sub_mnu_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_SUB_MNU_OBJ,val)
#define d2fobg_sub_ttl(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_SUB_TTL,val)
#define d2fobg_subcl_objgrp(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SUBCL_OBJGRP,val)
#define d2fobg_subcl_subobj(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SUBCL_SUBOBJ,val)
#define d2fobg_summ_blk_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_SUMM_BLK_NAM,val)
#define d2fobg_summ_func(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_SUMM_FUNC,val)
#define d2fobg_summ_itm_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_SUMM_ITM_NAM,val)
#define d2fobg_svpnt_mode(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_SVPNT_MODE,val)
#define d2fobg_sync_itm_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_SYNC_ITM_NAM,val)
#define d2fobg_sync_itm_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_SYNC_ITM_OBJ,val)
#define d2fobg_tab_act_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_TAB_ACT_STY,val)
#define d2fobg_tab_att_edge(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_TAB_ATT_EDGE,val)
#define d2fobg_tab_page(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_TAB_PAGE,val)
#define d2fobg_tab_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_TAB_STY,val)
#define d2fobg_tab_wid_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_TAB_WID_STY,val)
#define d2fobg_tbp_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_TBP_NAM,val)
#define d2fobg_tbp_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_TBP_OBJ,val)
#define d2fobg_tear_off_mnu(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_TEAR_OFF_MNU,val)
#define d2fobg_title(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2fobg_tooltip(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_TOOLTIP,val)
#define d2fobg_tooltip_vat_grp(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_TOOLTIP_VAT_GRP,val)
#define d2fobg_top_prmpt_align(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_TOP_PRMPT_ALIGN,val)
#define d2fobg_top_prmpt_ofst(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_TOP_PRMPT_OFST,val)
#define d2fobg_tre_allw_emp_branch(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_TRE_ALLW_EMP_BRANCH,val)
#define d2fobg_tre_data_qry(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_TRE_DATA_QRY,val)
#define d2fobg_tre_multi_select(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_TRE_MULTI_SELECT,val)
#define d2fobg_tre_rec_grp(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_TRE_REC_GRP,val)
#define d2fobg_tre_show_lines(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_TRE_SHOW_LINES,val)
#define d2fobg_tre_show_symbol(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_TRE_SHOW_SYMBOL,val)
#define d2fobg_trg_internal_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_TRG_INTERNAL_TYP,val)
#define d2fobg_trg_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_TRG_STY,val)
#define d2fobg_trg_txt(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_TRG_TXT,val)
#define d2fobg_trigger(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_TRIGGER,val)
#define d2fobg_ttl_reading_ordr(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_TTL_READING_ORDR,val)
#define d2fobg_unchked_val(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_UNCHKED_VAL,val)
#define d2fobg_updt_allowed(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_UPDT_ALLOWED,val)
#define d2fobg_updt_changed_cols(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_UPDT_CHANGED_COLS,val)
#define d2fobg_updt_commit(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_UPDT_COMMIT,val)
#define d2fobg_updt_if_null(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_UPDT_IF_NULL,val)
#define d2fobg_updt_layout(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_UPDT_LAYOUT,val)
#define d2fobg_updt_proc_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_UPDT_PROC_NAM,val)
#define d2fobg_updt_qry(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_UPDT_QRY,val)
#define d2fobg_use_3d_cntrls(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_USE_3D_CNTRLS,val)
#define d2fobg_use_security(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_USE_SECURITY,val)
#define d2fobg_validate_from_lst(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_VALIDATE_FROM_LST,val)
#define d2fobg_validation_unit(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VALIDATION_UNIT,val)
#define d2fobg_vat_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fobg_vat_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fobg_vat_typ(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VAT_TYP,val)
#define d2fobg_vert_fill(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_VERT_FILL,val)
#define d2fobg_vert_jst(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VERT_JST,val)
#define d2fobg_vert_margn(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VERT_MARGN,val)
#define d2fobg_vert_obj_ofst(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VERT_OBJ_OFST,val)
#define d2fobg_vert_orgn(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VERT_ORGN,val)
#define d2fobg_vert_tlbr_cnv(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_VERT_TLBR_CNV,val)
#define d2fobg_vis_attr(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_VIS_ATTR,val)
#define d2fobg_visible(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_VISIBLE,val)
#define d2fobg_vprt_hgt(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VPRT_HGT,val)
#define d2fobg_vprt_wid(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VPRT_WID,val)
#define d2fobg_vprt_x_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VPRT_X_POS,val)
#define d2fobg_vprt_x_pos_on_cnv(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VPRT_X_POS_ON_CNV,val)
#define d2fobg_vprt_y_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VPRT_Y_POS,val)
#define d2fobg_vprt_y_pos_on_cnv(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_VPRT_Y_POS_ON_CNV,val)
#define d2fobg_vsbl_in_horz_mnu_tlbr(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_VSBL_IN_HORZ_MNU_TLBR,val)
#define d2fobg_vsbl_in_menu(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_VSBL_IN_MENU,val)
#define d2fobg_vsbl_in_vert_mnu_tlbr(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_VSBL_IN_VERT_MNU_TLBR,val)
#define d2fobg_vtb_cnv_name(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_VTB_CNV_NAME,val)
#define d2fobg_where_clause(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_WHERE_CLAUSE,val)
#define d2fobg_white_on_black(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2fobg_width(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fobg_win_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_WIN_STY,val)
#define d2fobg_window(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_WINDOW,val)
#define d2fobg_wnd_nam(ctx,obj,val) \
           d2fobgt_GetTextProp(ctx,obj,D2FP_WND_NAM,val)
#define d2fobg_wnd_obj(ctx,obj,val) \
           d2fobgo_GetObjProp(ctx,obj,D2FP_WND_OBJ,val)
#define d2fobg_wrap_sty(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_WRAP_STY,val)
#define d2fobg_wrap_txt(ctx,obj,val) \
           d2fobgb_GetBoolProp(ctx,obj,D2FP_WRAP_TXT,val)
#define d2fobg_x_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fobg_y_pos(ctx,obj,val) \
           d2fobgn_GetNumProp(ctx,obj,D2FP_Y_POS,val)

#define d2fobs_access_key(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_ACCESS_KEY,val)
#define d2fobs_alias(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_ALIAS,val)
#define d2fobs_allow_expansion(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_ALLOW_EXPANSION,val)
#define d2fobs_allow_mlt_lin_prmpts(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_ALLOW_MLT_LIN_PRMPTS,val)
#define d2fobs_allow_strt_att_prmpts(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_ALLOW_STRT_ATT_PRMPTS,val)
#define d2fobs_allow_top_att_prmpts(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_ALLOW_TOP_ATT_PRMPTS,val)
#define d2fobs_alt_msg(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_ALT_MSG,val)
#define d2fobs_alt_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_ALT_STY,val)
#define d2fobs_arrow_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_ARROW_STY,val)
#define d2fobs_assoc_mnus(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_ASSOC_MNUS,val)
#define d2fobs_audio_chnnls(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_AUDIO_CHNNLS,val)
#define d2fobs_auto_col_wid(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_AUTO_COL_WID,val)
#define d2fobs_auto_disp(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_AUTO_DISP,val)
#define d2fobs_auto_hint(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_AUTO_HINT,val)
#define d2fobs_auto_pos(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_AUTO_POS,val)
#define d2fobs_auto_qry(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_AUTO_QRY,val)
#define d2fobs_auto_rfrsh(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_AUTO_RFRSH,val)
#define d2fobs_auto_skp(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_AUTO_SKP,val)
#define d2fobs_auto_slct(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_AUTO_SLCT,val)
#define d2fobs_back_color(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fobs_bevel(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_BEVEL,val)
#define d2fobs_blk_description(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_BLK_DESCRIPTION,val)
#define d2fobs_bounding_bx_scalable(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_BOUNDING_BX_SCALABLE,val)
#define d2fobs_btm_ttl(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_BTM_TTL,val)
#define d2fobs_btn_1_lbl(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_BTN_1_LBL,val)
#define d2fobs_btn_2_lbl(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_BTN_2_LBL,val)
#define d2fobs_btn_3_lbl(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_BTN_3_LBL,val)
#define d2fobs_calc_mode(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CALC_MODE,val)
#define d2fobs_cap_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CAP_STY,val)
#define d2fobs_case_insensitive_qry(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_CASE_INSENSITIVE_QRY,val)
#define d2fobs_case_rstrction(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CASE_RSTRCTION,val)
#define d2fobs_char_mode_logical_attr(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_CHAR_MODE_LOGICAL_ATTR,val)
#define d2fobs_chk_bx_other_vals(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CHK_BX_OTHER_VALS,val)
#define d2fobs_chked_val(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_CHKED_VAL,val)
#define d2fobs_client_info(ctx,obj,val) \
           d2fobsp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fobs_clip_hgt(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CLIP_HGT,val)
#define d2fobs_clip_wid(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CLIP_WID,val)
#define d2fobs_clip_x_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CLIP_X_POS,val)
#define d2fobs_clip_y_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CLIP_Y_POS,val)
#define d2fobs_closed(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_CLOSED,val)
#define d2fobs_cls_allowed(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_CLS_ALLOWED,val)
#define d2fobs_cmprssion_qlty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CMPRSSION_QLTY,val)
#define d2fobs_cnv_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_CNV_NAM,val)
#define d2fobs_cnv_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_CNV_OBJ,val)
#define d2fobs_cnv_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CNV_TYP,val)
#define d2fobs_col_dat_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_COL_DAT_TYP,val)
#define d2fobs_col_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_COL_NAM,val)
#define d2fobs_com_txt(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_COM_TXT,val)
#define d2fobs_com_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_COM_TYP,val)
#define d2fobs_comm_mode(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_COMM_MODE,val)
#define d2fobs_comment(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_COMMENT,val)
#define d2fobs_compress(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_COMPRESS,val)
#define d2fobs_conceal_data(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_CONCEAL_DATA,val)
#define d2fobs_console_win(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_CONSOLE_WIN,val)
#define d2fobs_copy_val_from_itm(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_COPY_VAL_FROM_ITM,val)
#define d2fobs_corner_radius_x(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CORNER_RADIUS_X,val)
#define d2fobs_corner_radius_y(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CORNER_RADIUS_Y,val)
#define d2fobs_cstm_spcing(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_CSTM_SPCING,val)
#define d2fobs_dash_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DASH_STY,val)
#define d2fobs_dat_src_blk(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DAT_SRC_BLK,val)
#define d2fobs_dat_src_x_axs(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DAT_SRC_X_AXS,val)
#define d2fobs_dat_src_y_axs(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DAT_SRC_Y_AXS,val)
#define d2fobs_dat_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DAT_TYP,val)
#define d2fobs_db_blk(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DB_BLK,val)
#define d2fobs_db_itm(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DB_ITM,val)
#define d2fobs_deferred(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DEFERRED,val)
#define d2fobs_del_allowed(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DEL_ALLOWED,val)
#define d2fobs_del_proc_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DEL_PROC_NAM,val)
#define d2fobs_del_rec(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DEL_REC,val)
#define d2fobs_detail_blk(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DETAIL_BLK,val)
#define d2fobs_detail_itemref(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DETAIL_ITEMREF,val)
#define d2fobs_dflt_alt_btn(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DFLT_ALT_BTN,val)
#define d2fobs_dflt_btn(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DFLT_BTN,val)
#define d2fobs_dirty_info(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DIRTY_INFO,val)
#define d2fobs_disp_in_kbrd_hlp(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DISP_IN_KBRD_HLP,val)
#define d2fobs_disp_no_priv(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DISP_NO_PRIV,val)
#define d2fobs_disp_qlty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DISP_QLTY,val)
#define d2fobs_disp_wid(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DISP_WID,val)
#define d2fobs_dist_btwn_recs(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DIST_BTWN_RECS,val)
#define d2fobs_dither(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DITHER,val)
#define d2fobs_dml_ary_siz(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DML_ARY_SIZ,val)
#define d2fobs_dml_dat_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DML_DAT_NAM,val)
#define d2fobs_dml_dat_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DML_DAT_TYP,val)
#define d2fobs_dml_ret_val(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DML_RET_VAL,val)
#define d2fobs_dsa_mode(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DSA_MODE,val)
#define d2fobs_dsa_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DSA_NAM,val)
#define d2fobs_dsa_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DSA_TYP,val)
#define d2fobs_dsa_typ_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DSA_TYP_NAM,val)
#define d2fobs_dsa_val(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DSA_VAL,val)
#define d2fobs_dsc_len(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DSC_LEN,val)
#define d2fobs_dsc_mandatory(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DSC_MANDATORY,val)
#define d2fobs_dsc_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DSC_NAM,val)
#define d2fobs_dsc_nochildren(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_DSC_NOCHILDREN,val)
#define d2fobs_dsc_parent_name(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DSC_PARENT_NAME,val)
#define d2fobs_dsc_precision(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DSC_PRECISION,val)
#define d2fobs_dsc_scale(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DSC_SCALE,val)
#define d2fobs_dsc_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_DSC_TYP,val)
#define d2fobs_dsc_type_name(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_DSC_TYPE_NAME,val)
#define d2fobs_edge_back_color(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_EDGE_BACK_COLOR,val)
#define d2fobs_edge_fore_color(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_EDGE_FORE_COLOR,val)
#define d2fobs_edt_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_EDT_NAM,val)
#define d2fobs_edt_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_EDT_OBJ,val)
#define d2fobs_edt_x_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_EDT_X_POS,val)
#define d2fobs_edt_y_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_EDT_Y_POS,val)
#define d2fobs_enabled(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_ENABLED,val)
#define d2fobs_enfrc_col_security(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_ENFRC_COL_SECURITY,val)
#define d2fobs_enfrc_prmry_key(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_ENFRC_PRMRY_KEY,val)
#define d2fobs_exec_hierarchy(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_EXEC_HIERARCHY,val)
#define d2fobs_exec_mode(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_EXEC_MODE,val)
#define d2fobs_fill_pat(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fobs_fire_in_qry(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_FIRE_IN_QRY,val)
#define d2fobs_fixed_bounding_bx(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_FIXED_BOUNDING_BX,val)
#define d2fobs_fixed_len(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_FIXED_LEN,val)
#define d2fobs_flnam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FLNAM,val)
#define d2fobs_fltr_before_disp(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_FLTR_BEFORE_DISP,val)
#define d2fobs_fmt_msk(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FMT_MSK,val)
#define d2fobs_font_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FONT_NAM,val)
#define d2fobs_font_scaleable(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_FONT_SCALEABLE,val)
#define d2fobs_font_siz(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FONT_SIZ,val)
#define d2fobs_font_spcing(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FONT_SPCING,val)
#define d2fobs_font_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FONT_STY,val)
#define d2fobs_font_wght(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FONT_WGHT,val)
#define d2fobs_fore_color(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fobs_formula(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FORMULA,val)
#define d2fobs_frame_align(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FRAME_ALIGN,val)
#define d2fobs_frame_ttl(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FRAME_TTL,val)
#define d2fobs_frame_ttl_align(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_ALIGN,val)
#define d2fobs_frame_ttl_back_color(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FRAME_TTL_BACK_COLOR,val)
#define d2fobs_frame_ttl_fill_pat(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FRAME_TTL_FILL_PAT,val)
#define d2fobs_frame_ttl_font_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FRAME_TTL_FONT_NAM,val)
#define d2fobs_frame_ttl_font_siz(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_SIZ,val)
#define d2fobs_frame_ttl_font_spcing(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_SPCING,val)
#define d2fobs_frame_ttl_font_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_STY,val)
#define d2fobs_frame_ttl_font_wght(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_WGHT,val)
#define d2fobs_frame_ttl_fore_color(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FRAME_TTL_FORE_COLOR,val)
#define d2fobs_frame_ttl_ofst(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_OFST,val)
#define d2fobs_frame_ttl_spcing(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_SPCING,val)
#define d2fobs_frame_ttl_vat_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FRAME_TTL_VAT_NAM,val)
#define d2fobs_frame_ttl_vat_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_FRAME_TTL_VAT_OBJ,val)
#define d2fobs_frst_navigation_blk_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_FRST_NAVIGATION_BLK_NAM,val)
#define d2fobs_frst_navigation_blk_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_FRST_NAVIGATION_BLK_OBJ,val)
#define d2fobs_gra_font_color(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_GRA_FONT_COLOR,val)
#define d2fobs_gra_font_color_code(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_GRA_FONT_COLOR_CODE,val)
#define d2fobs_gra_font_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_GRA_FONT_NAM,val)
#define d2fobs_gra_font_siz(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_GRA_FONT_SIZ,val)
#define d2fobs_gra_font_spcing(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_GRA_FONT_SPCING,val)
#define d2fobs_gra_font_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_GRA_FONT_STY,val)
#define d2fobs_gra_font_wght(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_GRA_FONT_WGHT,val)
#define d2fobs_gra_text(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_GRA_TEXT,val)
#define d2fobs_graphics_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_GRAPHICS_TYP,val)
#define d2fobs_height(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fobs_help_book_title(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_HELP_BOOK_TITLE,val)
#define d2fobs_help_book_topic(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_HELP_BOOK_TOPIC,val)
#define d2fobs_hide(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_HIDE,val)
#define d2fobs_hide_on_exit(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_HIDE_ON_EXIT,val)
#define d2fobs_highest_allowed_val(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_HIGHEST_ALLOWED_VAL,val)
#define d2fobs_hint(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_HINT,val)
#define d2fobs_hlp_description(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_HLP_DESCRIPTION,val)
#define d2fobs_horz_jst(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_HORZ_JST,val)
#define d2fobs_horz_margn(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_HORZ_MARGN,val)
#define d2fobs_horz_obj_ofst(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_HORZ_OBJ_OFST,val)
#define d2fobs_horz_orgn(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_HORZ_ORGN,val)
#define d2fobs_horz_tlbr_cnv(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_HORZ_TLBR_CNV,val)
#define d2fobs_htb_cnv_name(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_HTB_CNV_NAME,val)
#define d2fobs_icon_flnam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_ICON_FLNAM,val)
#define d2fobs_icon_in_mnu(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_ICON_IN_MNU,val)
#define d2fobs_iconic(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_ICONIC,val)
#define d2fobs_img_dpth(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_IMG_DPTH,val)
#define d2fobs_img_fmt(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_IMG_FMT,val)
#define d2fobs_impl_class(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_IMPL_CLASS,val)
#define d2fobs_inhrt_mnu(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_INHRT_MNU,val)
#define d2fobs_init_kbrd_dir(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_INIT_KBRD_DIR,val)
#define d2fobs_init_mnu(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_INIT_MNU,val)
#define d2fobs_init_val(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_INIT_VAL,val)
#define d2fobs_insrt_allowed(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_INSRT_ALLOWED,val)
#define d2fobs_insrt_proc_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_INSRT_PROC_NAM,val)
#define d2fobs_interaction_mode(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_INTERACTION_MODE,val)
#define d2fobs_internal_end_angle(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_INTERNAL_END_ANGLE,val)
#define d2fobs_internal_lin_wid(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_INTERNAL_LIN_WID,val)
#define d2fobs_internal_rotation_angle(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_INTERNAL_ROTATION_ANGLE,val)
#define d2fobs_internal_strt_angle(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_INTERNAL_STRT_ANGLE,val)
#define d2fobs_isolation_mode(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_ISOLATION_MODE,val)
#define d2fobs_itm_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_ITM_TYP,val)
#define d2fobs_itms_disp(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_ITMS_DISP,val)
#define d2fobs_join_cond(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_JOIN_COND,val)
#define d2fobs_join_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_JOIN_STY,val)
#define d2fobs_justification(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_JUSTIFICATION,val)
#define d2fobs_kbrd_acc(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_KBRD_ACC,val)
#define d2fobs_kbrd_hlp_txt(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_KBRD_HLP_TXT,val)
#define d2fobs_kbrd_navigable(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_KBRD_NAVIGABLE,val)
#define d2fobs_kbrd_state(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_KBRD_STATE,val)
#define d2fobs_keep_crsr_pos(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_KEEP_CRSR_POS,val)
#define d2fobs_key_mode(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_KEY_MODE,val)
#define d2fobs_label(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_LABEL,val)
#define d2fobs_lang_dir(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fobs_layout_data_blk_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_LAYOUT_DATA_BLK_NAM,val)
#define d2fobs_layout_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_LAYOUT_STY,val)
#define d2fobs_lin_spcing(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_LIN_SPCING,val)
#define d2fobs_lock_mode(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_LOCK_MODE,val)
#define d2fobs_lock_proc_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_LOCK_PROC_NAM,val)
#define d2fobs_lock_rec(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_LOCK_REC,val)
#define d2fobs_lov_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_LOV_NAM,val)
#define d2fobs_lov_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_LOV_OBJ,val)
#define d2fobs_lov_x_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_LOV_X_POS,val)
#define d2fobs_lov_y_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_LOV_Y_POS,val)
#define d2fobs_lowest_allowed_val(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_LOWEST_ALLOWED_VAL,val)
#define d2fobs_lst_in_blk_mnu(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_LST_IN_BLK_MNU,val)
#define d2fobs_lst_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_LST_STY,val)
#define d2fobs_lst_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_LST_TYP,val)
#define d2fobs_magic_itm(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_MAGIC_ITM,val)
#define d2fobs_main_mnu(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_MAIN_MNU,val)
#define d2fobs_max_len(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_MAX_LEN,val)
#define d2fobs_max_objs(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_MAX_OBJS,val)
#define d2fobs_max_qry_time(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_MAX_QRY_TIME,val)
#define d2fobs_max_recs_fetched(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_MAX_RECS_FETCHED,val)
#define d2fobs_maximize_allowed(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_MAXIMIZE_ALLOWED,val)
#define d2fobs_minimize_allowed(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_MINIMIZE_ALLOWED,val)
#define d2fobs_minimize_ttl(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_MINIMIZE_TTL,val)
#define d2fobs_mlt_lin(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_MLT_LIN,val)
#define d2fobs_mnu_drctry(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_MNU_DRCTRY,val)
#define d2fobs_mnu_flnam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_MNU_FLNAM,val)
#define d2fobs_mnu_itm_code(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_MNU_ITM_CODE,val)
#define d2fobs_mnu_itm_rad_grp(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_MNU_ITM_RAD_GRP,val)
#define d2fobs_mnu_itm_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_MNU_ITM_TYP,val)
#define d2fobs_mnu_mod(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_MNU_MOD,val)
#define d2fobs_mnu_param_init_val(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_MNU_PARAM_INIT_VAL,val)
#define d2fobs_mnu_role(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_MNU_ROLE,val)
#define d2fobs_mnu_src(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_MNU_SRC,val)
#define d2fobs_mnu_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_MNU_STY,val)
#define d2fobs_modal(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_MODAL,val)
#define d2fobs_mouse_navigate(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_MOUSE_NAVIGATE,val)
#define d2fobs_mouse_navigation_lmt(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_MOUSE_NAVIGATION_LMT,val)
#define d2fobs_mv_allowed(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_MV_ALLOWED,val)
#define d2fobs_name(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fobs_navigation_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_NAVIGATION_STY,val)
#define d2fobs_newdefer_req_enf(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_NEWDEFER_REQ_ENF,val)
#define d2fobs_nxt_navigation_blk_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_NXT_NAVIGATION_BLK_NAM,val)
#define d2fobs_nxt_navigation_blk_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_NXT_NAVIGATION_BLK_OBJ,val)
#define d2fobs_nxt_navigation_itm_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_NXT_NAVIGATION_ITM_NAM,val)
#define d2fobs_nxt_navigation_itm_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_NXT_NAVIGATION_ITM_OBJ,val)
#define d2fobs_obj_grp_child_real_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_OBJ_GRP_CHILD_REAL_OBJ,val)
#define d2fobs_old_lov_txt(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_OLD_LOV_TXT,val)
#define d2fobs_ole_act_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_OLE_ACT_STY,val)
#define d2fobs_ole_class(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_OLE_CLASS,val)
#define d2fobs_ole_in_place_act(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_OLE_IN_PLACE_ACT,val)
#define d2fobs_ole_insd_out_support(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_OLE_INSD_OUT_SUPPORT,val)
#define d2fobs_ole_popup_mnu_itms(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_OLE_POPUP_MNU_ITMS,val)
#define d2fobs_ole_resiz_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_OLE_RESIZ_STY,val)
#define d2fobs_ole_show_popup_mnu(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_OLE_SHOW_POPUP_MNU,val)
#define d2fobs_ole_show_tnnt_typ(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_OLE_SHOW_TNNT_TYP,val)
#define d2fobs_ole_tnnt_aspct(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_OLE_TNNT_ASPCT,val)
#define d2fobs_ole_tnnt_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_OLE_TNNT_TYP,val)
#define d2fobs_opt_hint(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_OPT_HINT,val)
#define d2fobs_ordr_by_clause(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_ORDR_BY_CLAUSE,val)
#define d2fobs_other_vals(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_OTHER_VALS,val)
#define d2fobs_par_flnam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fobs_par_flpath(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fobs_par_modstr(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fobs_par_modtyp(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fobs_par_module(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fobs_par_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fobs_par_sl1obj_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PAR_SL1OBJ_NAM,val)
#define d2fobs_par_sl1obj_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PAR_SL1OBJ_TYP,val)
#define d2fobs_par_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fobs_param_dat_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PARAM_DAT_TYP,val)
#define d2fobs_param_init_val(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PARAM_INIT_VAL,val)
#define d2fobs_persist_client_info(ctx,obj,val) \
           d2fobsp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fobs_persist_clt_inf_len(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fobs_pgu_txt(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PGU_TXT,val)
#define d2fobs_popup_mnu_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_POPUP_MNU_NAM,val)
#define d2fobs_popup_mnu_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_POPUP_MNU_OBJ,val)
#define d2fobs_popup_va_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_POPUP_VA_OBJ,val)
#define d2fobs_precomp_summ(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_PRECOMP_SUMM,val)
#define d2fobs_prev_navigation_blk_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PREV_NAVIGATION_BLK_NAM,val)
#define d2fobs_prev_navigation_blk_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_PREV_NAVIGATION_BLK_OBJ,val)
#define d2fobs_prev_navigation_itm_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PREV_NAVIGATION_ITM_NAM,val)
#define d2fobs_prev_navigation_itm_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_PREV_NAVIGATION_ITM_OBJ,val)
#define d2fobs_prmpt(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PRMPT,val)
#define d2fobs_prmpt_align(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PRMPT_ALIGN,val)
#define d2fobs_prmpt_align_ofst(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PRMPT_ALIGN_OFST,val)
#define d2fobs_prmpt_att_edge(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PRMPT_ATT_EDGE,val)
#define d2fobs_prmpt_att_ofst(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PRMPT_ATT_OFST,val)
#define d2fobs_prmpt_back_color(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PRMPT_BACK_COLOR,val)
#define d2fobs_prmpt_disp_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PRMPT_DISP_STY,val)
#define d2fobs_prmpt_fill_pat(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PRMPT_FILL_PAT,val)
#define d2fobs_prmpt_font_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PRMPT_FONT_NAM,val)
#define d2fobs_prmpt_font_siz(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_SIZ,val)
#define d2fobs_prmpt_font_spcing(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_SPCING,val)
#define d2fobs_prmpt_font_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_STY,val)
#define d2fobs_prmpt_font_wght(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PRMPT_FONT_WGHT,val)
#define d2fobs_prmpt_fore_color(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PRMPT_FORE_COLOR,val)
#define d2fobs_prmpt_jst(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PRMPT_JST,val)
#define d2fobs_prmpt_reading_ordr(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_PRMPT_READING_ORDR,val)
#define d2fobs_prmpt_vat_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PRMPT_VAT_NAM,val)
#define d2fobs_prmpt_vat_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_PRMPT_VAT_OBJ,val)
#define d2fobs_prmry_cnv(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_PRMRY_CNV,val)
#define d2fobs_prmry_key(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_PRMRY_KEY,val)
#define d2fobs_prvnt_mstrless_ops(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_PRVNT_MSTRLESS_OPS,val)
#define d2fobs_qry_all_recs(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_QRY_ALL_RECS,val)
#define d2fobs_qry_allowed(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_QRY_ALLOWED,val)
#define d2fobs_qry_dat_src_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_QRY_DAT_SRC_NAM,val)
#define d2fobs_qry_dat_src_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_QRY_DAT_SRC_TYP,val)
#define d2fobs_qry_len(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_QRY_LEN,val)
#define d2fobs_qry_only(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_QRY_ONLY,val)
#define d2fobs_raise_on_ent(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_RAISE_ON_ENT,val)
#define d2fobs_rdb_val(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_RDB_VAL,val)
#define d2fobs_reading_ordr(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_READING_ORDR,val)
#define d2fobs_rec_grp_fetch_siz(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_REC_GRP_FETCH_SIZ,val)
#define d2fobs_rec_grp_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_REC_GRP_NAM,val)
#define d2fobs_rec_grp_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_REC_GRP_OBJ,val)
#define d2fobs_rec_grp_qry(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_REC_GRP_QRY,val)
#define d2fobs_rec_grp_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_REC_GRP_TYP,val)
#define d2fobs_rec_ornt(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_REC_ORNT,val)
#define d2fobs_rec_vat_grp_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_REC_VAT_GRP_NAM,val)
#define d2fobs_rec_vat_grp_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_REC_VAT_GRP_OBJ,val)
#define d2fobs_recs_buffered_count(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_RECS_BUFFERED_COUNT,val)
#define d2fobs_recs_disp_count(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_RECS_DISP_COUNT,val)
#define d2fobs_recs_fetched_count(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_RECS_FETCHED_COUNT,val)
#define d2fobs_rel_type(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_REL_TYPE,val)
#define d2fobs_rendered(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_RENDERED,val)
#define d2fobs_required(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_REQUIRED,val)
#define d2fobs_resize_allowed(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_RESIZE_ALLOWED,val)
#define d2fobs_rev_dir(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_REV_DIR,val)
#define d2fobs_rpt_destination_fmt(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_RPT_DESTINATION_FMT,val)
#define d2fobs_rpt_destination_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_RPT_DESTINATION_NAM,val)
#define d2fobs_rpt_destination_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_RPT_DESTINATION_TYP,val)
#define d2fobs_rpt_params(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_RPT_PARAMS,val)
#define d2fobs_rpt_srvr(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_RPT_SRVR,val)
#define d2fobs_rtrn_itm(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_RTRN_ITM,val)
#define d2fobs_runtime_comp(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_RUNTIME_COMP,val)
#define d2fobs_scrlbr_align(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_SCRLBR_ALIGN,val)
#define d2fobs_scrlbr_cnv_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_SCRLBR_CNV_NAM,val)
#define d2fobs_scrlbr_cnv_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_SCRLBR_CNV_OBJ,val)
#define d2fobs_scrlbr_len(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_SCRLBR_LEN,val)
#define d2fobs_scrlbr_ornt(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_SCRLBR_ORNT,val)
#define d2fobs_scrlbr_tbp_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_SCRLBR_TBP_NAM,val)
#define d2fobs_scrlbr_tbp_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_SCRLBR_TBP_OBJ,val)
#define d2fobs_scrlbr_wid(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_SCRLBR_WID,val)
#define d2fobs_scrlbr_x_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_SCRLBR_X_POS,val)
#define d2fobs_scrlbr_y_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_SCRLBR_Y_POS,val)
#define d2fobs_share_lib(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHARE_LIB,val)
#define d2fobs_show_fast_fwd(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHOW_FAST_FWD,val)
#define d2fobs_show_horz_scrlbr(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHOW_HORZ_SCRLBR,val)
#define d2fobs_show_palette(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHOW_PALETTE,val)
#define d2fobs_show_play(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHOW_PLAY,val)
#define d2fobs_show_rec(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHOW_REC,val)
#define d2fobs_show_rewind(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHOW_REWIND,val)
#define d2fobs_show_scrlbr(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHOW_SCRLBR,val)
#define d2fobs_show_slider(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHOW_SLIDER,val)
#define d2fobs_show_time(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHOW_TIME,val)
#define d2fobs_show_vert_scrlbr(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHOW_VERT_SCRLBR,val)
#define d2fobs_show_volume(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHOW_VOLUME,val)
#define d2fobs_shrinkwrap(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SHRINKWRAP,val)
#define d2fobs_sizing_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_SIZING_STY,val)
#define d2fobs_snd_fmt(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_SND_FMT,val)
#define d2fobs_snd_qlty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_SND_QLTY,val)
#define d2fobs_sngl_obj_align(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_SNGL_OBJ_ALIGN,val)
#define d2fobs_sngl_rec(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SNGL_REC,val)
#define d2fobs_strt_prmpt_align(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_STRT_PRMPT_ALIGN,val)
#define d2fobs_strt_prmpt_ofst(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_STRT_PRMPT_OFST,val)
#define d2fobs_strtup_code(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_STRTUP_CODE,val)
#define d2fobs_sub_mnu_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_SUB_MNU_NAM,val)
#define d2fobs_sub_mnu_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_SUB_MNU_OBJ,val)
#define d2fobs_sub_ttl(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_SUB_TTL,val)
#define d2fobs_subcl_objgrp(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SUBCL_OBJGRP,val)
#define d2fobs_subcl_subobj(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_SUBCL_SUBOBJ,val)
#define d2fobs_summ_blk_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_SUMM_BLK_NAM,val)
#define d2fobs_summ_func(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_SUMM_FUNC,val)
#define d2fobs_summ_itm_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_SUMM_ITM_NAM,val)
#define d2fobs_sync_itm_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_SYNC_ITM_NAM,val)
#define d2fobs_sync_itm_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_SYNC_ITM_OBJ,val)
#define d2fobs_tab_act_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_TAB_ACT_STY,val)
#define d2fobs_tab_att_edge(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_TAB_ATT_EDGE,val)
#define d2fobs_tab_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_TAB_STY,val)
#define d2fobs_tab_wid_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_TAB_WID_STY,val)
#define d2fobs_tbp_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_TBP_NAM,val)
#define d2fobs_tbp_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_TBP_OBJ,val)
#define d2fobs_tear_off_mnu(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_TEAR_OFF_MNU,val)
#define d2fobs_title(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_TITLE,val)
#define d2fobs_tooltip(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_TOOLTIP,val)
#define d2fobs_tooltip_vat_grp(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_TOOLTIP_VAT_GRP,val)
#define d2fobs_top_prmpt_align(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_TOP_PRMPT_ALIGN,val)
#define d2fobs_top_prmpt_ofst(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_TOP_PRMPT_OFST,val)
#define d2fobs_tre_allw_emp_branch(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_TRE_ALLW_EMP_BRANCH,val)
#define d2fobs_tre_data_qry(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_TRE_DATA_QRY,val)
#define d2fobs_tre_multi_select(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_TRE_MULTI_SELECT,val)
#define d2fobs_tre_rec_grp(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_TRE_REC_GRP,val)
#define d2fobs_tre_show_lines(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_TRE_SHOW_LINES,val)
#define d2fobs_tre_show_symbol(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_TRE_SHOW_SYMBOL,val)
#define d2fobs_trg_internal_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_TRG_INTERNAL_TYP,val)
#define d2fobs_trg_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_TRG_STY,val)
#define d2fobs_trg_txt(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_TRG_TXT,val)
#define d2fobs_ttl_reading_ordr(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_TTL_READING_ORDR,val)
#define d2fobs_unchked_val(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_UNCHKED_VAL,val)
#define d2fobs_updt_allowed(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_UPDT_ALLOWED,val)
#define d2fobs_updt_changed_cols(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_UPDT_CHANGED_COLS,val)
#define d2fobs_updt_commit(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_UPDT_COMMIT,val)
#define d2fobs_updt_if_null(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_UPDT_IF_NULL,val)
#define d2fobs_updt_layout(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_UPDT_LAYOUT,val)
#define d2fobs_updt_proc_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_UPDT_PROC_NAM,val)
#define d2fobs_updt_qry(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_UPDT_QRY,val)
#define d2fobs_use_3d_cntrls(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_USE_3D_CNTRLS,val)
#define d2fobs_use_security(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_USE_SECURITY,val)
#define d2fobs_validate_from_lst(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_VALIDATE_FROM_LST,val)
#define d2fobs_validation_unit(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VALIDATION_UNIT,val)
#define d2fobs_vat_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fobs_vat_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fobs_vat_typ(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VAT_TYP,val)
#define d2fobs_vert_fill(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_VERT_FILL,val)
#define d2fobs_vert_jst(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VERT_JST,val)
#define d2fobs_vert_margn(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VERT_MARGN,val)
#define d2fobs_vert_obj_ofst(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VERT_OBJ_OFST,val)
#define d2fobs_vert_orgn(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VERT_ORGN,val)
#define d2fobs_vert_tlbr_cnv(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_VERT_TLBR_CNV,val)
#define d2fobs_visible(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_VISIBLE,val)
#define d2fobs_vprt_hgt(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VPRT_HGT,val)
#define d2fobs_vprt_wid(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VPRT_WID,val)
#define d2fobs_vprt_x_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VPRT_X_POS,val)
#define d2fobs_vprt_x_pos_on_cnv(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VPRT_X_POS_ON_CNV,val)
#define d2fobs_vprt_y_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VPRT_Y_POS,val)
#define d2fobs_vprt_y_pos_on_cnv(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_VPRT_Y_POS_ON_CNV,val)
#define d2fobs_vsbl_in_horz_mnu_tlbr(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_VSBL_IN_HORZ_MNU_TLBR,val)
#define d2fobs_vsbl_in_menu(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_VSBL_IN_MENU,val)
#define d2fobs_vsbl_in_vert_mnu_tlbr(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_VSBL_IN_VERT_MNU_TLBR,val)
#define d2fobs_vtb_cnv_name(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_VTB_CNV_NAME,val)
#define d2fobs_where_clause(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_WHERE_CLAUSE,val)
#define d2fobs_white_on_black(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_WHITE_ON_BLACK,val)
#define d2fobs_width(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fobs_win_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_WIN_STY,val)
#define d2fobs_wnd_nam(ctx,obj,val) \
           d2fobst_SetTextProp(ctx,obj,D2FP_WND_NAM,val)
#define d2fobs_wnd_obj(ctx,obj,val) \
           d2fobso_SetObjProp(ctx,obj,D2FP_WND_OBJ,val)
#define d2fobs_wrap_sty(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_WRAP_STY,val)
#define d2fobs_wrap_txt(ctx,obj,val) \
           d2fobsb_SetBoolProp(ctx,obj,D2FP_WRAP_TXT,val)
#define d2fobs_x_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fobs_y_pos(ctx,obj,val) \
           d2fobsn_SetNumProp(ctx,obj,D2FP_Y_POS,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif

#endif /* D2FOB */

/* Copyright (c) Oracle Corporation 1996.  All Rights Reserved. */

/*
   NAME
    D2FGRA.H -- Dev2K Forms API GRAphic declarations

   DESCRIPTION
    Contains the public declarations for the Forms API Graphic object

   PUBLIC FUNCTIONS
    d2fgracr_Create          - Cover for d2fobcr_Create
    d2fgrade_Destroy         - Cover for d2fobde_Destroy
    d2fgradu_Duplicate       - Cover for d2fobdu_Duplicate
    d2fgrasc_Subclass        - Cover for d2fobsc_Subclass
    d2fgraim_importImage     - Import an image file from disk
    d2fgrag?_Get*Prop        - Cover for d2fobg?_Get*Prop
    d2fgras?_Set*Prop        - Cover for d2fobs?_Set*Prop
    d2fgrahp_HasProp         - Cover for d2fobhp_HasProp
    d2fgraip_InheritProp     - Cover for d2fobip_InheritProp
    d2fgraii_IspropInherited - Cover for d2fobii_IspropInherited
    d2fgraid_IspropDefault   - Cover for d2fobid_IspropDefault
    d2fgrais_IsSubclassed    - Cover for d2fobis_IsSubclassed
*/

#ifndef D2FGRA
#define D2FGRA

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
** Object: Graphic Object (Boiler Plate)
**
** d2fgraim_importImage - imports an image from disk into a
**   Graphics Image object.  'format' is a D2FC_IMFM_* constant.
*/
ORA_RETTYPE(d2fstatus) d2fgracr_Create( d2fctx *pd2fctx, d2fob *parent, 
                                        d2fgra **ppd2fgra, text *name  );
ORA_RETTYPE(d2fstatus) d2fgrade_Destroy( d2fctx *pd2fctx, d2fgra *pd2fgra );
ORA_RETTYPE(d2fstatus) d2fgradu_Duplicate( d2fctx *pd2fctx, d2fob *new_parent,
                                           d2fgra *pd2fgra_src,
                                           d2fgra **ppd2fgra_dst,
                                           text *new_name );
ORA_RETTYPE(d2fstatus) d2fgrasc_SubClass( d2fctx *pd2fctx, d2fgra *pd2fgra,
                                          d2fob  *parent, boolean keep_path);
ORA_RETTYPE(d2fstatus) d2fgraim_importImage(d2fctx *pd2fctx, d2fgra *pd2fgra,
                                            text   *filename, number  format);
ORA_RETTYPE(d2fstatus) d2fgragb_GetBoolProp( d2fctx *pd2fctx, d2fgra *pd2fgra,
                                             ub2 pnum, boolean *pprp );
ORA_RETTYPE(d2fstatus) d2fgragn_GetNumProp( d2fctx *pd2fctx, d2fgra *pd2fgra,
                                            ub2 pnum, number *pprp );
ORA_RETTYPE(d2fstatus) d2fgragt_GetTextProp( d2fctx *pd2fctx, d2fgra *pd2fgra,
                                             ub2 pnum, text **pprp );
ORA_RETTYPE(d2fstatus) d2fgrago_GetObjProp( d2fctx *pd2fctx, d2fgra *pd2fgra,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fgragp_GetBlobProp( d2fctx *pd2fctx, d2fgra *pd2fgra,
                                            ub2 pnum, dvoid **pprp );
ORA_RETTYPE(d2fstatus) d2fgrasb_SetBoolProp( d2fctx *pd2fctx, d2fgra *pd2fgra,
                                             ub2 pnum, boolean prp );
ORA_RETTYPE(d2fstatus) d2fgrasn_SetNumProp( d2fctx *pd2fctx, d2fgra *pd2fgra,
                                            ub2 pnum, number prp );
ORA_RETTYPE(d2fstatus) d2fgrast_SetTextProp( d2fctx *pd2fctx, d2fgra *pd2fgra,
                                             ub2 pnum, text *prp );
ORA_RETTYPE(d2fstatus) d2fgraso_SetObjProp(d2fctx *pd2fctx, d2fgra *pd2fgra,
                                           ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fgrasp_SetBlobProp(d2fctx *pd2fctx, d2fgra *pd2fgra,
                                           ub2 pnum, dvoid *prp );
ORA_RETTYPE(d2fstatus) d2fgrahp_HasProp( d2fctx *pd2fctx, d2fgra *pd2fgra,
                                         ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fgraip_InheritProp( d2fctx *pd2fctx, d2fgra *pd2fgra,
                                             ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fgraii_IspropInherited( d2fctx *pd2fctx,
                                                 d2fgra *pd2fgra, ub2 pnum );
ORA_RETTYPE(d2fstatus) d2fgraid_IspropDefault( d2fctx *pd2fctx,
                                               d2fgra *pd2fgra, ub2 pnum);
ORA_RETTYPE(d2fstatus) d2fgrais_IsSubclassed( d2fctx *pd2fctx,
                                              d2fgra *pd2fgra);


/* Begin convenience macros  */
#define d2fgrag_allow_expansion(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_ALLOW_EXPANSION,val)
#define d2fgrag_allow_mlt_lin_prmpts(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_ALLOW_MLT_LIN_PRMPTS,val)
#define d2fgrag_allow_strt_att_prmpts(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_ALLOW_STRT_ATT_PRMPTS,val)
#define d2fgrag_allow_top_att_prmpts(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_ALLOW_TOP_ATT_PRMPTS,val)
#define d2fgrag_arrow_sty(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_ARROW_STY,val)
#define d2fgrag_back_color(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fgrag_bevel(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_BEVEL,val)
#define d2fgrag_bounding_bx_scalable(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_BOUNDING_BX_SCALABLE,val)
#define d2fgrag_cap_sty(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_CAP_STY,val)
#define d2fgrag_client_info(ctx,obj,val) \
           d2fgragp_GetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fgrag_clip_hgt(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_CLIP_HGT,val)
#define d2fgrag_clip_wid(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_CLIP_WID,val)
#define d2fgrag_clip_x_pos(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_CLIP_X_POS,val)
#define d2fgrag_clip_y_pos(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_CLIP_Y_POS,val)
#define d2fgrag_closed(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_CLOSED,val)
#define d2fgrag_corner_radius_x(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_CORNER_RADIUS_X,val)
#define d2fgrag_corner_radius_y(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_CORNER_RADIUS_Y,val)
#define d2fgrag_cstm_spcing(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_CSTM_SPCING,val)
#define d2fgrag_dash_sty(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_DASH_STY,val)
#define d2fgrag_disp_qlty(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_DISP_QLTY,val)
#define d2fgrag_dist_btwn_recs(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_DIST_BTWN_RECS,val)
#define d2fgrag_dither(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_DITHER,val)
#define d2fgrag_edge_back_color(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_EDGE_BACK_COLOR,val)
#define d2fgrag_edge_fore_color(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_EDGE_FORE_COLOR,val)
#define d2fgrag_edge_pat(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_EDGE_PAT,val)
#define d2fgrag_fill_pat(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fgrag_fixed_bounding_bx(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_FIXED_BOUNDING_BX,val)
#define d2fgrag_font_scaleable(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_FONT_SCALEABLE,val)
#define d2fgrag_fore_color(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fgrag_frame_align(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_FRAME_ALIGN,val)
#define d2fgrag_frame_ttl(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_FRAME_TTL,val)
#define d2fgrag_frame_ttl_align(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_ALIGN,val)
#define d2fgrag_frame_ttl_back_color(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_FRAME_TTL_BACK_COLOR,val)
#define d2fgrag_frame_ttl_fill_pat(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_FRAME_TTL_FILL_PAT,val)
#define d2fgrag_frame_ttl_font_nam(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_FRAME_TTL_FONT_NAM,val)
#define d2fgrag_frame_ttl_font_siz(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_SIZ,val)
#define d2fgrag_frame_ttl_font_spcing(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_SPCING,val)
#define d2fgrag_frame_ttl_font_sty(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_STY,val)
#define d2fgrag_frame_ttl_font_wght(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_WGHT,val)
#define d2fgrag_frame_ttl_fore_color(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_FRAME_TTL_FORE_COLOR,val)
#define d2fgrag_frame_ttl_ofst(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_OFST,val)
#define d2fgrag_frame_ttl_spcing(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_FRAME_TTL_SPCING,val)
#define d2fgrag_frame_ttl_vat_nam(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_FRAME_TTL_VAT_NAM,val)
#define d2fgrag_frame_ttl_vat_obj(ctx,obj,val) \
           d2fgrago_GetObjProp(ctx,obj,D2FP_FRAME_TTL_VAT_OBJ,val)
#define d2fgrag_gra_font_color(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_GRA_FONT_COLOR,val)
#define d2fgrag_gra_font_color_code(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_GRA_FONT_COLOR_CODE,val)
#define d2fgrag_gra_font_nam(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_GRA_FONT_NAM,val)
#define d2fgrag_gra_font_siz(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_GRA_FONT_SIZ,val)
#define d2fgrag_gra_font_spcing(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_GRA_FONT_SPCING,val)
#define d2fgrag_gra_font_sty(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_GRA_FONT_STY,val)
#define d2fgrag_gra_font_wght(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_GRA_FONT_WGHT,val)
#define d2fgrag_gra_text(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_GRA_TEXT,val)
#define d2fgrag_graphic(ctx,obj,val) \
           d2fgrago_GetObjProp(ctx,obj,D2FP_GRAPHIC,val)
#define d2fgrag_graphics_typ(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_GRAPHICS_TYP,val)
#define d2fgrag_height(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fgrag_horz_jst(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_HORZ_JST,val)
#define d2fgrag_horz_margn(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_HORZ_MARGN,val)
#define d2fgrag_horz_obj_ofst(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_HORZ_OBJ_OFST,val)
#define d2fgrag_horz_orgn(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_HORZ_ORGN,val)
#define d2fgrag_internal_end_angle(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_INTERNAL_END_ANGLE,val)
#define d2fgrag_internal_lin_wid(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_INTERNAL_LIN_WID,val)
#define d2fgrag_internal_rotation_angle(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_INTERNAL_ROTATION_ANGLE,val)
#define d2fgrag_internal_strt_angle(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_INTERNAL_STRT_ANGLE,val)
#define d2fgrag_join_sty(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_JOIN_STY,val)
#define d2fgrag_lang_dir(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fgrag_layout_data_blk_nam(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_LAYOUT_DATA_BLK_NAM,val)
#define d2fgrag_layout_sty(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_LAYOUT_STY,val)
#define d2fgrag_lin_spcing(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_LIN_SPCING,val)
#define d2fgrag_max_objs(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_MAX_OBJS,val)
#define d2fgrag_module(ctx,obj,val) \
           d2fgrago_GetObjProp(ctx,obj,D2FP_MODULE,val)
#define d2fgrag_name(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fgrag_next(ctx,obj,val) \
           d2fgrago_GetObjProp(ctx,obj,D2FP_NEXT,val)
#define d2fgrag_owner(ctx,obj,val) \
           d2fgrago_GetObjProp(ctx,obj,D2FP_OWNER,val)
#define d2fgrag_par_flnam(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fgrag_par_flpath(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fgrag_par_modstr(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fgrag_par_modtyp(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fgrag_par_module(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fgrag_par_nam(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fgrag_par_typ(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fgrag_persist_client_info(ctx,obj,val) \
           d2fgragp_GetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fgrag_persist_clt_inf_len(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fgrag_point(ctx,obj,val) \
           d2fgrago_GetObjProp(ctx,obj,D2FP_POINT,val)
#define d2fgrag_previous(ctx,obj,val) \
           d2fgrago_GetObjProp(ctx,obj,D2FP_PREVIOUS,val)
#define d2fgrag_recs_disp_count(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_RECS_DISP_COUNT,val)
#define d2fgrag_scrlbr_align(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_SCRLBR_ALIGN,val)
#define d2fgrag_scrlbr_wid(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_SCRLBR_WID,val)
#define d2fgrag_show_scrlbr(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_SHOW_SCRLBR,val)
#define d2fgrag_shrinkwrap(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_SHRINKWRAP,val)
#define d2fgrag_sngl_obj_align(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_SNGL_OBJ_ALIGN,val)
#define d2fgrag_source(ctx,obj,val) \
           d2fgrago_GetObjProp(ctx,obj,D2FP_SOURCE,val)
#define d2fgrag_strt_prmpt_align(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_STRT_PRMPT_ALIGN,val)
#define d2fgrag_strt_prmpt_ofst(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_STRT_PRMPT_OFST,val)
#define d2fgrag_tbp_nam(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_TBP_NAM,val)
#define d2fgrag_tbp_obj(ctx,obj,val) \
           d2fgrago_GetObjProp(ctx,obj,D2FP_TBP_OBJ,val)
#define d2fgrag_top_prmpt_align(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_TOP_PRMPT_ALIGN,val)
#define d2fgrag_top_prmpt_ofst(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_TOP_PRMPT_OFST,val)
#define d2fgrag_ttl_reading_ordr(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_TTL_READING_ORDR,val)
#define d2fgrag_updt_layout(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_UPDT_LAYOUT,val)
#define d2fgrag_vat_nam(ctx,obj,val) \
           d2fgragt_GetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fgrag_vat_obj(ctx,obj,val) \
           d2fgrago_GetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fgrag_vert_fill(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_VERT_FILL,val)
#define d2fgrag_vert_jst(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_VERT_JST,val)
#define d2fgrag_vert_margn(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_VERT_MARGN,val)
#define d2fgrag_vert_obj_ofst(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_VERT_OBJ_OFST,val)
#define d2fgrag_vert_orgn(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_VERT_ORGN,val)
#define d2fgrag_width(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fgrag_wrap_txt(ctx,obj,val) \
           d2fgragb_GetBoolProp(ctx,obj,D2FP_WRAP_TXT,val)
#define d2fgrag_x_pos(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fgrag_y_pos(ctx,obj,val) \
           d2fgragn_GetNumProp(ctx,obj,D2FP_Y_POS,val)

#define d2fgras_allow_expansion(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_ALLOW_EXPANSION,val)
#define d2fgras_allow_mlt_lin_prmpts(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_ALLOW_MLT_LIN_PRMPTS,val)
#define d2fgras_allow_strt_att_prmpts(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_ALLOW_STRT_ATT_PRMPTS,val)
#define d2fgras_allow_top_att_prmpts(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_ALLOW_TOP_ATT_PRMPTS,val)
#define d2fgras_arrow_sty(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_ARROW_STY,val)
#define d2fgras_back_color(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_BACK_COLOR,val)
#define d2fgras_bevel(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_BEVEL,val)
#define d2fgras_bounding_bx_scalable(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_BOUNDING_BX_SCALABLE,val)
#define d2fgras_cap_sty(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_CAP_STY,val)
#define d2fgras_client_info(ctx,obj,val) \
           d2fgrasp_SetBlobProp(ctx,obj,D2FP_CLIENT_INFO,val)
#define d2fgras_clip_hgt(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_CLIP_HGT,val)
#define d2fgras_clip_wid(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_CLIP_WID,val)
#define d2fgras_clip_x_pos(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_CLIP_X_POS,val)
#define d2fgras_clip_y_pos(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_CLIP_Y_POS,val)
#define d2fgras_closed(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_CLOSED,val)
#define d2fgras_corner_radius_x(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_CORNER_RADIUS_X,val)
#define d2fgras_corner_radius_y(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_CORNER_RADIUS_Y,val)
#define d2fgras_cstm_spcing(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_CSTM_SPCING,val)
#define d2fgras_dash_sty(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_DASH_STY,val)
#define d2fgras_disp_qlty(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_DISP_QLTY,val)
#define d2fgras_dist_btwn_recs(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_DIST_BTWN_RECS,val)
#define d2fgras_dither(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_DITHER,val)
#define d2fgras_edge_back_color(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_EDGE_BACK_COLOR,val)
#define d2fgras_edge_fore_color(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_EDGE_FORE_COLOR,val)
#define d2fgras_edge_pat(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_EDGE_PAT,val)
#define d2fgras_fill_pat(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_FILL_PAT,val)
#define d2fgras_fixed_bounding_bx(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_FIXED_BOUNDING_BX,val)
#define d2fgras_font_scaleable(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_FONT_SCALEABLE,val)
#define d2fgras_fore_color(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_FORE_COLOR,val)
#define d2fgras_frame_align(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_FRAME_ALIGN,val)
#define d2fgras_frame_ttl(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_FRAME_TTL,val)
#define d2fgras_frame_ttl_align(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_ALIGN,val)
#define d2fgras_frame_ttl_back_color(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_FRAME_TTL_BACK_COLOR,val)
#define d2fgras_frame_ttl_fill_pat(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_FRAME_TTL_FILL_PAT,val)
#define d2fgras_frame_ttl_font_nam(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_FRAME_TTL_FONT_NAM,val)
#define d2fgras_frame_ttl_font_siz(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_SIZ,val)
#define d2fgras_frame_ttl_font_spcing(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_SPCING,val)
#define d2fgras_frame_ttl_font_sty(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_STY,val)
#define d2fgras_frame_ttl_font_wght(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_FONT_WGHT,val)
#define d2fgras_frame_ttl_fore_color(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_FRAME_TTL_FORE_COLOR,val)
#define d2fgras_frame_ttl_ofst(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_OFST,val)
#define d2fgras_frame_ttl_spcing(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_FRAME_TTL_SPCING,val)
#define d2fgras_frame_ttl_vat_nam(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_FRAME_TTL_VAT_NAM,val)
#define d2fgras_frame_ttl_vat_obj(ctx,obj,val) \
           d2fgraso_SetObjProp(ctx,obj,D2FP_FRAME_TTL_VAT_OBJ,val)
#define d2fgras_gra_font_color(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_GRA_FONT_COLOR,val)
#define d2fgras_gra_font_color_code(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_GRA_FONT_COLOR_CODE,val)
#define d2fgras_gra_font_nam(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_GRA_FONT_NAM,val)
#define d2fgras_gra_font_siz(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_GRA_FONT_SIZ,val)
#define d2fgras_gra_font_spcing(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_GRA_FONT_SPCING,val)
#define d2fgras_gra_font_sty(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_GRA_FONT_STY,val)
#define d2fgras_gra_font_wght(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_GRA_FONT_WGHT,val)
#define d2fgras_gra_text(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_GRA_TEXT,val)
#define d2fgras_graphics_typ(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_GRAPHICS_TYP,val)
#define d2fgras_height(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_HEIGHT,val)
#define d2fgras_horz_jst(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_HORZ_JST,val)
#define d2fgras_horz_margn(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_HORZ_MARGN,val)
#define d2fgras_horz_obj_ofst(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_HORZ_OBJ_OFST,val)
#define d2fgras_horz_orgn(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_HORZ_ORGN,val)
#define d2fgras_internal_end_angle(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_INTERNAL_END_ANGLE,val)
#define d2fgras_internal_lin_wid(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_INTERNAL_LIN_WID,val)
#define d2fgras_internal_rotation_angle(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_INTERNAL_ROTATION_ANGLE,val)
#define d2fgras_internal_strt_angle(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_INTERNAL_STRT_ANGLE,val)
#define d2fgras_join_sty(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_JOIN_STY,val)
#define d2fgras_lang_dir(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_LANG_DIR,val)
#define d2fgras_layout_data_blk_nam(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_LAYOUT_DATA_BLK_NAM,val)
#define d2fgras_layout_sty(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_LAYOUT_STY,val)
#define d2fgras_lin_spcing(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_LIN_SPCING,val)
#define d2fgras_max_objs(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_MAX_OBJS,val)
#define d2fgras_name(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_NAME,val)
#define d2fgras_par_flnam(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_PAR_FLNAM,val)
#define d2fgras_par_flpath(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_PAR_FLPATH,val)
#define d2fgras_par_modstr(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_PAR_MODSTR,val)
#define d2fgras_par_modtyp(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_PAR_MODTYP,val)
#define d2fgras_par_module(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_PAR_MODULE,val)
#define d2fgras_par_nam(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_PAR_NAM,val)
#define d2fgras_par_typ(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_PAR_TYP,val)
#define d2fgras_persist_client_info(ctx,obj,val) \
           d2fgrasp_SetBlobProp(ctx,obj,D2FP_PERSIST_CLIENT_INFO,val)
#define d2fgras_persist_clt_inf_len(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_PERSIST_CLT_INF_LEN,val)
#define d2fgras_recs_disp_count(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_RECS_DISP_COUNT,val)
#define d2fgras_scrlbr_align(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_SCRLBR_ALIGN,val)
#define d2fgras_scrlbr_wid(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_SCRLBR_WID,val)
#define d2fgras_show_scrlbr(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_SHOW_SCRLBR,val)
#define d2fgras_shrinkwrap(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_SHRINKWRAP,val)
#define d2fgras_sngl_obj_align(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_SNGL_OBJ_ALIGN,val)
#define d2fgras_strt_prmpt_align(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_STRT_PRMPT_ALIGN,val)
#define d2fgras_strt_prmpt_ofst(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_STRT_PRMPT_OFST,val)
#define d2fgras_tbp_nam(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_TBP_NAM,val)
#define d2fgras_tbp_obj(ctx,obj,val) \
           d2fgraso_SetObjProp(ctx,obj,D2FP_TBP_OBJ,val)
#define d2fgras_top_prmpt_align(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_TOP_PRMPT_ALIGN,val)
#define d2fgras_top_prmpt_ofst(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_TOP_PRMPT_OFST,val)
#define d2fgras_ttl_reading_ordr(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_TTL_READING_ORDR,val)
#define d2fgras_updt_layout(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_UPDT_LAYOUT,val)
#define d2fgras_vat_nam(ctx,obj,val) \
           d2fgrast_SetTextProp(ctx,obj,D2FP_VAT_NAM,val)
#define d2fgras_vat_obj(ctx,obj,val) \
           d2fgraso_SetObjProp(ctx,obj,D2FP_VAT_OBJ,val)
#define d2fgras_vert_fill(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_VERT_FILL,val)
#define d2fgras_vert_jst(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_VERT_JST,val)
#define d2fgras_vert_margn(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_VERT_MARGN,val)
#define d2fgras_vert_obj_ofst(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_VERT_OBJ_OFST,val)
#define d2fgras_vert_orgn(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_VERT_ORGN,val)
#define d2fgras_width(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_WIDTH,val)
#define d2fgras_wrap_txt(ctx,obj,val) \
           d2fgrasb_SetBoolProp(ctx,obj,D2FP_WRAP_TXT,val)
#define d2fgras_x_pos(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_X_POS,val)
#define d2fgras_y_pos(ctx,obj,val) \
           d2fgrasn_SetNumProp(ctx,obj,D2FP_Y_POS,val)
/* End convenience macros  */

/* C++ Support */
#ifdef __cplusplus
}
#endif
               
#endif /* D2FGRA */

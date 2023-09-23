/*******************************************************************************
 * Size: 24 px
 * Bpp: 4
 * Opts: --bpp 4 --size 24 --font E:\ESP32_vscode_test\ui_code_8.3.3\assets\temp.ttf -o E:\ESP32_vscode_test\ui_code_8.3.3\assets\ui_font_temp.c --format lvgl -r 0xeb23 --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_TEMP
#define UI_FONT_TEMP 1
#endif

#if UI_FONT_TEMP

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+EB23 "" */
    0x0, 0x0, 0x1, 0xae, 0xea, 0x10, 0x0, 0x0,
    0x0, 0x0, 0x1e, 0xf9, 0x9f, 0xe1, 0x0, 0x0,
    0x3b, 0xb3, 0x8f, 0x30, 0x3, 0xf8, 0x3b, 0xb3,
    0x2a, 0xa2, 0xbc, 0x9, 0x90, 0xcb, 0x2a, 0xa2,
    0x0, 0x0, 0xbb, 0xc, 0xc0, 0xbb, 0x0, 0x0,
    0x4d, 0xd4, 0xbb, 0xc, 0xc0, 0xbb, 0x4d, 0xd4,
    0x2a, 0xa2, 0xbb, 0xc, 0xc0, 0xbb, 0x2a, 0xa2,
    0x0, 0x0, 0xbb, 0xc, 0xc0, 0xbb, 0x0, 0x0,
    0x4d, 0x70, 0xcb, 0xc, 0xc0, 0xbc, 0x7, 0xd4,
    0x2a, 0x52, 0xfa, 0xc, 0xc0, 0xaf, 0x25, 0xa2,
    0x0, 0xb, 0xe1, 0xc, 0xc0, 0x1e, 0xb0, 0x0,
    0x4a, 0x1f, 0x80, 0xe, 0xe1, 0x7, 0xf1, 0xa4,
    0x27, 0x3f, 0x40, 0x7f, 0xf7, 0x4, 0xf3, 0x73,
    0x0, 0x2f, 0x50, 0x3f, 0xf3, 0x5, 0xf2, 0x0,
    0x4a, 0xd, 0xb0, 0x0, 0x0, 0xb, 0xd0, 0xb4,
    0x27, 0x5, 0xf8, 0x0, 0x0, 0x8f, 0x50, 0x72,
    0x0, 0x0, 0x8f, 0xd8, 0x8d, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xad, 0xda, 0x30, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 384, .box_w = 16, .box_h = 19, .ofs_x = 4, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 60195, .range_length = 1, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_temp = {
#else
lv_font_t ui_font_temp = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_TEMP*/


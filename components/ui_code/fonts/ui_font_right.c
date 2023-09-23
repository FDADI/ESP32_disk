/*******************************************************************************
 * Size: 20 px
 * Bpp: 4
 * Opts: --bpp 4 --size 20 --font E:\ESP32_vscode_test\ui_code_8.3.3\assets\right.ttf -o E:\ESP32_vscode_test\ui_code_8.3.3\assets\ui_font_right.c --format lvgl -r 0xe61a --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_RIGHT
#define UI_FONT_RIGHT 1
#endif

#if UI_FONT_RIGHT

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+E61A "" */
    0x1, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x3e, 0x60, 0x0, 0x2, 0xe7, 0x0, 0x0,
    0x0, 0x0, 0x5f, 0xf6, 0x0, 0x3, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x4, 0xff, 0x60, 0x0, 0x3f,
    0xf8, 0x0, 0x0, 0x0, 0x0, 0x4f, 0xf7, 0x0,
    0x3, 0xef, 0x80, 0x0, 0x0, 0x0, 0x3, 0xff,
    0x70, 0x0, 0x2e, 0xf9, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xf8, 0x0, 0x2, 0xef, 0x90, 0x0, 0x0,
    0x0, 0x3, 0xef, 0x80, 0x0, 0x2e, 0xfa, 0x0,
    0x0, 0x0, 0x0, 0x2e, 0xf9, 0x0, 0x2, 0xdf,
    0xa0, 0x0, 0x0, 0x0, 0x5, 0xff, 0x50, 0x0,
    0x4f, 0xf6, 0x0, 0x0, 0x0, 0x3f, 0xf7, 0x0,
    0x2, 0xef, 0x90, 0x0, 0x0, 0x4, 0xff, 0x70,
    0x0, 0x3e, 0xf8, 0x0, 0x0, 0x0, 0x4f, 0xf7,
    0x0, 0x3, 0xef, 0x80, 0x0, 0x0, 0x4, 0xff,
    0x60, 0x0, 0x3f, 0xf8, 0x0, 0x0, 0x0, 0x5f,
    0xf6, 0x0, 0x4, 0xff, 0x70, 0x0, 0x0, 0x5,
    0xff, 0x50, 0x0, 0x4f, 0xf7, 0x0, 0x0, 0x0,
    0x5f, 0xf5, 0x0, 0x4, 0xff, 0x60, 0x0, 0x0,
    0x0, 0x2e, 0x40, 0x0, 0x1, 0xd6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 320, .box_w = 18, .box_h = 19, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 58906, .range_length = 1, .glyph_id_start = 1,
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
const lv_font_t ui_font_right = {
#else
lv_font_t ui_font_right = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_RIGHT*/


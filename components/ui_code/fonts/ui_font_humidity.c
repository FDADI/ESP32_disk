/*******************************************************************************
 * Size: 20 px
 * Bpp: 4
 * Opts: --bpp 4 --size 20 --font E:\ESP32_vscode_test\ui_code_8.3.3\assets\humidity.ttf -o E:\ESP32_vscode_test\ui_code_8.3.3\assets\ui_font_humidity.c --format lvgl -r 0xea30 --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_HUMIDITY
#define UI_FONT_HUMIDITY 1
#endif

#if UI_FONT_HUMIDITY

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+EA30 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0,
    0x0, 0x0, 0x5b, 0xbb, 0x30, 0x2, 0xff, 0x20,
    0x5, 0xbb, 0xb3, 0x9f, 0xff, 0x60, 0xc, 0xff,
    0xc0, 0xa, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x6f,
    0xaa, 0xf5, 0x0, 0x11, 0x0, 0x0, 0x0, 0x1,
    0xef, 0x11, 0xfe, 0x0, 0x0, 0x0, 0x49, 0x30,
    0x8, 0xf7, 0x0, 0x7f, 0x70, 0x4, 0x92, 0xaf,
    0x80, 0x1f, 0xe0, 0x0, 0xe, 0xf1, 0xa, 0xf7,
    0x2, 0x0, 0x8f, 0x60, 0x0, 0x6, 0xf8, 0x0,
    0x10, 0x0, 0x0, 0xfe, 0x0, 0x0, 0x0, 0xee,
    0x0, 0x0, 0x25, 0x5, 0xf8, 0x0, 0x0, 0x0,
    0x8f, 0x50, 0x51, 0xaf, 0x49, 0xf2, 0x0, 0x0,
    0x10, 0x3f, 0x96, 0xf7, 0x26, 0xb, 0xf0, 0x0,
    0x2, 0xea, 0x1f, 0xb1, 0x61, 0x0, 0x9, 0xf3,
    0x2, 0xef, 0xf5, 0x4f, 0x90, 0x0, 0x0, 0x4,
    0xfa, 0x3, 0xcb, 0x40, 0xbf, 0x40, 0x0, 0x0,
    0x0, 0xcf, 0x90, 0x0, 0x9, 0xfb, 0x0, 0x0,
    0x0, 0x0, 0x1d, 0xfe, 0xbb, 0xef, 0xd1, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x8e, 0xff, 0xe8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0,
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
        .range_start = 59952, .range_length = 1, .glyph_id_start = 1,
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
const lv_font_t ui_font_humidity = {
#else
lv_font_t ui_font_humidity = {
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



#endif /*#if UI_FONT_HUMIDITY*/


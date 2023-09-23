/*******************************************************************************
 * Size: 16 px
 * Bpp: 4
 * Opts: --bpp 4 --size 16 --font E:\ESP32_vscode_test\ui_code_8.3.3\assets\airtemp.ttf -o E:\ESP32_vscode_test\ui_code_8.3.3\assets\ui_font_airtemp.c --format lvgl -r 0xe6bd --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_AIRTEMP
#define UI_FONT_AIRTEMP 1
#endif

#if UI_FONT_AIRTEMP

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+E6BD "" */
    0x0, 0x0, 0x0, 0x7, 0xa0, 0x4e, 0xe4, 0x0,
    0x0, 0x0, 0x0, 0x7, 0xa0, 0xf5, 0x4f, 0x10,
    0x0, 0xc6, 0x0, 0x2, 0x12, 0xe0, 0xd, 0x30,
    0x0, 0x3e, 0x12, 0xbf, 0xf2, 0xe0, 0xd, 0x30,
    0x0, 0x0, 0x3f, 0xe8, 0x62, 0xe0, 0xd, 0x30,
    0x0, 0x0, 0xed, 0x10, 0x2, 0xe4, 0x5d, 0x30,
    0x0, 0x6, 0xf3, 0x0, 0x2, 0xe7, 0x8d, 0x30,
    0x66, 0x29, 0xe0, 0x0, 0x2, 0xe7, 0x8d, 0x30,
    0x9a, 0x4a, 0xe0, 0x0, 0x2, 0xe7, 0x8d, 0x30,
    0x0, 0x7, 0xf2, 0x0, 0xa, 0xc7, 0x8b, 0xb0,
    0x0, 0x1, 0xfb, 0x0, 0x6d, 0x1a, 0xb1, 0xc7,
    0x0, 0x0, 0x5f, 0xd2, 0xb6, 0x7f, 0xf8, 0x5c,
    0x0, 0x3e, 0x14, 0xd5, 0xb5, 0x9f, 0xfa, 0x4c,
    0x0, 0xc6, 0x0, 0x0, 0x7b, 0x2c, 0xd3, 0xa8,
    0x0, 0x0, 0x0, 0x0, 0xd, 0xa3, 0x29, 0xe1,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x9e, 0xea, 0x10
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 256, .box_w = 16, .box_h = 16, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 59069, .range_length = 1, .glyph_id_start = 1,
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
const lv_font_t ui_font_airtemp = {
#else
lv_font_t ui_font_airtemp = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
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



#endif /*#if UI_FONT_AIRTEMP*/


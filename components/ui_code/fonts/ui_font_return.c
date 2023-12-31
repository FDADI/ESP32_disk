/*******************************************************************************
 * Size: 20 px
 * Bpp: 4
 * Opts: --bpp 4 --size 20 --font E:\ESP32_vscode_test\ui_code_8.3.3\assets\return.ttf -o E:\ESP32_vscode_test\ui_code_8.3.3\assets\ui_font_return.c --format lvgl -r 0xe6ff --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_RETURN
#define UI_FONT_RETURN 1
#endif

#if UI_FONT_RETURN

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+E6FF "" */
    0x0, 0x0, 0x0, 0x22, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4, 0xf6, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6f, 0x60, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xf5, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x9e, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xe2, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0x92, 0x0, 0x2d,
    0xd4, 0x33, 0x33, 0x33, 0x33, 0x35, 0xbe, 0x30,
    0x1, 0xcc, 0x10, 0x0, 0x0, 0x0, 0x0, 0x7,
    0xe1, 0x0, 0xb, 0xd2, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xc7, 0x0, 0x0, 0x9e, 0x30, 0x0, 0x0,
    0x0, 0x0, 0x7a, 0x0, 0x0, 0x8, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0x7b, 0x0, 0x0, 0x0, 0x55,
    0x0, 0x0, 0x0, 0x0, 0xb8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x4, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x6f, 0x60, 0x0,
    0x0, 0x7, 0xff, 0xff, 0xff, 0xff, 0xd5, 0x0,
    0x0, 0x0, 0x1, 0x33, 0x33, 0x33, 0x31, 0x0,
    0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 320, .box_w = 18, .box_h = 17, .ofs_x = 1, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 59135, .range_length = 1, .glyph_id_start = 1,
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
const lv_font_t ui_font_return = {
#else
lv_font_t ui_font_return = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
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



#endif /*#if UI_FONT_RETURN*/


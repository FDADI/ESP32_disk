/*******************************************************************************
 * Size: 18 px
 * Bpp: 4
 * Opts: --bpp 4 --size 18 --font E:\ESP32_vscode_test\ui_code_8.3.3\assets\backlight.ttf -o E:\ESP32_vscode_test\ui_code_8.3.3\assets\ui_font_backlight.c --format lvgl -r 0xe6ae --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_BACKLIGHT
#define UI_FONT_BACKLIGHT 1
#endif

#if UI_FONT_BACKLIGHT

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+E6AE "" */
    0x0, 0x0, 0x0, 0xc, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa0, 0x4, 0x0, 0xf, 0x0, 0x0,
    0x0, 0x0, 0x90, 0x0, 0x0, 0x4, 0x0, 0x0,
    0x0, 0x0, 0x6, 0xbb, 0xba, 0x20, 0x0, 0x0,
    0xf, 0x11, 0xff, 0xff, 0xff, 0xfb, 0x3, 0xf0,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0x30, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x0,
    0xf4, 0xf, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x4e,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0x90, 0x0,
    0xa, 0x3a, 0xff, 0xff, 0xff, 0xff, 0x3, 0x90,
    0x6, 0x0, 0xaf, 0xff, 0xff, 0xf3, 0x0, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x4, 0xd0, 0x0, 0x0, 0xf, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0x10, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 288, .box_w = 16, .box_h = 17, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 59054, .range_length = 1, .glyph_id_start = 1,
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
const lv_font_t ui_font_backlight = {
#else
lv_font_t ui_font_backlight = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
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



#endif /*#if UI_FONT_BACKLIGHT*/


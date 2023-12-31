// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.3
// Project name: ui_code

#include "../ui.h"

void ui_homepage_screen_init(void)
{
    ui_homepage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_homepage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_homepage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homepage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_homepage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_homepagePanel = lv_obj_create(ui_homepage);
    lv_obj_set_width(ui_homepagePanel, 240);
    lv_obj_set_height(ui_homepagePanel, 280);
    lv_obj_set_align(ui_homepagePanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_homepagePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_homepagePanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homepagePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_homepagePanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_homepagePanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_homepagePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_homepagePanel, lv_color_hex(0x000000), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homepagePanel, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_homepagePanel, lv_color_hex(0x000000), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, -96);
    lv_obj_set_y(ui_Label1, 92);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xE21C1C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label1, &ui_font_temp, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, -96);
    lv_obj_set_y(ui_Label2, 116);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0x038FEC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label2, &ui_font_humidity, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_tempBar = lv_bar_create(ui_homepage);
    lv_bar_set_value(ui_tempBar, 25, LV_ANIM_OFF);
    lv_obj_set_width(ui_tempBar, 150);
    lv_obj_set_height(ui_tempBar, 10);
    lv_obj_set_x(ui_tempBar, -2);
    lv_obj_set_y(ui_tempBar, 91);
    lv_obj_set_align(ui_tempBar, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_tempBar, lv_color_hex(0xE78080), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_tempBar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_humidityBar = lv_bar_create(ui_homepage);
    lv_bar_set_value(ui_humidityBar, 25, LV_ANIM_OFF);
    lv_obj_set_width(ui_humidityBar, 150);
    lv_obj_set_height(ui_humidityBar, 10);
    lv_obj_set_x(ui_humidityBar, -2);
    lv_obj_set_y(ui_humidityBar, 118);
    lv_obj_set_align(ui_humidityBar, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_humidityBar, lv_color_hex(0x1623EE), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_humidityBar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_temp = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_temp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_temp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_temp, 87);
    lv_obj_set_y(ui_temp, 91);
    lv_obj_set_align(ui_temp, LV_ALIGN_CENTER);
    lv_label_set_text(ui_temp, "34");
    lv_obj_set_style_text_color(ui_temp, lv_color_hex(0xFC3D3D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_temp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_temp, &ui_font_alibaba14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_humidity = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_humidity, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_humidity, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_humidity, 92);
    lv_obj_set_y(ui_humidity, 118);
    lv_obj_set_align(ui_humidity, LV_ALIGN_CENTER);
    lv_label_set_text(ui_humidity, "50%");
    lv_obj_set_style_text_color(ui_humidity, lv_color_hex(0x02CCFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_humidity, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_humidity, &ui_font_alibaba14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Arc1 = lv_arc_create(ui_homepage);
    lv_obj_set_width(ui_Arc1, 150);
    lv_obj_set_height(ui_Arc1, 150);
    lv_obj_set_x(ui_Arc1, -2);
    lv_obj_set_y(ui_Arc1, -45);
    lv_obj_set_align(ui_Arc1, LV_ALIGN_CENTER);
    lv_arc_set_bg_angles(ui_Arc1, 0, 360);
    lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0x24FC6E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0x24FC6E), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc1, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0x24FC6E), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label5 = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, -2);
    lv_obj_set_y(ui_Label5, -47);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "~~~~~~~~~~~~~~~");
    lv_obj_set_style_text_color(ui_Label5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_hour = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_hour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_hour, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_hour, -25);
    lv_obj_set_y(ui_hour, -70);
    lv_obj_set_align(ui_hour, LV_ALIGN_CENTER);
    lv_label_set_text(ui_hour, "15");
    lv_obj_set_style_text_color(ui_hour, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_hour, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_hour, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label7 = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label7, -2);
    lv_obj_set_y(ui_Label7, -71);
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, ":");
    lv_obj_set_style_text_color(ui_Label7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label7, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_min = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_min, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_min, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_min, 23);
    lv_obj_set_y(ui_min, -70);
    lv_obj_set_align(ui_min, LV_ALIGN_CENTER);
    lv_label_set_text(ui_min, "00");
    lv_obj_set_style_text_color(ui_min, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_min, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_min, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_month = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_month, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_month, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_month, -41);
    lv_obj_set_y(ui_month, -33);
    lv_obj_set_align(ui_month, LV_ALIGN_CENTER);
    lv_label_set_text(ui_month, "9");
    lv_obj_set_style_text_color(ui_month, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_month, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_month, &ui_font_alibaba14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label10 = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label10, -35);
    lv_obj_set_y(ui_Label10, -32);
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "/");
    lv_obj_set_style_text_color(ui_Label10, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label10, &ui_font_alibaba14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_day = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_day, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_day, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_day, -25);
    lv_obj_set_y(ui_day, -33);
    lv_obj_set_align(ui_day, LV_ALIGN_CENTER);
    lv_label_set_text(ui_day, "15");
    lv_obj_set_style_text_color(ui_day, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_day, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_day, &ui_font_alibaba14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_year = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_year, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_year, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_year, 29);
    lv_obj_set_y(ui_year, -33);
    lv_obj_set_align(ui_year, LV_ALIGN_CENTER);
    lv_label_set_text(ui_year, "星期");
    lv_obj_set_style_text_color(ui_year, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_year, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_year, &ui_font_alibaba14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_airtempArc = lv_arc_create(ui_homepage);
    lv_obj_set_width(ui_airtempArc, 51);
    lv_obj_set_height(ui_airtempArc, 50);
    lv_obj_set_x(ui_airtempArc, -3);
    lv_obj_set_y(ui_airtempArc, -1);
    lv_obj_set_align(ui_airtempArc, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_airtempArc, -50, 50);
    lv_arc_set_value(ui_airtempArc, 6);
    lv_obj_set_style_bg_img_recolor(ui_airtempArc, lv_color_hex(0x0EACF6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui_airtempArc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_airtempArc, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_airtempArc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_airtempArc, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_img_recolor(ui_airtempArc, lv_color_hex(0x0EACF6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui_airtempArc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_airtempArc, lv_color_hex(0x0EACF6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_airtempArc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_airtempArc, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_airtempArc, lv_color_hex(0x0EACF6), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_airtempArc, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui_airtempArc, lv_color_hex(0x0EACF6), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui_airtempArc, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_airtempArc, LV_BLEND_MODE_MULTIPLY, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_airtempArc, 6, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label13 = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label13, -5);
    lv_obj_set_y(ui_Label13, -8);
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "");
    lv_obj_set_style_text_color(ui_Label13, lv_color_hex(0x324AF8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label13, &ui_font_airtemp, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_airtemp = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_airtemp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_airtemp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_airtemp, -3);
    lv_obj_set_y(ui_airtemp, 11);
    lv_obj_set_align(ui_airtemp, LV_ALIGN_CENTER);
    lv_label_set_text(ui_airtemp, "6");
    lv_obj_set_style_text_color(ui_airtemp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_airtemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_airtemp, &ui_font_alibaba14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weather = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_weather, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weather, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_weather, -2);
    lv_obj_set_y(ui_weather, -96);
    lv_obj_set_align(ui_weather, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weather, "多云");
    lv_obj_set_style_text_color(ui_weather, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_weather, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_weather, &ui_font_alibaba14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label11 = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label11, 98);
    lv_obj_set_y(ui_Label11, 91);
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "°");
    lv_obj_set_style_text_color(ui_Label11, lv_color_hex(0xFC3D3D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label15 = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label15, 4);
    lv_obj_set_y(ui_Label15, 11);
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "°");
    lv_obj_set_style_text_color(ui_Label15, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button7 = lv_btn_create(ui_homepage);
    lv_obj_set_width(ui_Button7, 63);
    lv_obj_set_height(ui_Button7, 28);
    lv_obj_set_x(ui_Button7, -5);
    lv_obj_set_y(ui_Button7, 55);
    lv_obj_set_align(ui_Button7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button7, lv_color_hex(0x54AAB3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Button7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label28 = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_Label28, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label28, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label28, -4);
    lv_obj_set_y(ui_Label28, 55);
    lv_obj_set_align(ui_Label28, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label28, "");
    lv_obj_set_style_text_font(ui_Label28, &ui_font_right, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label33 = lv_label_create(ui_homepage);
    lv_obj_set_width(ui_Label33, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label33, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label33, 51);
    lv_obj_set_y(ui_Label33, -33);
    lv_obj_set_align(ui_Label33, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label33, "一");
    lv_obj_set_style_text_color(ui_Label33, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label33, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label33, &ui_font_alibaba14, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button7, ui_event_Button7, LV_EVENT_ALL, NULL);

}

// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.3
// Project name: ui_code

#include "../ui.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "nvs_flash.h"
lv_obj_t *ui_Keyboard3;
// extern lv_chart_series_t * ui_Chart1_series_2;
static void Keyboard_enev(lv_event_t *e)
{
    lv_obj_t *tar = lv_event_get_target(e);
    if (e->code == LV_EVENT_PRESSED)
    {
        uint16_t id = lv_btnmatrix_get_selected_btn(ui_Keyboard3); // 确认按钮位39

        if(id==39)
        {
            
        }
        // lv_coord_t ui_Chart1_series_2_array[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
        // lv_chart_set_ext_y_array(ui_Chart1, ui_Chart1_series_2, ui_Chart1_series_2_array);
    }
}
void ui_WiFipage_screen_init(void)
{
    ui_WiFipage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_WiFipage, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_WiFipage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WiFipage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_WiFipage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WiFipagepanel = lv_obj_create(ui_WiFipage);
    lv_obj_set_width(ui_WiFipagepanel, 240);
    lv_obj_set_height(ui_WiFipagepanel, 280);
    lv_obj_set_align(ui_WiFipagepanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_WiFipagepanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_WiFipagepanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WiFipagepanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_WiFipagepanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_WiFipagepanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_WiFipagepanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_returnWiFi = lv_btn_create(ui_WiFipage);
    lv_obj_set_width(ui_returnWiFi, 82);
    lv_obj_set_height(ui_returnWiFi, 33);
    lv_obj_set_x(ui_returnWiFi, 48);
    lv_obj_set_y(ui_returnWiFi, 106);
    lv_obj_set_align(ui_returnWiFi, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_returnWiFi, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_returnWiFi, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_returnWiFi, lv_color_hex(0x131510), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_returnWiFi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_returnWiFi, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label24 = lv_label_create(ui_WiFipage);
    lv_obj_set_width(ui_Label24, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label24, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label24, 46);
    lv_obj_set_y(ui_Label24, 105);
    lv_obj_set_align(ui_Label24, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label24, "");
    lv_obj_set_style_text_color(ui_Label24, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label24, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label24, &ui_font_return, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label26 = lv_label_create(ui_WiFipage);
    lv_obj_set_width(ui_Label26, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label26, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label26, -77);
    lv_obj_set_y(ui_Label26, -105);
    lv_obj_set_align(ui_Label26, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label26, "账号");
    lv_obj_set_style_text_color(ui_Label26, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label26, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label26, &ui_font_alibaba20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label27 = lv_label_create(ui_WiFipage);
    lv_obj_set_width(ui_Label27, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label27, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label27, -77);
    lv_obj_set_y(ui_Label27, -59);
    lv_obj_set_align(ui_Label27, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label27, "密码");
    lv_obj_set_style_text_color(ui_Label27, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label27, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label27, &ui_font_alibaba20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextArea1 = lv_textarea_create(ui_WiFipage);
    lv_obj_set_width(ui_TextArea1, 150);
    lv_obj_set_height(ui_TextArea1, LV_SIZE_CONTENT); /// 29
    lv_obj_set_x(ui_TextArea1, 22);
    lv_obj_set_y(ui_TextArea1, -105);
    lv_obj_set_align(ui_TextArea1, LV_ALIGN_CENTER);
    lv_textarea_set_one_line(ui_TextArea1, true);

    ui_TextArea2 = lv_textarea_create(ui_WiFipage);
    lv_obj_set_width(ui_TextArea2, 150);
    lv_obj_set_height(ui_TextArea2, LV_SIZE_CONTENT); /// 25
    lv_obj_set_x(ui_TextArea2, 22);
    lv_obj_set_y(ui_TextArea2, -60);
    lv_obj_set_align(ui_TextArea2, LV_ALIGN_CENTER);
    lv_textarea_set_one_line(ui_TextArea2, true);

    ui_Keyboard3 = lv_keyboard_create(ui_WiFipage);
    lv_obj_set_width(ui_Keyboard3, 219);
    lv_obj_set_height(ui_Keyboard3, 112);
    lv_obj_set_x(ui_Keyboard3, 1);
    lv_obj_set_y(ui_Keyboard3, 24);
    lv_obj_set_align(ui_Keyboard3, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_Keyboard3, Keyboard_enev, LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_returnWiFi, ui_event_returnWiFi, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextArea1, ui_event_TextArea1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextArea2, ui_event_TextArea2, LV_EVENT_ALL, NULL);
}
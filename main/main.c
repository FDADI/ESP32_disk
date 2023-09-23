/*
 * @Author: lmh 885288596@qq.com
 * @Date: 2023-04-28 21:50:05
 * @LastEditors: lmh 885288596@qq.com
 * @LastEditTime: 2023-05-13 19:56:19
 * @FilePath: /st7789/main/main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdint.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "../components/user_dev/SPI/User_dev_spi.h"
#include "../components/user_dev/TOUCH/touch_iic.h"
#include "../components/user_mid/lcd.h"
#include "../components/lvgl/lvgl.h"
#include "../components/lvgl/lvgl_driver/lv_port_disp.h"
#include "../components/lvgl/demos/music/lv_demo_music.h"
#include "lv_demos.h"
#include "ui.h"
#include "../components/AHT20/ATH20.h"
#include "../components/WiFi_get_data/WiFi_get_data.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_sntp.h"
#include "esp_http_client.h"
#include "../components/task_manage/task_manage.h"
#include "freertos/FreeRTOSConfig.h"
#include "driver/ledc.h"
#include "peripheral.h"
extern wifi_ssid_password wifi;//wifi上电默认连接密码00000和id000000的wifi
#define wifi_ssid_init "000000"
#define wifi_pass_init "000000"
#define STORAGE_NAMESPACE "wifi_data"
void app_main(void)
{
   char x=1;
   char y=1;
   lv_init();
   lv_port_disp_init();
   touch_iic_init();
   ui_init();
   i2c_setup();            // AHT20
   lamp_gpio_init();       // 台灯
   buzzer_gpio_init();     // 蜂鸣器
   backlight_gpio_init();  // 背光
   backlight_duty_set(70); // 默认先背光70
   humidifier_gpio_init(); // 加湿器
   humidifier_open();

   esp_err_t err = nvs_flash_init();
   if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
   {
      ESP_ERROR_CHECK(nvs_flash_erase());
      err = nvs_flash_init();
   }
   ESP_ERROR_CHECK(err);
   nvs_handle_t wifi_handle;
   nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &wifi_handle);
   size_t length = sizeof(wifi);
   nvs_get_blob(wifi_handle, "wifi_password", &wifi, &length);
   nvs_close(wifi_handle);
   x = strcmp(wifi.password,wifi_pass_init);//判断上电的密码是否为初始密码
   y = strcmp(wifi.ssid,wifi_ssid_init);
   if(x==0 && y==0)
   {
      lv_disp_load_scr(ui_WiFipage);//加载到wifi页面重新设置密码和id
       //printf("NVS failuer123\r\n");
   }
   //printf("ssid :%s pass :%s x:%d y: %d\r\n",wifi.ssid,wifi.password,x,y);  
   // nvs_set_blob(wifi_handle,"wifi_password",&wifi,sizeof(wifi));
   // if(ESP_OK!=(nvs_commit(wifi_handle)))
   // {
   //     printf("NVS failuer123\r\n");
   // }
   // fast_scan();
   MX_FREERTOS_Init();

   vTaskDelete(NULL);
}

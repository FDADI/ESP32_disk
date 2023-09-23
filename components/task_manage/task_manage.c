#include "task_manage.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "stdio.h"
#include "../components/lvgl/lvgl.h"
#include "../components/lvgl/lvgl_driver/lv_port_disp.h"
#include "ATH20.h"
#include "ui.h"
#include "peripheral.h"
#include "esp_timer.h"
SemaphoreHandle_t humidifier_semap;//加湿器的湿度在60以下的信号量

void MX_FREERTOS_Init()
{
    humidifier_semap = xSemaphoreCreateBinary();
    //xSemaphoreGive(humidifier_semap);//释放
    xTaskCreate(lvgl_handler, "lvgl_handler", 2048*2, NULL, 5, NULL); // 创建lvgl_handler任务函数
    xTaskCreate(&aht20_read_measures, "task_read_ath20",  10096, NULL, 1, NULL);
    xTaskCreate(humidifiertask, "humidifiertask",  4096, NULL, 0, NULL);

}
/*用定时器给LVGL提供时钟*/
static void lv_tick_task(void *arg)
{
    (void)arg;
    lv_tick_inc(1);
}
void lvgl_handler(void *param)
{

    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui"};
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, 1000));
    ui_init();
    while (1)
    {
        lv_task_handler();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
void humidifiertask(void *param)
{

    while(1)
    {
        xSemaphoreTake(humidifier_semap, portMAX_DELAY);             /* 获取二值信号量 */
        humidifier_open();

    }
    


}
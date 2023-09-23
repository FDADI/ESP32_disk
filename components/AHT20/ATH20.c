#include "ATH20.h"
#include "ui.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "task_manage.h"
extern SemaphoreHandle_t humidifier_semap;
#define aht20_addr 0x38
float humi;
float temps;
static i2c_config_t aht20_i2c_conf = {
    .mode = I2C_MODE_MASTER,
    .sda_io_num = AHT_20_SDA, // default pin for SDA
    .scl_io_num = AHT_20_SCL, // default pin for SCL
    .sda_pullup_en = GPIO_PULLUP_DISABLE,
    .scl_pullup_en = GPIO_PULLUP_DISABLE,
    .master.clk_speed = 100000};
uint8_t AHT_Read_Status(void)
{
    uint8_t Byte_first;
    i2c_cmd_handle_t cmd_handle = i2c_cmd_link_create();
    i2c_master_start(cmd_handle);
    i2c_master_write_byte(cmd_handle, 0x71, true);

    i2c_master_read(cmd_handle, &Byte_first, 1, I2C_MASTER_NACK);
    i2c_master_stop(cmd_handle);
    i2c_master_cmd_begin(I2C_NUM_1, cmd_handle, 800 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd_handle);
    return Byte_first;
}

uint8_t AHT_Read(float *humi, float *temp)
{
    uint8_t cnt = 5;
    uint8_t Byte_1th = 0;
    uint8_t Byte_2th = 0;
    uint8_t Byte_3th = 0;
    uint8_t Byte_4th = 0;
    uint8_t Byte_5th = 0;
    uint8_t Byte_6th = 0;
    uint32_t RetuData = 0;

    i2c_cmd_handle_t cmd_handle = i2c_cmd_link_create();
    i2c_master_start(cmd_handle);
    i2c_master_write_byte(cmd_handle, 0x70, true);
    i2c_master_write_byte(cmd_handle, 0xAC, true);
    i2c_master_write_byte(cmd_handle, 0x33, true);
    i2c_master_write_byte(cmd_handle, 0x00, true);
    i2c_master_stop(cmd_handle);
    i2c_master_cmd_begin(I2C_NUM_1, cmd_handle, 800 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd_handle);
    vTaskDelay(150 / portTICK_PERIOD_MS);
    while ((AHT_Read_Status() & 0x80) == (0x80 && cnt))
    {
        vTaskDelay(5 / portTICK_PERIOD_MS);
        cnt--;
        AHT_Read_Status();
    }
    if (!cnt)
    {
        return 1;
    }

    i2c_cmd_handle_t cmd_handle1 = i2c_cmd_link_create();
    i2c_master_start(cmd_handle1);
    i2c_master_write_byte(cmd_handle1, 0x71, true);
    Byte_1th = i2c_master_read(cmd_handle1, &Byte_1th, 1, I2C_MASTER_ACK);
    Byte_2th = i2c_master_read(cmd_handle1, &Byte_2th, 1, I2C_MASTER_ACK);
    Byte_3th = i2c_master_read(cmd_handle1, &Byte_3th, 1, I2C_MASTER_ACK);
    Byte_4th = i2c_master_read(cmd_handle1, &Byte_4th, 1, I2C_MASTER_ACK);
    Byte_5th = i2c_master_read(cmd_handle1, &Byte_5th, 1, I2C_MASTER_ACK);
    Byte_6th = i2c_master_read(cmd_handle1, &Byte_6th, 1, I2C_MASTER_NACK);
    i2c_master_stop(cmd_handle1);
    i2c_master_cmd_begin(I2C_NUM_1, cmd_handle1, 800 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd_handle1);

    RetuData = (RetuData | Byte_2th) << 8;
    RetuData = (RetuData | Byte_3th) << 8;
    RetuData = (RetuData | Byte_4th);
    RetuData = RetuData >> 4;
    *humi = (RetuData * 1000 >> 20);
    *humi /= 10;

    RetuData = 0;
    RetuData = (RetuData | Byte_4th) << 8;
    RetuData = (RetuData | Byte_5th) << 8;
    RetuData = (RetuData | Byte_6th);
    RetuData = RetuData & 0xfffff;
    *temp = ((RetuData * 2000 >> 20) - 500);
    *temp /= 10;

    return 0;
}


void i2c_setup()
{

    i2c_param_config(I2C_NUM_1, &aht20_i2c_conf);
    i2c_driver_install(I2C_NUM_1, I2C_MODE_MASTER, 0, 0, 0);
}

void aht20_read_measures(void *ignore)
{
    while (1)
    {
        AHT_Read(&humi, &temps);
        printf("humi :%0.2f temp :%0.2f\n", humi, temps);
        lv_label_set_text_fmt(ui_temp,"%i",(int)temps);
        lv_label_set_text_fmt(ui_humidity,"%i",(int)humi);
        lv_slider_set_value(ui_tempBar,(int)temps,LV_ANIM_OFF);
        lv_slider_set_value(ui_humidityBar,(int)humi,LV_ANIM_OFF);
        if(humi<60)
        {
            xSemaphoreGive(humidifier_semap);//释放
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
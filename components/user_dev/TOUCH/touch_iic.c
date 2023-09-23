/*
 * @Author: lmh 885288596@qq.com
 * @Date: 2023-05-10 18:12:33
 * @LastEditors: lmh 885288596@qq.com
 * @LastEditTime: 2023-05-13 19:54:36
 * @FilePath: /st7789/components/user_dev/TOUCH/touch_iic.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "touch_iic.h"
#include "../../lvgl/lvgl_driver/lv_port_indev.h"
#include "esp_log.h"

#define I2C_HOST 0
#define CST816T_SENSOR_ADDR 0x15
#define I2C_MASTER_SCL_IO 12
#define I2C_MASTER_SDA_IO 11
#define I2C_MASTER_FREQ_HZ 600000
#define I2C_MASTER_TIMEOUT_MS 10

#define FingerNum 0x02
#define XposH 0x03



uint8_t cst816t_read_len(uint16_t reg_addr, uint8_t *data, uint8_t len)
{
    uint8_t res = 0;
    res = i2c_master_write_read_device(I2C_HOST, CST816T_SENSOR_ADDR, &reg_addr, 1, data, len, I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);
    return res;
}

static esp_err_t testtouch(uint8_t *touch_points_num)
{
    uint8_t res = 0;
    res = cst816t_read_len(FingerNum, touch_points_num, 1);
    return res;
}

esp_err_t get_coordinates(uint16_t *x, uint16_t *y)
{
    uint8_t data[4];
    int a, b;
    cst816t_read_len(XposH, data, 4);
    a = ((data[0] & 0x0f) << 8) | data[1];
    b = ((data[2] & 0x0f) << 8) | data[3];
    // if ((a<=240) && (b<=280))
    // {
    //     *x = a;
    //     *y = b;
    // }
    if ((a <= 240) && (b <= 280))
    {
        *x = 279 - b;
        *y = a;
    }
    return ESP_OK;
}

static void lvgl_touch_cb(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    uint16_t touchpad_x = 0;
    uint16_t touchpad_y = 0;
    uint8_t touch_points_num = 0;
    testtouch(&touch_points_num);

    if (touch_points_num == 1)
    {
        get_coordinates(&touchpad_x, &touchpad_y);
        if ((touchpad_x != 0) && (touchpad_y != 0))
        {
            data->point.x = touchpad_x;
            data->point.y = touchpad_y;
        }
        data->state = LV_INDEV_STATE_PRESSED;
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

extern lv_disp_t *disp; /*Descriptor of a display driver*/
void touch_iic_init()
{

    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };

    ESP_ERROR_CHECK(i2c_param_config((i2c_port_t)I2C_HOST, &conf));
    ESP_ERROR_CHECK(i2c_driver_install((i2c_port_t)I2C_HOST, conf.mode, 0, 0, 0));

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.disp = disp;
    indev_drv.read_cb = lvgl_touch_cb;
    // indev_drv.user_data = tp;

    lv_indev_drv_register(&indev_drv);

    ESP_LOGI("esp_iic", "successful");
}

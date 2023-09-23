/*
 * @Author: lmh 885288596@qq.com
 * @Date: 2023-05-09 22:09:16
 * @LastEditors: lmh 885288596@qq.com
 * @LastEditTime: 2023-05-10 12:49:32
 * @FilePath: /st7789/components/user_dev/SPI/User_dev_spi.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "User_dev_spi.h"
#include "driver/spi_master.h"
#include "esp_log.h"
#include <stdio.h>

static spi_device_handle_t spi;    //创建spi

extern void spi_disp_flush_ready(void);


IRAM_ATTR  void spi_ready(spi_transaction_t *trans)
{
    uint32_t spi_cnt = (uint32_t)trans->user;

    if (spi_cnt == 4)
    {
       spi_disp_flush_ready();
    }
}

static const spi_bus_config_t buscfg={   //spi定义
    .miso_io_num=LCD_MISO,
    .mosi_io_num=LCD_MOSI,
    .sclk_io_num=LCD_SCK,
    .quadwp_io_num=-1,
    .quadhd_io_num=-1,
    .max_transfer_sz=4094
};

static const spi_device_interface_config_t devcfg = {
    .clock_speed_hz = SPI_MASTER_FREQ_40M, // ST7789 最高只能一般只能到62.5Mhz，所以这边不建议用80Mhz
    .mode = 0,
    .spics_io_num = LCD_CS,
    .queue_size = 50, // 50个SPI消息队列
    .cs_ena_pretrans = 1,
   .post_cb = spi_ready,//注册一个SPI调用完成的回调
};

void vspi_init(void)
{
    spi_bus_initialize(SPI2_HOST,&buscfg,SPI_DMA_CH_AUTO);
    spi_bus_add_device(SPI2_HOST, &devcfg, &spi);
}

/*------------------------------------LCD传输8位指令---------------------------------------*/
void lcd_cmd(const uint8_t cmd)
{
    esp_err_t ret;
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));       //Zero out the transaction
    t.length=8;                     //Command is 8 bits
    t.tx_buffer=&cmd;               //The data is the cmd itself
    t.user=(void*)0;                //D/C needs to be set to 0
    ret=spi_device_polling_transmit(spi, &t);  //Transmit!
    assert(ret==ESP_OK);            //Should have had no issues.
}
/*------------------------------------LCD传输16位指令---------------------------------------*/

void VSPI_data16(const uint16_t dat)
{
    esp_err_t ret;
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));       //Zero out the transaction
    t.length=16;                     //Command is 8 bits
    t.tx_buffer=&dat;               //The data is the cmd itself
    t.user=(void*)0;                //D/C needs to be set to 0
    ret=spi_device_polling_transmit(spi, &t);  //Transmit!
    assert(ret==ESP_OK);            //Should have had no issues.
}

IRAM_ATTR void VSPI_data_x(uint16_t *dat, uint32_t len)
{
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));                             // Zero out the transaction
    t.length = len;                                       // Command is 8 bits
    t.tx_buffer = dat;                                    // The data is the cmd itself
    t.user = (void *)0;                                   // D/C needs to be set to 0
    esp_err_t ret = spi_device_polling_transmit(spi, &t); // Transmit!
    assert(ret == ESP_OK);                                // Should have had no issues.
}

IRAM_ATTR void VSPI_data_queue(uint16_t *dat, uint32_t len, uint32_t user_fg)
{
    static spi_transaction_t t[80];
    static uint32_t i = 0;

    memset(&t[i], 0, sizeof(spi_transaction_t)); // Zero out the transaction
    t[i].length = len;                           // Command is 8 bits
    t[i].tx_buffer = dat;                        // The data is the cmd itself
    t[i].user = (void *)user_fg;                 // D/C needs to be set to 0
    esp_err_t ret = spi_device_queue_trans(spi, &t[i], portMAX_DELAY);
    assert(ret == ESP_OK); // Should have had no issues.
    i++;
    if (i == 80)
    {
        i = 0;
    }
}

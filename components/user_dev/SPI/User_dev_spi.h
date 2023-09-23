/*
 * @Author: lmh 885288596@qq.com
 * @Date: 2023-05-09 22:09:16
 * @LastEditors: lmh 885288596@qq.com
 * @LastEditTime: 2023-05-09 22:27:18
 * @FilePath: /st7789/components/user_dev/SPI/User_dev_spi.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _USER_DEV_SPI_H_
#define _USER_DEV_SPI_H_
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <string.h>
#define LCD_HOST    HSPI_HOST
#define DMA_CHAN    2

#define LCD_SCK     18 
#define LCD_MOSI    17
#define LCD_MISO    -1
#define LCD_CS      14
#define LCD_RES     16
#define LCD_DC      15
#define LCD_BLK     13

void lcd_cmd(const uint8_t cmd);
void VSPI_data16(const uint16_t dat);
void vspi_init(void);
void VSPI_data_x(uint16_t *dat,uint32_t len);
IRAM_ATTR void VSPI_data_queue(uint16_t *dat,uint32_t len,uint32_t user_fg);

#endif

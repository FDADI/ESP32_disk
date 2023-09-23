#include "User_dev_spi.h"
#include "lcd.h"
#include "driver/gpio.h"
#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "unistd.h"
#include "memory.h"
#define DELAY(X) vTaskDelay(((X) / portTICK_PERIOD_MS))

#define TAG "main"
/******************************************************************************
	  函数说明：LCD写入数据
	  入口数据：dat 写入的数据
	  返回值：  无
******************************************************************************/
void LCD_WR_DATA8(uint8_t dat)
{
	gpio_set_level(LCD_DC, 1);
	lcd_cmd(dat);
}

/******************************************************************************
	  函数说明：LCD写入数据
	  入口数据：dat 写入的数据
	  返回值：  无
******************************************************************************/
void LCD_WR_DATA(uint16_t dat)
{
	gpio_set_level(LCD_DC, 1);
	LCD_WR_DATA8(dat >> 8);
	LCD_WR_DATA8(dat);
}

/******************************************************************************
	  函数说明：LCD写入命令
	  入口数据：dat 写入的命令
	  返回值：  无
******************************************************************************/
void LCD_WR_REG(uint8_t dat)
{
	gpio_set_level(LCD_DC, 0);
	lcd_cmd(dat);
}

/*x1=0 y1=0 x2=4 y2=4*/

/******************************************************************************
	  函数说明：设置起始和结束地址
	  入口数据：x1,x2 设置列的起始和结束地址
				y1,y2 设置行的起始和结束地址
	  返回值：  无
******************************************************************************/
void LCD_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	LCD_WR_REG(0x2a); // 列地址设置
	LCD_WR_DATA(x1);
	LCD_WR_DATA(x2);
	LCD_WR_REG(0x2b); // 行地址设置

	LCD_WR_DATA(y1 );
	LCD_WR_DATA(y2);
	LCD_WR_REG(0x2c); // 储存器写
}

/******************************************************************************
	  函数说明：LCD清屏函数
	  入口数据：无
	  返回值：  无
******************************************************************************/
void LCD_Clear(uint16_t Color)
{
	LCD_Address_Set(0, 0, LCD_W - 1, LCD_H - 1);
	gpio_set_level(LCD_DC, 1);
	// LCD_DC_SET();//写数据
	uint16_t color_temp[240 * 2];
	memset(color_temp, Color, sizeof(color_temp));
	for (uint16_t i = 0; i < LCD_W / 2; i++)
	{
		VSPI_data_x(color_temp, 240 * 16 * 2);
	}
}

/*16bit rgb 565*/
IRAM_ATTR void LCD_Fill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t *color)
{
	uint32_t siofs = 240 * 2 * 10; // 同时刷多少行240 *2（8bit）*10行
	uint32_t siof = 240 * 1 * 10;  // 因为数组是16位的，但字节指向的地址
	uint32_t size = (x2 + 1 - x1) * (y2 + 1 - y1) * 2;
	LCD_Address_Set(x1, y1, x2, y2);
	gpio_set_level(LCD_DC, 1);
	// LCD_DC_SET();					   //写数据
	uint32_t send_cnt = size / siofs;  // 需要整行刷新多少行
	uint32_t send_cnt2 = size % siofs; // 整行刷不完还剩多少字节
	if (size == 0)
	{
		ESP_LOGE(TAG, "size为0,跳出了");
		return;
	}
	for (int i = 0; i < send_cnt; i++)
	{
		if ((i + 1) == send_cnt && send_cnt2 == 0)
		{
			VSPI_data_queue(&color[i * siof], siof * 16, 4);
		}
		else
		{
			VSPI_data_queue(&color[i * siof], siof * 16, 3);
		}
	}
	if (send_cnt2 != 0)
	{
		VSPI_data_queue(&color[send_cnt * siof], send_cnt2 * 8, 4);
	}
}

void lcd_init()
{
	gpio_pad_select_gpio(LCD_RES);
	gpio_pad_select_gpio(LCD_DC);
	gpio_pad_select_gpio(LCD_BLK);

	gpio_set_direction(LCD_RES, GPIO_MODE_OUTPUT);
	gpio_set_direction(LCD_DC, GPIO_MODE_OUTPUT);
	gpio_set_direction(LCD_BLK, GPIO_MODE_OUTPUT);
	gpio_set_level(LCD_RES, 1);
	gpio_set_level(LCD_DC, 0);
	gpio_set_level(LCD_BLK, 0);

	vspi_init();

	gpio_set_level(LCD_RES, 0);
	DELAY(100);
	gpio_set_level(LCD_RES, 1);
	DELAY(100);

	gpio_set_level(LCD_BLK, 1);
	DELAY(100);
	// ************* Start Initial Sequence **********//
	LCD_WR_REG(0x11); // Sleep out
	DELAY(120);		  // Delay 120ms

	LCD_WR_REG(0x36);
	LCD_WR_DATA8(0xa0);
	//LCD_WR_DATA8(0x00);
	LCD_WR_REG(0x3A); 
	LCD_WR_DATA8(0x05);

	LCD_WR_REG(0xB2);
	LCD_WR_DATA8(0x0B);
	LCD_WR_DATA8(0x0B);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x33);
	LCD_WR_DATA8(0x33); 

	LCD_WR_REG(0xB7); 
	LCD_WR_DATA8(0x11);  

	LCD_WR_REG(0xBB);
	LCD_WR_DATA8(0x2F);

	LCD_WR_REG(0xC0);
	LCD_WR_DATA8(0x2C);

	LCD_WR_REG(0xC2);
	LCD_WR_DATA8(0x01);

	LCD_WR_REG(0xC3);
	LCD_WR_DATA8(0x0D); 

	LCD_WR_REG(0xC4);
	LCD_WR_DATA8(0x20);  

	LCD_WR_REG(0xC6); 
	LCD_WR_DATA8(0x13);    

	LCD_WR_REG(0xD0); 
	LCD_WR_DATA8(0xA4);
	LCD_WR_DATA8(0xA1);

	LCD_WR_REG(0xD6); 
	LCD_WR_DATA8(0xA1);

	LCD_WR_REG(0xE0);
	LCD_WR_DATA8(0xF0);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x09);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x25);
	LCD_WR_DATA8(0x33);
	LCD_WR_DATA8(0x3C);
	LCD_WR_DATA8(0x34);
	LCD_WR_DATA8(0x10);
	LCD_WR_DATA8(0x10);
	LCD_WR_DATA8(0x29);
	LCD_WR_DATA8(0x32);

	LCD_WR_REG(0xE1);
	LCD_WR_DATA8(0xF0);
	LCD_WR_DATA8(0x05);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x0A);
	LCD_WR_DATA8(0x09);
	LCD_WR_DATA8(0x05);
	LCD_WR_DATA8(0x25);
	LCD_WR_DATA8(0x32);
	LCD_WR_DATA8(0x3B);
	LCD_WR_DATA8(0x3B);
	LCD_WR_DATA8(0x17);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x2E);
	LCD_WR_DATA8(0x37);

	LCD_WR_REG(0xE4);
	LCD_WR_DATA8(0x25);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);



	LCD_WR_REG(0x21);

	LCD_WR_REG(0x29);

	LCD_WR_REG(0x2A);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0xEF);

	LCD_WR_REG(0x2B);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x14);
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0x2B);	

	LCD_WR_REG(0x2C);
}

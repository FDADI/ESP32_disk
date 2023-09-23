/*
 * @Author: lmh 885288596@qq.com
 * @Date: 2023-05-10 18:12:19
 * @LastEditors: lmh 885288596@qq.com
 * @LastEditTime: 2023-05-10 18:14:26
 * @FilePath: /st7789/components/user_dev/TOUCH/touch_iic.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef  __TOUCH_IIC_H
#define  __TOUCH_IIC_H

#include "driver/i2c.h"

void  touch_iic_init(void);
uint8_t cst816t_read_len(uint16_t reg_addr,uint8_t * data,uint8_t len);

#endif


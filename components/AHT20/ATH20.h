#ifndef AHT_20_H
#define AHT_20_H

#include "driver/i2c.h"
#include "driver/gpio.h"
#include "esp_types.h"

#define AHT_20_SDA 4
#define AHT_20_SCL 5

void aht20_read_measures(void *ignore);
void i2c_setup();
uint8_t AHT_Read(float *humi, float *temp);
uint8_t AHT_Read_Status(void);

#endif

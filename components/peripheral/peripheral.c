#include "peripheral.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "hal/lcd_types.h"
void lamp_gpio_init()
{
    gpio_pad_select_gpio(lamp_pin);
    gpio_set_direction(lamp_pin, GPIO_MODE_OUTPUT);
}
void lamp_on()
{
	gpio_set_level(lamp_pin,0);
}
void lamp_off()
{
	gpio_set_level(lamp_pin,1);
}
void buzzer_gpio_init()
{
    gpio_pad_select_gpio(buzzer_pin);
    gpio_set_direction(buzzer_pin, GPIO_MODE_OUTPUT);
}

void buzzer_on()
{
	gpio_set_level(buzzer_pin,0);
}
void buzzer_off()
{
	gpio_set_level(buzzer_pin,1);
}

void backlight_gpio_init()
{
    ledc_timer_config_t backlight_timer = { 
	.duty_resolution = LEDC_TIMER_8_BIT,	// PWM占空比分辨率8191
	.freq_hz = 3000,						// PWM信号频率
	.speed_mode = LEDC_HIGH_SPEED_MODE,				// 定时器模式
	.timer_num = LEDC_TIMER_0				// 定时器序号;使用哪个定时器0-3;
    };
    ledc_timer_config(&backlight_timer);

    ledc_channel_config_t backlight_channel = { 
	.channel =	LEDC_CHANNEL_7,	// LED控制器通道号, 
	.duty = 0,               //占空比
	.gpio_num = backlight_pin,				// LED控制器通道对应GPIO, 
	.speed_mode = LEDC_HIGH_SPEED_MODE, // 模式, 
	.timer_sel = LEDC_TIMER_0,   		// 使用哪个定时器0-3
    };
    ledc_channel_config(&backlight_channel);
}
void backlight_duty_set(char duty)
{
    int transition = duty*2.3;//背光最亮的占空比在230
    ledc_set_duty(LEDC_HIGH_SPEED_MODE,LEDC_CHANNEL_6,transition);//改变PWM占空比
	ledc_update_duty(LEDC_HIGH_SPEED_MODE,LEDC_CHANNEL_6);

}
void humidifier_gpio_init()
{
    ledc_timer_config_t humidifier_timer = { 
	.duty_resolution = LEDC_TIMER_3_BIT,	// PWM占空比分辨率8191
	.freq_hz = 108000,						// PWM信号频率
	.speed_mode = LEDC_HIGH_SPEED_MODE,				// 定时器模式
	.timer_num = LEDC_TIMER_1				// 定时器序号;使用哪个定时器0-3;
    };
    ledc_timer_config(&humidifier_timer);

    ledc_channel_config_t humidifier_channel = { 
	.channel =	LEDC_CHANNEL_6,	// 控制器通道号, 
	.duty = 0,               //占空比
	.gpio_num = humidifier_pin,				//控制器通道对应GPIO, 
	.speed_mode = LEDC_HIGH_SPEED_MODE, // 模式, 
	.timer_sel = LEDC_TIMER_1,   		// 使用哪个定时器0-3
    };
    ledc_channel_config(&humidifier_channel);
}
void humidifier_open()
{
    ledc_set_duty(LEDC_HIGH_SPEED_MODE,LEDC_CHANNEL_6,3);//改变PWM占空比
	ledc_update_duty(LEDC_HIGH_SPEED_MODE,LEDC_CHANNEL_6);
}
void humidifier_close()
{
    ledc_set_duty(LEDC_HIGH_SPEED_MODE,LEDC_CHANNEL_6,0);//改变PWM占空比
	ledc_update_duty(LEDC_HIGH_SPEED_MODE,LEDC_CHANNEL_6);
}
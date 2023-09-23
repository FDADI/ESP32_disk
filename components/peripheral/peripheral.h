#ifndef __PERIPHERAL__H__
#define __PERIPHERAL__H__

#define lamp_pin 3
#define buzzer_pin 13 
#define backlight_pin 19 
#define humidifier_pin 8

void lamp_gpio_init();
void buzzer_gpio_init();
void backlight_gpio_init();
void humidifier_gpio_init();
void backlight_duty_set(char duty);
void humidifier_open();
void humidifier_close();
void lamp_on();
void lamp_off();
void buzzer_on();
void buzzer_off();
#endif  //!__PERIPHERAL__H__
#ifndef _LED_H
#define _LED_H
#include "type.h"

#define MAX_NUMBER_OF_LEDS 8

void set_led_intensity(uint16_t intensity);
void LED_refresh_timer_init(void);
void turn_off_all_leds(void);
void turn_on_all_leds(void);

#endif // _LED_H

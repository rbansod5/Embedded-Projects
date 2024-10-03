#ifndef _74HC595_
#define _74HC595_

#include "type.h"
#include "stdint.h"
#define STCP (1<<16)

#define LATCH_DIR() (LPC_GPIO0->FIODIR = STCP)

void test_leds(void);
void parallel_data_output_high_74hc595(void);
void parallel_data_output_low_74hc595(void);
void turn_on_led(uint8_t led_mask); 

#endif // _74HC595_


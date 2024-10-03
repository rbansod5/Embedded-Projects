#ifndef _LED_H
#define _LED_H

/* Macro Definitions*/ 
#define LED1 (1 << 17)
#define LED2 (1 << 18)
#define LED3 (1 << 19)
#define LED4 (1 << 20)
#define LED5 (1 << 21)
#define LED6 (1 << 22)
#define LED7 (1 << 23)
#define LED8 (1 << 24)
#define LED_ALL  LED1| LED2 | LED3 | LED4 | LED5 | LED6 | LED7 | LED8
void LED_Init(void);

#endif

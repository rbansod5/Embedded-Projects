								/*LCD, RS->P0.10,  EN->P0.11
       DATA->P0.15 TO P0.22*/
#include<lpc17xx.h>
#include "lcd.h"

int main()
{
unsigned int val;
lcd_config();

//LPC_SC->PCLKSEL0|=(3<<24);
LPC_SC->PCONP|=(1<<12);
LPC_PINCON->PINSEL1|=(1<<18);
//LPC_PINCON->PINSEL1&=~(1<<19);

LPC_ADC->ADCR=(1<<2)|(4<<8)|(1<<16)|(1<<21)|(1<<26);

//lcd_str("GOOD");
//delay(500);

	while(1)
	{
	while(!((LPC_ADC->ADDR2)&(1U<<31)));
	val=(LPC_ADC->ADDR2&(0XFFF<<4));
	val=(val>>4);
	val=val/13;
	lcd_num(val);
	delay(500);
	lcd_cmd(0x01);
	}

}


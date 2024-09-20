#include <reg52.h>

#include "delay.h"

#define LEDS P0

void binary_print(unsigned char);

main()
{
	unsigned int num;

	for(num=0;num<=255;num++)
	{
		binary_print(num);
		//LEDS = num;	//8 leds are active high leds
		//LEDS = ~num;	//8 leds are active low leds
		//LEDS = num^0x0F;	//8 leds (4 - active high leds + 4 - active low leds)
		delay_ms(100);
		//if(num==255)
			//break;
	}
	while(1);
}

void binary_print(unsigned char ch)
{
	LEDS = ch;
}

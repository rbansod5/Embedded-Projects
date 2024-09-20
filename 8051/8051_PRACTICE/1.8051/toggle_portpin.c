#include <reg52.h>

#include "delay.h"

//sfr P1 = 0x90;

sbit portpin = P1^0;

main()
{
	while(1)
	{
		portpin = 1;
		delay_ms(1000);
		portpin = 0;
		delay_ms(1000);	
	}
}

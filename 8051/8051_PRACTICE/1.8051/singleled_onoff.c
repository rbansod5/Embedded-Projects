#include <reg52.h>

#include "delay.h"

sbit LED = P1^0;

main()
{
	while(1)
	{
		LED = 1;
		delay_ms(1000);
		LED = 0;
		delay_ms(1000);	
	}
}

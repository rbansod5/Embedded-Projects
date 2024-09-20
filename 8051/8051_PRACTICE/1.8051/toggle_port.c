#include <reg52.h>

#include "delay.h"

#define port0 P0
#define port1 P1
#define port2 P2
#define port3 P3

main()
{
	while(1)
	{
		port0 = 0xff;
		port1 = 0xff;
		port2 = 0xff;
		port3 = 0xff;
		delay_ms(1000);
		port0 = 0x00;
		port1 = 0x00;
		port2 = 0x00;
		port3 = 0x00;
		delay_ms(1000);	
	}
}

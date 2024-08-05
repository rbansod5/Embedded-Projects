#include <reg52.h>

sbit SW1 = P2^0;//active low switch
sbit LED = P2^7;//active low led

main()
{
	while(1)
	{
		LED = SW1;	
	}

}

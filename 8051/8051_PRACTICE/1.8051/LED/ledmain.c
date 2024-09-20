//Write an ECP for blinking the LED connected to P1.0
#include<reg51.h>
#include"delay.h"
sbit led=P1^0;
char x;
main()
{
	for(;;)
	{
		led=~led;
		delay_ms(1000);			
	}
}

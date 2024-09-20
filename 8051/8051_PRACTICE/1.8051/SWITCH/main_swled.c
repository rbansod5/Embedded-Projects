/*Write an ECP for controlling the status of a active LOW LED
with Active LOW switch */
#include<reg51.h>
sbit led=P1^0;
sbit sw=P1^1;
main()
{
	while(1)
	{
	/*	if(sw==0)//switch is active
			led=0;//active low led
		else
			led=1;	*/
		led=sw;
	}
}


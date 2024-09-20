
/*
sfr port1=0x90;
//#include<reg51.h>


main()
{
 int ch;
for(ch=0;ch<=255;ch++)
	port1=ch;
}
*///METHOD2:

#include<reg51.h>
//sfr P1=0x90;
#define leds_8 P1
void delay_ms(unsigned int);

main()
{
	int ch;
	for(ch=0;ch<=255;ch++)
	{
		leds_8=ch;//256=0x0100
		delay_ms(1000);
	}
}

void delay_ms(unsigned int dly)
{
	unsigned int i;
	for(dly;dly>0;dly--)
		for(i=12;i>0;i--);//In 8051 for integer variable iteration 8 MC are taking=121x8=968
}//ret;2mc

//in 8051 1ms=1000mc @12MHz
//f=1/t or t=1/f

/*Time Period for one clock cycle time period=1/12MHz
In 8051 1MC=12 Clock Cycles

1MCT=12x(1/12MHz)
1MCT=1x10^-6
	=1Usec


1Msec=1x10^-3=1x(10^-3x10^-3)/10^-3
=1x10^-6x10^3
1Msec=1000Usec

1Msec=1000x1USec
=1000x1MC
1MSec=1000MC

int i=121;//2bytes
mov r0,#lb;1m.c
mov r1,#hb;1m.c
lb has to check;2m.c
hb has to check;2m.c
decremet=lb subtraction=2m.c
		 hb subtraction = 2m.c
*/







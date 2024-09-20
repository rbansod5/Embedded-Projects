

/* Display binary equivalent of a number on 8.leds  */


#include<reg51.h>
#define leds_8 P1

void delay_ms(unsigned int dly)//mov r6,#hb, mov r7,#lb
{
	unsigned char i;
	for(;dly>0;dly--)//16bit condition ata time it's not possible to check 16 bit value
	// so divided into 2, 8 bits, So, 2 times have to check.2 times branch instruction has to take
	//Each time 2MC=Total 2x2=4MC
	// subtraction/dec also not possible with 16 bit
	//so, divided into 2,8-bits
	//2 times subtractions. Each time 2m.c=2x2=4MC
	{
		for(i=255;i>0;i--);
		for(i=232;i>0;i--);
	}
}

main()
{
	unsigned char i;
	for(i=0;i<=255;i++)
	{
		leds_8=~i;//0x00,0x01,0x02,0x03------0xff
		delay_ms(1000);
	}
}
/*0	0	0	0	0	0	0	1		AL
on	on	on	on	on	on	on	off*/


//ASS-1:  DISPLAY ALTERNATE LEDS
//ASS-2:  DISPLAY ONE BY ONE LED FROM LEFT TO RIGHT

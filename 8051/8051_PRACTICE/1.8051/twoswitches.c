
//  l1l2  l3  l4  l5  l6  l7  l8
//p0.7 6  5   4   3   2   1   0
/* 8   4  2	  1	  8	  4	  2	  1
   1   0  1	  0	  1	  0	  1	  0

		A			A



   0	1	0	1	0	1	0	1
		
		5			5
*/

#include<reg51.h>

/* AL SWITCHES*/
//0- PRESSED
sbit sw1=P1^0;
sbit sw2=P1^1;

/*ACTIVE HIGH LEDS*/
#define leds_8 P0	//1- ON 0- OFF

void delay_ms(unsigned int);


main()
{
			
	while(1)
	{
		if(sw1==0)
		{
			leds_8=0xff;
			delay_ms(500);
			leds_8=0x00;
			delay_ms(500);
		}
		else if(sw2==0)
		{
			leds_8=0xaa;
			delay_ms(500);
			leds_8=0x55;
			delay_ms(500);
		}
	}	
}

void delay_ms(unsigned int dly)//mov r6,#hb, mov r7,#lb
{
	unsigned char i;
	for(;dly>0;dly--)//16bit condition at a time it's not possible to check 16 bit value
	// so divided into 2, 8 bits, So, 2 times have to check.2 times branch instruction has to take
	//Each time 2MC=Total 2x2=4MC
	// subtraction/dec also not possible with 16 bit
	//so, divided into 2,8-bits
	//2 times subtractions. Each time 2m.c=2x2=4MC
	{
		for(i=255;i>0;i--);//MOV R0,#255 , DJNZ R0,$
		for(i=232;i>0;i--);//MOV R0,#232 , DJNZ R0,4
	}
}//RET

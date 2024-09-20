


/* Flash eight Active Low LEDs upto 10 times @500ms */

#include<reg51.h>

#define seg_cat P2	

sbit seg1_anode=P3^0;
sbit seg2_anode=P3^1;


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


//Display 0-99 on 2, 7-segments

unsigned char seg_lut[]={0xC0,0xF9,0xA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
main()
{
	unsigned char i;
	unsigned int dly;
	for(i=0;i<=99;i++)
	{
		for(dly=100;dly>0;dly--)
		{
			seg_cat=seg_lut[i/10];//1st digit
			seg1_anode=1;				  // Pass logic 1 on 1st segment anode pin
			delay_ms(5);
			seg1_anode=0;				  // Pass logic 0 on 1st segment anode pin
	
			seg_cat=seg_lut[i%10];//2nd digit
			seg2_anode=1;				  // Pass logic 1 on 2nd segment anode pin
			delay_ms(5);
			seg2_anode=0;				  // Pass logic 0 on 2nd segment anode pin
		}
	
	}
}
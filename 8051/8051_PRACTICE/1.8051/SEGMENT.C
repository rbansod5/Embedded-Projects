


/* Flash eight Active Low LEDs upto 10 times @500ms */

#include<reg51.h>

#define seg_7 P1	// leds_8 equ P1

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


unsigned char seg_lut[]={0xC0,0xF9,0xA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
main()
{
	unsigned char i;
	for(i=0;i<10;i++)
	{
		seg_7=seg_lut[i];//mov leds_8,#0x00//mov P1,#0x00//cpu is writing 0x00 on P1
		delay_ms(500);	
	}
}
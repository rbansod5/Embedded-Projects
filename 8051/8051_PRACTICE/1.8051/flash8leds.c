/* Flash eight Active Low LEDs upto 10 times @500ms */

#include<reg51.h>
#include"delay.h"
//#define leds_8 P2	// leds_8 equ P1
sbit led1=P1^0;
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

main()
{

	unsigned char i;
 //i;
	while(1)
	{
	delay_ms(1);//ACALL
	for(i=0;i<10;i++)
	{
		//leds_8=0xff;//mov leds_8,#0x00//mov P1,#0x00//cpu is writing 0x00 on P1
			led1=0x01;
		delay_ms(1000);
		led1=0x00;
	//	leds_8=0x00;
		delay_ms(1000);
	}
}	 }

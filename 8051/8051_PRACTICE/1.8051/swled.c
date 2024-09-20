



/* Flash a Active Low LED upto 10 times */



#include<reg51.h>
//sfr p1=0x90;

sbit led=P1^0;	//led equ p1.0
sbit sw=P1^7;

#define PRESSED 0	//AL SWITCH
#define ON 0		//AL LED
#define OFF 1		//AL LED
/*void delay_ms(unsigned int dly)//mov r6,#hb, mov r7,#lb
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
}*/

main()
{
	while(1)//infinite loop
	{
		if(sw==PRESSED)
			led=ON;			//clr led
		else
			led=OFF;			//setb led
	}					
}
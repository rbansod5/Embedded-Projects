#include<reg51.h>
sbit led1=P1^0;

void EINT0(void) interrupt 0
{
	led1=~led1;
}

main()
{
	IE=0x81;//EA=EX0=1
	IT0=1; //Selects falling edge triggering
   	while(1);
}






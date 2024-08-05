 //check7seg.c
#include"LPC21XX.h"
void delay()
{
	unsigned int i,j;
	for(i<0;i<2000;i++)
		for(j<0;j<2000;j++);
}
int main()
{
	IODIR0=0XFFFFFFFF; 
	while(1)
	{
			IOSET0=0XFFFFFFFF;
			IOCLR0=0XFFFFFFFF;
			delay();
			IOSET0=0XFFFFFFFF;
			IOCLR0=0XFFFFFFFF;
			delay();
	}
}
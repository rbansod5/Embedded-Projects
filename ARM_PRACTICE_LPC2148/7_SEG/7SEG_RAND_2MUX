#include<lpc21xx.h>
#include"types.h"
#include"defines.h"
#include"delay.h"

#define SEG7 0
#define SEL1 8
#define SEL2 9
#define SW 10
int main()
{       
u16 a[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
u8 i;
//initialization


        WRITEBYTE(IODIR0,SEG7,0xff);
        SETBIT(IODIR0,SEL1);

while(1)
{

  
        for(i=0;i<10;i++)
        {       
        a[i]=rand()%9;
	if(READBIT(IOPIN0,SW)==0)
	{
	while(READBIT(IOPIN0,SW)==0);
        WRITEBYTE(IOPIN0,SEG7,a[i]);
        WRITEBIT(IOSET0,SEL1,1);
        delay_ms(1000);
        WRITEBIT(IOCLR0,SEL1,1);
	}
	//delay_s(1);
	}
}
}

#include<lpc21xx.h>
#include"types.h"
#include"defines.h"
#include"delay.h"

#define S EG7 0
#define SEL1 8
#define SEL2 9
  
int main()
{       
u16 a[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
u8 i,m;
//initialization


        WRITEBYTE(IO0
		. DIR0,SEG7,0xff);
        SETBIT(IODIR0,SEL1);
 		SETBIT(IODIR0,SEL2);

while(1)
{

  
        for(i=0;i<10;i++)
        {       
        a[i]=rand()%10+48;
	 
	for(m=0;m<=100;m++)
				{	
					WRITEBYTE(IOPIN0,SEG7,(a[i/10]));
					WRITEBIT(IOSET0,SEL1,1);
					 delay_ms(10);					 
 					WRITEBIT(IOCLR0,SEL1,1);
					
					WRITEBYTE(IOPIN0,SEG7,(a[i%10]));
					WRITEBIT(IOSET0,SEL2,1);
					delay_ms(10);
					WRITEBIT(IOCLR0,SEL2,1);
				}
			}
	delay_s(1);
	}
}


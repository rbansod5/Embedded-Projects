#include<lpc21xx.h>
#include"delay.h"
#include"types.h"
#include"defines.h"
#include<math.h>
#define SEG7 0
#define SEL1 8
#define SEL2 9
u8 a[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
u8 i;
int Isprime(u32 num)
{
u8 i;
	for(i=2;i<=sqrt(num);i++)
		if(num%i==0)
		{
		return 0; 
		}
		return 1;
	
}

int main()
{

//initialize
u8 n,m;
WRITEBYTE(IODIR0,SEG7,0xff);
SETBIT(IODIR0,SEL1);
SETBIT(IODIR0,SEL2);
while(1)
{
		for(n=2;n<=99;n++)
		{
			if(Isprime(n)==1)
			{
				for(m=0;m<=100;m++)
				{	
					WRITEBYTE(IOPIN0,SEG7,(a[n/10]));
					WRITEBIT(IOSET0,SEL1,1);
					 delay_ms(1);					 
 					WRITEBIT(IOCLR0,SEL1,1);
					
					WRITEBYTE(IOPIN0,SEG7,(a[n%10]));
					WRITEBIT(IOSET0,SEL2,1);
					delay_ms(1);
					WRITEBIT(IOCLR0,SEL2,1);
				}
			}
			delay_ms(1000);
		}
}
}

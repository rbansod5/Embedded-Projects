/*00-99*/

#include<LPC21XX.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
#define LED 0
#define DSEL1 8
#define DSEL2 9
#define dp 0x7f
u32 a[10]={0xcf,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int main()
{
u8 i;
WRITEBYTE(IODIR0,LED,0xff);
SETBIT(IODIR0,DSEL1);
SETBIT(IODIR0,DSEL2);
while(1)
{
for(i=0;i<=99;i++)
{

WRITEBYTE(IOPIN0,LED,0xff);
{
SETBIT(IOPIN0,DSEL1);
WRITEBYTE(IOPIN0,LED,a[i/10]);
delay_s(1);
for(i=0;i<=9;i++)
{
SETBIT(IOPIN0,DSEL2);
WRITEBYTE(IOPIN0,LED,a[i%10]);
delay_s(1);
CLRBIT(IOPIN0,DSEL2);
}
}
}	}
}
/*test2_7seg.c*/

#include<lpc21xx.h>
#include"delay.h"
#include"types.h"
#include"defines.h"
#define DSEL1 8
#define DSEL2 9
#define LED7SEG 0
#define dp 0x7f
int main()
{
u8 i;
u16 j;
u8 a[14]={0xcf,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xc8,0x80,0x90};
WRITEBYTE(IODIR0,LED7SEG,0xff);
SETBIT(IODIR0,DSEL1);
SETBIT(IODIR0,DSEL2);
while(1)
{
for(i=0;i<=10;i++)
{
SETBIT(IOPIN0,DSEL1);
WRITEBYTE(IOPIN0,LED7SEG,a[i/10]&dp);
CLRBIT(IOPIN0,DSEL1);
delay_s(1);
}
for(j=0;j<=10;j++)
{
SETBIT(IOPIN0,DSEL1);
WRITEBYTE(IOPIN0,LED7SEG,a[i%10]);
CLRBIT(IOPIN0,DSEL1);
delay_s(1);
}
}
}



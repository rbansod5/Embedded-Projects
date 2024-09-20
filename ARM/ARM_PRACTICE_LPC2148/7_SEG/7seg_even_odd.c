/*7seg Even Odd*/

#include<LPC21XX.h>
#include"delay.h"					  
#include"defines.h"
#include"types.h"
#define LED 0
#define DSEL1 8
#define DSEL2 9
u32 a[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int main()
{
u8 i;
WRITEBYTE(IODIR0,LED,0xff);
SETBIT(IODIR0,DSEL1);
SETBIT(IODIR0,DSEL2);
while(1)
{
WRITEBYTE(IOPIN0,LED,0xff);
for(i=1;i<10;i++)
{
if(i%2==0)
{
SETBIT(IOPIN0,DSEL1);
WRITEBYTE(IOPIN0,LED,a[i]);
delay_s(1);
CLRBIT(IOPIN0,DSEL1);
}
else if(i%2==1) 
{

 SETBIT(IOPIN0,DSEL2);
WRITEBYTE(IOPIN0,LED,a[i]);
delay_s(1);
CLRBIT(IOPIN0,DSEL2);
}
}
}
}

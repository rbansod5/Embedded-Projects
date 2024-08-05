		 
#include<lpc21xx.h>
#include"delay.h"
#include"types.h"
#include"defines.h"
#define DSEL1 8
 
#define LED7SEG 0
 
int main()
{
char i;
 
char a[14]={0xcf,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xc8,0x80,0x90};
WRITEBYTE(IODIR0,LED7SEG,0xff);
SETBIT(IODIR0,DSEL1);
 
while(1)
{
for(i=0;i<=10;i++)
{

WRITEBYTE(IOPIN0,LED7SEG,a[i]);
SETBIT(IOPIN0,DSEL1);
delay_s(1);
CLRBIT(IOPIN0,DSEL1);
}
}
}





































































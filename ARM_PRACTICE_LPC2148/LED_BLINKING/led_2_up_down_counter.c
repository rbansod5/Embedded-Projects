/*
------------------------------------------------------------------
implement a 2 digit 
up and down counter use two switeches and 8 LED's as mentioned.
sw1 for incrementing count,sw2 for decremebting count and 
display a updated count on LED's.
-------------------------------------------------------------------
*/
#include<LPC21xx.h>
#include"defines.h"
#include"delay.h"
#define LED 0
#define sw1 8
#define sw2 9
int main()
{
int cnt=0;
WRITEBYTE(IODIR0,LED,0xff);
WRITEBIT(IODIR0,sw1,1);
WRITEBIT(IODIR0,sw2,1);
WRITEBYTE(IOPIN0,LED,0x0f);
while(1)
if(READBIT(IOPIN0,sw1)==0)
{
while(READBIT(IOPIN0,sw1)==0);
{
cnt++;
if(cnt<=255)
WRITEBYTE(IOPIN0,LED,(cnt^0x0f));
}
if(READBIT(IOPIN0,sw2)==0)
{
while(READBIT(IOPIN0,sw2)==0);
cnt--;
if(cnt>=0)
WRITEBYTE(IOPIN0,LED,(cnt^0x0f));
}
}
}

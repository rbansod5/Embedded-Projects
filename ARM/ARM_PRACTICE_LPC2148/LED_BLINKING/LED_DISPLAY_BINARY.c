/*
----------------------------------------------------------------
write an ecp to display binary equivalent of switch press count
on 8 LED's (4AH and 4AH)
----------------------------------------------------------------
*/

#include<LPC21xx.h>
#include"defines.h"
#include"delay.h"
#define LED 0
#define sw 8
int main()
{
int cnt=0;
WRITEBYTE(IODIR0,LED,0xff);
WRITEBYTE(IOPIN0,LED,0x0f);
while(1)
{
if(READBIT(IOPIN0,sw)==0)
{
while(READBIT(IOPIN0,sw)==0);
cnt++;
WRITEBYTE(IOPIN0,LED,(cnt^0x0f));
}
}
}

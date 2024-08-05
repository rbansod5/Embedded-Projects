/*
5. PART2: Implement up and down counter. Use two AL switches and 8 leds (4-active
high leds and 4-active low leds) as mentioned:
As long as sw1 is pressed increment the count value with respect to 1 sec
As long as sw2 is pressed decrement count value with respect to 1 sec
And display updated count on leds.
If both switches are pressed at a time, don’t do any operation on count.
Note: if count value is 0, at this time if sw2 pressed it should display 0 only on leds and if
count value is 255 then if sw1 pressed it should display 255 only on leds.
*/


#include<lpc21xx.h>
#include"types.h"
#include"delay.h"
#include"defines.h"
#define LED 0
#define SW1 8
#define SW2 9

int main()
{
s8 cnt=0;
WRITEBYTE(IODIR0,LED,255);
WRITEBYTE(IOPIN0,LED,0x0f);
while(1)
{
if(cnt!=-1 && cnt!=256)
{
if(READBIT(IOPIN0,SW1)==1)
{
delay_s(1);
cnt++;

WRITEBYTE(IOPIN0,LED,(0x0f^cnt));
}
if(READBIT(IOPIN0,SW2)==0)
{ 
while(READBIT(IOPIN0,SW2)==0);
delay_s(1);
cnt--;


WRITEBYTE(IOPIN0,LED,(0x0f^cnt));
}
if(READBIT(IOPIN0,SW1)==0 && READBIT(IOPIN0,SW2)==0)
{
delay_s(1);
//WRITEBYTE(IOPIN0,LED,0xf0^cnt);
}
}
}
}


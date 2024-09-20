#include<lpc21xx.h>
#include"defines.h"
#include"delay.h"
#include"types.h"

#define sw1 8
#define sw2 9

#define led 0

int main()
{
int e,o;
WRITEBYTE(IODIR0,led,0xff);
while(1)
{
if(READBIT(IOPIN0,sw1)==0)
{
for(e=0;e<=255;e++)
{
if(e%2==0)
{
WRITEBYTE(IOPIN0,led,e);
delay_ms(100);
}
}
}
else if(READBIT(IOPIN0,sw2)==0)
{
   
for(e=0;e<=255;e++)
{
if(e%2==1)
{
WRITEBYTE(IOPIN0,led,e);
delay_ms(100);
}
}
}}}
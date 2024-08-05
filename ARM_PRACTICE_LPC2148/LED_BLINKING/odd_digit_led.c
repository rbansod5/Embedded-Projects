/*odd_digit_led*/
#include<LPC21XX.H>
#include"delay.h"
#include"types.h"
#include"defines.h"
int main()
{
u8 i,n=255;
SETBYTE(IODIR0,0,0xff);
while(1)
{
for(i=1;i<=n;i++)
{
if(i%2==1)
{
WRITEBYTE(IOPIN0,0,(i^0x0f));
delay_s(2);
}
}
}
}

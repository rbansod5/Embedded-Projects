/*power of 2*/
#include<LPC21XX.H>
#include"delay.h"
#include"types.h"
#include"defines.h"
int main()
{
u8 n,num=2;
SETBYTE(IODIR0,0,0xff);
{
for(n=0;n<=8;n++)
{
if(n!=0)
{
num=2*num;
}

WRITEBYTE(IOPIN0,0,(num^0x0f));
delay_s(5);
}
}
while(1);
}






#include<LPC21XX.H>
//#include"delay.h"
#include"types.h"
#include"defines.h"
#include"delay.h"
//#define delay_s(j) for(i=12000000*j;i>0;i--)

int main()
{
unsigned int i,j,k;
 while(1)
{
SETBYTE(IODIR0,0,0xff);
for(i=0X0;i<=0Xf;i++)
{
WRITENIBBLE(IOPIN0,0,i);
delay_ms(500);
}
CLRNIBBLE(IOPIN0,0,0xf);
delay_s(1);
for(j=0x10;j>=0x00;j--)//al
{
WRITENIBBLE(IOPIN0,4,j);
delay_s(1);
CLRNIBBLE(IOPIN0,0,0xf);
for(k=0x00;k<=0x0f;k++) //ah
WRITENIBBLE(IOPIN0,0,k);
delay_s(1);

}
}
}

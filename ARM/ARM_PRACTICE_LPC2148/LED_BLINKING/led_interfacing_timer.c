//time in binary
#include<lpc21xx.h>
#include"delay.h"
#include"defines.h"
#include"types.h"

int main()
{
int i,j,k;
IODIR0=0xffffff;
while(1)
{
for(i=0;i<=24;i++)
{
for(j=0;j<=60;j++)
{
for(k=0;k<=60;k++)
{
WRITEBYTE(IOPIN0,0,k);
WRITEBYTE(IOPIN0,8,j);
WRITEBYTE(IOPIN0,15,i);
delay_ms(1000);
}
}
}				  }}
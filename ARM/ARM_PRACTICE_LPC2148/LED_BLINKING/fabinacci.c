#include<lpc21xx.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
int main()
{
int i=0,j=1,k=0;
WRITEBYTE(IODIR0,0,0xff);
do
{
i=j;
j=k;
WRITEBYTE(IOPIN0,0,k);
delay_ms(100);
}while((k=i+j)<100);
}

#include<lpc21xx.h>
#include"delay.h"
#include"types.h"
#include"defines.h"
#include<math.h>
#define led 0
main()
{
int i;
int j,x,y;
char ch;
SETBYTE(IODIR0,led,0xff);
while(1)
{
for(i=0,j=7;i<j;i++,j--)
{
 x=pow(2,i); 
 y=pow(2,j);
 ch=x|y;
 WRITEBYTE(IOPIN0,led,(ch^0x0f));
 delay_ms(500);
 }}}

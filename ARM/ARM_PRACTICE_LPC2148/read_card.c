#include<lpc21xx.h>
#include"delay.h"
#include"types.h:
#include"defines.h"
#include"uart.h"
#include"uart_defines.h>
int main()
{
u8 i,str[20],*p;

InitUART0();
while(1)
{ 

i=U0RXCHAR();
U0TXCHAR(i
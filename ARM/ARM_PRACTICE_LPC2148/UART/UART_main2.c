
/* display welcome to vector into hyper terminal*/
#include<lpc21xx.h>
#include"delay.h"
#include"types.h"
#include"defines.h"
#include"uart.h"
#include"uart_defines.h"
u8 rDat __attribute__((at(0x40000010)));
main()
{
InitUART0();
U0TXSTR("\n\r welcome to vector \n\r");
delay_ms(100);
while(1);
}




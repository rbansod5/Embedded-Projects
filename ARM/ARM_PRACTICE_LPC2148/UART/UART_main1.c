
/* display in hyper uart char string integer float*/
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
U0TXCHAR('A');
delay_ms(100);
U0TXSTR("\n\r hello RAHUL \n\r");
delay_ms(100);
U0TXSTR("\n\r");
U0TXS32(-12345);
U0TXSTR("\n\r");
U0TXU32(12345);
U0TXSTR("\n\r");
U0TXF32(12.345,3);
U0TXSTR("\n\r");
while(1);
}




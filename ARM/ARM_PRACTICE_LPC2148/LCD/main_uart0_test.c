//main_uart0_test.c
#include"types.h"
#include"defines.h"
#include<LPC21XX.h>
#include<string.h>
#include"delay.h"
#include"uart.h"
s8 rDat[20] __attribute__((at(0x40000100)));
main()
{
InitUART0();
U0TxChar('A');
delay_ms(100);
U0TxStr("\n\rHello\n\r");
delay_ms(100);
U0TxStr("\n\r");
U0TxS32(12345);
U0TxStr("\n\r");
U0TxS32(-12345);
U0TxStr("\n\r");
U0TxF32(-12.345,3);
U0TxChar(U0RxChar());
U0TxStr("\n\r");
U0TxStr("enter any string \n\r");
U0TxStr(U0RxStr());	
while(1);
}

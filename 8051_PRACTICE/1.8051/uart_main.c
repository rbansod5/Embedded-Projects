#include <reg52.h>

#include "delay.h"
#include "uart.h"

main()
{
	unsigned char ch='A';

	UART_Init();
	UART_Str("UART TESTING\r\n");
	while(1)
	{
		ch = UART_Rxchar();
		delay_ms(100);
		UART_Txchar(ch);
		UART_Str("\r\n");
		UART_Str("INTEGER VALUE: ");
		UART_Int(1234);
		UART_Str("\r\n");
		UART_Str("FLOAT VALUE: ");
		UART_Float(32.142,3);
		UART_Str("\r\n");
		UART_RxTx_String();
	}
}
/*
1. WAP to receive one characte from uart and display equivalent 
binary value on 8 leds

2. WAP to receive one string from uart with respect to 9600 baud rate
and display that on LCD
*/

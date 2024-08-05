#include <reg51.h>
#include "delay.h"
#include "uart.h"

//initialisation of onchip uart functionality using mode1 with 9600 baudrate
void UART_Init(void)
{
	SCON = 0x50;
	TMOD = 0x20; //timer1 mode2 (auto-reload mode)
	TH1 = 253;
	TR1 = 1;
}
//sending one character from 8051 cpu to external uart based device
void UART_Txchar(unsigned char ch)
{
	SBUF = ch;//writing 8-bit data into SBUF register
	while(TI == 0);
	TI = 0;
}
//receiving one character from external uart based device to 8051 cpu
unsigned char UART_Rxchar(void)
{
	while(RI == 0);
	RI = 0;
	return SBUF;//reading data from SBUF register

}
//sending one string to uart based device form 8051 cpu
void UART_Str(unsigned char *str)
{
	while(*str != '\0')
		UART_Txchar(*str++);
} 
/*
uart will accepct only ascii characters
integer value - 1234
                '1' '2' '3' '4' 
*/
//sending one integer value to uart based device from 8051 cpu
void UART_Int(unsigned int n)
{
	unsigned char a[5]={0};	
	char i=0;
	
	if(n==0)
		UART_Txchar('0');
	else
	{
		while(n>0)
		{	
		 a[i]=(n%10)+48;//0x30 / '0'
		 n=n/10;
		 i++;
		}
    for(--i;i>=0;i--)
        UART_Txchar(a[i]);
  }		
} 
//sending float value to the uart based device from 8051 cpu
void UART_Float(float f,unsigned char ndp)
{
	unsigned int i; char j;
	i=f;
	UART_Int(i);
	UART_Txchar('.');
	for(j=0;j<ndp;j++)
	{
		f=(f-i)*10;
		i=f;
		UART_Txchar(i+48);
	}
}	
//receiving one string from uart based device nad transmit back to uart based device
void UART_RxTx_String()
{
	unsigned char arr[20],index=0;
	
	while(1)
	{
		arr[index] = UART_Rxchar();
		if((arr[index] == '\r') || (index==19))
		{
			arr[index] = '\0';
			break;
		}
		index++;
	}
	UART_Str("\r\n");
	UART_Str("Received string is :");
	UART_Str(arr);
	UART_Str("\r\n");
}	   
	


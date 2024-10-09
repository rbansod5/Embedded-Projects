#include <LPC21xx.H>
//defines for UART
#define RXD0_EN   1<<0
#define TXD0_EN   1<<2
/*
UART0:
BAUD RATE = PCLK/(16*DIVISOR);
DIVISOR = (U0DLM*256) + U0DLL;
*/
#define FOSC      12000000
#define CCLK  	  5*FOSC
#define PCLK  	  CCLK/4
#define BAUD  	  9600
#define DIVISOR   (PCLK/(16 * BAUD))
//bit defines for U0LCR
#define DLAB_BIT 7
//bit defines for U0LSR
#define RDR_BIT  0
#define THRE_BIT 5
#define TEMT_BIT 6

void Init_UART0(void)
{
	//cfg P0.0 as TXD0 & P0.1 as RXD0  functions
 	PINSEL0 |= TXD0_EN|RXD0_EN;
 	//cfg for 8data bits,1 stop bit,DLAB enabled 
 	U0LCR=0x83;
 	//Load Val for 9600 
 	U0DLL=DIVISOR;
 	U0DLM=DIVISOR>>8;
 	//DLAB disabled
 	U0LCR&=~(1<<DLAB_BIT); 
}
void UART0_Tx_char(unsigned char dat)
 {
	U0THR=dat;
	while(((U0LSR>>TEMT_BIT)&1)==0);
 }
 
unsigned char UART0_Rx_char(void)
{
  while(((U0LSR>>RDR_BIT)&1)==0);
 	return U0RBR;
} 	

void UART0_Tx_str(char *p)
{
	while(*p)
		UART0_Tx_char(*p++);	
}

void UART0_Tx_int(signed int n)
{
	char a[10],i=0;
  if(n<0)
	{
		UART0_Tx_char('-');
		n=-n;
	}
	do                       
	{
		a[i++]=n%10+48;	
		n=n/10;
	}while(n);
    for(;i>0;i--)
		UART0_Tx_char(a[i-1]);
}

void UART0_Tx_float(float f,char i)
{
//1st arg(f) is the float number to be displayed  on hyperterminal
//2nd arg(i) is number digits to be displayed after the dot('.')                      
  unsigned long int n=f;
	UART0_Tx_int(n);
	UART0_Tx_char('.');
  for(;i>0;i--)
	{
		f=f*10;
    n=f;	
		UART0_Tx_char(n%10+48);
	}	
} 

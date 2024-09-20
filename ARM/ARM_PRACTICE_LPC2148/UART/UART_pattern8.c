   /* 
uart_pattern



*/


#include<lpc21xx.h>
#include"defines.h"
#include"types.h"
#include"delay.h"

//uart_defines.h
//u0LCR sfr defines
#define LEN_8BITS 3
#define WORD_LEN LEN_8BITS
#define DLAB_BIT 7
//u0LCR SFR defines
#define DR_BIT 0
#define THRE_BIT 5
#define TEMT_BIT 6
#define BAUD 19200
#define FOSC 12000000
#define CCLK (FOSC*5)
#define PCLK CCLK/4
#define DIVISOR (PCLK/(16*BAUD))
#define TxD0_PIN_EN 0x00000001
#define RxD0_PIN_EN 0X00000004
#define Tx_LED 6//p0.6
#define Rx_LED 7//P0.7
s8 a[20];
void InitUART(void)
{
SETBIT(IODIR0,Tx_LED);
SETBIT(IODIR0,Rx_LED);
PINSEL0=TxD0_PIN_EN|RxD0_PIN_EN;

U0LCR=1<<DLAB_BIT|WORD_LEN;
U0DLL=DIVISOR;
U0DLM=DIVISOR>>8;
CLRBIT(U0LCR,DLAB_BIT);
}
void U0TXCHAR(u8 sDat)
{
U0THR=sDat;
while(READBIT(U0LSR,TEMT_BIT)==0);
CPLBIT(IOPIN0,Tx_LED);
}
u8 U0RXChar(void)
{
while(READBIT(U0LSR,DR_BIT)==0);
CPLBIT(IOPIN0,Rx_LED);
return U0RBR;
}
void U0TXStr(u8 *p)
{
while(*p)
U0TXCHAR(*p++);
}
s8 *U0RXStr(void)
{

u32 i=0;
while(1)
{
a[i]=U0RXChar();
U0TXCHAR(a[i]);
if(a[i]=='\r')
{
a[i]='\0';
break;
}i++;
}
U0TXStr("\n\r");
return a;
}
s8 rDat[20] __attribute__((at(0x40000100)));
main()
{
while(1)
{
unsigned int i,j,n=5;
InitUART();
for(i=1;i<=5;i++)
{
U0TXStr("\n\r");
for(j=1;j<=5;j++)
{
if(j<i)
{
U0TXCHAR(' ');
U0TXCHAR(' ');
}
else
{
U0TXCHAR('*');
U0TXCHAR(' ');
}

}
 


delay_s(1);
}}}
 

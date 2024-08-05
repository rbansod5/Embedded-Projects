//test_uart0.c
#include "types.h"
#include "defines.h"
#include<LPC21XX.H>
#include "uart_defines.h"
#include"uart.h"
s8 rDat[20] __attribute__((at(0x40000100)));
void InitUART0(void)
{
SETBIT(IODIR0,Tx_LED);
SETBIT(IODIR0,Rx_LED);
//cfg p0.0 and p0.1 are uart0tx,rx,fun
PINSEL0=TxD0_PIN_EN|RxD0_PIN_EN;
//cgf U0LCR reg
U0LCR=1<<DLAB_BIT|WORD_LEN;
//cfg BAUDRATE 9600
U0DLL=DIVISOR;
U0DLM=DIVISOR>>8;
//clr DLAB bit
CLRBIT(U0LCR,DLAB_BIT);
}
void U0TXCHAR(u8 sDat)
{
//load data in tx_buffer
U0THR=sDat;
//wait until transmitter(PISO reg)empty
while(READBIT(U0LSR,TEMT_BIT)==0);
//status for user visibility
CPLBIT(IOPIN0,Tx_LED);
}
void U0TXSTR(u8 *p)
{
while(*p)
U0TXCHAR(*p++);
}
void U0TXU32(u32 n)
{
u32 a[10];
s32 i=0;
if(n==0)
U0TXCHAR('0');
else
{
while(n)
{
a[i]=(n%10)+48;
i++;
n=n/10;
}
for(--i;i>=0;i--)
U0TXCHAR(a[i]);
}
}
void U0TXS32(s32 n)
{
if(n<0)
{
U0TXCHAR('-');
n=-n;
}
U0TXU32(n);
}
void U0TXF32(f32 f,u8 nDP)
{
u32 i;
s32 j;
if(f<0.0)
{
U0TXCHAR('-');
f=-f;
}
i=f;
U0TXU32(i);
U0TXCHAR('.');
for(j=0;j<nDP;j++)
{
f=(f-i)*10;
i=f;
U0TXCHAR(i+48);
}
}
u8 U0RXCHAR(void)
{
while(READBIT(U0LSR,DR_BIT)==0);
//CPLBIT(IOPIN0,Rx_LED);
return U0RBR;
}
s8 * U0RXSTR(void)
{
static s8 a[20];
u32 i=0;
while(1)
{
a[i]=U0RXCHAR();
U0TXCHAR(a[i]);
if(a[i]=='\r')
{
a[i]='\0';
break;
}
i++;
}
U0TXSTR("\n\r");
return a;
}

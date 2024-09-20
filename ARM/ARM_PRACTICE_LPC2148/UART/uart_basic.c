	  //uart0_test.c
#include"types.h"
#include"defines.h"
#include<lpc21xx.h>
void delay_ms(u32 dlyMS)
{
dlyMS*=12000;
while(dlyMS--);
}
//U0LCR SFR DEFINES
#define LEN_8BIT 3
#define WORD_LEN LEN_8BIT
#define DLAB_BIT 7
//U0LSR SFR defines
#define DR_BIT 0
#define THRE_BIT 5
#define TEMT_BIT 6
#define BAUD 9600
#define FOSC 12000000
#define CCLK (FOSC*5)
#define PCLK CCLK/4
#define DIVISOR (PCLK/(16*BAUD))
#define TXD0_PIN_EN 0x00000001
#define RXD0_PIN_EN 0x00000004
#define TX_LED 6//p0.6
#define RX_LED 7//p0.7

void InitUART0 (void)
{
SETBIT(IODIR0,TX_LED);
SETBIT(IODIR0,RX_LED);
//cfg p0.0 &p0.1,tx,rx fun
PINSEL0=TXD0_PIN_EN|RXD0_PIN_EN;
//cfg UOLCR register
U0LCR =1<<DLAB_BIT|WORD_LEN;
//cfg. baudrate 9600
U0DLL=DIVISOR;
U0DLM=DIVISOR>>8;
//clr DLAB bit
CLRBIT(U0LCR,DLAB_BIT);
 }
void U0TXChar(u8 sDat)
{
//load data in TX_buffer
U0THR=sDat;
//wait until transmitter(PISO reg) empty
while(READBIT(U0LSR,TEMT_BIT)==0);
//status for user visibility
CPLBIT(IOPIN0,TX_LED);
}
void U0TXStr(void)
{
while(*p)
U0TXChar(*p++);
}
void U0TXU32(u32 n)
{
u32 a[10];
s32 i=0;
if(n==0)
U0TXChar('0');
else
{
while(n)
{
a[i]=(n%10)+48;
i++;
n/=10;
}
for(--i;i>=0;i--)
U0TXChar(a[i]);
}
}
void U0TXS32(s32 n)
{
if(n<0)
{
U0TXChar('_');
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
U0TXChar('_');
f=-f;
}i=f;
U0TXU32(i);
U0TXChar('.');
for(j=0;j<nDP;j++)
{
f=(f-i)*10;
i=f;
U0TXChar(i+48);
}
}
u8 U0TXChar(void)
{
while(READBIT (U0LSR,DR_BIT)==0);
CPLBIT(IOPIN0,RX_LED);
return U0RBR;

u8 rDat __attribute__((at(0x40000100)));
main()
{
InitUART0();
U0TXChar('A');
delay_ms(100);
U0TXStr("\n\r HELLO \n\r");
delay_ms(100);
U0TXStr("\n\r");
U0TXS32(-12345);
U0TXStr("\n\r");
U0TXF32(-12.345,3);
U0TXChar(U0RXChar());
U0TXStr("\n\r");
while(1);
}

}
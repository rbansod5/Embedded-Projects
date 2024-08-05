#include<lpc21xx.h>
#include "defines.h"
#include"delay.h"
#define fosc 12000000
#define baud 9600
#define cclk fosc*5
#define pclk cclk/4
#define divisor pclk/(16*baud)

void inituart(void)
{
PINSEL0=0x05;
U0LCR=0x83;
U0DLL=divisor;
U0DLM=divisor>>8;
U0LCR=0x03;
}

void txuart(unsigned char sdat)
{
U0THR=sdat;
while(READBIT(U0LSR,6)==0);
}
unsigned char rxuart(void)
{
while(READBIT(U0LSR,0)==0);
return U0RBR;
}

unsigned char* string(unsigned char *p)
{
 while(*p)
 {
 txuart(*p++);
 }
 return p;

}
 int main()
 {
 char ch;
 inituart();
 while(1)
 {
 //ch=rxuart();
  string("pankaj baya lawda");
  delay_ms(1000);
// txuart(ch);
 }
 }


 

#include <LPC21xx.H>  /* LPC21xx definitions         */
#include <string.h>

#include "uart.h"

#define UART_INT_ENABLE 1

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
#define THRE_BIT 5//recheck
#define TEMT_BIT 6

//char buff[6]="hello",dummy;
char buff[20];
char dummy;
unsigned char i=0,rx,flag,t=0;

void UART0_isr(void) __irq
{
  if((U0IIR & 0x04)) //check if receive interrupt
  {
		rx =  U0RBR;	/* Read to Clear Receive Interrupt */
		if(rx==0X02)
			flag=1;
		else if((flag == 1) && (rx!=0X03))
		{
			buff[i++] = rx; 
		}
		else
		{
			buff[i] = '\0';
			i=0;
			flag = 2;
		}
  }
  else
  {
      dummy=U0IIR; //Read to Clear transmit interrupt
  }
   VICVectAddr = 0; /* dummy write */
}

void Init_UART0 (void) /* Initialize Serial Interface       */ 
{  
  PINSEL0 |= 0x00000005; /* Enable RxD0 and TxD0              */

  U0LCR = 0x83;         /* 8 bits, no Parity, 1 Stop bit     */
  U0DLL = 97;           /* 9600 Baud Rate @ CCLK/4 VPB Clock  */
  U0LCR = 0x03;         /* DLAB = 0  */

  #if UART_INT_ENABLE > 0

  VICIntSelect = 0x00000000; // IRQ
  VICVectAddr0 = (unsigned)UART0_isr;
  VICVectCntl0 = 0x20 | 6; /* UART0 Interrupt */
  VICIntEnable = 1 << 6;   /* Enable UART0 Interrupt */
 // U0IIR = 0xc0;
 // U0FCR = 0xc7;
  U0IER = 0x03;       /* Enable UART0 RX and THRE Interrupts */   
            
  #endif
}

 void UART0_Tx_char(unsigned char ch)  /* Write character to Serial Port    */  
{ 
  while (!(U0LSR & 0x20));
  U0THR = ch;                
}
unsigned char UART0_Rx_char(void)

{

  while(((U0LSR>>RDR_BIT)&1)==0);
	return U0RBR;

} 	


void UART0_Tx_str(char *s)
{
   while(*s)
       UART0_Tx_char(*s++);
}


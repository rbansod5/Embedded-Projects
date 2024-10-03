										  /*********************************************************************
**	Project Name : UART0																						**
**  Pin Numbers  : P0.0 - Tx0																				**
**				   P0.1 - Rx0																				**
**	Buad Rate		 : 9600																							**
*********************************************************************/
//#include <stdio.h>               
#include <LPC21xx.H>            /* LPC21xx definitions */
#include "Serial.h"
#include "led.h"


#define UART0_TEXT "\n\r Testing UART0 LPC2148Board \n\r Board Version : 1 \n\r Firmware Version: 1 \n\r "

/**
*****************************************************************************
  Function Name : delay()

  Description :This function suspends the tasks for specified ticks.	

  Input :  ticks:no of ticks in multiple of 1 usec
            task: task to be suspended

  Output : void

  Note :
*******************************************************************************
*/

void delay_ms(int count)
{
  int j=0,i=0;

  for(j=0;j<count;j++)
  {
    /* At 60Mhz, the below loop introduces
    delay of 10 us */
    for(i=0;i<35;i++);
  }
}

/* main program */
int main (void)  {                /* execution starts here                    */
	
	LED_Init();
  uart0_init();					  // Initialize UART0
  delay_ms(100000);

  uart0_puts (UART0_TEXT);	  // Transffer data to PC through Serial
  delay_ms(100000);
	uart0_puts ("*****************************\n\r");

  while (1) {                    /* An embedded program does not stop */
  uart0_puts ("\n\rHello World\n\r");	  // Transffer data to PC through Serial
  delay_ms(100000);
  }                               
}

   /*********************************************************************
**	Project Name : UART1																						**
**  Pin Numbers  : P0.8 - Tx1																				**
**				   P0.9 - Rx1																				**
**	Buad Rate	 : 9600																							**
*********************************************************************/
//#include <stdio.h>               
#include <LPC214x.H>              /* LPC21xx definitions */
#include "Serial.h"
#include "led.h"


#define UART1_TEXT "\n\r Testing UART1 LPC2148 Board \n\r Board version : 1 \n\r Firmware Version: 1 \n\r "

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
  uart1_init();					  // Initialize UART1
  delay_ms(100000);

  uart1_puts (UART1_TEXT);	  // Transffer data to PC through Serial
  delay_ms(100000);
	uart1_puts ("*****************************\n\r");

  
  {                    /* An embedded program does not stop */
  uart1_puts ("\n\r Hello World \n\r");	  // Transffer data to PC through Serial
  delay_ms(100000);
  }
  while (1);                               
}

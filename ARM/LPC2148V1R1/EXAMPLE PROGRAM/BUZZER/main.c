												 /*********************************************************************
**	Project Name : Buzzer																						**
**  Pin Numbers  : P0.11																						**
*********************************************************************/

/* LPC2129 Header File */ 

#include <LPC21xx.H>

#include "led.h"

/* Macro Definitions */ 
#define BUZZER (1 << 15)

/* Delay Function */
/* for 12MHz Cloock Frequency it generates = 1ms Delay */
void delay(int count)
{								// Delay Start
	int i,j;					// Variable Declaration
	for(i = 0;i < count;i++)	// Delay Loop
	for(j = 0;j < 1275;j++);	// Delay Loop 
} 								// End of Delay Function

/* Main Function */
int main()
{					   			// Main Starts
	int count=0;	
//	PINSEL0 = 0x00000000;			// count variable declaration
	IODIR0 |= BUZZER;			// Declared as output pin - P0.25
	IOCLR0 |= BUZZER;			// Initially Clear the Pin P0.25
	
	//LED_Init();					// LED Initialization 
	while(1)
	{	
	for(count=0;count<5;count++)// Buzz for 5 times
	{							// for loop open
		IOSET0 = BUZZER;		// Buzzer - ON
		delay(1500);				// Delay
		IOCLR0 = BUZZER;		// Buzzer - OFF
		delay(1500);				// Delay
	}	
	}						// End of for loop 
}								// End of Start

/********************************************************************
**                         End of File  						   **
********************************************************************/


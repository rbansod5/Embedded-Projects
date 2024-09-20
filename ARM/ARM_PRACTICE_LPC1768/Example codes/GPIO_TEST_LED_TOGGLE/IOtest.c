/*****************************************************************************
 *   iotest.c:  main C entry file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/

#include "lpc17xx.h"

//#define LED (1 << 25)

#define LED1 (1 << 19)
#define LED2 (1 << 20)
#define LED3 (1 << 21)
#define LED4 (1 << 22)
#define LED5 (1 << 23)
#define LED6 (1 << 24)	 
#define LED7 (1 << 25)
#define LED8 (1 << 26)
#define LED_ALL  LED1| LED2 | LED3 | LED4 | LED5 | LED6 | LED7 | LED8





void delay(int count)
{								// Delay Start
	int i,j;					// Variable Declaration
	for(i = 0;i < count;i++)	// Delay Loop
	for(j = 0;j < 1275;j++);	// Delay Loop 
} 



int main (void)
{	    		
	//uint32_t j;

	int L1,L8;	
	
	SystemInit();

	LPC_GPIO1->FIODIR  |= LED_ALL;			// Declared as output pin - P1.17 to P1.24
	LPC_GPIO1->FIOCLR |= LED_ALL;			// Clear all LED's

	//LPC_GPIO1->FIODIR   |=  LED;				// P1.29 = Outputs 
//	LPC_GPIO1->FIOCLR 	 =  LED;				// Turn-OFF LED

	//Loop LED Test
/*	while(1)
	{
		LPC_GPIO1->FIOSET 	 =  LED;				// Turn-ON LED
		for(j = 1000000; j > 0; j--);
		LPC_GPIO1->FIOCLR 	 =  LED;				// Turn-OFF LED
		for(j = 1000000; j > 0; j--);
	}*/	



					// First and Last LED' Variable Declaration
//	LED_Init();					// LED Initialization
	while(1)		   			// Infinite Loop  ( main while )
	{	
	
		  /* 	LPC_GPIO1->FIOSET 	 =  LED7;
			delay(1000);
				LPC_GPIO1->FIOCLR 	 =  LED7;	
					delay(1000);	  */
			
			
								// While open
		L1=19, L8=26;			// First and Last LED'S Pin Number Initialization
		while((L1 <= 22)&&(L8 >= 23)) 	 	// Check for the pin number condition
		{							  		// while open
		LPC_GPIO1->FIOSET = ((1 << L1)|(1 << L8));	// ON LED's 
			delay(1000);						// Delay
			L1++;							// Increment First LED Count
			L8--;							// Decrement Last LED Count
		}									// End of while
		
		L1=22,L8=23;						// LED'S Pin Number Initialization
		while((L1 >= 19) && (L8 <= 26))		// Check for the pin number condition
		{									// while open
			LPC_GPIO1->FIOCLR = ((1 << L1)|(1 << L8));	// OFF LED's
			delay(1000);						// Delay
			L1--;							// Decrement First LED Count
			L8++;							// Increment Last LED Count
		}	
	 }			


}





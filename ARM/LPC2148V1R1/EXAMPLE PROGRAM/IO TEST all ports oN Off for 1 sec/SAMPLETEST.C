
  // Header:  NSK ELECTRONICS
  // File Name:  I/O TEST 
  // Author: KIRAN
  // Date:	1/05/2007



/* HAI START WITH SMALL TEST PROGRAM TO TEST 
 DOWNLOAD THE FIRST I/O TEST PROGRAM THROUGH FLASHER ,ALL THE LEDS START BLINKING WITH BEEP */

#include <LPC21xx.H>                       /* LPC21xx definitions  */

/********************************************************************************
Function Declaration
********************************************************************************/
void ledonoff(void);
void delay(void);

/********************************************************************************
Main function
********************************************************************************/

int main()
{
	IODIR1 = 0xFFFFFFFF;               // Make port bits P1.16......P1.23 as output
	IODIR0 = 0xFFFFFFFF;    
	ledonoff();			               // Initialize LED
    return 0;

}

void ledonoff(void)
{
	while(1)
	{
		IOSET1 = 0xFFFFFFFF;				//Make port bits high
		IOSET0 = 0xFFFFFFFF;				
		delay();  
		IOCLR1 = 0xFFFFFFFF;				//Make port bits low
		IOCLR0 = 0xFFFFFFFF;
		delay();

						
}

}

void delay(void)
{
	int i;
	char k;
	for(k=0;k<=8;k++)
	{
		for(i=0;i<=400000;i++) ;
	}
}

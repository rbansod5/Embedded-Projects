
// Read/Write Internal RTC of LPC2148
// Display Result on UART0(9600,N,8,1)

#include "LPC214x.H" 	                                	// LPC2148 MPU Register
#include <stdio.h>											// For Used Function printf 
#include "uart.h"
#include "uart0.c"

#define MASKSEC 0x3F  										// Second 00..59   00000000:00000000:00xxxxxx
#define MASKMIN 0x3F00										// Minute 00..59   00000000:00xxxxxx:00000000
#define MASKHR  0x1F0000									// Hour 00..23	   000xxxxx:00000000:00000000

int main(void)
{  
  unsigned char Hour,Minute,Second,Last_Second;				// RTC Buffer Data
  init_serial0();		   									// Initilial UART0 = 9600,N,8,1
  sprintf(uart0_buf,"\n\n\n NSK ELECTRONICS ARM7 USB-LPC2148....TEST RTC\n"); 	// Call prinff Function
  print_uart0();

  // Initial Internal RTC Function
  // Initial RTC Function
  CCR  = 0;													// Reset All Bit Control
  CCR |= 0x00000010; 										// CLKSRC = 1 = Used EXT 32.768 KHz
 // HOUR = 0x03;
 // MIN  = 0x03;
 // SEC  = 0x03;
  CCR |= 0x00000002; 										// Reset   Clock
  CCR &= 0xFFFFFFFD;										// Release Reset
  CCR |= 0x00000001;										// Start RTC Clock	

  Last_Second = 0x00;
 
  // Start Test Read RTC and Display on UART0 //
  while(1)
  { 
    do 														// Repeat Get Second until Second Change
	{		
	  Hour   = (CTIME0 & MASKHR)>>16;						// Read Hour
	  Minute = (CTIME0 & MASKMIN)>>8;		 				// Read Minute
	  Second = CTIME0 & MASKSEC;		  					// Read Second
    }
    while(Last_Second == Second);							// Repeat if Second Not Change
	
    Last_Second = Second;									// Update Current Second
          
    //************************************//
    // Display Clock = Hour:Minute:Second //
    //************************************//
	sprintf(uart0_buf,"\rReal Time Clock = ");
	print_uart0();
    //printf("\rReal Time Clock = ");							// Print Message String 
  	sprintf(uart0_buf," %2d : %2d : %2d\n",Hour,Minute,Second);	 
	print_uart0();
  }
}


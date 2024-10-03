#include "lpc17xx.h"
#include "type.h"
#include "ps2kbd.h"





/**
*****************************************************************************
	Function Name : extISR0()

	Description   :

	Input         :  

	Output        : 

	Note          :
******************************************************************************
*/
void extISR0(void) __irq
{
  static uint8_t key_data;          // Holds the received scan code
  uint32_t clkstat;
  uint32_t datstat;
  uint32_t paritystat;
 
  clkstat = kbCLK;             //check CLK pin state;
  datstat = kbDAT;             //check DAT pin state;

  bitcount++;
  
  if (bitcount==K_STARTBIT)
  {
      if (datstat || clkstat)	bitcount=0;
      key_data=0;
      paritystat=0; 
  }
  else if (bitcount==K_PARITYBIT)
  {
      paritystat = datstat;
  }
  else if (bitcount==K_STOPBIT)
  {   
     decode (key_data);
      bitcount=0;         
  }
  else
  {
      // For all bits from 2, 3...9 (total 8-bit)
      key_data= key_data >> 1;
      if (datstat)
      {
  	    key_data = key_data | 0x80;
      }
   }

  EXTINT = 0x01;      //clear interrupt
  VICVectAddr = 0; 
}//extISR


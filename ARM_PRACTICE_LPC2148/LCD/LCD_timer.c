/*
4. Write an ECP display the basic time (HH:MM:SS) on LCD.
Note: don’t use RTC registers
*/

#include "types.h"
#include "lcd_defines.h"
#include "defines.h"
#include<LPC21xx.h>
#include "delay.h"
#include "lcd.h"

int main()
{
u8 H,M,S;
	InitLCD();
	while(1)
	{
	CmdLCD(0x01);
   for(H=0;H<=24;H++)
   {	
   

   for(M=0;M<=60;M++)
   {
      
   for(S=0;S<=60;S++)
	 {
	 CmdLCD(0xC0);
	 StrLCD("HH:MM:SS");
	 CmdLCD(0x80);
  
	 U32LCD(H);
 	 CmdLCD(0x82);
	 CharLCD(':');
	 CmdLCD(0x83);
	 U32LCD(M);
	 CmdLCD(0x85);
	 CharLCD(':');
	 CmdLCD(0x86);
	 U32LCD(S);
	 CmdLCD(0x88);
	delay_s(1);
	 
	 }					                             
	}
	}
	}
	}
	

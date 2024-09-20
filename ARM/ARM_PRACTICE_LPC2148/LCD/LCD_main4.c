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
u32 H,M,S;
	InitLCD();
	while(1)
	{
	//CmdLCD(0x01);
   for(H=0;H<=24;H++)
   {
   CmdLCD(0x80);
   InitLCD();
	 U32LCD(H);
	 CmdLCD(0x80+2);
	 CharLCD(':');

   for(M=0;M<=60;M++)
   {
    CmdLCD(0x80+3);
   InitLCD();
	 U32LCD(M);
	 CmdLCD(0x80+5);
	 CharLCD(':');
   for(S=0;S<=60;S++)
	 {
	   CmdLCD(0x80+6);
        InitLCD();
	 U32LCD(S);
	 CmdLCD(0x80+8);
	 CharLCD(':');
	 delay_s(1);
	 CmdLCD(0x01);
	 }
	}
	}
	}
	}
	

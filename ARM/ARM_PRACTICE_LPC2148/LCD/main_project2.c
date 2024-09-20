/****************************************************************
		MAIN_PROJECT_FILE.C
***************************************************************/

#include<lpc21xx.h>

#include <stdlib.h>

#include "delay.h"

#include "uart.h"

#include "defines.h"

#include "lcd.h"
#include"lcd_defines.h"

#include "keypad.h"

#define LED_DATA 8
#define SW1 0
#define SW2 1

int main()

{

	u32 i;

	u8 ch,ch1,cp;

    InitLCD();

	InitUART0();

	

	while(1)

	{
	U0TXSTR("Dignostic the system");
	U0TXSTR("press sw1 to Diagnostics");
	U0TXSTR("press sw2 to continue");
	if(READBIT(IOPIN0,SW1)==0)
	{
	  
	  U0TXSTR("checking LCD");
	  U0TXSTR("check EN RS pin");
	  CmdLCD(0x80);

	  for(i=0;i<13;i++)

	{

		CharLCD('A'+i);

		delay_ms(300);

	}

		CmdLCD(0xc0);

		for(i=13;i<26;i++)

		{

		 CmdLCD('A'+i);

		delay_ms(300);

	    }
		StrLCD("LCD WORKING...");
		delay_ms(50);
	  U0TXSTR("checking all LED's");
	  CmdLCD(0x80);
	  StrLCD("checking all LED's");
	  delay_ms(100);
	  CmdLCD(0x01);
	  int x=5;
	  while(x--)
	  {
	  WRITEBYTE(IODIR0,LED_DATA,0Xff);
	  delay_ms(1);

	  WRITEBYTE(IOPIN0,LED_DATA,0X00);
	  }

	  CmdLCD(0x80);
	  StrLCD("LED's checked");
	  delay_ms(100);
	  CmdLCD(0x01);

	  U0TXSTR("check Keypad matrix");
	  StrLCD("check keypad matrix");
	  int cp;
	  cp = keyscan();

	  CharLCD(cp);

	  U0TXCHAR(cp);
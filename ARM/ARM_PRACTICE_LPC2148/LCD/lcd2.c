//lcd2.c

#include"lcd.h"
#include"delay.h"
#include"lcd_defines.h"
#include"kpm_defines.h"
#include"keypad.h"
main()
{
	u8 KeyV;
	InitLCD();
	InitKpm();
	strLCD( "4x4KPM:" );
	while(1)
	{
		KeyV=KeyScan();
		while(!ColScan())
		{
			CmdLCD(0xc0);
			strLCD("            ");
			CmdLCD(0xc0);
			CharLCD(KeyV);
			}
	}
}

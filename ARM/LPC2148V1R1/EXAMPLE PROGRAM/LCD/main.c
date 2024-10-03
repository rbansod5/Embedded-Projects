
#include"prototype.h"


int main()
{
	PINSEL0 |= 0x00000000;
	IODIR0 |= LCD_ALL;

	lcd_init();
	while(1)
	{
	lcdcmd(0x01);
	lcdcmd(0x80);
	lcd_print("NSK ELECTRONICS");
	Delay(100);
	
	lcdcmd(0x01);
	lcdcmd(0x80);
	lcd_print("BENGALURU");
	Delay(100);
	lcdcmd(0x01);
	}
}

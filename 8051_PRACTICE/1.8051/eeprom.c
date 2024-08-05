#include "i2c.h"
#include "lcd.h"


main()
{
	unsigned char ch;

	LCD_Init();
	Write_CMD_LCD(0x80);
	Write_str_LCD("EEPROM TEST:");
	i2cDevByteWrite(0xA0,0x00,'A');

	ch = i2cDevRandomRead(0xA0,0x00);

	Write_CMD_LCD(0xC0);
	Write_DAT_LCD(ch);
	while(1);
}

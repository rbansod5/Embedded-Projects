#include"lcd.h"
main()
{
//	signed int i;
	LCD_Init();//LCD initialization
   Write_CMD_LCD(0x80);//selecting starting line and staring pos
   Write_DAT_LCD('A');//ASCII value of the character to be //displayed
	Write_DAT_LCD('B');
    Write_CMD_LCD(0xC0);
	Write_str_LCD("INDIA");
    Write_CMD_LCD(0x82);
    Write_int_LCD(123);
    
	Write_CMD_LCD(0x87);
	Write_float_LCD(12.345,3);
	while(1);
}


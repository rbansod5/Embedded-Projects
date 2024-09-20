
#include "i2c.h"
#include "lcd.h"
#include"i2c_defines.h"

main()
{
	unsigned char ch;

	initlcd();
	cmdlcd(0x80);
	strlcd("EEPROM TEST:");
	ch=0+48;
	 
	i2cDevByteWrite(0xA0,0x00,ch);
	ch = i2cDevRandomRead(0xA0,0x00);
    cmdlcd(0xC0);	
	datalcd(ch);
	 
	ch++;
    i2cDevByteWrite(0xA0,0x0A,ch);
	ch = i2cDevRandomRead(0xA0,0x0A);
    cmdlcd(0xC3);	
	datalcd(ch);
 

	//Write_CMD_LCD(0xC6);
    //Write_DAT_LCD(ch);

     
	while(1);
}

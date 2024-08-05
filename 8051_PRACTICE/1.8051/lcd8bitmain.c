#include"lcd.h"

main()
{
	initlcd();//cursor will display in first line first position with out any data
	
//because of display on cursor is visible to us 
//data is writing using 8-data lines, data fixed in 5x7 pixel able to 32 characters in 16x2 lcd
	datalcd('A');

	strlcd(" VECTOR INDIA ");
	cmdlcd(0xc5);
	integerlcd(1546);
	BuildCgram();// CUSTOMIZED CHARACTER HEXADECIMAL VALUES ARE STORED IN CGRAM
	cmdlcd(0xc0/* To move the cursor secondline 1st position*/);
	//If we need to display customized character, bring those hex values from CGRAM to DDRAM
	datalcd(0);//If Customized character hex values in 0x40 -0x47 - pass 0 index number

/*	index number 1 - 0x48 - 0x4f
 	index number 2 - 0x50 - 0x57
	index number 3 - 0x58 - 0x5f
	index number 4 - 0x60 - 0x67
	index number 5 - 0x68 - 0x6f
	index number 6 - 0x70 - 0x77
	index number 7 - 0x78 - 0x7f
	*/
	while(1);
}


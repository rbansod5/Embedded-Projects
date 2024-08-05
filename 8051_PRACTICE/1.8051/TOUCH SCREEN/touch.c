#include<reg51.h>
#include<string.h>
#include"lcd.h"
#include"delay.h"
#include"uart.h"

sbit LED = P1^0;
extern idata unsigned char buff[25];
extern char flag;
bit i_flag;


main()
{
	int xval=0,yval=0,zval=0;
	LED = 1; // led off

	LCD_Init();
	UART_Init();
	Write_CMD_LCD(0x01);
	Write_CMD_LCD(0x80);
	Write_str_LCD("  TOUCH SCREEN  ");
	Write_CMD_LCD(0xC0);
	Write_str_LCD("*** PROJECT ***");
	delay_ms(1000);	
	while(1)
	{
		flag=0;
		while(flag==0);
		xval=((buff[3]-'0')*1000)+((buff[4]-'0')*100)+((buff[5]-'0')*10)+((buff[6])-'0');
		yval=((buff[10]-'0')*1000)+((buff[11]-'0')*100)+((buff[12]-'0')*10)+((buff[13])-'0');
		zval=((buff[17]-'0')*1000)+((buff[18]-'0')*100)+((buff[19]-'0')*10)+((buff[20])-'0'); 

		Write_CMD_LCD(0x01);
		Write_CMD_LCD(0x80);
		Write_int_LCD(xval);
		Write_str_LCD("   ");
		Write_int_LCD(yval);
		Write_CMD_LCD(0xC0);
		Write_int_LCD(zval);
		delay_ms(500);
	}

}

/** compiler directives **/
#include<reg52.h>
#include<string.h>

/** user defined header files **/
#include"delay.h"
#include"lcd.h"
#include"uart.h"

extern unsigned char rec_buff[25],k;
extern bit r_flag;

/** main function **/
int main()
{
	delay_ms(1000);
	uart_init();
	init_lcd();
	while(1)
	{
		uart_string("\r\nEnter data:\r\n");
		cmd_lcd(0x01);
		cmd_lcd(0x80);
		str_lcd("Waiting for data");
		r_flag=0;k=0;
		memset(rec_buff,'\0',25);
		while(r_flag==0);
		cmd_lcd(0x01);	
		cmd_lcd(0x80);
		str_lcd("Data Received");
		delay_ms(1000);
		cmd_lcd(0x01);
		cmd_lcd(0x80);
		str_lcd("Data is :");
		cmd_lcd(0xc0);
		str_lcd(rec_buff);
		delay_ms(5000);
	}

}//main end




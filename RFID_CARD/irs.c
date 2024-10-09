#include "uart.h"
#include "lcd.h"
#include "delay.h"

extern char buff[20];
extern unsigned char i,ch,r_flag;

int main()
{
 	Init_UART0();
   	LCD_Init();


  while(1)
  {
  	LCD_cmd(0x80);
	LCD_str("Waiting for card");
  		i=0;r_flag=0;
 		while(r_flag != 2);
		LCD_cmd(0x01);
		LCD_str("Card received");
		delay_ms(500);
		LCD_cmd(0xC0);
 		LCD_str(buff);
 		delay_s(1);
   }

}


#include<reg52.h>

#include"delay.h"

#define lcd_data P0

sbit rs=P3^4;
sbit rw=P3^5;
sbit en=P3^6;

void write_lcd(unsigned char dat)
{
  lcd_data=dat;
  rw=0; 
  en=1;
  en=0;
  delay_ms(2);
}
void cmd_lcd(unsigned char cmd)
{
  rs=0; //sel cmd reg
  write_lcd(cmd);

}

void putc_lcd(unsigned char val)
{
   rs=1;  // sel data register
   write_lcd(val);

}
void init_lcd()
{
 	cmd_lcd(0x02);//return home
	cmd_lcd(0x38);//8_bit mode
 	cmd_lcd(0x06);//increment cursor to right
 	cmd_lcd(0x0c);//display on cursor off
 	cmd_lcd(0x01);//clear screen
 	cmd_lcd(0x80);//first line first position

}

void str_lcd(unsigned char *p)
{
	while(*p)
   		putc_lcd(*p++);
}





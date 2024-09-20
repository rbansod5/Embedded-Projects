#include<reg51.h>
#include"delay.h"
#include"lcd.h"
#define LCD_DAT P0
sbit rs=P3^4;
sbit rw=P3^5;
sbit en=P3^6;
void LCD_Init(void)
{
	delay_ms(16);
    Write_CMD_LCD(0x30);
    delay_ms(6);
	Write_CMD_LCD(0x30);
    delay_ms(1);
    Write_CMD_LCD(0x30);
    delay_ms(1);
    Write_CMD_LCD(0x38);//set 8-bit mode of operation with 2 lines
						// and 5X7 character font 
	Write_CMD_LCD(0x10);//Turning OFF the display
	Write_CMD_LCD(0x01);//clearing the display
    Write_CMD_LCD(0x06);//Shifting the cursor to the right side
                        //after writing each byte onto the display
	Write_CMD_LCD(0x0f);//Enabling the display with blinking cursor

}
void Write_CMD_LCD(char cmd)
{
    rs=0;
	Write_LCD(cmd);
}
void Write_DAT_LCD(char dat)
{
	rs=1;
	Write_LCD(dat);
}
void Write_LCD(char ch)
{
	rw=0;
	LCD_DAT=ch;
	en=1;
	en=0;
	delay_ms(2);
}
void Write_str_LCD(char *p)
{
	while(*p)
		Write_DAT_LCD(*p++);	
}

void Write_int_LCD(signed int n)
{
	char a[10],i=0;
    if(n<0)
	{
		Write_DAT_LCD('-');
		n=-n;
	}
	do                       
	{
		a[i++]=n%10+48;	
		n=n/10;
	}while(n);
    for(i;i>0;i--)
		Write_DAT_LCD(a[i-1]);
}
/*
void Write_float_LCD(float f,char i)
//1st arg(f) is the float number to be displayed  on LCD
//2nd arg(i) is number digits to be displayed after the dot('.')                      
{
    unsigned long int n=f;
	Write_int_LCD(n);
	Write_DAT_LCD('.');
    for(i;i>0;i--)
	{
		f=f*10;
        n=f;	
		Write_DAT_LCD(n%10+48);
	}	
}
*/

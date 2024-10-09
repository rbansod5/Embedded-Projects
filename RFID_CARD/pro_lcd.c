#include <LPC214x.H>
#include "defines.h"
#include "delay.h"
#include "lcd.h"
#include "keypad.h"
//p0.8 - p0.15 pins are connected to lcd data pins
#define LCD_DATA 8
//p0.16 is connected to RS of LCD
#define RS 16
#define RW 18
//p0.17 is connected to EN of LCD
#define EN 17
//void LCD_cmd(char cmd)
char bat[]={0X04,0X04,0X0A,0X0A,0X0A,0X0A,0X0E,0x00};	//BAT
char robo[] = {0x0E,0x0E,0x04,0x0E,0x15,0x04,0x0A,0x0A};//ROBO
char heart[]={0X00,0X00,0X0A,0X15,0X11,0X0E,0X04,0X00};//HAERT
char smile[]={0X00,0X00,0X0A,0X00,0X11,0X0E,0X00,0X00}; //SMILE

void WriteLCD(unsigned char DAT)
{
SCLRBIT(IOCLR0,RW);
WRITEBYTE(IOPIN0,LCD_DATA,DAT);
SSETBIT(IOSET0,EN);
delay_us(1)	 ;
SCLRBIT(IOCLR0,EN);
delay_ms(2);
}

void LCD_Init(void)
{
	WRITEBYTE(IODIR0,LCD_DATA,0XFF);
	WRITEBIT(IODIR0,RS,1);
	WRITEBIT(IODIR0,EN,1);
	delay_ms(16);
	LCD_cmd(0x30);
	delay_ms(5);
	LCD_cmd(0x30);
	delay_ms(1);
	LCD_cmd(0x30);
	delay_ms(1);
	LCD_cmd(0x38);//
	LCD_cmd(0x10);//
	LCD_cmd(0x01);//
	LCD_cmd(0x06);//
	LCD_cmd(0x0F);//0X0E,0X0C	
}

void LCD_cmd(char cmd)
{
	WRITEBYTE(IOPIN0,LCD_DATA,cmd);
	WRITEBIT(IOCLR0,RS,1);
	WRITEBIT(IOSET0,EN,1);
	WRITEBIT(IOCLR0,EN,1);
	delay_ms(2);
}

void LCD_char(char data)
{
	WRITEBYTE(IOPIN0,LCD_DATA,data);
	WRITEBIT(IOSET0,RS,1);
	WRITEBIT(IOSET0,EN,1);
	WRITEBIT(IOCLR0,EN,1);
	delay_ms(2);
}

void LCD_str(char *str)
{
	while(*str != '\0')
	{
		LCD_char(*str);
		str++;
	}
}

void Store_ROBO(void)
{
	int i;
	LCD_cmd(0x48);
	for(i=0;i<8;i++)
		LCD_char(robo[i]);	
}

void CGRAM_BAT(void)

{
	int i;
	LCD_cmd(0x40);
	for(i=0;i<8;i++)
		LCD_char(bat[i]);	
}

void CGRAM_HEART(void)
{
	int i;
	LCD_cmd(0x50);
	for(i=0;i<8;i++)
		LCD_char(heart[i]);
}
void CGRAM_SMILE(void)
{
    int i;
	LCD_cmd(0x58);
	for(i=0;i<8;i++)
		LCD_char(smile[i]);
}
void u32LCD(int n)
{
	signed int i=0;
	unsigned char a[10]="\0";
	SSETBIT(IOSET0,RS);

if(n==0)
{
	WriteLCD('0');
}
else
{
	while(n)
	{
	a[i++]=(n%10)+48;
	n/=10;
	}
	for(--i;i>=0;i--)
	{
	WriteLCD(a[i]);
	}
}
}




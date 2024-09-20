/*
1. Write an ECP to develop the driver for 16*2 alphanumeric LCD.
a) To display a character
b) To display a string
c) To display an integer
d) To display float number up to three decimal places.
e) To display any custom character.
*/
//main.c
#include "types.h"
#include "lcd_defines.h"
#include "defines.h"
#include<LPC21xx.h>
#include "delay.h"
#include "lcd.h"

//u8 a[16]={0X1F,0X04,0X02,0X1F,0X06,0X04,0X02,0X00,0x17,0x14,0x14,0x1f,0x05,0x05,0x1c,0x00};
u8 a[8]={0x0e,0x0e,0x04,0x1f,0x04,0x04,0x0a,0x00};
//0x00,0X1F,0X04,0X02,0X1F,0X06,0X04,0X02,0X00
//0x02,0x0a,0x1f,0x0a,0x02,0x00,0x00
//u8 cgram_lut1[8]={0X00,0X09,0X06,0X1F,0X0A,0X09,0X00};
//0x1d,0x05,0x05,0x1f,0x14,0x14,0x17
int main()
{
	InitLCD();
	CharLCD('A');
	delay_s(1);
	CmdLCD(CLRSCR);
	F32LCD(-12345.6789,3);
	delay_s(1);
	CmdLCD(CLRSCR);
	U32LCD(12345);
	delay_s(1);
	CmdLCD(CLRSCR);
	S32LCD(-12345);
	delay_s(1);
	CmdLCD(CLRSCR);
    StrLCD("CUTE CACTUS");
	delay_s(1);
	CmdLCD(CLRSCR);
	BuildCGRAM(a,8);//swastik character
	CharLCD(0);
	CharLCD(1);
	delay_s(1);
	hexLCD('A',8);
	  /*BinLCD('A',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	  BinLCD('B',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	  BinLCD('C',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	  BinLCD('D',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	  BinLCD('E',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	  BinLCD('F',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	   BinLCD('G',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	   BinLCD('H',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	   BinLCD('I',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	   BinLCD('J',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	   BinLCD('K',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	   BinLCD('L',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	   BinLCD('M',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	   BinLCD('N',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	   BinLCD('O',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	   BinLCD('P',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR); 
	   BinLCD('Q',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR); 
	   BinLCD('R',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR); 
	   BinLCD('S',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR); 
	   BinLCD('T',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR); 
	   BinLCD('U',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR); 
	   BinLCD('V',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR); 
	   BinLCD('W',8);
	  delay_ms(2000);
	   
	   BinLCD('X',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR); 
	   BinLCD('Y',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR); 
	   BinLCD('Z',8);
	  delay_ms(2000);
	  CmdLCD(CLRSCR);
	  */ 
	while(1);
}

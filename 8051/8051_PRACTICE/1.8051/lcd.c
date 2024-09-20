#include<reg51.h>
#include"delay.h"
#include"lcd.h"
#define LCD_DAT P0
  sbit RS=P3^4;
sbit RW=P3^5;
sbit EN=P3^6;

char cgram_lut[]={0x17,0x14,0x14,0x1f,0x05,0x05,0x1d,0x00};
void cmdlcd(char cmd)
{
	RS=0;		// COMMAND REGISTER WILL OPEN
	LCD_DAT=cmd;
	RW=0;		// WRITE MODE, 8 BIT INFO(CMD) IS WRITING ON LCD
	EN=1;
	delay_ms(2);
	EN=0;		// To Process the info
}	
void datalcd(char dat)
{
	RS=1;		// DATA REGISTER WILL OPEN
	LCD_DAT=dat;
	RW=0;		// WRITE MODE, 8 BIT INFO(CMD) IS WRITING ON LCD
	EN=1;
	delay_ms(2);
	EN=0;		// To Process the info
}	
void initlcd(void)
{
	cmdlcd(0x38);//5x7 pixel, 8-bit mode, 2lines
	cmdlcd(0x10);//display off , cursor off
	cmdlcd(0x01);//clear the screen
	cmdlcd(0x0e);//displayon cursor on
	cmdlcd(0x80);//first line first position
}
void strlcd(char *str/*VECTOR*/)
{
	while(*str!='\0')//'V','E','C','T','O','R','\0' -  LOOP FAILS
	{
		datalcd(*str);//1('V')
		str++;//base address will increment
	}
}
void integerlcd(int num )
{
	char a[10], index=0;
	if(num==0)
		datalcd(0+48);
	while(num)//123 is not zero //12 is not zero // 1 is not zero // 0 is zero. So, cond fails,breaks the loop
	{
		a[index++]=num%10;//(1)123%10 = > a[0]=3, index=1  (2)12%10=2 => a[1]=2 , index=2
		//(3)1%10=1 => a[2]=1,index=3
		num=num/10;	//(1) 123/10=12	(2)12/10=1  (3) 1/10=0 
	}
	for(--index;index>=0;index--)//index ==>3-1=2  //2-1=1				//1-1=0
		datalcd(a[index]+48);	//a[2]+48=>1+48='1'//a[1]+48=2+48='2'	//a[0]+48=3+48='3'
}

/* Store Customzied characters hexadecimal values in CGRAM */
void BuildCgram(void)
{
	char i=0;
	cmdlcd(0x40);//CGRAM ADDRESS STARTS FROM 0X40 - 0x47
	for(i=0;i<8;i++)
		datalcd(cgram_lut[i]);
}


 
 
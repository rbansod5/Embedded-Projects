
#include"prototype.h"

void Delay(unsigned int ct)
{
	int i, j;
	for(i = 0; i < ct; i++)
		for(j = 0; j < 5000; j++);
}

void lcd_init(void)
{
	IODIR0 |= LCD_ALL;
//	lcdcmd(0X02);		//return to home
	lcdcmd(0X38);		// 8-bit mode
	lcdcmd(0x0f);		//display on cursor blinking
  	lcdcmd(0X01);  		//Clear display
	lcdcmd(0X80);		//start with beging
}

void lcd_print(char *str)
{
 	while(*str)
	{	
  		lcddata(*str);
		str++;
  	}
}


void lcdcmd(int a)
{	
	IOPIN0 = a << 16;
	IOCLR0 |= LCD_RS;
	IOCLR0 |= LCD_RW;
	IOSET0 = LCD_EN;
	Delay(40);
	IOCLR0 = LCD_EN;
	Delay(40);	 		  
} 

void lcddata(unsigned char b)
{
	IOPIN0 = b << 16;
	
	IOCLR0 |=LCD_RW;
	IOSET0 |= LCD_RS;
	IOSET0 = LCD_EN;
	Delay(10);
	IOCLR0 = LCD_EN;
	Delay(10);
}

void display(int dig)
{		
	if(dig)
		display(dig / 10); 
	lcddata((dig % 10)+0x30);  

}



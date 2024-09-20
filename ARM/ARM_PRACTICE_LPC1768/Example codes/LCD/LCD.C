							

  #include<lpc17xx.h>



#define LCD0						(0 << 15)
#define LCD1						(0 << 16)
#define LCD2						(0 << 17)
#define LCD3						(0 << 18)
#define LCD4						(0 << 19)
#define LCD5						(0 << 20)
#define LCD6						(0 << 21)
#define LCD7						(0 << 22)
#define LCD_EN					(0 << 11)
//#define LCD_RW					(1 << 12)
#define LCD_RS					(0 << 10)					   
#define LCD_ALL					(LCD0|LCD1|LCD2|LCD3|LCD4|LCD5|LCD6|LCD7|LCD_EN|LCD_RS)

void lcd_init(void);
void lcdcmd(int a);
void lcddata(unsigned char b);
void lcd_print(char *);
void display(int dig);
void Delay(unsigned int );


	  int main()
{

	LPC_GPIO0->FIODIR  |= LCD_ALL;
 	LPC_PINCON->PINSEL0 |= 0x00000000;
//	IODIR0 |= LCD_ALL;

	lcd_init();
	while(1)
	{
	lcdcmd(0x01);
	lcdcmd(0x80);
	lcd_print("CRANES SOFTWARE");
	Delay(50);
	
	lcdcmd(0x01);
	lcdcmd(0x80);
	lcd_print("BENGALURU");
	Delay(20);
	lcdcmd(0x01);
	}
}




 void Delay(unsigned int ct)
{
	int i, j;
	for(i = 0; i < ct; i++)
		for(j = 0; j < 5000; j++);
}

void lcd_init(void)
{
	LPC_GPIO0->FIODIR |= LCD_ALL;
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
LPC_GPIO0->	FIOPIN0 = a << 15;
LPC_GPIO0->	FIOCLR0 |= LCD_RS;
//LPC_GPIO1->	FIOCLR0 |= LCD_RW;
LPC_GPIO0->	FIOSET0 = LCD_EN;
	Delay(200);
LPC_GPIO0->	FIOCLR0 = LCD_EN;
	Delay(200);	 		  
} 

void lcddata(unsigned char b)
{
LPC_GPIO0->	FIOPIN0 = b << 15;
	
//LPC_GPIO1->	FIOCLR0 |=LCD_RW;
LPC_GPIO0->	FIOSET0 |= LCD_RS;
LPC_GPIO0->	FIOSET0 = LCD_EN;
	Delay(200);
LPC_GPIO0->	FIOCLR0 = LCD_EN;
	Delay(200);	
}

void display(int dig)
{		
	if(dig)
	{
		display(dig / 10); 
		lcddata((dig % 10)+0x30);  
	}
}









/*LCD, RS->P0.10,  EN->P0.11
       DATA->P0.15 TO P0.22*/


#define RS      (1<<10)
#define EN	(1<<11)
#define DATA    (0xFF<<15)



void delay1(unsigned int a);
void lcd_config(void);
void lcd_cmd(unsigned char c);
void lcd_data(unsigned char d);
void lcd_str(unsigned char *ptr);



void lcd_config(void)
{
LPC_GPIO0->FIODIR|=RS|EN|DATA;

lcd_cmd(0x38);
lcd_cmd(0x0E);
lcd_cmd(0x01);
lcd_cmd(0x80);
}

void lcd_cmd(unsigned char c)
{
LPC_GPIO0->FIOCLR=DATA;
LPC_GPIO0->FIOSET=(c<<15);
LPC_GPIO0->FIOCLR=RS;
LPC_GPIO0->FIOSET=EN;
delay1(50);
LPC_GPIO0->FIOCLR=EN;
}

void lcd_data(unsigned char d)
{
LPC_GPIO0->FIOCLR=DATA;
LPC_GPIO0->FIOSET=(d<<15);
LPC_GPIO0->FIOSET=RS;
LPC_GPIO0->FIOSET=EN;
delay1(50);
LPC_GPIO0->FIOCLR=EN;
}

void lcd_str(unsigned char *ptr)
{
	while(*ptr !='\0')
	{
	lcd_data(*ptr);
	ptr++;
	}
}

void lcd_num(unsigned int num)
{
	if(num)
	{
	lcd_num(num/10);
	lcd_data(num%10+0x30);
	}
}

void delay1(unsigned int a)
{
unsigned int i,j;

	for(i=0;i<a;i++)
	for(j=0;j<1000;j++);
}

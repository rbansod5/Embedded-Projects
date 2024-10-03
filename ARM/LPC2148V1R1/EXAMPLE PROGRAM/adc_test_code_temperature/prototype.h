
#include<lpc21xx.h>	  /* LPC2129 Header File */ 


#define LCD0						(1 << 16)
#define LCD1						(1 << 17)
#define LCD2						(1 << 18)
#define LCD3						(1 << 19)
#define LCD4						(1 << 20)
#define LCD5						(1 << 21)
#define LCD6						(1 << 22)
#define LCD7						(1 << 23)
#define LCD_EN					(1 << 13)
#define LCD_RW					(1 << 12)
#define LCD_RS					(1 << 10)					   
#define LCD_ALL					(LCD0|LCD1|LCD2|LCD3|LCD4|LCD5|LCD6|LCD7|LCD_EN|LCD_RW|LCD_RS)

void Delay(unsigned int c);


//-----For LCD-----

void lcd_init(void);
void lcdcmd(int a);
void lcddata(unsigned char b);
void lcd_print(char *);
void display(int dig);
void Delay(unsigned int );




#define CH (1 << 1)
#define CLK_DIV (3 << 8)
#define BST_ON (1 << 16)
#define BST_OFF (0 << 16)
#define CLK_RES (0 << 17)
#define OPERATIONAL (1 << 21)
#define START (1 << 24)

#define adc0_init_macro (CH | CLK_DIV | BST_ON | CLK_RES | OPERATIONAL)
		
void adc0_init_temperature(void);
int adc_read_value_temperature(void);

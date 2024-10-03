
#include<lpc21xx.h>


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




//-----For LCD-----

void lcd_init(void);
void lcdcmd(int a);
void lcddata(unsigned char b);
void lcd_print(char *);
void display(int dig);
void Delay(unsigned int );


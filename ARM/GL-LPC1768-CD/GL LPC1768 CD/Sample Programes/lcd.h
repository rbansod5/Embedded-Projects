#ifndef _LCD_H
#define _LCD_H

#include "lpc17xx.h"
#include "type.h"

#define MAX_CHAR_IN_ONE_LINE 16

#define LCD_BACK_LIGHT_TIMEOUT 1000

#define LCD_BACKLIGHT (1 << 21)

#define LCD_BACK_LIGHT_DIR LPC_GPIO1->FIODIR
#define LCD_BACK_LIGHT_SET LPC_GPIO1->FIOSET
#define LCD_BACK_LIGHT_CLR LPC_GPIO1->FIOCLR

#define LCD_DATA_DIR	   LPC_GPIO2->FIODIR
#define LCD_DATA_SET	   LPC_GPIO2->FIOSET
#define LCD_DATA_CLR	   LPC_GPIO2->FIOCLR

#define LCD_CTRL_DIR	   LPC_GPIO1->FIODIR
#define LCD_CTRL_SET       LPC_GPIO1->FIOSET
#define LCD_CTRL_CLR       LPC_GPIO1->FIOCLR

#define LCDRS	           (1 << 24)
#define LCDRW	           (1 << 23)
#define LCDEN	           (1 << 22)

#define LCD_D4 (1 << 4)
#define LCD_D5 (1 << 5)
#define LCD_D6 (1 << 6)
#define LCD_D7 (1 << 7)

#define LCD_DATA_MASK           (LCD_D4 | LCD_D5 | LCD_D6 | LCD_D7)
#define LCD_BUSY_FLAG           LCD_D7

//#define LCD_CONTROL_MASK        0x01C00000

enum ROW_NUMBERS
{
  LINE1,
  LINE2	
};

void init_lcd(void);
void lcd_putstring(unsigned char line, char *string);
void lcd_clear(void);
void lcd_backlight_on(void);
void lcd_backlight_off(void);
int lcd_gotoxy(unsigned int x, unsigned int y);
void lcd_putchar(int c);
void process_keyboard(void);
uint8_t xgetkey(void);
uint8_t is_valid_ascii(int8_t key);
#endif

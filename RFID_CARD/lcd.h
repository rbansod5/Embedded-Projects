#ifndef _LCD_H_
#define _LCD_H_

void LCD_Init(void);
void LCD_cmd(char);
void LCD_char(char);
void LCD_str(char *);
void u32LCD(int);
void Store_ROBO(void);
void CGRAM_BAT(void);
void CGRAM_HEART(void);
void CGRAM_SMILE(void);

#endif


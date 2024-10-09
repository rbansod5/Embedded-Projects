#ifndef __KEYPAD_H__s
#define __KEYPAD_H__

unsigned int colscan(void);
void initrows(void);
void initcols(void);
unsigned char keyscan(void);
void LCD_pwd(void);

#endif


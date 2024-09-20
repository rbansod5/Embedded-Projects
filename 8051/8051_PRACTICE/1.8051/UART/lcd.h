#ifndef lcd_h
#define lcd_h

extern void write_lcd(unsigned char);
extern void cmd_lcd(unsigned char);
extern void putc_lcd(unsigned char);
extern void init_lcd();
extern void build_cgram(char *,unsigned char);
extern void str_lcd(unsigned char *);
extern void int_lcd(unsigned int);
extern void float_lcd(float);

#endif

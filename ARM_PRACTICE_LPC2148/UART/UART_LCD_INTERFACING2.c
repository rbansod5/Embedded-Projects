#include<lpc21xx.h>
#include"lcd.h"
#include"lcd_defines.h"
#include"uart.h"
#include"delay.h"
 char a[8]={0x00,0x04,0x0a,0x10,0x10,0x10,0x80,0x00};
int main()
{
u8 X;
InitLCD();
InitUART0();
while(1)
{
// U0TXCHAR(X);
 CmdLCD(0x80);
 BuildCGRAM(a,8);
 delay_s(1);
// CharLCD(X);

 }
 }

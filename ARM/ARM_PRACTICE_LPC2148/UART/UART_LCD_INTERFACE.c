#include<lpc21xx.h>
#include"lcd.h"
#include"lcd_defines.h"
#include"uart.h"
#include"delay.h"
u8 ch;
int main()
{
InitUART0();
InitLCD();

while(1)
{
ch=U0RXCHAR();
U0TXCHAR(ch);
delay_s(1);
CmdLCD(0x80);
CharLCD(ch);
delay_ms(200);
}
}



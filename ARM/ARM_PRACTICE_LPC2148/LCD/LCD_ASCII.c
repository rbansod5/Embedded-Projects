 
/* 
 11. Write an ECP to display the ASCII table information for A-Z, a-z & 0-9 on LCD
screen with respect to 5 seconds.
For example,
1 st line: A D H O
2 nd line: A 65 41 101
1 st line: A D H O
2 nd line: B 66
After 5 secs
42 102 and so on ....

*/

#include "types.h"
#include "lcd_defines.h"
#include "defines.h"
#include<LPC21xx.h>
#include "delay.h"
#include "lcd.h"

int main()
{
u8 i;

InitLCD();
CmdLCD(0x80);
StrLCD("A  D  H    O");
/*CmdLCD(0x80);
CharLCD('A');
delay_ms(200);
//InitLCD();
CmdLCD(0x82);
CmdLCD('A');
delay_ms(200);
//InitLCD();
CharLCD(0x85);
CmdLCD('A');
delay_ms(200);
//InitLCD();
CmdLCD(0x80+11);
CharLCD('O');
  */
while(1)
{
StrLCD("A  D  H    O");
for(i=48;i<=57;i++)
{
CmdLCD(0xC0);
CharLCD(i);
CmdLCD(0xC2);
U32LCD(i);
CmdLCD(0xC6);
HexLCD(i);
CmdLCD(0xC0+11);
OctLCD(i);
delay_s(1);
//CmdLCD(0x01);
}
for(i=65;i<=90;i++)
{
CmdLCD(0xC0);
CharLCD(i);
CmdLCD(0xC2);
U32LCD(i);
CmdLCD(0xC6);
HexLCD(i);
CmdLCD(0xC0+11);
OctLCD(i);
delay_s(1);
//CmdLCD(0x01);
}
for(i=97;i<=122;i++)
{
CmdLCD(0xC0);
CharLCD(i);
CmdLCD(0xC2);
U32LCD(i);
CmdLCD(0xC6);
HexLCD(i);
CmdLCD(0xC0+11);
OctLCD(i);
delay_s(1);
//CmdLCD(0x01);
}
delay_s(1);
CmdLCD(0x01);
}
}

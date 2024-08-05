/*
9. Write a program to display the message “VECTOR” on the first Line and “Institute”
on the second line of a 2x16 LCD. Then make “Institute” scroll from right to left on
second line of LCD screen.

*/

#include<lpc21xx.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
#include"lcd.h"
#include"lcd_defines.h"
int main()
{
u8 i,j;
InitLCD();
while(1)
{

for(i=0,j=17;i<=17,j>0;j--,i++)
{
CmdLCD(0x80+j);
StrLCD("VECTOR");
CmdLCD(0xC0+i);                                                                                                                                                                                              
StrLCD("INSTITUTE");
delay_ms(500);
CmdLCD(0x01);
}
for(i=0,j=17;i<=17,j>0;j--,i++)
{
CmdLCD(0x80+i);
StrLCD("VECTOR");
CmdLCD(0xC0+j);                                                                                                                                                                                              
StrLCD("INSTITUTE");
delay_ms(500);
CmdLCD(0x01);
}
}
}

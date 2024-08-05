/*
 2. Write a program to display the message “VECTOR” on the first Line and “Institute”
on the second line of a 2x16 LCD. Then make “Institute” flash at the rate of 1sec for 5
times, then clear the LCD screen

*/
#include<lpc21xx.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
#include"lcd.h"
#include"lcd_defines.h"

int main()
{
u8 i;
InitLCD();
while(1)
{
CmdLCD(0x80);
StrLCD("VECTOR");
for(i=0;i<=5;i++)
{
delay_ms(5);                                                                                                                                                                                              
StrLCD("INSTITUTE");
CmdLCD(0x01);
}
CmdLCD(0x01);
}
}






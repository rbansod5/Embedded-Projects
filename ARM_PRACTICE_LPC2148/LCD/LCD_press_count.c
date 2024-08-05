//5. Write an ECP to display the switch press count on LCD.
#include<lpc21xx.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
#include"lcd.h"
#include"lcd_defines.h"

int main()
{
static u8 cnt=0;
InitLCD();
while(1)
{
if(READBIT(IOPIN0,0)==1)
{
while(READBIT(IOPIN0,0)==1);
cnt++;
CmdLCD(0x80);
U32LCD(cnt);
delay_s(1);
CmdLCD(0x01);
}
}
}

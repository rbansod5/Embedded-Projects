 //main_sms_kpm_lcd.c

#include<LPC21XX.h>
#include"types.h"
#include"defines.h"
#include"lcd.h"
#include"kpm_defines.h"
#include"sms_keypad.h"
#include"lcd_defines.h"
#include"delay.h"
#define LED 19//p0.19
extern s32 presskey,khcount;
main()
{
u32 dly_ms=250;
s32 pos=-1;
InitLCD();
InitKpm();
StrLCD("sms keypad:");
while(1)
{
khcount=-1;
while(ColScan());
for(dly_ms=12000*250;dly_ms>0;dly_ms--)
{
WRITENIBBLE(IOPIN1,Row0,0);
if(!ColScan())
 {
 if(khcount==3)
 khcount=-1;
 else if (khcount==-1)
 {
 pos++;
 if(pos>15)
 {
 CmdLCD(GOTO_LINE2_POS0);
 StrLCD("                ");
 CmdLCD(0XC0);
 pos=0;
 }
 }
 khcount++;
 presskey=KeyScan();
 CmdLCD((0xC)+pos);
 CharLCD(presskey);
 while(!ColScan())
 dly_ms=12000*250;
 }
 }
 }
 }

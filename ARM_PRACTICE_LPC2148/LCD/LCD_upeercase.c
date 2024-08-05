/*

10. Write an ECP to convert first character of each word in to upper case and display the
final result on LCD.
Note: Connect two switches. Based on first switch press, take “vector india” as input and
do the operation; Based on second switch press, take “vector Hyderabad” as input and do
the operation. In both cases print input and output on lcd screen.
Embedded-C AssignmentsOutput:
When Switch1 is pressed, display “vector india” on the 1 st line of LCD and when the
switch1 is released display “Vector India” on the 2 nd line of LCD.
When Switch2 is pressed, display “vector hyderabad” on the 1 st line of LCD and when
the switch2 is released display “Vector Hyderabad” on the 2 nd line of LCD.
If none of the switch is pressed, display “waiting for input” on the 1 st line of LCD.

*/


    
#include "types.h"
#include "lcd_defines.h"
#include "defines.h"
#include<LPC21xx.h>
#include "delay.h"
#include "lcd.h"
#include<string.h>

#define SW1 0
#define SW2 1

int main()
{
InitLCD();
while(1)
{
u8 str[30],i;
str="rahul bansod";
if(READBIT(IOPIN0,0)==0)
{
while(READBIT(IOPIN0,0)==0);
CmdLCD(0x80);
StrLCD("rahul bansod");
}
delay_ms(20);
if(READBIT(IOPIN0,1)==0)
{
while(READBIT(IOPIN0,1)==0);
CmdLCD(0xC0);
StrLCD("waiting for output...");
 if(str[0]>=97&&str[0]<=122)
        {
                str[i]-=32;
                i++;
        }
        while(str[i])
        {
                if(str[i]==32)
                {
                        str[i+1]-=32;

                        if(islower(str[i+1]!=0))
                        {
                                str[i+1]-=32;
                        }
                }

		  }
		  CmdLCD(0xC0);
		  StrLCD(str);
}


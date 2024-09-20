/* 
13. Write an ECP to convert first and last character of each word in to upper case and display the final result on LCD.
Note: Connect two switches. Based on first switch press, take “vector india” as input and do the operation; Based on second switch press, take “vector Hyderabad” as 
input and do the operation. In both cases print input and output on lcd screen.
Output:
When Switch1 is pressed, display “vector india” on the 1st line of LCD and when the switch1 is released display “VectoR IndiA” on the 2nd line of LCD. 
When Switch2 is pressed, display “vector hyderabad” on the 1st line of LCD and when the switch2 is released display “VectoR HyderabaD” on the 2nd line of LCD. 
If none of the switch is pressed, display “waiting for input” on the 1st line of LCD.
*/

#include "types.h"
#include "lcd_defines.h"
#include "defines.h"
#include<LPC21xx.h>
#include "delay.h"
#include "lcd.h"
#include<string.h>
#include<stdlib.h>

#define SW1 0
#define SW2 1

int main()
{
u8 i=0,cnt;
char str1[30]="vector india";
char str2[30]="vector hyderabad";
InitLCD();
while(1)
{
if(READBIT(IOPIN0,SW1)==0)

{
while(READBIT(IOPIN0,SW1)==0);
cnt=0;
for(i=0;i<=strlen(str1)-1;i++)
{
CmdLCD(0x80+cnt);
cnt++;
CharLCD(str1[i]);
}
//CmdLCD(0x01);
i=0;
if(str1[0]>=97&&str1[0]<=122)
        {
                str1[0]-=32;
                i++;
        }
        while(str1[i])
        {
                if(str1[i]==32)
                {
                        str1[i+1]-=32;
                        str1[i-1]-=32;       
                }
				
				i++;

		  }
		  if(str1[i]==0)
				{
                        str1[i-1]-=32;    
                }
		  //CmdLCD(0xC0);
		  //CmdLCD(CLRSCR);
		  cnt=0;
		  for(i=0;i<=strlen(str1)-1;i++)
		  {
		  
		  CmdLCD(0xC0+cnt);
		  cnt++;
		  CharLCD(str1[i]);
		  //CmdLCD(0x01);
		  }
delay_s(2);
CmdLCD(0x01);		  
}


if(READBIT(IOPIN0,SW2)==0)
{
while(READBIT(IOPIN0,SW2)==0);

//CmdLCD(0x80);
cnt=0;
for(i=0;i<=strlen(str2)-1;i++)
{
CmdLCD(0x80+cnt);
cnt++;
CharLCD(str2[i]);
}
//CmdLCD(0x01);

  i=0;
 if(str2[0]>=97&&str2[0]<=122)
        {
                str2[0]-=32;
                i++;
        }
        while(str2[i])
        {
                if(str2[i]==32)
                {
                        str2[i+1]-=32;
						str2[i-1]-=32;
				}

                
				i++;

		  }
		  if(str2[i]==0)
				{
                        str2[i-1]-=32;
                        
                }
		 // CmdLCD(0xC0);
		  //CmdLCD(CLRSCR);
		  cnt=0;
		  for(i=0;i<=strlen(str2)-1;i++)
		  {
		  
		  CmdLCD(0xC0+cnt);
		  cnt++;
		  CharLCD(str2[i]);
		  //CmdLCD(0x01);
		  }
		  delay_s(2);
CmdLCD(0x01);
}

}
}


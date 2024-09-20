/* 
 14. Write an ECP to remove extra spaces in a given string and display the final result
  on LCD.
Note: Connect two switches. Based on first switch press, take “ An  Apple a day” as 
input and do the operation; Based on second switch press, take “ vector   stu  !” as 
input and do the operation. In both cases print input and output on lcd screen.
Output:
When Switch1 is pressed, display “ An  Apple a day” on the 1st line of LCD and when 
the switch1 is released display “An Apple a day” on the 2nd line of LCD. 
When Switch2 is pressed, display “ vector   stu  !” on the 1st line of LCD and when 
the switch2 is released display “vector stu !” on the 2nd line of LCD. 
If none of the switch is pressed, display “waiting for input” on the 1st line of LCD.
*/
#include<lpc21xx.h>
#include<string.h>
#include<stdlib.h>
#include "types.h"
#include "lcd_defines.h"
#include "defines.h"
#include "delay.h"
#include "lcd.h"
#define SW1 0
#define SW2 1
int main()
{
s8 str1[]="An  Apple  a day" ;
s8 str2[]="vector   stu   !";
        u32 i=0,cnt;

InitLCD();
while(1)
{
        
		          
if(READBIT(IOPIN0,SW1)==0)
 {      
 //while(READBIT(IOPIN0,SW2)==0);
  cnt=0;
for(i=0;i<=strlen(str1)-1;i++)
{
CmdLCD(0x80+cnt);
cnt++;
CharLCD(str1[i]);
}
i=0;
        while(str1[0]==32)
                memmove(str1,str1+1,strlen(str1+1)+1);
        while(str1[i])
        {
                if((str1[i]==32)&&(str1[i+1]==32))
                {
                        memmove(str1+i,str1+i+1,strlen(str1+i+1)+1);
                i--;
        }
        i++;
        }

        if(str1[strlen(str1)-1]==32)
                str1[i-1]=0;
        //CmdLCD(CLRSCR);
		  cnt=0;
		  
		  for(i=0;i<=strlen(str1)-1;i++)
		  {
		  
		  CmdLCD(0xc0+cnt);
		  cnt++;
		  CharLCD(str1[i]);
		  }	
		 // CmdLCD(0xC0);
		  //StrLCD(str2);
		  delay_s(2);
}
		          
if(READBIT(IOPIN0,SW2)==0)
 {      
 //while(READBIT(IOPIN0,SW2)==0);
  cnt=0;
for(i=0;i<=strlen(str2)-1;i++)
{
CmdLCD(0x80+cnt);
cnt++;
CharLCD(str2[i]);
}
i=0;
        while(str2[0]==32)
                memmove(str2,str2+1,strlen(str2+1)+1);
        while(str2[i])
        {
                if((str2[i]==32)&&(str2[i+1]==32))
                {
                        memmove(str2+i,str2+i+1,strlen(str2+i+1)+1);
                i--;
        }
        i++;
        }

        if(str2[strlen(str2)-1]==32)
                str2[i-1]=0;
        //CmdLCD(CLRSCR);
		  cnt=0;
		  
		  for(i=0;i<=strlen(str2)-1;i++)
		  {
		  
		  CmdLCD(0xc0+cnt);
		  cnt++;
		  CharLCD(str2[i]);
		  }
		  delay_s(2);	
		 // CmdLCD(0xC0);
		  //StrLCD(str2);
}

CmdLCD(0x01);
StrLCD("waiting 4 input");
delay_s(1);
}

}


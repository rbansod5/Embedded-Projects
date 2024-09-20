#include<lpc21xx.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
#include"lcd.h"
#include<string.h>
#include<stdlib.h>
int main()
{		   InitLCD();
while(1)
{
        char str[100]="malayalam";
  
        int i,j,k;
		for(k=0;str[k];k++)
		{
		CmdLCD(0x80+k);
		CharLCD(str[k]);
		}
        if(str[strlen(str)-1]==10)
        {
                str[strlen(str)-1]=0;
        }
        for(i=0,j=strlen(str)-1;i<=j;i++,j--)
                if(str[i]!=str[j])
                        break;
        if(i>j)
		{
		CmdLCD(0xC0);
                StrLCD("palindrome");
		}
        		 else
				 {
				 CmdLCD(0xC0);
                StrLCD("not palindrom");
				}


			
}
}

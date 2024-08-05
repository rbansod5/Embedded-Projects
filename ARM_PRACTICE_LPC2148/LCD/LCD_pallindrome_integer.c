/* 
 
 Write an ECP to take ten 3-digit numbers randomly in an array and find palindrome
numbers in the list of numbers to display on LCD.
Note: must use rand() function

*/

#include<lpc21xx.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
#include"lcd.h"

int main()
{
	int i,min=1,max=999,rev=0,rem,temp;
	InitLCD();
	while(1)
	{
	for(i=min;i<=max;i++)
	{
		temp=i;
		rev=0;
		while(temp)
		{
			rem=temp%10;
			rev=rev*10+rem;
			temp=temp/10;
		}
		if(i==rev)
		{
			CmdLCD(0xC0);
			U32LCD(i);
			delay_ms(200);
			CmdLCD(0x01);
		}
		CmdLCD(0x80);
		StrLCD("palindrome interger");

	}
	}
}

/*
6. Write an ECP to take 20 numbers randomly in an array and find the prime numbers in
the list of numbers to display on LCD.
Note: must use rand() function
*/
#include<lpc21xx.h>
#include<math.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
#include"lcd.h"
#include"lcd_defines.h"

 int Isprime(u32 num)
{
u8 i;
	for(i=2;i<=sqrt(num);i++)
		if(num%i==0)
		
		return 0; 
		
		return 1;
	
}

int main()
{
while(1)
{
u8 j,a[30];
InitLCD();
a[j]=rand()%100;
for(j=0;j<=30;j++)
{
	if(Isprime(a[j]==1))
	{
	U32LCD(a[j]);
	delay_s(1);
	CmdLCD(0x01);
	}
  }
}}

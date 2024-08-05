   /*

10. Write an ECP to convert first character of each word in to upper case and display the
final result on LCD.
Note: Connect two switches. Based on first switch press, take ?vector india? as input and
do the operation; Based on second switch press, take ?vector Hyderabad? as input and do
the operation. In both cases print input and output on lcd screen.
Embedded-C AssignmentsOutput:
When Switch1 is pressed, display ?vector india? on the 1 st line of LCD and when the
switch1 is released display ?Vector India? on the 2 nd line of LCD.
When Switch2 is pressed, display ?vector hyderabad? on the 1 st line of LCD and when
the switch2 is released display ?Vector Hyderabad? on the 2 nd line of LCD.
If none of the switch is pressed, display ?waiting for input? on the 1 st line of LCD.

*/
	#include<reg51.h>
	#include"delay.h"
	#include"lcd.h"
	#include"uart.h"
	#include<string.h>
	sbit sw1=P0^0;
	sbit sw2=P0^1;
main()
{
char str[30]={"rahul bansod"};	
int i=0;
initlcd();
while(1)
{

if(sw1==0)
{
while(sw1==0);
cmdlcd(0x80);
 
strlcd("rahul bansod");
}
delay_ms(500);
if(sw2==0)
{
while(sw2==0);
cmdlcd(0xC0);
strlcd("waiting for output");
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

                        str[i-1]-=32;

                }
			 i++;
		  }
		  if(str[i]=='\0')
		  {
		  str[i-1]-=32;
		  }
			//charlcd(0x01);
		   for(i=0;i<12;i++)
		  {
		  cmdlcd(0x94+i);
		  datalcd(str[i]);
		  delay_ms(100);
		  }

}

}
}

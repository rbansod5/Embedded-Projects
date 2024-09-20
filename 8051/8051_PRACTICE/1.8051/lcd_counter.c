			   		      #include<reg51.h>
	#include"delay.h"
	#include"lcd.h"
	#include"uart.h"
					sbit sw1=P0^0;
					sbit sw2=P0^1;
main()
{	
	int cnt=0;
initlcd();

while(1)
{
  cmdlcd(0x80);
  strlcd("switch 1 for count++");
  cmdlcd(0xc0);
  strlcd("switch 2 for count--");

  if(sw1==0)
  {
  cnt++;
 
  cmdlcd(0x94);
   //cmdlcd(0x01);
	integerlcd(cnt);
 }
 if(sw2==0)
 {
 cnt--;

 cmdlcd(0xd4);
  //cmdlcd(0x01);
 integerlcd(cnt);
 }
}
}
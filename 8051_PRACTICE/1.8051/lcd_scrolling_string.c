
  	#include<reg51.h>
	#include"delay.h"
	#include"lcd.h"
	#include"uart.h"
	sbit sw1=P0^0;
	sbit sw2=P0^1;
main()
{	
	int i,j;
initlcd();
   while(1)
   {
   for(i=0,j=20;i<14;i++,j--)
   {
   cmdlcd(0x01);
   cmdlcd(0x80+i);
   strlcd("vector");
  // delay_ms(1000);


   cmdlcd(0xc0+j);
   strlcd("vector");
   //delay_ms(1000);
   cmdlcd(0x94+i);
   strlcd("vector");
  // delay_ms(1000);
   cmdlcd(0xd4+j);
   strlcd("vector");
   delay_ms(1000);
    
   }
   }
   }
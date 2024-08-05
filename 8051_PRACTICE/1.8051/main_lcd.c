    #include<reg51.h>
	#include"delay.h"
	#include"lcd.h"
	#include"uart.h"

main()
{	int cnt=1;
   // char ch;
	initlcd(); 
 	 while(1)
	 {
	 while(1)
	 {
	 if((cnt%1)==0)
	{
	 cmdlcd(0x80);
	datalcd('A');
	delay_ms(1000);
	cmdlcd(0x01);
	cmdlcd(0x80);
	cnt++;	 
	}
	if((cnt%2)==0)
	{
	cmdlcd(0xc0);
	strlcd("AMMA I LOVE U");
	delay_ms(1000);
	cmdlcd(0x01);
	cnt++;
	}
	if((cnt%3)==0)
	{
	cmdlcd(0x94);
	integerlcd(1546);
	delay_ms(1000);
	cmdlcd(0x01);
	cmdlcd(0x80);
	cnt++;
	 
	}
	if((cnt%4)==0)
	 {
	cmdlcd(0xd4);
	strlcd("testing done");
	delay_ms(1000);
	cmdlcd(0x01);
	cmdlcd(0x80);
	cnt++; 
	}
	
	if(cnt>=16)
	break;

}	
	}

	  }
 
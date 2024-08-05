/*Write an ECP for displaying the binary equivalent of
key value on 8-LEDs using 4X4 keypad matrix*/
/*
 [sw1  sw2  sw3  sw4      [0   1   2   3 
  sw5  sw6  sw7  sw8     ; 4   5   6   7
  sw9  sw10 sw11 sw12      8   9   10  11 
  sw13 sw14 sw15 sw16 ]    12  13  14  15}*/
#include"delay.h"
#include"lcd.h"
#include"keypad.h"
main()
{
	char ch;
	char p[20];
	char i=0;
	LCD_Init();//LCD initialization
	Write_CMD_LCD(0x80);//selecting starting line and staring 	//pos
	while(1)
	{	 
	while((ch=keyvalue())!='#') 
	{
	p[i]=ch;
	i++;
	}
	 p[i-1]='\0';
	                                                                
		delay_ms(200);
       	Write_str_LCD(p);
     }
}

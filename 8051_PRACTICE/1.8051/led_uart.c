#include<reg52.h>
#include"delay.h"
#include"uart.h"
#include"lcd.h"
#define LED P1
main()
{
  unsigned char ch,str[20],i=0;
  UART_Init();
  initlcd();									
  while(1)
  {	
  i=0;
  
   while((ch=UART_Rxchar())!='\n')
  {	 	 
   //cmdlcd(0x80+i);
  str[i]=ch;
  UART_Txchar(ch);
  //datalcd(str[i]);
  i++;
  }	 
str[i-1]='\0';
cmdlcd(0x80);
cmdlcd(0x01);
strlcd(str);
delay_ms(1000);
  }
}

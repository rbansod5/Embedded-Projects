#include<reg52.h>
#include"delay.h"
#include"uart.h"
#include"lcd.h"

  
void voting(void)
{
char ch;

cmdlcd(0x01);
cmdlcd(0x80);
 strlcd("1.BJP 2.CONGRESS ");
 cmdlcd(0xc0);
 strlcd("3.LOCAL PARTY 4.NOTA");
delay_ms(1000);
cmdlcd(0x01);
cmdlcd(0x94);
strlcd("please enter party");
//ch=UART_Rxchar();
ch=keyscan();
delay_ms(1000);
cmdlcd(0x01);
strlcd("watting....");
delay_ms(2000);

switch(ch)
{
case '1':
cmdlcd(0x01);
cmdlcd(0x80);
strlcd("ayega to modi hi");
delay_ms(5000);
cmdlcd(0x01);
break;
case '2':
cmdlcd(0x01);
cmdlcd(0xc0);
strlcd("rahul gandhi zindabad");
delay_ms(5000);
cmdlcd(0x01);
break;
case '3':
cmdlcd(0x01);
cmdlcd(0xc0);
strlcd("local party");
delay_ms(5000);
cmdlcd(0x01);
break;
case '4':
cmdlcd(0x01);
cmdlcd(0xc0);
strlcd("nota nota nota");
delay_ms(5000);
cmdlcd(0x01);
break;
}
 }
void pan(void)
{
char ch;


cmdlcd(0x01);
cmdlcd(0x80);
 strlcd("name ");
 cmdlcd(0xc0);
 strlcd("card number");
delay_ms(1000);
cmdlcd(0x94);
strlcd("please enter option");
ch=UART_Rxchar();
delay_ms(1000);
cmdlcd(0x01);
strlcd("watting....");
delay_ms(2000);

switch(ch)
{
case '1':
cmdlcd(0x01);
cmdlcd(0x80);
strlcd(" rahul");
delay_ms(5000);
cmdlcd(0x01);
break;
case '2':
cmdlcd(0x01);
cmdlcd(0xc0);
strlcd(" cdtpb0669l");
delay_ms(5000);
cmdlcd(0x01);
break;
}
 }
 void atm(void)
{
char ch;


cmdlcd(0x01);
cmdlcd(0x80);
 strlcd("ballance ");
 cmdlcd(0xc0);
 strlcd("withdraw");
delay_ms(1000);
cmdlcd(0x94);
cmdlcd(0x01);
strlcd("please enter option");
ch=UART_Rxchar();
delay_ms(1000);
cmdlcd(0x01);
strlcd("watting....");
delay_ms(2000);

switch(ch)
{
case '1':
cmdlcd(0x01);
cmdlcd(0x80);
strlcd(" 500000");
delay_ms(5000);
cmdlcd(0x01);
break;
case '2':
cmdlcd(0x01);
cmdlcd(0xc0);
strlcd(" not permitted");
delay_ms(5000);
cmdlcd(0x01);
break;
}
 }
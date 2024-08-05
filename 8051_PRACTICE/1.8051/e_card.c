#include<reg52.h>
#include"delay.h"
#include"uart.h"
#include"lcd.h"
 #include"e_card_function.h"
 #include"keypad.h"

int main()
{
char ch=0;
UART_Init();
initlcd();
  while(1)
{
cmdlcd(0x01);
cmdlcd(0x80);
strlcd("1.VOTING 2.PAN");
cmdlcd(0xc0);
strlcd("3.ATM 4.EXIT");
delay_ms(5000);
 
cmdlcd(0x01);
cmdlcd(0x80);
strlcd("wating...");
delay_ms(2000);
//ch=UART_Rxchar();
ch=keyscan();
switch(ch)
{
case '1': strlcd(" FOR VOTING..."); cmdlcd(0x01);delay_ms(3000);voting();break;
case '2': strlcd("FOR PAN DETAILS");cmdlcd(0x01);delay_ms(3000); pan();break;
case '3': strlcd("FOR ATM...");	delay_ms(3000);cmdlcd(0x01);atm();break;
case '4':strlcd("EXIT...");	delay_ms(3000);break;
}
}
}
#include<reg51.h>
#include"delay.h"
#include"uart.h"
#include"lcd.h"
#include"e_card_function.h"
#include"i2c_defines.h"
#include"i2c.h"
#include"keypad.h"

int main()
{

UART_Init();
initlcd();
  while(1)
{
char ch=0;
//lable:
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
while((ch=UART_Rxchar())==0);
//ch=key_val();
switch(ch)
{
case '1': strlcd(" FOR VOTING..."); cmdlcd(0x01);delay_ms(3000);voting();break;
case '2': strlcd("FOR PAN DETAILS");cmdlcd(0x01);delay_ms(3000); pan();break;
case '3': strlcd("FOR ATM...");	delay_ms(3000);cmdlcd(0x01);atm();break;
case '4':strlcd("EXIT...");	delay_ms(3000);break;
}
}
}

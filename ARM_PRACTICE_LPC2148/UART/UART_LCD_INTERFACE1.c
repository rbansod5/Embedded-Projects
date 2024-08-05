#include<lpc21xx.h>
#include"lcd.h"
#include"lcd_defines.h"
#include"uart.h"
#include"delay.h"

int main()
{
u8 i,j,n;
u8 ch,k;
InitUART0();
InitLCD();
//u8 i,j,k;

while(1)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n+1-i;j++)
{
u32 k=n+1-j;
//U0TXStr("");
//U0TXCHAR((k/10)+48);
//U0TXCHAR(U0RXCHAR(k%10)+48);
delay_s(1);
CmdLCD(0x80);
//ch=U0RXCHAR((k%10)+48);
k=U0TXCHAR((k%10)+48);
U32LCD(k);
delay_ms(1000);
}
//U0TXSTR("\n\r");
delay_ms(100);
}

}
}
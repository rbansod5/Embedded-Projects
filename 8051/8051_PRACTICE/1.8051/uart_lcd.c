#include<reg51.h>
#include"delay.h"
#include"lcd.h"
#include"uart.h"
int main() 
{
char  p[20];
char ch;
int i=0;
while(1)
{
while((ch=UART_Rxchar())!='\r')
{
p[i++]=ch;
}
p[i]='\0';


UART_Str(p);

cmdlcd(0x80);
strlcd(p);
}
}

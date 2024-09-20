#include<reg51.h>
#include"delay.h"
#include"uart.h"
#include"lcd.h"
#include"i2c.h"
#include"keypad.h"
#include"i2c_defines.h"
#include<string.h>
static int bal=1000;
const int pinn=1234;
int amount;
unsigned char a[5]={"1234"};
unsigned char b[5];
static char flag=0;
unsigned char sdat=0; 
unsigned char ch=0;
unsigned char i=0;
 
   
void voting(void)
{
 ch=0;

cmdlcd(0x01);
cmdlcd(0x80);
 strlcd("1.BJP 2.CONGRESS ");
 cmdlcd(0xc0);
 strlcd("3.LOCAL_PARTY 4.NOTA");
delay_ms(1000);
cmdlcd(0x94);
strlcd("please enter party");
cmdlcd(0xd4);
strlcd("watting....");
delay_ms(2000);
while((ch=UART_Rxchar())==0);
 i2cDevByteWrite(0xA0,0x00,flag+48); 
flag=i2cDevRandomRead(0xA0,0x00);
if(flag==0)
{
switch(ch)
{
case '1':
cmdlcd(0x01);
cmdlcd(0x80);
strlcd("now you'r adhabhakt ");
delay_ms(5000);
cmdlcd(0x01);
flag=1;
	i2cDevByteWrite(0xA0,0x00,flag+48); 
break;
case '2':
cmdlcd(0x01);
cmdlcd(0xc0);
strlcd("now you are chamcha");
delay_ms(5000);
cmdlcd(0x01);
flag=1;
	i2cDevByteWrite(0xA0,0x00,flag+48);
 
break;
case '3':
cmdlcd(0x01);
cmdlcd(0xc0);
strlcd("local party");
delay_ms(5000);
cmdlcd(0x01);
flag=1;
	i2cDevByteWrite(0xA0,0x00,flag+48);
break;
case '4':
cmdlcd(0x01);
cmdlcd(0xc0);
strlcd("nota nota nota");
delay_ms(5000);
cmdlcd(0x01);
flag=1;
	i2cDevByteWrite(0xA0,0x00,flag+48);
break;
default :cmdlcd(0x01);cmdlcd(0x80); strlcd("invalid input");delay_ms(1000);
}
}
else if(flag==1)
{
cmdlcd(0x01);
cmdlcd(0x80);
strlcd("voting done");
delay_ms(1000);
}
cmdlcd(0x01);
cmdlcd(0xc0);
strlcd("return to menu");
delay_ms(2000);
 }
 
 //===================================================
void pan(void)
{
char ch=0;


cmdlcd(0x01);
cmdlcd(0x80);
 strlcd("name ");
 cmdlcd(0xc0);
 strlcd("card number");
cmdlcd(0x94);
strlcd("please enter option");
while((ch=UART_Rxchar())==0);
cmdlcd(0x01);
strlcd("watting....");
delay_ms(2000);

switch(ch)
{
case '1':
cmdlcd(0x01);
cmdlcd(0x80);
strlcd("PAN CARD HOLDER");
cmdlcd(0xC0);
strlcd("RAHUL S. BANSOD");
delay_ms(5000);
cmdlcd(0x01);
break;
case '2':
cmdlcd(0x01);
cmdlcd(0x80);
strlcd("PAN CARD NUMBER");
cmdlcd(0xc0);
strlcd("CDTPB0669L");
delay_ms(5000);
cmdlcd(0x01);
break;
}
 }
 //------------------------------------------------------------------------------------------
void with(void)
{
ch=0;
cmdlcd(0x01);
cmdlcd(0x80);
strlcd("enter the pin");
delay_ms(1000);
i=0;
while((sdat=UART_Rxchar())=='\n')
{
b[i]=sdat;
		  i++;
}
b[i-1]='\0';
if(strcmp(a,b)!=0)
{	   
lable:
strlcd("enter withdrawal amount ");
	delay_ms(1000);
	amount=UART_Rxchar();
		delay_ms(1000);
	if(amount%100==0&&amount<=bal)
	{
		bal-=amount;
		cmdlcd(0x01);
		cmdlcd(0XC0);

		strlcd("REMAING BALANCE");
		delay_ms(1000);
		cmdlcd(0x01);
		cmdlcd(0XC0);
	integerlcd(bal);
	delay_ms(2000);

	}
	else 
	{
	cmdlcd(0x01);
		cmdlcd(0XC0);
		//printf("invalid amount\n")
		strlcd("invalid ammount");
		delay_ms(2000);
		cmdlcd(0x94);
		strlcd("please try again...");
		delay_ms(2000);
		goto lable;
	}

}
else 
 
strlcd("invalid password try again ");
}
//====================================================
void deposite(void)
{

sdat=0; 
strlcd("enter deposite");
delay_ms(1000);
while((sdat=UART_Rxchar())==0);
bal+=sdat;
cmdlcd(0x01);
cmdlcd(0x80);
integerlcd(bal);
delay_ms(1000);
}
void check(void)
{
 
strlcd("your ballance");
cmdlcd(0x01);
cmdlcd(0x80);
integerlcd(bal);

}

void pin(void)
{

}
//===============================================
 void atm(void)
{
char ch=0;
cmdlcd(0x01);
cmdlcd(0x80);
 strlcd("1.withdraw 2.deposite ");
 delay_ms(1000);
 cmdlcd(0xc0);
 strlcd("3.check 4.pin 5.exit");
delay_ms(1000);
cmdlcd(0x94);
cmdlcd(0x01);
strlcd("please enter option");
delay_ms(1000);
while((ch=UART_Rxchar())==0);
delay_ms(1000);
cmdlcd(0x01);
strlcd("watting....");
delay_ms(2000);
switch(ch)
{
case '1':with();break;
case '2':deposite();break;
case '3':check();break;
case '5': break;//goto lable; 
case '4': pin();break;
default : cmdlcd(0x01);cmdlcd(0x80);strlcd("invalid key\n");
}
}


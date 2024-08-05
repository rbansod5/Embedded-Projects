#include<reg52.h>
#include"delay.h"
#define LED P2

int main()
{
char i;
char a[5]={'a','b','c','d','e'};
	 while(1)
	 {
for(i=0;i<5;i++)
{
LED=a[i]^0x0f;
delay_ms(1000);
}
			 }
}

#include<reg51.h>
#include<stdlib.h>											 
#include"delay.h"
#define LED P1

int main()
{
char i;
char *a=(int*)malloc(25*sizeof(char));
for(i=0;i<25;i++)

a[i]= rand()%200+20;
while(1)
{
for(i=0;i<5;i++)
{
LED=a[i]^0x0f;
delay_ms(1000);
}			
}
}

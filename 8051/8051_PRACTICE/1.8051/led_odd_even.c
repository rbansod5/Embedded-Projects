#include<reg52.h>
#include"delay.h"			    
#define LED P1
int main()
{
int i,j,num,rem;
 i=0;
 num=255;
 while(1)
 {
for(i=0;i<num;i++)
{
while(i)
{
rem=i%10;
if(rem%2==1)
LED=0x0f^rem;
delay_ms(2000);
i=i/10;
}
}
}
}
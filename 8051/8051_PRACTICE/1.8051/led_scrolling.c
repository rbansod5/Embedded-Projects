#include<reg51.h>
#include"delay.h"
#include<math.h>
#define LED P1

main()
{
char i,a;
 while(1)
 {

for(i=0;i<8;i++)
{
a=pow(2,i);
LED=a^0x0f;
delay_ms(1000);
}
for(i=8;i>0;i--)
{
a=pow(2,i);
LED=a^0x0f;
delay_ms(1000);
}
}
}
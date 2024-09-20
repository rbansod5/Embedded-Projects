#include<reg52.h>
#include"delay.h"
#define LED P2

main()
{
char i;
while(1)
{
for(i=0;i<255;i++)
{
LED=i^0x0f;
delay_ms(2000);
}
}
}

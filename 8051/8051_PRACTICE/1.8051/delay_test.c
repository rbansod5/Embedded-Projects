#include<reg52.h>
#include"delay.h"
#define LED P0
int main()
{
while(1)
{
LED=0xff;
delay_ms(1000);
LED=0x00;
}
}



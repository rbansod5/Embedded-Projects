#include<reg52.h>
#include"delay.h"
#include"i2c.h"
#define LED P2
sbit SW1=P0^3;
sbit SW2=P0^4;

int main()
{
int i=0;
char ch=0;
 i2cstart();
while(1)
{
if(SW1==0)
{
i++;
i2cwrite(i^0x0f);
LED=i2cread();
}
else if(SW2==0)
{
i--;
i2cwrite(i^0x0f);
LED=i2cread();
}
i2cstop();
}
}

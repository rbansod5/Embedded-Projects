#include<lpc21xx.h>
#include"delay.h"
#include"defines.h"
#include"types.h"

#define led 0

main()
{
int arr[4]={0x81,0x42,0x24,0x18};
int i;
while(1)
{
for(i=0;i<4;i++)
{
WRITEBYTE(IOPIN0,led,arr[i]^0x0f);
delay_ms(500);
}
for(i=3;i>=0;i--)
{
WRITEBYTE(IOPIN0,led,arr[i]^0x0f);
delay_ms(500);
}
}
}
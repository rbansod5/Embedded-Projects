#include<lpc21xx.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
#define led 0
main()
{
WRITEBYTE(IODIR0,led,0xff);
while(1)
{
IOPIN0|=0x81;
delay_ms(500);
IOPIN0&=~(0xff<<led);
IOPIN0|=0x42;
delay_ms(500);
IOPIN0&=~(0xff<<led);
IOPIN0|=0x24;
delay_ms(500);
IOPIN0&=~(0xff<<led); 
IOPIN0|=0x18;
delay_ms(500);
IOPIN0&=~(0xff<<led);
}
}


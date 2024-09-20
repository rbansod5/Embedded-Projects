#include<lpc21xx.h>
#include "delay.h"
#include"types.h"
#include"defines.h"
int main()
{
SET(IODIR0,3,0xf);
while(1)
{
CPL(IOPIN0,3,15);
delay_s(1);
}
}

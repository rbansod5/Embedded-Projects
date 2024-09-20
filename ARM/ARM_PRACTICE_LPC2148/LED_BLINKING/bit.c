#include<lpc21xx.h>
#include"delay.h"
int main()
{
IODIR0|=255<<0;
delay_ms(2);
IODIR0&=~(255<<0);
delay_ms(2);
}
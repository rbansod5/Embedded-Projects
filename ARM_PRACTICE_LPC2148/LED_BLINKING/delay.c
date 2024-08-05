 //delay.c
#include"types.h"      
void delay_us(u32 dlyus)
{
dlyus*=12;
while(dlyus--);
}
void delay_ms(u32 dlyms)
{
dlyms*=12000;
while(dlyms--);
}
void delay_s(u32 dlys)
{
dlys*=12000000;
while(dlys--);
}


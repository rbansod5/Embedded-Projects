/*   deay called fun*/

#include "typ.h"
void delay_us(u32 dlyu)
{
dlyu*=12;
while(dlyu--);
}
void delay_ms(u32 dlym)
{
dlym*=12000;
while(dlym--);
}
void delay_s(u32 dlys)
{
dlys*=12000000;
while(dlys--);
}

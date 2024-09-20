#include "types.h"

void delay_ms(u16 dlyMS)
{
  u16 i;
  for(;dlyMS>0;dlyMS--)
  {
    for(i=122;i>0;i--);
  }  
}

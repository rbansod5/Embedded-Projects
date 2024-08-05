#include<reg51.h>
#include"delay.h"
#include<math.h>
#define LED P1

main()
{
//char i,a;
 while(1)
 {
  LED=0;
  LED=0X03^0x0f;
  delay_ms(1000);
  LED=0;
  LED=0x0c^0x0f;
  delay_ms(1000);
  LED=0;
  LED=0x30^0x0f;
  delay_ms(1000);
  LED=0;
  LED=0xc0^0x0f;
  delay_ms(1000);
  }
  }
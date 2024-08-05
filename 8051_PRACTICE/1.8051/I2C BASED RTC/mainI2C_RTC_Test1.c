		

					/* mainI2C_EEPROM_Test2.c */
#include "types.h"
#include <reg51.h>
#include "i2c.h"
#include "delay.h"
#include <string.h>
#include "ds1307.h"

sbit ledSuccess=P3^5;
sbit ledFailure=P3^4;
#define I2C_RTC_SA 0xD0 //slave address + w

main()
{
  setTime("13:45:50");
  while(1)
  {
   delay_ms(1000);
   if(strcmp(getTime(),"13:46:23")==0)
     break;   
  }
  ledSuccess=~ledSuccess;
  while(1);
}	

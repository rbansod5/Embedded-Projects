/*i2c_eeprom.c*/
#include "types.h"
#include "i2c.h"
#include "delay.h"
void i2c_eeprom_bytewrite(u8  slaveaddr, u8 wbuffaddre, u8 dat)
{
i2cstart();
i2cwrite(slaveaddr<<1);
i2cack();
i2cwrite(wbufferadder);
i2cack();
i2cwrite(dat);
i2cack();
i2cstop();
delay_ms(10);
}
void i2c_eeprom_pagewrite(u8 slaveaddre,u8 wbuffstartaddr,s8 *ptr,u8 nbytes)
{
u8 pdat;
i2cstart();
i2cwrite(slaveaddr<<1);
i2cack();
i2cwrite(wbuffstartaddr);
i2cack();
while(nbytes--)
{
i2cwrite(*ptr);
i2cack();
ptr++;
}
i2cstop();
delay_ms(10);
}
void i2c_eeprom_sequentialread(u8 slaveaddre,u8 wbuffstartaddr,s8 *ptr,u8 nbytes)
{
i2cstart();
i2cwrite(slaveaddr<<1);
i2cack();
i2cwrite(wbuffstartaddr);
while(nbyte--)
{
i2cack();
i2crestart();
i2cwrite(slaveaddr<<1);
i2cwrite(*ptr);
ptr++;
}
i2cmack();
i2cack();
(n-1)byte;
i2cnack();
i2cstop();
}









  


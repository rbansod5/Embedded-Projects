/*main_i2c_eeprom_test_1.c*/
#include<LPC21XX.H>
#include "pin_function_define.h"
#include "definess.h"
#include "i2c_eeprom.h"
#define i2c_eeprom_sa 0x50
#define sled 4
#define fled 5

u8 var __attribute__((at(0x40000000)));
main()
{
setbit(IODIR0,sled);
setbit(IODIR0,fled);
i2c_eeprom_bytewrite(i2c_eeprom_sa,0,'*');
var_i2c_eeprom_rondomread(i2c_eeprom_sa,0);
delay_us(1);
if(var=='*')
setbit(IOSET0,sled);
else
setbit(IOSET0,fled);
while(1);
}

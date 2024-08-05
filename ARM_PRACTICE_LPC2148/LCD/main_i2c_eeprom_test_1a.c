/*main_i2c_eeprom_test_1a.c*/
#include<lpc21xx.h>
#include "pin_function_defines.h"
#include "defines.h"
#include "delay.h"
#include "i2c_eeprom.h"
#include<string.h>
#define i2c_eeprom_sa 0x50
#define sled 4
#define fled 5
u8 var[35]__attribute__((at(0x40000000)));
main()
{
u32 i;
s8 s[]="welcome to vector india pvt ltd";
setbit(IODIR0,sled);
setbit(IODIR0,fled);
for(i=0;s[i];i++)
i2c_eeprom_bytewrite(i2c_eeprom_sa,i,s[i]);
for(i=0;s[i];i++)
var [i]=i2c_eeprom_randomread(i2c_eeprom_sa,i);
var[i]='\0';
delay_ms(2000);
if(strcmp(var,s)==0);
setbit(IOSET0,sled);
else
setbit(IOSET0,fled);
while(1);
}

                                    /* i2c_eeprom.c */

#include <LPC21xx.h>
#include "typ.h"
#include "i2c.h"
#include "delay.h"


void i2c_eeprom_write(u8 slaveAddr,u16 wBuffAddr,u8 dat)
{
  i2c_start();	
  i2c_write(slaveAddr); //slaveAddr + w
  i2c_write((wBuffAddr>>8)&0xFF);    //wBuffAddr
  i2c_write((wBuffAddr&0xFF));
  i2c_write(dat);    //wBuffAddr
  i2c_stop();
  delay_ms(10);
}			 


u8 i2c_eeprom_read(u8 slaveAddr,u16 rBuffAddr)
{
	u8 dat;
	i2c_start();	
    i2c_write(slaveAddr); //slaveAddr + w
	i2c_write((rBuffAddr>>8)&0xFF);    //rBuffAddr
	i2c_write((rBuffAddr&0xFF));
	i2c_restart();	
	i2c_write(slaveAddr|1); //slaveAddr + r
    dat=i2c_nack();	
	i2c_stop();
	return dat;
}


#ifndef __I2C_H__
#define __I2C_H__
#include "typ.h"

void init_i2c(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_restart(void);
void i2c_write(u8);
void i2c_eeprom_write(u8,u16,u8);
u8   i2c_eeprom_read(u8,u16);
u8   i2c_read(void);
u8 i2c_ack(void);
u8 i2c_nack(void);
u8 i2c_masterack(void);

#endif

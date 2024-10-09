
                           /* i2c_eeprom.h */

#ifndef __I2C_EEPROM_H__

#define __I2C_EEPROM_H__


#include "types.h"


void i2cDevWrite(u8 slaveAddr,u8 wBuffStartAddr,u8 *p,u8 nBytes);

void i2cDevRead(u8 slaveAddr,u8 rBuffStartAddr,u8 *p,u8 nBytes);


#endif
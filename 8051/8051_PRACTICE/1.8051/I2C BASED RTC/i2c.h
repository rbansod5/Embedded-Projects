#ifndef __I2C_H__
#define __I2C_H__

#include "types.h"
//prototypes for i2c Bus Events
void i2cStart(void);//declaration of driver for i2c start event
void i2cReStart(void);//declaration of driver for i2c start event
void i2cStop(void); //declaration of driver for i2c stop  event
void i2cWrite(u8 byte);//declaration of driver for i2c byte write to slave
u8   i2cRead(void);    //declaration of driver for i2c byte read  from slave
void i2cSlaveAck(void);//declaration of driver for i2c master taking ack from slave
void i2cNAck(void);
void i2cMasterAck(void);

//prototypes for i2c Communication Algorithms
void i2cDevByteWrite(u8,u8,u8);
u8   i2cDevRandomRead(u8,u8);
void i2cDevPageWrite(u8,u8,u8 *,u8);
void i2cDevSeqRead(u8,u8,u8 *,u8);
//more declaration to added as required...

#endif

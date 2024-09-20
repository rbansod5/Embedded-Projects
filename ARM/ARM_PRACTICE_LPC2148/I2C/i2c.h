/*i2c.h*/
#ifndef __i2c_h__
#define __i2c_h__
#include "types.h"
void init_init (void)
void i2c_start(void);
void i2c_stop(void);
void i2c_restart(void);
void i2c_write(u8);
void i2c_read(void);
u8 i2c_ack(void);
u8 i2c_nack(void);
u8 i2c_masterack(void);
#endif

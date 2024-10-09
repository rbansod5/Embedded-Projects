                         /* i2c_defines.h */

#ifndef __I2C_DEFINES_H__
#define __I2C_DEFINES_H__

//defines for pin function selection
#define SCL_EN  0x00000010
#define SDA_EN  0x00000040

//defines for I2C_SPEED Configuration 
#define CCLK      60000000  //Hz
#define PCLK      CCLK/4    //Hz
#define I2C_SPEED 100000    //Hz
#define LOADVAL   ((PCLK/I2C_SPEED)/2)
//bit defines for I2CONSET sfr
#define   AA_BIT 2
#define   SI_BIT 3
#define  STO_BIT 4
#define  STA_BIT 5
#define I2EN_BIT 6

#endif

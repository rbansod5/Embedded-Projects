#ifndef __I2C_DEFINES_H__
#define __I2C_DEFINES_H__

#include <reg51.h>
sbit scl=P2^0;//i/o pin of 8051 connected to scl line of i2c bus
sbit sda=P2^1;//i/o pin of 8051 connected to sda line of i2c bus
sbit s1=P2^7;
sbit s2=P2^6;

#endif

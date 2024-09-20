#include "types.h"
#include "delay.h"
#include "i2c_defines.h"

// low level embedded-c driver for i2c bus events

/* routine to issue start event/condition */
void i2cStart(void)
{
//  sda=1;//default status of sda line can be avoided
//  scl=1;//default status of scl line can be avoided
  sda=0;//pull down sda from high to low issues start event 
}

/* routine to issue re start event/condition in-between  certain i2c
   communication alogirthm somewhere between the start & stop.
*/
void i2cReStart(void)
{
  scl=0;//make scl low to make/release sda 1
  sda=1;//default status of sda line can be avoided
  scl=1;//default status of scl line can be avoided
  sda=0;//pull down sda from high to low issues start event 
}

/* routine to issue stop event/condition */
void i2cStop(void)
{
  scl=0;//to change status of sda ,scl is made low during communication
  sda=0;//now scl is made low
  scl=1;//scl line is released
  sda=1;//sda is raised from low to high to issue stop condition
}



/* 
  routine for serializing out byte in order msb toward lsb across sda line
  with clock cycles across scl line
*/
void i2cWrite(u8 byte)
{
  u8 i;
  for(i=0;i<8;i++)
  {
    scl=0;//to allow change of bit status across sda line
    sda=(byte>>(7-i))&1;//serialize-out data msb to lsb/changing sda line
    //sda= (byte&(0x80>>i)) ? 1 : 0;//serialize data msb to lsb/changing sda line
    /*if(byte & (0x80>>i))
      sda=1;
    else
      sda=0;
    */
    scl=1;//release scl line so that slave can check/read/monitor bit received
          //across
  }  
}

/* 
  routine for serializing-in a byte in order msb toward lsb across sda line
  with clock cycles across scl line
*/
u8 i2cRead(void)
{
  u8 i,buff;
  for(i=0;i<8;i++)
  {
    scl=0;//to allow change of bit status across sda line by slave
    scl=1;//master releases scl line so that it can check/read/monitor bit received
          //across sda line
    if(sda)//reading valid bit status
      buff|=0x80>>i; //& updating appropriate bit pos with '1' level
    else
      buff&=~(0x80>>i);//or updating appropriate bit pos with '0' level
  }
  return buff;   
}





/*
   master taking acknowlegement from slave after writing byte of information
*/

void i2cSlaveAck(void)
{
  scl=0;//master make scl=0 to change sda to high/release sda
  sda=1;//master is releasing sda,so that slave can pull down sda for +ack
  scl=1;//master releases scl also
  while(sda);//master is checking sda if it is high/low,
             //if sda continues to remain high,implies -ve ack/no ack received
             //sda is low ,implies +ve ack,& master can continue further activity. 
}

/*
   master issues not of acknowlegement onto bus for slave for only byte/last of several
   bytes read from slave
*/

void i2cNAck(void)
{
  scl=0;//master make scl=0 to change sda to high/release sda
  sda=1;//master is releasing sda,so slave can read this status of not of acknowledge
  scl=1;//master releases scl,slave read here that status 
}

/* 
   master issue acknowlegment to slave for every byte read except the last
   of several bytes being read.
*/

void i2cMasterAck(void)
{
   scl=0;//master makes scl=0 to pull down sda =0 for issuing its +ve ack
   sda=0;//master pulls down sda for +ve ack issue,& slave release sda from its end
   scl=1;//master release scl ,so that slave can read that status of ack (+ve/-ve)
   scl=0;//master now has to release sda,so scl=0
   sda=1;//now master release sda from low to high      
}







// low lever embedded-c drivers for i2c communication algorithms

/*
   This routine is attempts to write to any random location of the eeprom
   by each time providing the address location where data needs to be written into
*/
void i2cDevByteWrite(u8 slaveAddr7Bit,u8 wBuffAddr,u8 dat)
{
  i2cStart();
  i2cWrite((slaveAddr7Bit)|0);
  i2cSlaveAck();
  i2cWrite(wBuffAddr);
  i2cSlaveAck();
  i2cWrite(dat);
  i2cSlaveAck();
  i2cStop();
  delay_ms(10);
}

/*
   This routine is attempts to read from any random location of the eeprom
   by each time providing the address location where data needs to read from
*/
u8 i2cDevRandomRead(u8 slaveAddr7Bit,u8 rBuffAddr)
{
  u8 buff;
  i2cStart();
  i2cWrite((slaveAddr7Bit)|0);
  i2cSlaveAck();
  i2cWrite(rBuffAddr);
  i2cSlaveAck();
  i2cReStart();
  i2cWrite((slaveAddr7Bit)|1);
  i2cSlaveAck();
  buff=i2cRead();
  i2cNAck();
  i2cStop(); 

  return buff;
}






void i2cDevPageWrite(u8 slaveAddr7Bit,
                     u8 wBuffSeqStartAddr,
                     u8 *ptr8Bytes,
                     u8 nBytes)
{
  u8 i;
  i2cStart();
  i2cWrite((slaveAddr7Bit)|0);
  i2cSlaveAck();
  i2cWrite(wBuffSeqStartAddr);
  i2cSlaveAck();

  for(i=0;i<nBytes;i++)
  {
    i2cWrite(*ptr8Bytes++);
    i2cSlaveAck();
  }
  i2cStop();
  delay_ms(10);
}

void i2cDevSeqRead(u8 slaveAddr7Bit,
                     u8 rBuffSeqStartAddr,
                     u8 *ptr8Bytes,
                     u8 nBytes)
{
  u8 i;
  i2cStart();
  i2cWrite((slaveAddr7Bit)|0);
  i2cSlaveAck();
  i2cWrite(rBuffSeqStartAddr);
  i2cSlaveAck();
  i2cReStart();
  i2cWrite((slaveAddr7Bit)|1);
  i2cSlaveAck();
  for(i=0;i<nBytes-1;i++)
  {
    ptr8Bytes[i]=i2cRead();
    i2cMasterAck();
  }
  ptr8Bytes[i++]=i2cRead();
  ptr8Bytes[i]='\0';
  i2cNAck();
  i2cStop();
}

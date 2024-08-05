#include <LPC21xx.h>
#include "types.h"
#include "defines.h"
#include "delay.h"

//define pin functions  
#define FUNC2 1
#define SCL_PIN_0_2   FUNC2
#define SDA_PIN_0_3  FUNC2

//define CFGPIN macro
#define CFGPIN(WORD,PIN,FUNC)  \
WORD=((PIN<16) ? \
 ((WORD&~(3<<(PIN*2)))|(FUNC<<(PIN*2))) : \
 ((WORD&~(3<<((PIN-16)*2)))|(FUNC<<((PIN-16)*2))))

//defines for I2C_SPEED Configuration 
#define FOSC      12000000
#define CCLK      5*FOSC
#define PCLK      CCLK/4    //Hz
#define I2C_SPEED 100000    //Hz
#define BITRATE   ((PCLK/I2C_SPEED)/2)

//bit defines for I2CONSET sfr
#define   AA_BIT 2
#define   SI_BIT 3
#define  STO_BIT 4
#define  STA_BIT 5
#define I2EN_BIT 6

//bit defines for I2CONCLR sfr
#define   AAC_BIT 2
#define   SIC_BIT 3
#define  STAC_BIT 5
#define I2ENC_BIT 6

#define I2C_EEPROM_SA 0x50 //7Bit Slave Addr
#define sLED 1<<4 //P0.4
#define fLED 1<<5 //P0.5

void init_i2c(void)
{
   //Cfg p0.2 for SCL functions using PINSEL0
 //  CFGPIN(PINSEL0,2,SCL_0_2);
  //Cfg p0.3 for SDA functions using PINSEL0
//  CFGPIN(PINSEL0,3,SDA_0_3);
 //Cfg Speed for I2C Serial Communication
 PINSEL0=0x50;
  I2SCLL=BITRATE;
  I2SCLH=BITRATE;
  //I2C Peripheral Enable for Communication
  SSETBIT(I2CONSET,I2EN_BIT); 
}	
void i2c_start(void)
{
    // start condition
   SSETBIT(I2CONSET,STA_BIT);
   //wait for start bit status
   while(READBIT(I2CONSET,SI_BIT)==0);
   // clear start condition
   SCLRBIT(I2CONCLR,STA_BIT);
}	
void i2c_restart(void)
{
   // start condition
   SSETBIT(I2CONSET,STA_BIT);
   //clr prev SI_BIT
    SCLRBIT(I2CONCLR,SI_BIT);
    //wait for SI bit status
    while(READBIT(I2CONSET,SI_BIT)==0);
   // clear start condition
   SCLRBIT(I2CONCLR,STA_BIT);
}	
void i2c_write(u8 dat)
{
   //put data into I2DAT
    I2DAT=dat;	
    //clr SI_BIT using I2CON
    SCLRBIT(I2CONCLR,SIC_BIT);
    //wait for SI bit status using I2CONSET
    while(READBIT(I2CONSET,SI_BIT)==0);
}	
void i2c_stop(void)
{
    // issue stop condition
    SSETBIT(I2CONSET,STO_BIT);
    // clr SI bit status	
    SCLRBIT(I2CONCLR,SIC_BIT);
    //stop will cleared automatically
    //while(READBIT(I2CONSET,SI_BIT)==0);
}
u8 i2c_nack(void)
{	
     I2CONSET = 0x00; //Assert Not of Ack
     SCLRBIT(I2CONCLR,SI_BIT);
     while(READBIT(I2CONSET,SI_BIT)==0);
     return I2DAT;
}

u8 i2c_mack(void)
{	
    SSETBIT(I2CONSET,AA_BIT); //Assert Ack
    SCLRBIT(I2CONCLR,SI_BIT);
    while(READBIT(I2CONSET,SI_BIT)==0);
    SCLRBIT(I2CONCLR,AAC_BIT); //Clear Assert Ack
    return I2DAT;
}	
void i2c_eeprom_bytewrite(u8 slaveAddr,u8   wBuffAddr,u8 dat)
{
    //issue i2c start
    i2c_start();	
    //slaveAddr + w,& take ack
    i2c_write(slaveAddr<<1); 
    //wBuffAddr,ack
    i2c_write(wBuffAddr);    
    //dat,ack
   i2c_write(dat);   
   //issue i2c stop	
   i2c_stop();
   //write cycle delay
   delay_ms(10);
}			 

u8 i2c_eeprom_randomread(u8 slaveAddr,u8 rBuffAddr)
{
    u8 dat;	
    //start condition
    i2c_start();	
    //slaveAddr + w , &take ack
    i2c_write(slaveAddr<<1);
    //rBuffAddr , &take ack
    i2c_write(rBuffAddr);
    //restart    
    i2c_restart();	
    //slaveAddr + r, &take ack
    i2c_write(slaveAddr<<1|1); 
    dat=i2c_nack();	
    //stop condition
    i2c_stop();
    return dat;
}

void i2c_eeprom_pagewrite(u8 slaveAddr,u8  wBuffStartAddr,s8 *p,u8 nBytes)
{
  u8 i;
  i2c_start();	
 //slaveAddr + w
  i2c_write(slaveAddr<<1);    
  //wBuffStartAddr
  i2c_write(wBuffStartAddr);  
   for(i=0;i<nBytes;i++)
   {
       //wDATA
       i2c_write(p[i]);             
    }
    i2c_stop();
    delay_ms(10);
}			 

void i2c_eeprom_seqread(u8 slaveAddr,u8 rBuffStartAddr,s8 *p,u8 nBytes)
{
   u8 i;
   i2c_start();	
   i2c_write(slaveAddr<<1); //slaveAddr + w
   i2c_write(rBuffStartAddr);    //rBuffAddr
   i2c_restart();	
   i2c_write(slaveAddr<<1|1); //slaveAddr + r  for(i=0;i<nBytes-1;i++)
   {
          p[i]=i2c_mack();	
    }
   p[i]=i2c_nack();
   i2c_stop();
}

u8 t  __attribute__((at(0x40000000)));
s8 rbuff[18] __attribute__((at(0x40000040)))="";

main()
{
    s8 wbuff[]="ABCDEFGHIJKLMNOPQ";

    init_i2c();
    //IODIR0|=sLED|fLED;

    i2c_eeprom_bytewrite(I2C_EEPROM_SA,0x00,'a');
  /*  delay_ms(2000);
	    t=i2c_eeprom_randomread(I2C_EEPROM_SA,0x00);
  delay_ms(2000);
(t=='a') ? SSETBIT(IOSET0,sLED) : SCLRBIT(IOCLR0,fLED);

i2c_eeprom_pagewrite(I2C_EEPROM_SA,0x00,wbuff,17);
   delay_ms(1000);
 i2c_eeprom_seqread(I2C_EEPROM_SA,0x00,rbuff,17);
 delay_ms(1000);
 if(strcmp((cs8 *)rbuff,(cs8 *)wbuff)==0)
      SSETBIT(IOSET0,sLED);
  else
      SCLRBIT(IOCLR0,fLED);
	  */
   while(1);
}


/******************************************************
www.firmcodes.com
DEVELOPED BY:- FIRMWARE DEVELOPER
WHAT PROGRAM DO:-This Program write and read data from EEPROM 24LC04 by I2C Protocol 
with arm ( lpc2129 ) and send data to through UART.
******************************************************/
 
 
#include <LPC21xx.H>
#include"prototype.h"
 
#define MAX_BUFFER_SIZE 16
//#define MAX_BUFFER_SIZE 32
#define DEVICE_ADDR 0xA0
#define BLK_0 0x00
#define BLK_1 0x02
#define MAX_BLOCK_SIZE 256
 
 
 
 
//void Delay(unsigned char j);

void Send_Start(void);
void Send_Stop(void);
unsigned char Send_I2C(unsigned char *Data,unsigned char Len);
unsigned char Read_I2C(unsigned char *Data,unsigned char Len);
unsigned char Page_Write(unsigned char BLOCK_NUMBER,unsigned char BLOCK_ADDR);
unsigned char Page_Read(unsigned int BLOCK_NUMBER,unsigned char BLOCK_ADDR);
unsigned char I2C_Status(unsigned char status_code);
 
 
unsigned char I2C_WR_Buf[MAX_BUFFER_SIZE]={"NSK ELECTRONICS "};
unsigned char I2C_RD_Buf[MAX_BUFFER_SIZE];
unsigned char Status=0;
unsigned char Status_Flag=0;
 
//void  Delay(unsigned char j)
//{  
// unsigned int  i;
// for(;j>0;j--)
// {
//  for(i=0; i<60000; i++);
// } 
//} 

void Send_Start()
{
 I2CONSET=0x20; 
}
 
 
void Send_Stop()
{
 I2CONSET=0x10;
}
 
// This function sends sequential data to the EEPROM 24LC04
// The buffer size for EEPROM 24LC04 is 16 bytes
// The Len parameter should not exceed this value
unsigned char Send_I2C(unsigned char *Data,unsigned char Len)
{
 while(Len)
 {
  I2DAT=*Data;
  if(I2C_Status(0x28))
  {
   return 1;
  }
  Len--;
  Data++;
 }
 return 0;
}
 
 
// This function reads random data from the EEPROM 24LC04
 
unsigned char Read_I2C(unsigned char *Data,unsigned char Len)
{
 while(Len)
 {
  if(Len==1)  //Last byte
  {
   I2CONCLR=0x04;		 //set hardware to send nack
   if(I2C_Status(0x58))	//last byte has been received and NACK has been returned
   {
    return 1;
   }
   *Data=I2DAT;
  }
  else
  {
   I2CONSET=0x04;	 		//set hardware to send  ack
   if(I2C_Status(0x50))	//Byte has been received ACK has been returned
   {
    return 1;
   }
   *Data=I2DAT;	
  } 
  Data++;
  Len--;
 }
 return 0;
}
 
 
unsigned char I2C_Status(unsigned char status_code)
{
 while(Status_Flag==0);
 Status_Flag=0;
 if(Status!=status_code)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}
 
 
unsigned char Page_Write(unsigned char BLOCK_NUMBER,unsigned char BLOCK_ADDR)
{
 Send_Start();
 if(I2C_Status(0x08))	//Start has been transmitted
 {
  return 1;
 }
 
 I2DAT=DEVICE_ADDR | BLOCK_NUMBER;	// Send Address
 if(I2C_Status(0x18))					//Device address, block num and write has been transmitted
 {
  return 1;
 }
 
 I2DAT=BLOCK_ADDR;	// Send block address
 if(I2C_Status(0x28))	//Block address has been transmitted
 {
  return 1;
 }
 
 if(Send_I2C(I2C_WR_Buf,MAX_BUFFER_SIZE))			//Send Data
 {
  Send_Stop();
  return 1;
 }
 Send_Stop();
 return 0;
}
 
 
unsigned char Page_Read(unsigned int BLOCK_NUMBER,unsigned char BLOCK_ADDR)
{
 Send_Start();
 if(I2C_Status(0x08))	//Start has been transmitted
 {
  return 1;
 }
 
 I2DAT=DEVICE_ADDR | BLOCK_NUMBER;	// Send Address
 if(I2C_Status(0x18))	//Device address, block num and write has been transmitted
 {
  return 1;
 }
 
 I2DAT=BLOCK_ADDR;
 if(I2C_Status(0x28))	//Block address has been transmitted
 {
  return 1;
 }
 
 Send_Start();		     // Repeat Start
 if(I2C_Status(0x10))	//Repeated Start has been transmitted
 {
  return 1;
 }
 
 I2DAT=DEVICE_ADDR | BLOCK_NUMBER | 0x01;			//Device address, block num and read has been transmitted
 if(I2C_Status(0x40))	//
 {
  return 1;
 }
 if(Read_I2C(I2C_RD_Buf,MAX_BUFFER_SIZE))			//Receive 16bytes of Data from EEPROM
 {
  Send_Stop();
  return 1;
 }
 Send_Stop();
 return 0;
}
 
 
void  __irq I2C0_Status(void)
{ 
  Status_Flag=0xFF; 			//update status flag
  Status=I2STAT;				//Read Status byte
  I2CONCLR=0x28;				
  VICVectAddr = 0x00;   		//Acknowledge Interrupt
}	
 
 
void I2C_Init()
{
 PINSEL0&=0xFFFFFF0F;
 PINSEL0|=0x00000050;
 
 I2CONCLR=0x6C;
 I2CONSET=0x40;
 I2SCLH=80;
 I2SCLL=70;
 
 /*  Init VIC for I2C0	*/
 VICIntSelect = 0x00000000;		// Setting all interrupts as IRQ(Vectored)
 VICVectCntl0 = 0x20 | 9;		// Assigning Highest Priority Slot to I2C0 and enabling this slot
 VICVectAddr0 = (unsigned long)I2C0_Status; // Storing vector address of I2C0
 VICIntEnable = (1<<9);	
 
}
 
int  main(void)
{  


 lcd_init();
 lcd_print("LCD_INIT");

 I2C_Init();
 lcd_clr();
 lcd_print("I2C INIT");

 if(Page_Write(BLK_1,0x00))
 {
 	lcd_clr();
  	lcd_print("Write Failed");

 }
 else
 {
 	lcd_clr();
	lcd_print("WRITE PASS");
	}
 	
 	Delay(1);
 

 
 if(Page_Read(BLK_1,0x00))
 {
  	lcd_clr();
	lcd_print("Read Failed");

 }
 else
 {
 	lcd_clr();
 	lcd_print("EEPROM READ:");
	lcdcmd(0xc0);	
  	lcd_print(I2C_RD_Buf);

 }

 while(1)
 {
  
 }
 
}

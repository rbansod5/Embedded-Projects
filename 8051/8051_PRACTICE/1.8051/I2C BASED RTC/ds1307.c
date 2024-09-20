							/* ds1307.c */
#include "types.h"
#include "i2c.h"

u8 AsciiToHexBCD(u8 t1,u8 t2)
{
  return (((t1&0x0f)<<4)|(t2&0x0f));
}

u8 HexBCDtoAsciiUNibble(u8 bcdVal)
{
  return ((bcdVal>>4)+48);        
}

u8 HexBCDtoAsciiLNibble(u8 bcdVal)
{
  return ((bcdVal&0x0f)+48);        
}

u8 Dec2HexBCD(u8 val)
{
  return (((val/10)<<4)|(val%10)); 
}

u8 HexBCD2Dec(u8 val)
{
  return (((val/16)*10)+(val%16));
}

void setTime(u8 *time /*13:45:50*/)
{
  u8 hrs,mins,secs;
  hrs=AsciiToHexBCD(time[0],time[1]);
  mins=AsciiToHexBCD(time[3],time[4]);
  secs=AsciiToHexBCD(time[6],time[7]);
  i2cDevByteWrite(0xd0,0x02,hrs);
  i2cDevByteWrite(0xd0,0x01,mins);
  i2cDevByteWrite(0xd0,0x00,secs);
}

u8 * getTime(void)
{
   static u8 time[9]="00:00:00";
   u8 hrs,mins,secs;
  
   hrs=i2cDevRandomRead(0xd0,0x02);  
   mins=i2cDevRandomRead(0xd0,0x01);
   secs=i2cDevRandomRead(0xd0,0x00);
  
   time[0]=HexBCDtoAsciiUNibble(hrs);
   time[1]=HexBCDtoAsciiLNibble(hrs);
   time[3]=HexBCDtoAsciiUNibble(mins);
   time[4]=HexBCDtoAsciiLNibble(mins);
   time[6]=HexBCDtoAsciiUNibble(secs);
   time[7]=HexBCDtoAsciiLNibble(secs);

   return time;
}

void setHrs(u8 hrs)
{
  u8 t;
  t=Dec2HexBCD(hrs);
  i2cDevByteWrite(0xD0,0x02,t);
}

void setMins(u8 mins)
{
  u8 t;
  t=Dec2HexBCD(mins);
  i2cDevByteWrite(0xD0,0x01,t);
}

void setSecs(u8 secs)
{
  u8 t;
  t=Dec2HexBCD(secs);
  i2cDevByteWrite(0xD0,0x00,t);
}

u8 getHrs()
{
  u8 t;
  t=i2cDevRandomRead(0xD0,0x02);
  t=HexBCD2Dec(t);
  return t;
}

u8 getMins()
{
  u8 t;
  t=i2cDevRandomRead(0xD0,0x01);
  t=HexBCD2Dec(t);
  return t;
}

u8 getSecs()
{
  u8 t;
  t=i2cDevRandomRead(0xD0,0x00);
  t=HexBCD2Dec(t);
  return t;
}



#include<lpc21xx.h>
#include "delay.h"
#include "types.h"
#include "defines.h"

#define fosc 12000000
#define speed 1000000
#define cclk fosc*5
#define pclk cclk/4
#define bitrate ((pclk/speed)/2)

void init_i2c(void)
{
PINSEL0=0x50;
I2SCLL=bitrate;
I2SCLH=bitrate;
I2CONSET=0x40;
}
void start(void)
{
I2CONSET=0x20;
//I2CONCLR=0x08;
while(READBIT(I2CONSET,3)==0);
I2CONCLR=0x20;
}
void restart(void)
{
I2CONSET=0x20;
I2CONCLR=0x08;
while(READBIT(I2CONSET,3)==0);
I2CONCLR=0x20;
}

u8 write(u8 sdat)
{

I2DAT=sdat;
I2CONCLR=0x08;
while(READBIT(I2CONSET,3)==0);
return I2DAT;
}

void stop(void)
{
I2CONSET=0x10;
I2CONCLR=0x08;
//while(READBIT(I2CONSET,3)==0);
}
u8 nack(void)
{
I2CONSET=0X00;
I2CONCLR=0X08;
while(READBIT(I2CONSET,3)==0);
return I2DAT;
}

u8 mack(void)
{
I2CONSET=0X02;
I2CONCLR=0X08;
while(READBIT(I2CONSET,3)==0);
I2CONCLR=0X02;
return I2DAT;
}

void bytewrite(u8 slaveaddr,u8 wbuffaddr,u8 data)
{

 start();
 write(slaveaddr<<1);
 write(wbuffaddr);
 write(data);
 nack();
 stop();
 }

u8 byteread(u8 slaveaddr,u8 rbuffaddr)
{
u8 dat;
 start();
 write(slaveaddr<<1);
 write(rbuffaddr);
 restart();
 write(slaveaddr<<1|1);
 dat=nack();
 stop();

}

u8 t  __attribute__((at(0x40000000)));
s8 rbuff[18] __attribute__((at(0x40000040)))="";
int main()
{ u8 ch='R';
u8 d=0x40000000;
u8 e=0x40000040;
init_i2c();

while(1)
{
	  ch;
 bytewrite(d,e,ch);
 ch=byteread(d,e);


}

}

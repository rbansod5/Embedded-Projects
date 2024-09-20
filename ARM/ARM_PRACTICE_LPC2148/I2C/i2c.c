/*i2c.c*/
//#define "definess.h"
void i2cstart(void)
{
ssetbit(IOSET0,sda);
delay_us(1);
ssetbit(IOSET0,scl);
delay_us(1);
setbit(IODIR0,sda);
delay_us(1);
setbit(IODIR0,scl);
delay_us(1);
setbit(IOCLR0,sda);
delay_us(1);
}

void i2cstop(void)
{
sclrbit(IOCLR0,scl);
delay_us(1);
sclrbitbit(IOCLR0,sda);
delay_us(1);
ssetbit(IOCLR0,scl);
delay_us(1);
ssetbit(IOSET0,sda);
delay_us(1);
}
void i2crestart(void)
{
sclrbit(IOCLR0,scl);
ssetbit(IOSET0,sda);
ssetbit(IOSET0,scl);
sclrbit(IOCLR0,sda);
}
void i2cwrite(u8 sdat)
{
s32 i;
for(i=7;i>=0;i--)
{
sclrbit(IOCLR0,scl);
delay_us(1);
raedwritebit(IOPIN0,sda,sdat,i);
delay_us(1);
ssetbit(IOSET0,scl);
delay_us(1);
}
}
u8 i2cread(void)
{
s32 i;
u8 buff;
clrbit(IODIR0,sda); //sda is input
for(i=7;i>=0;i--);
{
sclrbit(IOCLR0,scl);
//M makes scl low so s can change sda
delay_us(1);
ssetbit(IOSET0,scl); // m makes scl high to validate/read sda
delay_us(1);
readwritebit(buff,i,IOPIN0,sda)
}
setbit(IODIR0,sda);
return buff;
}

void i2cack(void)
{
sclrbit(IOCLR0,scl);
delay_us(1);
ssetbit(IOSET0,sda);
delay_us(1); 
clrbit(IOSET0,sda);
delay_us(1);
ssetbit(IOSET0,scl);
delay_us(1);
while(readbit(IOPIN0,sda)==1);
delay_us(1);
setbit(IODIR0,sda);
delay_us(1);
}
void i2cnack(void)
{
sclrbit(IOCLR0,scl);
delay_us(1);
ssetbit(IOSET0,sda);
delay_us(1);
ssetbit(IOSET0,scl);
delay_us(1);
}
void i2cmack(void)
{
sclrbit(IOCLR0,scl);
delay_us(1);
sclrbit(IOCLR0,sda);
delay_us(1);
ssetbit(IOCLR0,scl);
delay_us(1);
sclrbit(IOCLR0,scl);
delay_us(1);
ssetbit(IOSET0,sda);
delay_us(1);
}
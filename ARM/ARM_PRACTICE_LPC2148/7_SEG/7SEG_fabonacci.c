#include<lpc21xx.h>
#include"delay.h"
#include"types.h"
#include"defines.h"
#define SEG7 0
#define DSEL1 8
#define DSEL2 9
u32 a[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int main()
{
unsigned int x,y,z;
unsigned int i,n=12;
WRITEBYTE(IODIR0,SEG7,0Xff);
WRITEBIT(IODIR0,DSEL1,1);
WRITEBIT(IODIR0,DSEL2,1);
while(1)
{
x=0;
y=1;
WRITEBIT(IOPIN0,DSEL1,1);
WRITEBYTE(IOPIN0,SEG7,a[x]);
delay_ms(1000);
WRITEBYTE(IOPIN0,SEG7,a[y]);

for(i=1;i<=n;i++)
{
z=x+y;
x=y;
y=z;

WRITEBYTE(IOPIN0,SEG7,a[z/10]);
WRITEBIT(IOSET0,DSEL1,1);
delay_s(1);
WRITEBIT(IOCLR0,DSEL1,1);
WRITEBYTE(IOPIN0,SEG7,a[z%10]);
WRITEBIT(IOSET0,DSEL2,1);
delay_s(1);
WRITEBIT(IOCLR0,DSEL2,1);
}
}
}




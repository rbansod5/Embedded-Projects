//external_interrupt_test.c
#include<lpc21xx.h>
#include"types.h"
#include"defines.h"
#define EINT0_PIN 1
#define EINT0_LED 16
#define FUN4      3
#define EINT0_PIN_FUN  FUN4
#define CFGPIN(WORD,BITPAIRPOS,FUN) WORD=((WORD&(~(3<<BITPAIRPOS)))|(FUN<<BITPAIRPOS))

void eint0_isr(void) __irq
{
CPLBIT(IOPIN0,EINT0_LED);
EXTINT=0X01;
VICVectAddr=0;
}
void enable_EINT0(void)
{
SETBIT(IODIR0,EINT0_LED);
PINSEL0=0X0000000C;
EXTMODE=0X01;
EXTPOLAR=0X01;
VICIntEnable=1<<14;
VICVectCntl0=1<<5|14;
VICVectAddr0=(unsigned)eint0_isr;
}
u32 count;
main()
{
enable_EINT0();
while(1)
{
count++;
}
}

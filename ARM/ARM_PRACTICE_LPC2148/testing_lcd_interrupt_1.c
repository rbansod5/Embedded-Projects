 //Testing_lcd_interrupt_1.c

#include<LPC21XX.h>
#include"types.h"
#include"defines.h"
#include"delay.h"

#define EINT0_PIN 1
#define EINT1_PIN 3
#define EINT0_LED 16 
#define EINT1_LED 17

#define FUN4 3

#define EINT0_PIN_FUN FUN4
#define  EINT1_PIN_FUN FUN4
#define CFGPIN(WORD,PIN,FUN)\
WORD=((WORD&(~(3<<(PIN*2))))|(FUN<<(PIN*2)))
void enit0_isr(void) __irq
{
CPLBIT(IOPIN0,EINT0_LED);
EXTINT=0x01;
VICVectAddr=0;
delay_ms(500);
}
void eint1_isr(void) __irq
{
CPLBIT(IOPIN0,EINT1_LED);
EXTINT=0x02;
VICVectAddr=0;
dealy_ms(100);
}
void Enable_ENITS(void)
{
SETBIT(IODIR0,EINT0_LED);
SETBIT(IODIR0,EINT1_LED); 
//cfg gpio p0.1 pin as eint0 input pin

CFGPIN(PINSEL0,1,EINT0_PIN_FUN);
 //cfg gpio p0.3 pin as eint1 input pin

CFGPIN(PINSEL0,3,EINT1_PIN_FUN);
//cfg external interrupt peripheral
//EXTINT=0x00;
//cfg eint0,eint1 to taken as E_TRIG

EXTMODE=0x03;
//cfg eint0,eint1 to be taken as Redge

EXTPOLAR=0x03;
//VICIntselect=0; //all irqs
//enable eint 0,eint1 channel in VIC

VICIntEnable=1<<14|1<<15;
//allow isr address to load into VICVectAddrN
//With req interrupt source

VICVectcntl0=1<<5|14;
VICVectAddr0=(unsigned)eint0 _isr;
}
u32 count;
main()
{
Enable_EINTS();
while(1)
{
count++;
}
}
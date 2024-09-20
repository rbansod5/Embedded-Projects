//seg.c
#include <LPC21xx.h>
#include"defines.h"
#include"delay.h"
#include"seg.h"
#include"types.h"
u8 seglut[14]={0xc0,0xf9,0xa4,0xb0,0x88,0x99,0x92,0x82,0x83,0xc6,0xf8,0x80,0x90,0xa1};
#define CA7SEG_2_MUX  0
#define DSEL1         8
#define DSEL2         9

void Init_CA7SEG_2_MUX(void)
{
WRITEBYTE(IODIR0,CA7SEG_2_MUX,0XFF);
SETBIT(IODIR0,DSEL1);
SETBIT(IODIR0,DSEL2);
}

void dispi_2_mux_ca7seg(u8 i)
{
WRITEBYTE(IOPIN0,CA7SEG_2_MUX,seglut[i/10]);
SSETBIT(IOSET0,DSEL1);
delay_ms(1);
SCLRBIT(IOCLR0,DSEL1);

WRITEBYTE(IOPIN0,CA7SEG_2_MUX,seglut[i%10]);
SSETBIT(IOSET0,DSEL2);
delay_ms(1);
SCLRBIT(IOCLR0,DSEL2);
}

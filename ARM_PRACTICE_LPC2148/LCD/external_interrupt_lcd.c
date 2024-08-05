//external_interrupt_lcd.c
#include<lpc21xx.h>
#include"types.h"
#include"defines.h"
#include"lcd_defines.h"
#include"lcd.h"
#include"delay.h"

#define EINT1_PIN 3
#define FUN4 3
#define EINT1_PIN_FUN FUN4
#define CFGPIN(WORD,BITPAIRPOS,FUN) WORD=((WORD&(~(3<<BITPAIRPOS)))|(FUN<<BITPAIRPOS))

 void eint1_isr(void)__irq
	  {
	  cmdLCD(GOTO_LINE2_POS0);
	  strLCD("IN ISR");
	  delay_ms(1000);
	  cmdLCD(GOTO_LINE2_POS0);
	  strLCD("                ");
	  cmdLCD(GOTO_LINE2_POS0);
	  strLCD("EXIT ISR");
	  EXTINT=0x02;
	  VICVectAddr=0;
	  }
void Enable_EINT1(void)
	  {
	  CFGPIN(PINSEL0,6,EINT1_PIN_FUN);
	  EXTMODE=0X02;
	  EXTPOLAR=0X02;
	  VICIntEnable=1<<15;
	  VICVectCntl0=1<<5|15;
	  VICVectAddr0=(unsigned)eint1_isr;
	  }
	   u32 count;
	   main()
	   {
	   InitLCD();
	   Enable_EINT1();
	   while(1)
	   {
	   cmdLCD(GOTO_LINE2_POS0);
	   strLCD("IN MAIN");
	   delay_ms(2000);
	   cmdLCD(CLRSCR);
	   count++;
	   }
	   }

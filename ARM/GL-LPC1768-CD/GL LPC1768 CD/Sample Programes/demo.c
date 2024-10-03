/*----------------------------------------------------------------------------
 *      Name:    DEMO.C
 *      Purpose: USB HID Demo
 *      Version: V1.20
 *----------------------------------------------------------------------------
 *      This software is supplied "AS IS" without any warranties, express,
 *      implied or statutory, including but not limited to the implied
 *      warranties of fitness for purpose, satisfactory quality and
 *      noninfringement. Keil extends you a royalty-free right to reproduce
 *      and distribute executable files created using this software for use
 *      on NXP Semiconductors LPC family microcontroller devices only. Nothing 
 *      else gives you the right to use this software.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include "LPC17xx.H"                        /* LPC17xx definitions */
#include "ps2kbd.h"
#include "type.h"
//#include "i2c.c"
#include "usb.h"
#include "usbcfg.h"
#include "usbhw.h"
#include "demo.h"
#include "lcd.h"
#include "adc.h"
#include "uart.h"
#include "ps2kbd.h"
#include "extint.h"
#include "led.h"
#include "dac.h"
#include "spi.h"
#include "74HC595.h"
#include "can.h"
#include "lpc2000_spi.h"

#if POWERDOWN_MODE_USB_WAKEUP
#include "timer.h"
extern volatile uint32_t SuspendFlag;
extern volatile uint32_t timer0_counter;
extern volatile uint32_t USBActivityInterruptFlag;
volatile uint32_t WakeupFlag = 0;
#endif



#define  I2C_SPEED_100   0
#define  EEPROM_24XX256  7

int m24xx_write(
    int eeprom_type,    //-- EEPROM type
    int eeprom_addr,    //-- start eeprom addr ( not included Hardware A2,A1,A0)
    int eeprom_cs_val,  //-- Hardware A2,A1,A0 (valid from 24XX32)
    char * buf,         //-- Data src buf
    int num);           //-- Bytes to write qty

int m24xx_read(
  int eeprom_type,    //-- EEPROM type
  int eeprom_addr,    //-- start eeprom addr ( not included Hardware A2,A1,A0)
  int eeprom_cs_val,  //-- Hardware A2,A1,A0 (valid from 24XX32)
  char * buf,         //-- Data dst buf
  int num);           //-- Bytes to read qty

void i2c_lpc_init(int Mode);

unsigned int val_Tx = 0, val_Rx = 0; 


uint8_t InReport;                              /* HID Input Report    */
                                            /*   Bit0   : Buttons  */
                                            /*   Bit1..7: Reserved */

uint8_t OutReport;                             /* HID Out Report      */
                                            /*   Bit0..7: LEDs     */


/*
 *  Get HID Input Report -> InReport
 */

void GetInReport (void) {
  uint32_t kbd_val;

  kbd_val = (LPC_GPIO1->FIOPIN >> 20) & KBD_MASK;

  InReport = 0x00;
  if ((kbd_val & KBD_UP)     == 0) InReport |= 0x01;  /* up     pressed means 0 */
  if ((kbd_val & KBD_LEFT)   == 0) InReport |= 0x02;  /* left   pressed means 0 */
  if ((kbd_val & KBD_RIGHT)  == 0) InReport |= 0x04;  /* right  pressed means 0 */
  if ((kbd_val & KBD_SELECT) == 0) InReport |= 0x08;  /* select pressed means 0 */
  if ((kbd_val & KBD_DOWN)   == 0) InReport |= 0x10;  /* down   pressed means 0 */
}


/*
 *  Set HID Output Report <- OutReport
 */

void SetOutReport (void) {
  static unsigned long led_mask[] = { 1<<28, 1<<29, 1UL<<31, 1<<2, 1<<3, 1<<4, 1<<5, 1<<6 };
  int i;

  for (i = 0; i < LED_NUM; i++) {
    if (OutReport & (1<<i)) {
      if (i < 3) LPC_GPIO1->FIOPIN |= led_mask[i];
      else       LPC_GPIO2->FIOPIN |= led_mask[i];
    } else {
      if (i < 3) LPC_GPIO1->FIOPIN &= ~led_mask[i];
      else       LPC_GPIO2->FIOPIN &= ~led_mask[i];
    }
  }
}

/**
*******************************************************************
	Funtion Name : test_i2c_at24c256_flash()

	Description  : 

	Input        : 

	Output       : 

	Note         :
*****************************************************************
*/
int test_i2c_at24c256_flash(void)
{
  char  i=0;
  int status=1;
  char buf[128];

  for(i=0;i<sizeof(buf);i++)
    buf[i] = i;
  
  m24xx_write(EEPROM_24XX256, 0 , 0 , (char *)buf , sizeof(buf));

  for(i=0;i<sizeof(buf);i++)
    buf[i] = 0;

  m24xx_read(EEPROM_24XX256, 0 , 0 , (char *)buf , sizeof(buf));

  for(i=0;i<sizeof(buf);i++)
  {
    if(buf[i] != i)
    {
      status = 0;
      break;
    }    
  }

  if(status == 1)
  {
    for(i=0;i<sizeof(buf);i++)
      buf[i] = sizeof(buf)-1-i;
    
    m24xx_write(EEPROM_24XX256, 0 , 0 , (char *)buf , sizeof(buf));
    
    for(i=0;i<sizeof(buf);i++)
      buf[i] = 0;
    
    m24xx_read(EEPROM_24XX256, 0 , 0 , (char *)buf , sizeof(buf));
    
	for(i=0;i<sizeof(buf);i++)
    {
      if(buf[i] != sizeof(buf)-1-i)
      {
        status = 0;
        break;
      }
    }
  }
  
	return status;
}

#define LED_ON_OFF_DELAY 1000000
extern volatile uint32_t UART0Count;
extern volatile uint8_t UART0Buffer[BUFSIZE];
extern volatile uint32_t UART1Count;
extern volatile uint8_t UART1Buffer[BUFSIZE];




/**
********************************************************************************************
	Function Name :	process_kbd()

	Description :
	
	Input :	Void

	Output : Void

	Note :
**********************************************************************************************
*/
void process_kbd(int8_t key)
{
  static int8_t position = 0;
	
  if(is_valid_ascii(key))
  {
    lcd_gotoxy(LINE2, position);
    lcd_putchar(key);
    if(position == MAX_CHAR_IN_ONE_LINE)
    {
      lcd_clear();
      position = 0;
    }		
    position++;
  }
}

void DAC_test(void)
{
	uint32_t i=0,j=0;
	uint32_t k=0;

  for(k=0;k<10000;k++)
  {
	LPC_DAC->DACR = (i << 6) | DAC_BIAS;
	i++;
	for(j = 1000; j > 1; j--);
	if ( i == 1024 )
	{
	  i = 0;
	}
  }
}

void test_leds_n_buzzer(void)
{
	int i=0, j=0;
	LPC_GPIO1->FIODIR |= (1<<29);
	LPC_GPIO2->FIODIR |= (1<<11);

	for(j=0; j <4 ;j++ )
	{
		LPC_GPIO1->FIOSET = (1<<29);
		LPC_GPIO2->FIOCLR  = (1<<11);
		turn_on_all_leds();

		for(i=0;i<LED_ON_OFF_DELAY;i++);
		
		LPC_GPIO1->FIOCLR  = (1<<29);
		LPC_GPIO2->FIOSET = (1<<11);
		turn_off_all_leds();

		for(i=0;i<LED_ON_OFF_DELAY;i++);
	}
}
#define GET_SCALED_LED_MASK_BUF_INDEX(val) (val/114)


const int8_t led_mask_buf[] = {0,1,3,7,0xF,0x1F,0x3F,0x7F,0xFF};
/**
********************************************************************************************
	Function Name :	process_adc()

	Description :
	
	Input :	Void

	Output : Void

	Note :
**********************************************************************************************
*/
void process_adc(void)
{
  int16_t adc_value = 0;
  int8_t index = 0;

  adc_value = ADC0Read(2);
  index = GET_SCALED_LED_MASK_BUF_INDEX(adc_value);
  if(index > sizeof(led_mask_buf))
    index = sizeof(led_mask_buf) -1;
  turn_on_led(led_mask_buf[index]);
}


/*----------------------------------------------------------------------------
  initialize CAN interface
 *----------------------------------------------------------------------------*/
void can_Init (void) {

  CAN_setup (1);                                  /* setup CAN Controller #1 */
  CAN_setup (2);                                  /* setup CAN Controller #2 */
  CAN_wrFilter (1, 33, STANDARD_FORMAT);          /* Enable reception of messages */

  CAN_start (1);                                  /* start CAN Controller #2 */
  CAN_start (2);                                  /* start CAN Controller #2 */

  CAN_waitReady (1);                              /* wait til tx mbx is empty */
  CAN_waitReady (2);                              /* wait til tx mbx is empty */
}

void can_test(void)
{
	int32_t	i=0;
  
  	CAN_TxMsg[1].id = 33;                           /* initialise message to send */
  	for (i = 0; i < 8; i++) CAN_TxMsg[0].data[i] = 0;
  	CAN_TxMsg[1].len = 1;
  	CAN_TxMsg[1].format = STANDARD_FORMAT;
  	CAN_TxMsg[1].type = DATA_FRAME;
 	
	val_Tx = 0xAA;
    if (CAN_TxRdy[1]) {                           /* tx message on CAN Controller #2 */
      CAN_TxRdy[1] = 0;

      CAN_TxMsg[1].data[0] = val_Tx;             /* data[0] field = ADC value */
      CAN_wrMsg (2, &CAN_TxMsg[1]);               /* transmit message */
    }

    for(i=0;i<10000;i++);                        /* Wait a while to receive the message */

    if (CAN_RxRdy[0]) {                           /* rc message on CAN Controller #1 */
      CAN_RxRdy[0] = 0;

      val_Rx = CAN_RxMsg[0].data[0];
	}

	if(val_Tx == val_Rx)
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
}

/**
*******************************************************************
	Funtion Name : init_sdcard()

	Description  : 

	Input        : 

	Output       : None

	Note         :
*****************************************************************
*/
U8 init_sdcard(void);
U8 init_sdcard(void)
{
 if(if_initInterface(0)==0)
 return 1;
 else
 return 0;
}
/**
*******************************************************************
	Funtion Name : test_sd_card()

	Description  : 

	Input        : 

	Output       : None

	Note         :
*****************************************************************
*/
void test_sd_card(void);
void test_sd_card(void)
{
  if(init_sdcard())
  {
    //lcd_clear();
    lcd_putstring(LINE2,"SD card - PASS");
  }
  else
  {
    //lcd_clear();
    lcd_putstring(LINE2,"SD card - FAIL");
  }
}

/* Main Program */

int main (void) {

	volatile int i=0,j=0;

	SystemInit();                         /* initialize clocks */
	init_lcd();
	lcd_backlight_on();	
  	lcd_putstring(0," NGX-Blueboard ");
  	lcd_putstring(1,"    LPC1768   ");
	init_keyboard();
	SPIInit();

	test_leds_n_buzzer();

	lcd_clear();

	i2c_lpc_init(I2C_SPEED_100);
	if( test_i2c_at24c256_flash() == 1)
	{
		lcd_putstring(0,"I2C EEPROM-PASS");	
	}
	else
	{
		lcd_putstring(0,"I2C EEPROM-FAIL");
	}

	test_sd_card();
	ADCInit(ADC_CLK);
	EINTInit();
	
  	UARTInit(0, 38400);	/* baud rate setting */
  	UARTInit(1, 38400);	/* baud rate setting */
	

	DACInit();
	DAC_test();


	USB_Init();                           /* USB Initialization */
	USB_Connect(TRUE);                    /* USB Connect */
	while (1) 
	{
	if(keyhit())
    		{
     		 
			 process_keyboard();
    
			}

	  if ( UART0Count != 0 )
		{
			  LPC_UART0->IER = IER_THRE | IER_RLS;			/* Disable RBR */
			  UARTSend( 0, (uint8_t *)UART0Buffer, UART0Count );
			  UART0Count = 0;
			  LPC_UART0->IER = IER_THRE | IER_RLS | IER_RBR;	/* Re-enable RBR */			  
		}
		if ( UART1Count != 0 )
		{
			  LPC_UART3->IER = IER_THRE | IER_RLS;			/* Disable RBR */
			  UARTSend( 1, (uint8_t *)UART1Buffer, UART1Count );
			  UART1Count = 0;
			  LPC_UART3->IER = IER_THRE | IER_RLS | IER_RBR;	/* Re-enable RBR */
		}
		process_adc();
	}

}


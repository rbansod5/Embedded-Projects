/*****************************************************************************
 *   extint.c:  External interrupt API C file for NXP LPC17xx 
 *   Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
*****************************************************************************/
#include "lpc17xx.h"
#include "type.h"
#include "extint.h"

volatile uint32_t eint0_counter;

/*****************************************************************************
** Function name:		EINT0_Handler
**
** Descriptions:		external INT handler
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
volatile int int_count=0;

void EINT2_IRQHandler (void) 
{
  	int i=0;
	
	int_count++;

  	LPC_GPIO2->FIOCLR  = (1<<11);
  	for(i=0;i<1000000;i++);
	LPC_GPIO2->FIOSET  = (1<<11);

	LPC_SC->EXTINT = EINT2;		/* clear interrupt */	
}

/*****************************************************************************
** Function name:		EINTInit
**
** Descriptions:		Initialize external interrupt pin and
**						install interrupt handler
**
** parameters:			None
** Returned value:		true or false, return false if the interrupt
**						handler can't be installed to the VIC table.
** 
*****************************************************************************/
uint32_t EINTInit( void )
{
	  
  LPC_PINCON->PINSEL4 &= ~(0x03000000);
  LPC_PINCON->PINSEL4 |= (0x01000000);	/* set P2.12 as EINT1 and  */  
 // LPC_GPIOINT->IO2IntEnF |= 0xFFFF;	/* Port2.12 is falling edge. */
  LPC_SC->EXTMODE |= EINT2_EDGE;		/* INT2 edge trigger */
  LPC_SC->EXTPOLAR = 0;				/* INT2 is falling edge by default */

  NVIC_EnableIRQ(EINT2_IRQn);
  return( TRUE );
}

/******************************************************************************
**                            End Of File
******************************************************************************/


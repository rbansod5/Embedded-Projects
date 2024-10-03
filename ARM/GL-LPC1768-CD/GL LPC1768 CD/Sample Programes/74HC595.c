#include "type.h"
#include "lpc17xx.h"

#include "spi.h"
#include "74HC595.h"
//#include "led.h"

#define PARALLEL_DATA_HIGH_74HC595 0xFF
#define PARALLEL_DATA_LOW_74HC595 0x00

#define LATCH_SET() (LPC_GPIO0->FIOSET = STCP)
#define LATCH_CLR() (LPC_GPIO0->FIOCLR = STCP)

/**
********************************************************************************************
	Function Name :	parallel_data_output_high_74hc595()

	Description :
	
	Input :	Void

	Output : Void

	Note :
**********************************************************************************************
*/
void parallel_data_output_high_74hc595()
{
  uint8_t data = PARALLEL_DATA_HIGH_74HC595;

  LATCH_CLR();
  SPISendN(&data, sizeof(data));
  LATCH_SET();
}

/**
********************************************************************************************
	Function Name :	parallel_data_output_low_74hc595()

	Description :
	
	Input :	Void

	Output : Void

	Note :
**********************************************************************************************
*/
void parallel_data_output_low_74hc595()
{
  uint8_t data = PARALLEL_DATA_LOW_74HC595;

  LATCH_CLR();
  SPISendN(&data, sizeof(data));
  LATCH_SET();
}

/**
********************************************************************************************
	Function Name :	turn_on_led()

	Description :
	
	Input :	Void

	Output : Void

	Note :
**********************************************************************************************
*/
void turn_on_led(uint8_t led_mask) 
{
  LATCH_CLR();
  SPISendN(&led_mask, sizeof(led_mask));
  LATCH_SET();	
}


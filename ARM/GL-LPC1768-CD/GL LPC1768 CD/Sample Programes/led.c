#include "74HC595.h"
#include "type.h"
#include "led.h"


#define MAX_NUM_OF_LED_TOGGLE 3

#define MAX_INTENSITY_VALUE 1023
#define MAX_ON_PERIOD 20
#define GET_SCALED_VALUE(i) (i/50)



/**
*******************************************************************************
  Function Name : leds_on()

  Description :	 

  Input :	none
  
  Output :	none

  Note : 
*******************************************************************************
*/
void turn_on_all_leds(void)
{
  parallel_data_output_high_74hc595();
}

/**
*******************************************************************************
  Function Name : leds_off()

  Description :	 

  Input :	none
  
  Output :	none

  Note : 
*******************************************************************************
*/
void turn_off_all_leds(void)
{
  parallel_data_output_low_74hc595();
}




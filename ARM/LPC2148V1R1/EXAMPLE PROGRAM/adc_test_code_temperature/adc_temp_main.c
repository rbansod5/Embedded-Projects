#include"prototype.h"

  	int main()
	{
		int temp_value;
		lcd_init();
		lcd_print("Lcd Initilized");
		Delay(2000);
		lcdcmd(0x01);
		adc0_init_temperature();
	
		lcd_print("ADC Initilized");
		Delay(2000);
		lcdcmd(0x01);
		
		while(1)
		{
			temp_value = adc_read_value_temperature();
			temp_value /= 3;
			
			lcdcmd(0x01);
			lcd_print("Temperature :");
			lcdcmd(0xc0);
			display(temp_value);
			Delay(1000);
		}

	}

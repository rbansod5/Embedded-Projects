#include"prototype.h"

  	int main()
	{
		int Pot_value;
		lcd_init();
		lcd_print("Lcd Initilized");
		lcdcmd(0x01);
		adc0_init_pot();
	
		lcd_print("LDR Initilized");
		lcdcmd(0x01);
		
		while(1)
		{
			Pot_value = adc_read_value_pot();
				
			lcdcmd(0x01);
			lcd_print("LDR :");
			lcdcmd(0xc0);
			display(Pot_value);
			Delay(1000);
		}

	}

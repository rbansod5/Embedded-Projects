
	#include "prototype.h"

	void adc0_init_pot(void)
	{
		PINSEL1 |= (1 << 18) |(0 << 19);// FOR ADC3  port 0.25
		ADCR = adc0_init_macro;
	} 

	int adc_read_value_pot(void)
	{
		unsigned int done = 1;
		int sample = 8;
		int result = 0;
		int sum = 0;
		while(sample)
		{
		
			while(!(ADDR & (done << 31)));
			result = (ADDR >> 6) & 0X3FF;
			sum += result; // finding sum to find average	
			sample--;
		}
		sum = (sum >> 3);	//rght shifting 3 is same as dividing by 8
		return(sum);

	}

/** Implementing a function for generating the delay 
               using Embedded C **/
void delay_ms(unsigned int ms_dly)
{
	unsigned int i;
	for(ms_dly;ms_dly>0;ms_dly--)
		for(i=122;i>0;i--);	   //121 got 6 mc less 
                               //122 got 2 mc extra 
}
	#include<LPC214X.H>
	/*--------------------------------------------------------
	MACRO FOR ADC
	-------------------------------------------------------- */
//	#define ch (1 << 3)
	#define ch (1 << 2)
	#define clk_div (3 << 8)
	#define bst_on (1 << 16)
//#define bst_off (0 << 16)
	#define clk_res (0 << 17)
	#define operational (1 << 21)
	#define start (0 << 24)
	#define adc_init_macro ch | clk_div | bst_on | clk_res | operational | start
	/*-------------------------------------------------------------
	MACRO FOR LCD
	---------------------------------------------------------------*/
	#define EN (1 << 13)
	#define RW (1 << 12)
	#define RS (1 << 10)
	#define DATA  (0Xff << 16)
	#define port  EN | RW | RS | DATA
	/*---------------------------------------------------------------
	MACRO FOR LED AND BUZZ
	---------------------------------------------------------------*/
	#define LED (1 << 21)
	#define BUZ	(1 << 25)
/*----------------------------------------------------------------------
FUNCTION DECLARATIONS
-----------------------------------------------------------------------*/
		void adc_init(void);
		void delay(int count);
		void cmd(int c);
		void data(char d);
		void lcd_string(char *str);
		void display(unsigned int n);
		
/*----------------------------------------------------------------------------
		GLOBAL VARIABLES
-----------------------------------------------------------------------------*/
		unsigned int result;
		long int temp = 1;
/*-------------------------------------------------------------------------------
		FUNCTION DEFINITIONS
---------------------------------------------------------------------------------*/
		void adc_init(void)
		{
			AD0CR = adc_init_macro;
		} 
		void cmd(int c)
		{
			IOPIN0 = c << 16;
			IOCLR0 = RW;
			IOCLR0 = RS;
			IOSET0 = EN;
			delay(100); 
			IOCLR0 = EN;
		}
		void data(char d)
		{
			IOPIN0 = d << 16;
			IOCLR0 = RW;
			IOSET0 = RS;
			IOSET0 = EN;
			delay(100); 
			IOCLR0 = EN;
		}

		void lcd_string(char *str)
		{
			while(*str)
			{
				data(*str);
				str++;
				delay(20);
			}
		}
		void display(unsigned int n)
		{ 
			if(n == 0)
				data(n+0x30);
			if(n)
			{
				display(n / 10);
				data((n % 10) + 0x30);
			}
		} 

		void delay(int count)
		{
			int i,j;
			for(i = 0;i < count;i++)
				for(j = 0;j < 5000;j++);
		} 
/*-------------------------------------------------------------------
MAIN
---------------------------------------------------------------------*/
			int main()
			{
				int c = 0;
				IODIR0 |= port ;
			//	PINSEL1 = ((1 << 28) | (0 << 29));	// p0.30  adcchannel ADC0.3	temperature sensor
				PINSEL1 = ((1 << 26) | (0 << 27));	//po.29 ADc channel ADC0.2	  pot 
				
				cmd(0x38);
				cmd(0x0E);
				cmd(0X80);
				cmd(0X01);

				adc_init();
				lcd_string("ADC PROGRAM");
				cmd(0X01); 
				while(1)
				{
					cmd(0x01);
					while(!(AD0DR2 & (0x80000000)));
				 	result = (AD0DR2 & (0X3FF << 6));
					result = result >> 6;
					lcd_string("ADC:");
					cmd(0x86);
					display(result/3);  //only in the case of temperature sensor
					//display(result);  //only in the case of temperature sensor
					cmd(0xc0);
					delay(1000);
				}	 	
			
			}








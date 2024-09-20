


/* Flash eight Active Low LEDs upto 10 times @500ms */

#include<reg51.h>

#define seg_cat P2//seg1 a-dp & seg2 a-dp pins can short & connect to P2	

sbit seg1_anode=P3^0;
sbit seg2_anode=P3^1;


void delay_ms(unsigned int dly)
{
	unsigned int i;
	for(dly;dly>0;dly--)
		for(i=122;i>0;i--);//In 8051 for integer variable iteration 8 MC are taking=121x8=968
}//ret;2mc




//Display 0-99 on 2, 7-segments

unsigned char seg_lut[]={0xC0,0xF9,0xA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
main()
{
	unsigned char i;
	unsigned int dly;
	for(i=0;i<=99;i++)
	{
		for(dly=100;dly>0;dly--)//this is for delay for each & every number
		{
			seg_cat=seg_lut[i/10];//1st digit
			seg1_anode=1;				  // Pass logic 1 on 1st segment anode pin
			delay_ms(5);
			seg1_anode=0;				  // Pass logic 0 on 1st segment anode pin
	
			seg_cat=seg_lut[i%10];//2nd digit
			seg2_anode=1;				  // Pass logic 1 on 2nd segment anode pin
			delay_ms(5);
			seg2_anode=0;				  // Pass logic 0 on 2nd segment anode pin
				
		}
	
	}
}

#include<reg51.h>

#define seg_7 P1	


unsigned char seg_lut[]={0xC0,0xF9,0xA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

void delay_ms(unsigned int dly)
{
	unsigned int i;
	for(dly;dly>0;dly--)
		for(i=122;i>0;i--);//In 8051 for integer variable iteration 8 MC are taking=121x8=968
}//ret;2mc

//0-9
main()
{
			
	unsigned char index;
	while(1)
	{
	for(index=0;index<10;index++)
	{
		seg_7=seg_lut[index];
		delay_ms(500);	
	}
	}
	//while(1);
} //ret

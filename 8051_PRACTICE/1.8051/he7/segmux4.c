



#include<reg51.h>

#define seg_cat P2//seg1 a-dp & seg2 a-dp seg3 & seg4 a-dppins can short & connect to P2	

sbit seg1_anode=P3^0;
sbit seg2_anode=P3^1;
sbit seg3_anode=P3^2;
sbit seg4_anode=P3^3;


void delay_ms(unsigned int dly)
{
	unsigned int i;
	for(dly;dly>0;dly--)
		for(i=122;i>0;i--);//In 8051 for integer variable iteration 8 MC are taking=121x8=968
}//ret;2mc

unsigned char seg_lut[]={0xC0,0xF9,0xA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};


void displayinteger(unsigned int );

void displayinteger(unsigned int num)
{

//			1234			----->			1
		seg_cat=seg_lut[num/1000];
		seg1_anode=1;//seg1 is on
		delay_ms(5);
		seg1_anode=0;//seg1 is off
		
//				1234 ---------->			2
		seg_cat=seg_lut[(num/100)%10];
		seg2_anode=1;//seg2 is on
		delay_ms(5);
		seg2_anode=0;//seg2 is off
//				1234  --------->            3

		seg_cat=seg_lut[(num/10)%10];
		seg3_anode=1;
		delay_ms(5);
		seg3_anode=0;
//				1234 ---------------->4
		seg_cat=seg_lut[num%10];
		seg4_anode=1;
		delay_ms(5);
		seg4_anode=0;

}


main()
{
	unsigned int dly;
	seg1_anode=seg2_anode=seg3_anode=seg4_anode=0;//off
//	for(num=0;num<4567;num++);
//	{
		for(dly=100;dly>0;dly--)
		{	
			displayinteger(4567);						
		}		
	} 
}




 





/* Display 0-99 on 2,7-segments */

#include<reg51.h>

#define seg1_7 P2//a-dp	
#define seg2_7 P3//a-dp


void delay_ms(unsigned int dly)
{
	unsigned int i;
	for(dly;dly>0;dly--)
		for(i=122;i>0;i--);//In 8051 for integer variable iteration 8 MC are taking=121x8=968
}//ret;2mc


unsigned char seg_lut[]={0xC0,0xF9,0xA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
main()
{
	unsigned char i;
	for(i=0;i<=99;i++)
	{
		seg1_7=seg_lut[i/10];		//2/10=0	//12/10=1
		seg2_7=seg_lut[i%10];		//2%10=2	//12%10=2
		delay_ms(500);	
	}
}

/*num=1234 on 4 segments


1	2	3	4 as individual digits


seg_lut[num%10]= 10)1234(123
			1230
			______
				4  - seg_lut[4]=seg4


1234		-		3

1234/10=123%10=3

seg_lut[(num/10)%10] -seg3

1234		-		2

seg_lut[(num/100)%10)  -  seg2


1234		-		1

seg_lut[num/1000] - seg1












			_____
*/




/* Display 0-99 on 2,7-segments */

#include<reg51.h>
#include"delay.h"
#define seg1_7 P2	
#define seg2_7 P3

 

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
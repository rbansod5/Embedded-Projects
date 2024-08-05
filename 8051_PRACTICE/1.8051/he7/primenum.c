


#include<reg51.h>
#define leds_8 P2

bit flag;

main()
{

	for(int isprimenum=0;isprimenum<=255;isprimenum++)
	{
		flag=0;
		for(int j=2;j<isprimenum/2;j++)
		{
			if(isprimenum%j==0)
				flag=1;
		}
		if(flag==0)
		{	
		  leds_8 =isprimenum;
		  delay_ms(500);
		} 	
	} 
}

void delay_ms(unsigned int dly)
{
	unsigned int i;
	for(dly;dly>0;dly--)
		for(i=122;i>0;i--);//In 8051 for integer variable iteration 8 MC are taking=121x8=968
}
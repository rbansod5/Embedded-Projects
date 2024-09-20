#include<reg51.h>

sbit led=P1^0;


void delay_ms(unsigned int dly);

main()
{

	while(1)
	{
		led=0;//AL LED ON
		delay_ms(500);
		led=1;//AL LED OFF
		delay_ms(500);
	}
}

void delay_ms(unsigned int dly)
{
	unsigned int i;
	for(dly;dly>0;dly--)
		for(i=122;i>0;i--);//In 8051 for integer variable iteration 8 MC are taking=121x8=968
}
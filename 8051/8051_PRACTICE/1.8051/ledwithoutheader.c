



/* Flash a Active Low LED upto 10 times */



#include<reg51.h>


sbit led=P1^0;

main()
{
	char i;
	for(i=0;i<10;i++)
	{
		led=0;
		led=1;
	}
}

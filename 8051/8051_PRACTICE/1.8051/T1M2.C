




#include<reg51.h>

/*Generate 200us using T1M2*/
/*
TMOD=	GATE	C/Tbar	M1	M0	GATE	C/Tbar	M1	M0
		0		0		1	0	0		0		0	0
		8		4		2	1	8		4		2	1
				2						0				=0X20


RTD=200us
MTD based on Mode = 256

DTD  =  MTD   -   RTD
	 =	256   -   200
	 =	56US

1MC=1USEC @12MHz CF
6US 	= 56MC
*/
main()
{
	TMOD=0X20;
	TH1=TL1=56;
	TR1=1;
	while(TF1==0);
	TR1=0;
	TF1=0;
}

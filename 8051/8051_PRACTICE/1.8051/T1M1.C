

/* Generate 1ms using T1M1 */

/*TMOD = GATE	C/Tbar	M1	M0	GATE	C/Tbar	M1	M0
		0	0		0	1	0		0		0	0
				TIMER1				TIMER0
		8	4		2	1		0
0X				1				0						-	TIMER1MODE1

RTD=1MS=1000MC for 12MHz frequency


DTD=MTD-RTD
MTD for Mode1 - 16 bit timer - 2^16-65536
DTD=65536-1000;
DTD=64536;
1)Convert into Binary lower 8 bit load into TL1 & Higher 8 bit load into TH1
2) DTD/256,DTD%256
3) TH1=DTD>>8;//Lower byte left out, hogher byte will come into lower position
	TL1=DTD;//Lower byte will assign & higher byte will ignore

Starts the timer.It is Timer1. So, Make TR1=1;
Wait for overflow flag till it is getting high.It is timer1. So wait till the TF1 flag is 1
When it is 1 clear TR1 & TF1*/

#include<reg51.h>
main()
{
	TMOD=0X10;//T1M1
	TH1=64536>>8;
	TL1=64536;
	TR1=1;
	while(TF1==0);
	TR1=0;
	TF1=0;
}

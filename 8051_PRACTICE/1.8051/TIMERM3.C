


/* In 8051 CPU 
For Timer0 We should use
1)Lower nibble of TMOD
2)TH0
3)TL0
4)TR0 & TF0 which is in TCON register

For Timer1 We should use
1)Higher nibble of TMOD
2)TH1
3)TL1
4)TR1 & TF1 which is in TCON register

Above steps suitable for MODE0,1&2


In MODE3:
Time1 is Disabled in Mode3
So, If we select T1M3 no use. Because of that TR1 & TF1 bits are free at T1M#

Timer0 Mode3 - capability is 8bit - 2^8=256 - 0-255
To load 8 bit value one register is sufficient either TL0 or TH0
By default TL0 will take to load the Value
So, TH0 is free in TIMER0
TR1 & TF1 bits are free in Timer1
By considering above 2 points manufacturer provided one extra option for Timer0 Mode3 only

Ans: TR1 & TF1 bits are controlling for TH0 - 8bit
	 TR0 & TF0 bits are controlling for TL0 - 8bit

As per above answer 2, 8bits are splitted for Timer0

*/

#include<reg51.h>
main()
{
	TMOD=0X33;//mode3
	TH0=TL0=56;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
	TR1=1;
	while(TF1==0);
	TR1=0;
	TF1=0;
}

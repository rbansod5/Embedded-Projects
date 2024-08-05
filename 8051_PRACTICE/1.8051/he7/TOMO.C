



/* Generate 1ms delay using Timer0Mode0 */
/*
1) Select Specific Timer & Specific Mode, Select counter/Timer, Select S/w or H/w Comtrol

Based on requirement 

Lower nibble of TMOD we need to select based on requirement, because lower nibble representing 
Timer0

Mode0 - 13 bit timer - 2^13- 8192 using M1 & M0 bits we can select Mode0

C/T bar bit can make 0 for Timer

GATE bit make 0 to starts timer through S/W


GATE	C/Tbar	M1	M0	GATE	C/Tbar	M1	M0
0		0		0	0	0		0		0	0	-0X00-TMOD

2)Load the values into TH0 & TL0 registers
	Desired Time Delay(DTD)=Maximum Time Delay based on mode(MTD) - Required Time Delay(RTD)
RTD is nothing our requirement.How much delay are we going to generate
MTD for Mode0 - 8192
	for Mode1 - 65536
	for Mode2&3 - 256
DTD value has to store into TH0 & TL0

	DTD=8192-1MS

1MS= CONVERT INTO MACHINE CYCLES

MS  ---->  US   ---->	MC

1X10^-3X10^-3/10^-3=1X10^-6X10^3=1000USECS

If CF= 12MHz 1MC=1Usec =MCT=12/f
1000USecs=1000x1USec=1000x1MC=1000MC 

DTD=8192-1000 @12MHz frequency

DTD=7192 = 13 bits

1)7192 convert into binary - higher 8 bits load into TH0 and lower 5 bits load into TL0
2)7192/32=TH0  & 7192%32=TL0 basednon below formula
TH0=8BITS=2^8=256,  TL0=5BITS=2^5=32     256X32=8192	8192/32= 256-Q  0 - reminder
3)7192>>5=TH0  7192&0x1f=TL0

TH0
HIGHER 8 BITS
D12-D5					D4-D0
TH0						TL0


3)Start Timer by using TR0 bit
Make TR0=1

4) Check overflow flag with TF0
By default it is 0

After TR0=1

Machine cycles will add into TH0 & TL0

At one point both registers will reach Maximum to Minimum

In Mode0 8191 to 0

Then automatically through internal H/W TF0 bit will get high

When it is High then we got RTD

TH0 & TL0  - 7192,7193,7194,7195----------8191 to 0 
When TF0 is 1
5)StoP Timer by making TR0=0;
6)Clear overflow falg by making TF0=0
*/

#include<reg51.h>
main()
{
	TMOD=0X00;//T0M0
	TH0=7192>>5;//LOWER 5 BITS LEFT OUT & HIGHER 8 BITS STORED INTO TH0
	TL0=7192&0X1F;//0X1F-11111- SO, WE WILL GET LOWER 5 BITS, REMAINING BITS WILL CLEAR
	TR0=1;
	while(TF0==0);//WAIT TILL THE MAX VALUE IS REACHED
	TR0=0;
	TF0=0;
}

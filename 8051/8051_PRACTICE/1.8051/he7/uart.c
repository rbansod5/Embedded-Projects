#include<reg51.h>
#include"lcddef.c"

void Init_UART(void)
{
	SCON=0x50;//REN,Frame format by selecting mode(M1) of operation
	TMOD=0x20;//Timer 1 in mode 2
	TH1=TL1=253;//9600 baud rate @Fosc=11.0592MHz
	TR1=1;//Timer 1 runs 
}
unsigned char RxCharUART(void)
{
	while(RI==0);//waiting for the data to arrive
	//while receiving, bits will receive from P3.0-RXD - each bit is storing into SBUF
	// If SBUF is full of 8 bit data, half of stop bit is received. then internal H/W will make RI=1 
	RI=0;
	return(SBUF);//received data in SBUF register	
}
void TxCharUART(unsigned char ch)
{
	SBUF=ch;//Load character which is going to be transmitted
	//When transmission is completed SBUF is Empty
	//If TI=1, then transmission is completed
	while(TI==0);//waiting for transmission
	TI=0;
}

main()
{
	char ch;
	Init_UART();
	initlcd();
	while(1)
	{
	ch=RxCharUART();//8051 CPU is receiving the character from UART based device. Assume that here the
	// device is PC.From Keyboard hit character, that character will be taken by PC CPU,from CPU
	// through RS-232 cable passing the data to MAX232. From MAX 232 to 8051 CPU will receive 
	// by connecting respective pins
/*	keyboard--->cpu---->db9 port with rs-232 cable transmitter pin ----> MAX232R1IN 
	---->CONVERTING VOLTAGE LEVEL---R1OUT----->RXD pin of 8051uc  ----->SBUF
*/
	datalcd(ch);
	TxCharUART(ch);
	//8051 CPU---SBUF--->(TXD)--->MAX232T1IN ------>Internally converting  ----->T1OUT----->
	//RS232 CABLE -->RX PIN  -> PC based CPU will receive and passed on Monitor
	//In Monitor open Hyper Terminal/Flash Magic/X-CTU
	//There set the BR,FRAME FORMAT & COM PORT
	//Then data will display on respective terminal
	
	}
}

/*RS-232
_________________
logic1- -3v - -25v
logic0- +3v - +25v

MAX 232------------------- Voltage level converter - it is converting the voltage levels from RS-232  - TTL vice vers

TTL
_______________
logic1 -5v
logic0 -0v


*/

/*UART:SERIAL/FULL DUPLEX/ASYNCHRONOUS

SCON
SBUF
PCON

TMOD
TH1
TL1
TR1U IKL,

P3.0 -RXD
P3.1 -TXD

FULL DUPLEX
*/

/*UC   ------   PC   ------> MODE1 - UNIVERSAL STANDARD UART MODE


SM0	SM1	SM2	REN	TB8	RB8	TI	RI
0	1	0	1	0	0	0	0
8	4	2	1	8	4	2	1
	1X4	+1X1		0
	4	+	1		0
		5			0			-STANDARD UART MODE1 will enable for both transmission & reception


BR=2^SMODX11.0592X10^6/(12X32X256-TH1)
	=2^0X110592X10^2/(12X32X256-TH1)
9600=11059200/384X(256-TH1)
256-TH1=11059200/3686400
256-TH1=3
256-3=TH1
TH1=253

*/

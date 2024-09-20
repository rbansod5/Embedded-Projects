//keypad.h
		  /* Header Files */
#include<reg52.h>
//#include"delay.h"


/* Declaration : Row & coloumn Pins for Telephonic Keypad */
sbit C0=P2^0;       
sbit C1=P2^1;
sbit C2=P2^2;
sbit C3=P2^3;

sbit R0=P2^4;
sbit R1=P2^5;
sbit R2=P2^6;
sbit R3=P2^7;

unsigned char colscan();
 unsigned char keyscan();
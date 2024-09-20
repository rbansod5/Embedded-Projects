/*
--------------------------------------------------------------------------------------
Create a display on 8 LED’s (4-active high and 4-active low) 
connected to port0 (0.0-0.7) in the given pattern. 
    a. First all LEDs should be OFF, at 1st second, LED 0 and LED 7 (P0.0 and P0.7) 
	should be ON
    b. At 2nd second, LED 1 and LED 6 (P0.1 and P0.6) should be ON  
    c. At 3rd second, LED 2 and LED 5 (P0.2 and P0.5) should be ON 
    d. At 4th second, LED 3 and LED 4 (P0.3 and P0.4) should be ON
    e. Repeat above pattern for 5 times and stop the process.
--------------------------------------------------------------------------------------
*/

#include<LPC21xx.h>
#include"define.h"
#include"delay.h"
#define LED 0
#define sw1 16
#define sw2 17
#define sw3 18
#define sw4 19
int main()
{
WRITEBYTE(IODIR0,0,0xff);
WRITEBYTE(IOPIN0,0,0xf0);
SETNIBBLE(IODIR0,16,0xf);
while(1)
{
if(READBIT(IOPIN0,sw1)==0)

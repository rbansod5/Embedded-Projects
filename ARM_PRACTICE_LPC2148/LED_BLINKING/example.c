#include<LPC21XX.h>
//#include"defines.h"
#define SETBIT(WORD,BITPOS) (WORD|=(255<<BITPOS))
#define CLRBIT(WORD,BITPOS) (WORD&=~(255<<BITPOS))
#define CPLBIT(WORD,BITPOS) (WORD^=(255<<BITPOS))
#define WRITEBIT(WORD,BITPOS) (WORD=((WORD&=~(255<<BITPOS))|(255<<BITPOS)))

#define PIN 0
#include "delay.h"

int main()
{
//WRITEBIT(IODIR0,PIN);
IODIR0=0xff;
while(1)
{



WRITEBIT(IOPIN0,PIN);
delay_s(1);
CLRBIT(IOPIN0,PIN);
delay_s(1);
} 
}




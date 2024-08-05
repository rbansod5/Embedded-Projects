/*flash an led connected to any part line at the rate of 1se for for 10 times & stop*/
typedef unsigned char u8;
typedef unsigned int u32;
#include<LPC21XX.H>
#define SETBYTE(WORD,BITPOS,BTYE) (WORD|=BYTE<<BITPOS)
void delay_s(u32 delays)
{
delays*=12000000;
while(delays--);
}
#define SETBIT(WORD,BIT) (WORD|=1<<BIT)
#define CLRBIT(WORD,BIT) (WORD&=~(1<<BIT))
#define SETBYTE(WORD,BITPOS,BYTE) (WORD=|(BYTE<<BITPOS))
#define CLRBYTE(WORD,BITPOS,BYTE) (WORD&=~(BYTE<<BITPOS))
//writenibble(word,startbitpos,nibble) (word=((word&~(15<<startbitpos))|(nibble<<startbitpos)))
#define PIN 0
main()
{
u8 i;
SETBYTE(IODIR0,PIN,255);
for(i=0;i<=31;i++)
{
SETBYTE(IOPIN0,PIN,0x0f);
delay_s(3);
CLRBYTE(IOPIN0,PIN,255);
delay_s(3);
}

while(1);											  
}

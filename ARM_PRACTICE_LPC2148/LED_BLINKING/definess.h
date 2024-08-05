 //defines.h
(small letter)

#define setbit(word,bitpos) (word|=1<<bitpos)

#define clrbit(word,bitpos) (word&=~(1<<bitpos))

#define cplbit(word,bitpos) (word^=1<<bitpos)

#define writebit(word,bitpos,bit) (word=((word&~(1<<bitpos))|(bit<<bitpos)))

#define ssetbit(word,bitpos) (word=1<<bitpos)

#define sclrbit ssetbit

#define readbit(word,bitpos) ((word>>bitpos)&1)

#define readwritebit(dword,dbit,sword,sbit) ((dword&~(1<<dbit))|(((sword>>sbit)&1)<<dbit))               

#define writenibble(word,startbitpos,nibble) (word=((word&~(15<<startbitpos))|(nibble<<startbitpos)))

#define readnibble(word,startbitpos) ((word>>startbitpos)&15)

#define writebyte(word,startbitpos,byte) (word=((word&~(255<<startbitpos))|(byte<<startbitpos)))

#define readbyte(word,startbitpos) ((word>>startbitpos)&255)

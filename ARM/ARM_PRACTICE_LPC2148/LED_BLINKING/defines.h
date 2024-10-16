#define SSETBIT(WORD,BITPOS) (WORD=1<<BITPOS)
#define SETBIT(WORD,BITPOS) (WORD|=1<<BITPOS)
#define SETBYTE(WORD,BITPOS,BYTE) (WORD|=BYTE<<BITPOS)
#define SETNIBBLE(WORD,BITPOS,NIBBLE) (WORD|=NIBBLE<<BITPOS)
#define SCLRBIT    SSETBIT


#define CLRBIT(WORD,BITPOS)(WORD&=~(1<<BITPOS))
#define CLRNIBBLE(WORD,BITPOS,NIBBLE)(WORD&=~(NIBBLE<<BITPOS))
#define CLRBYTE(WORD,BITPOS,BYTE)(WORD&=~(BYTE<<BITPOS))


#define CPLBIT(WORD,BITPOS)(WORD^=1<<BITPOS)
#define CPLNIBBLE(WORD,BITPOS,NIBBLE)(WORD^=NIBBLE<<BITPOS)
#define CPLBYTE(WORD,BITPOS,BYTE)(WORD^=BYTE<<BITPOS)


#define SET(WORD,BITPOS,BIT) (WORD|=(BIT<<BITPOS))
#define CLR(WORD,BITPOS,BIT) (WORD&=~(BIT<<BITPOS))
#define CPL(WORD,BITPOS,BIT) (WORD^=(BIT<<BITPOS))
#define WRITE(WORD,BITPOS,BIT) (WORD=((WORD&=~(BIT<<BITPOS))|(BIT<<BITPOS)))


#define WRITEBIT(WORD,BITPOS,BIT) (WORD=((WORD&~(1<<BITPOS))|(BIT<<BITPOS)))
#define READBIT(WORD,BITPOS)((WORD>>BITPOS)&1)
#define READWRITEBIT(WORD,DBIT,SBIT)(WORD=(WORD&~(1<<DBIT))|(((WORD>>SBIT)&1)<<DBIT))
#define READWRITEBIT2(DWORD,WBIT,SWORD,RBIT)(DWORD=((DWORD&~(1<<WBIT))|(((SWORD>>RBIT)&1)<<WBIT)))
#define WRITENIBBLE(WORD,BITPOS,NIBBLE)(WORD=((WORD&~(15<<BITPOS))|(NIBBLE<<BITPOS)))
#define READNIBBLE(WORD,BITPOS)((WORD>>BITPOS)&15)
#define WRITEBYTE(WORD,BITPOS,BYTE)(WORD=((WORD&~(255<<BITPOS))|(BYTE<<BITPOS)))
#define READBYTE(WORD,BITPOS) ((WORD>>BITPOS)&225)

#define CFGPIN(WORD,PINNO,FUNC) WORD = (PINNO<16)?((WORD&~(0X03<<(PINNO*2))) | (FUNC<<(PINNO*2))):((WORD&~(0X03<<((PINNO-16)*2))) | (FUNC<<((PINNO-16)*2)))





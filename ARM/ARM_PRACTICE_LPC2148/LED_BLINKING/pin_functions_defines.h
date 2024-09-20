/*pin_function_defines.h*/

#define FUN1 0
#define FUN2 1
#define FUN3 2
#define FUN4 3

//typedef volatile unsigned int vu32; 

#define CFGPIN(WORD,PIN,FUN)\
           WORD=((PIN<16)?\
((WORD&(~(unsigned)3<<(PIN*2)))|((unsigned)FUN<<(PIN*2))) : \
((WORD&(~(unsigned)3<<((PIN-16)*2)))|((unsigned)FUN<<((PIN-16)*2))))



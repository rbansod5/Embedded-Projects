/*sfr_access_1.c*/
#include "types.h"
#include "pin_functions_defines.h"
#include<LPC21XX.H>
#define PINSEL0 (*((vu32*) 0xE002C000))
#define PINSEL1 (*((vu32*) 0xE002C004))
main()
{
//cfg p0.0 pin
CFGPIN(PINSEL0,0,FUN4);
CFGPIN(PINSEL0,0,FUN3);
CFGPIN(PINSEL0,0,FUN2);
CFGPIN(PINSEL0,0,FUN1);

//cfg p0.16

CFGPIN(PINSEL1,16,FUN4);
CFGPIN(PINSEL1,16,FUN3);
CFGPIN(PINSEL1,16,FUN2);
CFGPIN(PINSEL1,16,FUN1);
while(1);
}

//sfr_access_3.c
#include "types.h"
#include "pin_functions_defines.h"
vu32 pinsel0 __attribute__((at(0xE002C000)));
vu32 pinsel1 __attribute__((at(0xE002C004)));

main()				   
{
//cfg p0.0 function
CFGPIN(pinsel0,0,FUN4);
CFGPIN(pinsel0,0,FUN3);
CFGPIN(pinsel0,0,FUN2);
CFGPIN(pinsel0,0,FUN1);

//cfg p0.16 function

CFGPIN(pinsel1,16,FUN4);
CFGPIN(pinsel1,16,FUN3);
CFGPIN(pinsel1,16,FUN2);
CFGPIN(pinsel1,16,FUN1);

while(1);
}


/*sfr_access_3a.c*/
#include "types.h"
#include "pin_functions_defines.h"
vu32 pinsel[2] __attribute__((at(0xE002C000)));

main()
{
//cfg p0.0 function
CFGPIN(pinsel[0],0,FUN4);
CFGPIN(pinsel[0],0,FUN3);
CFGPIN(pinsel[0],0,FUN2);
CFGPIN(pinsel[0],0,FUN1);

//cfg p0.16

CFGPIN(pinsel[1],16,FUN4);
CFGPIN(pinsel[1],16,FUN3);
CFGPIN(pinsel[1],16,FUN2);
CFGPIN(pinsel[1],16,FUN1);

while(1);
}


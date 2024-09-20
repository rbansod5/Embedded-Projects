/*sfr_access_4.c: preview of style(used in arm cortex based vcs)*/

#include "types.h"
#include "pin_functions_defines.h"

typedef struct
{
vu32 PINSEL0;
vu32 PINSEL1;
vu32 dummy[3];
vu32 PINSEL2;
}pinconnectblock;

pinconnectblock *PCB =((pinconnectblock*) 0xE002C000);

/*
struct pinconnectblock
{
vu32 PINSEL0; //at 0xE002C000
vu32 PINSEL1; // at 0xE002C004
vu32 dummy[3];//0xE002C008,0xE002C00C,0xE002C010
vu32 PINSEL2; //0xE002C014
};
struct pinconnectblock *PCB=((struct pinconnectblock *) 0xE002C000);
*/

main()
{
//cfg p0.0 function

CFGPIN(PCB->PINSEL0,0,FUN4);
CFGPIN(PCB->PINSEL0,0,FUN3);
CFGPIN(PCB->PINSEL0,0,FUN2);
CFGPIN(PCB->PINSEL0,0,FUN1);


//cfg p0.16 function

CFGPIN(PCB->PINSEL1,16,FUN4);
CFGPIN(PCB->PINSEL1,16,FUN3);
CFGPIN(PCB->PINSEL1,16,FUN2);
CFGPIN(PCB->PINSEL1,16,FUN1);

//cfg p0.1
CFGPIN(((*PCB).PINSEL0),1,FUN4);
CFGPIN(((*PCB).PINSEL0),1,FUN3);
CFGPIN(((*PCB).PINSEL0),1,FUN2);
CFGPIN(((*PCB).PINSEL0),1,FUN1);

while(1);
}









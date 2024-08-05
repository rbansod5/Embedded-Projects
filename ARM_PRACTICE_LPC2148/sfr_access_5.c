/*sfr_access_5.c:preview of style(used in arm cortex based LPCvcs) */

#include"types.h"
#include"pin_functions_defines.h"
typedef struct //struct bitfields
{
u32 b0:1;
u32 b1:1;
u32 b2:1;
u32 b3:1;
u32 b4:1;
u32 b5:1;
u32 b6:1;
u32 b7:1;
u32 b8:1;
u32 b9:1;
u32 b10:1;
u32 b11:1;
u32 b12:1;
u32 b13:1;
u32 b14:1;
u32 b15:1;
u32 b16:1;
u32 b17:1;
u32 b18:1;
u32 b19:1;
u32 b20:1;
u32 b21:1;
u32 b22:1;
u32 b23:1;
u32 b24:1;
u32 b25:1;
u32 b26:1;
u32 b27:1;
u32 b28:1;
u32 b29:1;
u32 b30:1;
u32 b31:1;
}bitfield;
typedef union //pinsel0
{
vu32 PINSEL1; //sfrword;
bitfield bit;
}pinsel0;
typedef union /*pinsel1*/
{
vu32 PINSEL1; //sfrword;
bitfield sfrbit; //sfrbit;
}pinsel1;
typedef struct
{
pinsel0 pinsel0;
pinsel1 pinsel1;
}pinconnectblock;

pinconnectblock *PCB=((pinconnectblock *) 0xE002C000);

enum pinfun
{
f1,f2,f3,f4
};


main()
{
//cfg p0.0
CFGPIN(PCB->pinsel0.sfrword,0,f4);
PCB->pinsel0.sfrbit.b0=0;
PCB->pinsel0.sfrbit.b1=1;

CFGPIN(PCB->pinsel0.sfrword,0,f2);
PCB->pinsel0.sfrbit.b0=0;
PCB->pinsel0.sfrbit.b1=0;

//cfg p0.16
CFGPIN(PCB->pinsel1.sfrword,16,f4);
PCB->pinsel1.sfrbit.b0=0;
PCB->pinsel1.sfrbit.b1=0;

CFGPIN(PCB->pinsel0.sfrword,0,f2);
PCB->pinsel1.sfrbit.b0=0;
PCB->pinsel1.sfrbit.b1=0;
while(1);
}



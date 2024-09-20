//keypad.c

#include"types.h"
#include"defines.h"
#include"keypad.h"
#include <LPC21xx.H>
#define ROW0 16

#define ROW1 17

#define ROW2 18

#define ROW3 19

#define COL0 20

#define COL1 21

#define COL2 22

#define COL3 23


u8 keypadLUT[4][4]=

{

{1,2,3,4},{5,6,7,8},{9,0,'*','#'},{'!','@','$','&'}

};


void InitRows(void)

{

WRITENIBBLE(IODIR1,ROW0,0xf);

}


void InitCols(void)

{

WRITENIBBLE(IOSET1,COL0,0xf);

}


u8 colscan()

{

u8 t;

t=(READNIBBLE(IOPIN1,COL0));

t=(t<15)?0:1;

return t;

}


u8 keyscan(void)

{

u8 rNo,cNo,keyval=0;

while(colscan())
{
keyval++;
}

WRITENIBBLE(IOPIN1,ROW0,0xE);

if(!colscan())
{
rNo=0;

goto colcheck;//jumping statement

}


WRITENIBBLE(IOPIN1,ROW0,0xD);
 
if(!colscan())

{

rNo=1;

goto colcheck;

}


WRITENIBBLE(IOPIN1,ROW0,0xB);

if(!colscan())

{

rNo=2;

goto colcheck;

}


WRITENIBBLE(IOPIN1,ROW0,7);

if(!colscan())

{

rNo=3;

goto colcheck;

}

//jumping lable
colcheck:

WRITENIBBLE(IOPIN1,ROW0,0);

if(READBIT(IOPIN1,COL0)==0)           cNo=0;

else if(READBIT(IOPIN1,COL1)==0)      cNo=1;

else if(READBIT(IOPIN1,COL2)==0)      cNo=2;

else if(READBIT(IOPIN1,COL3)==0)      cNo=3;


keyval=keypadLUT[rNo][cNo];

return keyval;

}

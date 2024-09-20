 
//sms_keypad.c

#include"types.h"
#include"defines.h"
#include<LPC21xx.h>
#include"kpm_defines.h"
const u8 kpm_LUT[4][4][4]=
{
	{'7','8','9','%','4','5','6','*','1','2','3','-','c','0','=','+',},
	{'a','d','g',' ','j','m','p',' ','s','v','y',' ',' ',' ',' ',' ',},
	{'b','e','h',' ','k','n','q',' ','t','w','z',' ',' ',' ',' ',' ',},
	{'c','f','i',' ','l','o','r',' ','u','x',' ',' ',' ',' ',' ',' ',}

};
const u8 Scancode[4]={14,13,11,7};
s32 presskey,khcount;
void InitKpm(void)
{
WRITENIBBLE(IODIR1,Row0,15);
}
u8 ColScan(void)
{
u8 t;
t=(READNIBBLE(IOPIN1,Col0)<15)?0:1;
return t;
}
u8 Colcheck()
{
u8 i,cNo;
for(i=0;i<4;i++)
{
if(READNIBBLE(IOPIN1,Col0==Scancode[i]))
{
	cNo=i;
	break;
}
}
 return cNo;
 }
 u8 Rowcheck()
 {
 u8 i,rNo;
 for(i=0;i<4;i++)
 {
 WRITENIBBLE(IOPIN1,Row0,Scancode[i]);
 if(!ColScan())
 {
 rNo=i;
 break;
 }
 }
 WRITENIBBLE(IOPIN1,Row0,0);
 return rNo;
 }
 u8 KeyScan()
 {
 u8 row=0,col=0;
 static u8 prow=0,pcol=0;
 row=Rowcheck();
 col=Colcheck();
 if(row!=prow)
 {
 khcount=0;
 prow=row;
 }
 if(col!=pcol)
 {
 khcount=0;
 pcol=col;
 }
  return kpm_LUT[khcount][row][col];
 }

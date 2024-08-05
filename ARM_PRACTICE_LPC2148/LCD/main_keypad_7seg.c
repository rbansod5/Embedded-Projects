/*main_keypad_7seg.c*/
#include"types.h"
#include"keypad.h"
#include"seg.h"
#include"defines.h"
#include<lpc21xx.h>
u8 key;
main()
{
 
Init_CA7SEG_2_MUX();
while(1)
{
key=keyscan();
while(!colscan())
{
dispi_2_mux_ca7seg(key);
}
}
}
/*u8 scancodes[4]={14,13,11,7};
void initcols(void)
{
//WRITENIBBLE(IODIR0,COL0,0x0);
}
void initrows(void)
{
WRITENIBBLE(IODIR1,16,0xf);
}
void initcols(void)
{
//WERITENIBBLE(IODIR1,COL0,0x0);
} 
u8 colscan()
{
u8 t;
t=READNIBBLE(IOPIN1,20)<15?0:1;
return t;
}
u8 keyscan(void)
{
u8 rno,cno,keyval=0,i;
//waiting to detect,proceed to identify row and col in which key was pressed while key is in pressed state
for(i=0;i<4;i++)
{
//ground one row at a time 
WRITENIBBLE(IOPIN1,16,scancodes[i]);
if(!colscan())
{
rno=i;
break;
}
}
//reinitializing rows
WRITENIBBLE(IOPIN1,16,0);
for(i=0;i<4;i++)
{
if(READBIT(IOPIN1,20+i)==0)
{
cno=i;
break;
}
}
keyval=keypadlut[rno][cno];
return keyval;
}
 	  */

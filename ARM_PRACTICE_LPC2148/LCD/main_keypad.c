/*main.c*/
#include"types.h"
#include"keypad.h"
u8 key __attribute__((at(0x40000101)));
main()
{
InitRows();
InitCols();
InitLCD();

while(1)
{
key=keyscan();
U32LCD(key);
delay_ms(200);
while(!colscan());
}
}


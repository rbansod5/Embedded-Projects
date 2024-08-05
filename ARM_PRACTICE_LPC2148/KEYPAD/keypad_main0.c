/*main.c*/
#include"types.h"
#include"keypad.h"

u8 key __attribute__ ((at(0x40000000)));
main()
{
initrows();
initcols();
while(1)
{
key=keyscan();
while(!colscan());
}
}

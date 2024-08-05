//mainkeypad.c
#include"types.h"
#include<lpc214x.h>
#include"keypad.h"
#include"seg.h"
u8 key;

main()

{

InitRows();

InitCols();

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

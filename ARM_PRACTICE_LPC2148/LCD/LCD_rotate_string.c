/* 
 
 3. Write an ECP to rotate a string on LCD (From right to left)

*/


#include<lpc21xx.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
#include"lcd.h"
#include"lcd_defines.h"

int main()
{
u8 i;
InitLCD();
while(1)
{
for(i=0;i<17;i++)
{
CmdLCD(0x80+i);
StrLCD("VECTOR INSTITUTE");
delay_ms(500);
CmdLCD(0x01);
}

/*delay_s(1);
for(i=17;i>0;i--)
{
CmdLCD(0x80+i);
StrLCD("VECTOR INSTITUTE");
CmdLCD(0x01);
}
*/
}
}


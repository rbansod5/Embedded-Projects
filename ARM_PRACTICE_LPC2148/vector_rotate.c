#include"lcd.h"
#include"delay.h"
#include"lcd_defines.h"
//void Rotate_Array(u8 *,u8);
u8 a[17]="vector institute";
main()
{
InitLCD();
while(1);
{
StrLCD(a);
delay_ms(100);
Roate_Array(a,'l');
CmdLCD(GOTO_LINE1_POS0);
}
/*void Rotate_Array(u8 *p,u8 dir)
{
s8 i,temp;
if(dir=='r')
{
temp=a[15];
for(i=15;i>0;i--)
{
a[i]=a[i-1];
}
a[0]=temp;
}
else if(dir=='l')
{
temp=a[0];
for(i=0;i<15;i++)
{
a[i]=a[i+1];
}
a[15]=temp;
}
}
} */

}






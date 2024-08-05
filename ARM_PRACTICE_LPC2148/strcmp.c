#include"types.h"
#include<LPC21XX.H>
//#include"delay.h"
#include"defines.h"
//#include"lcd.h"
#define PIN1 8
#define PIN2 9
//SETBIT(IODIR0,8);
//SETBIT(IODIR0,9);
int main()
{
SETBIT(IODIR0,PIN1);
SETBIT(IODIR0,PIN2);
SETBIT(IOPIN0,PIN1);
SETBIT(IOPIN0,PIN2);
//u32 *P;
u32 i;
u8 s1[100]="rahul",s2[20]="nihar"; //dont know about it
for(i=0;s1[i]==s2[i];i++)
{
if((s1[i]==s2[i])==0)
{
CLRBIT(IOPIN0,PIN1);  //same
}
else 
CLRBIT(IOPIN0,PIN2);	 //not same
}
}


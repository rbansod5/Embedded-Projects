#include<lpc21xx.h>
#include<math.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
#define led 0
int isprime(int num)
{
int i;
for(i=2;i<sqrt(num);i++)
if(num%i==0)
return 1;
return 0;
}                                                                                                                                                                                                                                                                                                  
int main()
{
int i;
SETBYTE(IODIR0,led,0xff);
while(1)
{
for(i=2;i<=100;i++)
{
if(isprime(i)==0)
{
delay_ms(500);
WRITEBYTE(IOPIN0,led,i);
}}}}

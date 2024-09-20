#include<lpc21xx.h>
#include"delay.h"
#include"hedshiv.h"
 //sum of digit
int main()
{
int n,temp,rem,sum=0;
 writebyte(IODIR0,0,0xff);
n=5698;

while(n)
{
temp=n%10;
sum=sum+temp;
n=n/10;
}
writebyte(IOPIN0,0,sum);
}

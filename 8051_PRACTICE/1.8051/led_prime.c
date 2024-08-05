#include<reg52.h>
#include"delay.h"
#include<stdio.h>
#include<math.h>
#define led P2
int isprime(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++)
	if(n%i==0)
	return 0;
	return 1;
}

int main()
{
	int num=0;
	while(1)
	{
 			 for(num=2;num<255;num++)
									 {
	while(num)
	{
		long int rem=num%10;
		if(isprime(rem)==1)
		{
		led=rem^0x0f;
		delay_ms(1000);
		}
		num/=10;
 

	}
}
}	 }

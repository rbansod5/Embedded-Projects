#include<reg52.h>
#include<math.h>
#include"delay.h"
#define LED P1
int armstrong(int num)
{	int sum=0;
	int cnt=0;
	int temp=num;
	while(num%10)
	{
		cnt++;
		num/=10;
	}
	while(temp)
	{
		int rem;
		rem=temp%10;
		sum=sum+pow(rem,cnt);
		temp/=10;
	}
	return sum;
}
int main()
{
	int min,max;
	
	min=1;
	max=255;
	while(1)
	{
       for(min;min<=max;min++)
	{
 LED=0x0f^armstrong(min);
 delay_ms(3000);
	}
	}
}
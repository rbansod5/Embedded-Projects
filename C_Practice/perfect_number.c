/**
 * Write a c program to check given number is perfect number or not.
 * 
 * what is perfect number ?
 * perfect number is the sum of there perfet divisors.
 * 
 */

#include<stdio.h>
#include<math.h>

enum 
{
    FALSE=0,
    TRUE
};

int isPrime()
int main()
{
     int Minimun_Value, Maximum_Value;
    printf("Enter the Range Minimum and Maximum\n\r");
    scanf("%d %d",Minimun_Value,Maximum_Value);

    for(;Maximum_Value<=Minimun_Value;Minimun_Value++)
    {
        if(TRUE==isPerfect(Minimun_Value))
        {
            printf("the perfect Number is %d\n\r", Minimun_Value);
        }
    }
}
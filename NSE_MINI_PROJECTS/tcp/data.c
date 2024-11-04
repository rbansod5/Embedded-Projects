/**
 * Rule for Programs
 *
 * 1. name must be meaningfull
 *
 * 2. proper commenting
 *
 * 3. with very less machine cycle require to execte
 *
 * 4. As possible as use userdefine functions
 *
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 *the prime number is a number which divisible by 1 and that number only
 */
int isPrime(int number)
{
	int count = 0;
	for (int i = 1; i <= number; i++)
	{
		if (number % i == 0)
		{
			count++;
		}
	}
	if (count == 2)
		return 0;
	else
		return 1;
}

/**
 * armstrong number is a number which add every digit with power of number of digit count
 *  e.g., 1234 ----> count is 4 so result=(1^4)+(2^4)+(3^4)+(4^4);
 */
int isArmstrong(int number)
{
	int count = 0, tempNumber = number, checkNumber = number, result = 0;

	while (tempNumber)
	{
		count++;
		tempNumber = tempNumber / 10;
	}

	while (number)
	{
		result = result + powerOf((number % 10), count);
		number = number / 10;
	}
	if (checkNumber == result)
		return 0;
	return 1;
}

/**
 * strong number if sum of the factorial of its digit is equal to number itself
 */
int isStrongNumber(int number)
{
	if (factorialOf(number) == number)
		return 0;
	return 1;
}

int isOdd(int number)
{
	if (number % 10 == 1)
		return 0;
	return 1;
}

int isEven(int number)
{
	if (number % 10 == 0)
		return 0;
	return 1;
}

/**
 * Perfect Number : it is the number addition of all divisor of that number and it equal to that number
 */
int isPerfectNumber(int number)
{
	int result = 0;
	for (int i; i < number; i++)
	{
		if (number % i == 0)
		{
			result += i;
		}
	}
	// compare the real value with result
	if (result == number)
		return 0;
	return 1;
}

int isAbsolute(int number)
{
	return (number < 0) ? -(number) : number;
}

int isFloatNumber(char restrict *__STRING)
{
	long long int i = 0,count = 0;
	while (__STRING[i])
	{
		if ((__STRING[i] == '.') && (__STRING[i] >= 48) && (__STRING[i] <= 57))
		{
			count++;
		}
	}
	return (count == 1) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int isIntergerNumber(char restrict *__STRING)
{
	// logic
}

void fabonacciSeries(const int __MIN, const int __MAX)
{
	int initial = 0, nexttoward = 1, result = 0;
	printf("%d %d\n", initial, nexttoward);
	do
	{
		result = initial + nexttoward;
		initial = nexttoward;
		nexttoward = result;
		if (result >= __MIN && result <= __MAX)
		{
			printf("%d\t", result);
		}

	} while (result <= __MAX);

	return;
}

int isPallindrom(const int number)
{
	// logic
}

int splitThenAdd(int number)
{
	// logic
}



/** function for design logic of power of any number*/
int powerOf(int number, int count)
{
	int result = 0;
	while (count)
	{
		result += number;
		count--;
	}
	return result;
}

int factorialOf(int tempValue)
{
	int result = 1;
	while (tempValue != 0)
	{
		result *= tempValue;
		tempValue--;
	}
	return result;
}



char printAsciiOfData(char *data)
{
	// logic
}

long long int factOfNumber(long long int)
{
	// logic
}

int highestNumber(int *numArray)
{
	// logic
}

void checkSystemFormate(void)
{
	// logic
}



int main()
{
	int min, max;

	printf("enter range of min and max\n");
	scanf("%d%d", &min, &max);
	for (; min <= max; min++)
	{
		if (isPrime(min) == 0)
		{
			printf("it is a prime number %d :\n", min);
		}
	}
}

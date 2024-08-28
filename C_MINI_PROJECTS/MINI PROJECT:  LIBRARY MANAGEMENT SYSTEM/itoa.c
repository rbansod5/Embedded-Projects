#include<stdio.h>
#include<stdlib.h>

char *itoa(int number)
{
    int temp = number;
    int digits = 0;

    // Count the number of digits in the number
    while (temp != 0) {
        temp /= 10;
        digits++;
    }

    // Allocate memory for the string (+1 for null terminator)
    char *p = malloc(digits + 1);
    if (p == NULL) {
        return NULL; // Check for allocation failure
    }

    p[digits] = '\0'; // Null-terminate the string

    // Fill the string with digits from the number
    while (digits > 0) {
        p[--digits] = (number % 10) + '0';
        number /= 10;
    }

    return p;
}

int main()
{
    int number = 123456789;
    char *p = itoa(number);
    if (p != NULL) {
        printf("%s\n", p);
        free(p); // Don't forget to free the allocated memory
    }
    return 0;
}


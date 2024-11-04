#include "colors.h"
/* macros for functions and syntax*/

#define NEW_LINE printf("\n");
#define EXIT exit(1);
#define ERROR perror(RED BBLACK"an error has occured\n"RESET);
#define MAIN main()
#define BEGIN {
#define END }
#define INFINITE while (1);

#define STAR_LINE(size)               \
    for (int i = 0; i <= size; i++)   \
    {                                 \
        printf(RED "********" RESET); \
    }

/* macros for logical operators*/

#define AND &&
#define OR ||
#define NOT !

/* macros for bitwise operator*/

#define BIT_AND &
#define BIT_OR |
#define BIT_NOT ~

/* addition operator */

#define ADD +
#define SUB -

/* multiplication */

#define MUL *
#define DIV /
#define MOD %


/* ruppee symbol*/
#define RUPPEE \u20B9
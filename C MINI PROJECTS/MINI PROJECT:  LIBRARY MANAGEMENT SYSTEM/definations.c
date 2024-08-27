#include "header.h"
#include <ctype.h>
/* Function to display the menu */
void displayMenu()
{
    printf("Please enter your choice:\n");
    printf(MAGENTA BBLACK "1. Add Member Name\n2. Edit Member Name\n3. Delete Member Name\n4. Display List of Members\n11. Exit\n" RESET);
}

void projectLable()
{
    printf(RED BBLACK "   _     _ _                          \n");
    printf("  | |   (_) |__  _ __ __ _ _ __ _   _ \n");
    printf("  | |   | | '_ \\| '__/ _` | '__| | | |\n");
    printf("  | |___| | |_) | | | (_| | |  | |_| |\n");
    printf("  |_____|_|_.__/|_|  \\__,_|_|   \\__, |\n");
    printf("                                |___/ \n" RESET);
    printf(BLUE BBLACK "   __  __                                                   _   \n");
    printf("  |  \\/  | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_ \n");
    printf("  | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|\n");
    printf("  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_ \n");
    printf("  |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|\n");
    printf("                            |___/                               \n" RESET);
    printf(GREEN BBLACK "   ____            _                 \n");
    printf("  / ___| _   _ ___| |_ ___ _ __ ___  \n");
    printf("  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n");
    printf("   ___) | |_| \\__ \\ ||  __/ | | | | |\n");
    printf("  |____/ \\__, |___/\\__\\___|_| |_| |_|\n");
    printf("         |___/                       \n" RESET);
}

studentData *addMember(studentData *student)
{
    studentData *newnode = NULL;
    newnode = malloc(sizeof(studentData));
    if (newnode == NULL)
    {
        printf("In defination.c: newnode is not created");
        logError(__LINE__, "In defination.c: newnode is not created");
        return NULL;
    }
    else
    {
        printf("Enter student Roll Number\n");
        scanf("%d", &newnode->rollNumber);
        fflush(stdin);
        getchar();
        printf("Enter student name\n");
        newnode->studentName = getstring();

        do
        {
            printf("Enter contact number\n");
            scanf("%ld", &newnode->contactNo);
            __fpurge(stdin);
        } while (validate(newnode->contactNo) == 1);

        printf("Enter address of student\n");
        getchar();
        newnode->address = getstring();
        newnode->next = NULL;

        if (student == NULL)
        {
            student = newnode;
        }
        else
        {
            studentData *pTemporary = student;
            while (pTemporary->next != NULL)
            {
                pTemporary = pTemporary->next;
            }
            pTemporary->next = newnode;
        }
    }
    return student;
}

studentData *deleteMember(studentData *student)
{
    studentData *temporary = student;
    int rollNumber, count = 0;
    printf("Please Enter Roll Number to delete\n");
    scanf("%d", &rollNumber);
    for (; rollNumber != temporary->next->rollNumber; temporary = temporary->next)
        ;
    if (temporary->next == NULL)
    {
        logError(__LINE__, "defination.c : temporary->next=NULL");
    }
    else
    {
        free(temporary->address);
        free(temporary->studentName);
        temporary->next = temporary->next->next;
    }
    return student;
}

void displayMember(studentData *student)
{
    studentData *temporary = student;
    if (NULL == temporary)
    {
        printf("defination.c : student data structure is empty\n");
        logError(__LINE__, "defination.c : student data structure is empty\n");
        return;
    }
    for (; NULL != temporary->next; temporary = temporary->next)
    {
        printf("%-20d  %-20s | %-20ld | %-20s |\n", temporary->rollNumber, temporary->studentName,
               temporary->contactNo, temporary->address);
    }
    printf("%-20d %-20s %-20ld %-20s\n", temporary->rollNumber, temporary->studentName,
           temporary->contactNo, temporary->address);
}

long int validate(long int contactNo)
{
    bool isInteger = true;
    int count = 0;
    char *arg = itoa(contactNo);
    while (*arg)
    {
        if (*arg < '0' || *arg > '9')
        {
            isInteger = false;
            break;
        }
        arg++;
        count++;
    }
    if (10 == count)
    {
        return (isInteger ? 0 : 1);
    }
    else
    {
        logInfo(__LINE__, "In defination.c : this is not contact number");
    }
    return 1;
}

char *getstring()
{
    char *pString = NULL;
    int count = 0;
    char character;

    do
    {
        character = getchar();
        pString = realloc(pString, count + 2);
        pString[count++] = character;
    } while (character != '\n');

    pString[count - 1] = '\0'; // Replace '\n' with '\0'
    return pString;
}

char *itoa(long int number)
{
    long int temp = number;
    int digits = 0;
    while (temp != 0)
    {
        temp /= 10;
        digits++;
    }

    char *p = malloc(digits + 1);
    if (p == NULL)
    {
        return NULL; // Check for allocation failure
    }
    p[digits] = '\0'; // Null-terminate the string
    while (digits > 0)
    {
        p[--digits] = (number % 10) + '0';
        number /= 10;
    }

    return p;
}


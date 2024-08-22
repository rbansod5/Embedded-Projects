
#include "header.h"
libraryData *library_data;
studentData *student;
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
        printf("no node created\n");
        exit(1);
    }
    else
    {
        printf("enter book name\n");
        newnode->studentName = getstring();
        getchar();
    lable:
        printf("enter contact number\n");
        scanf("%ld", &newnode->contactNo);
        if (validate(newnode->contactNo) == 1)
        {
            goto lable;
        }
        printf("enter address of student\n");
        if (student == NULL)
        {
            student = newnode;
        }
        else
        {
            studentData *pTemperory = student;
            for (; pTemperory != NULL; pTemperory = pTemperory->next);
            pTemperory->next = newnode;
        }
    }
    return student;
}

/* validate */
int validate(int i_information)
{
    char *i_Data = itoa(i_information);
    int count = 0;
    int length = sizeof(i_information);
    while (*i_Data != NULL)
    {
        if ('48' >= i_Data[count] && '57' <= i_Data[count])
        {
            count++;
        }
        if (count == length-1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

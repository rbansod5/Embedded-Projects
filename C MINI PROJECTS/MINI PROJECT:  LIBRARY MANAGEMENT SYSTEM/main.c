/**
 * @file    main.c
 * @author  RAHUL SHRIDHAR BANSOD (https://github.com/rbansod5/Embedded-Projects.git)
 *
 *  @brief   Library Management System
            • Overview: Create a console-based application that allows users to manage
              a small library. Users can add books, view available books, borrow books, 
              and return them.
            • Key Features:
                ◦ Add, delete, and search books.
                ◦ Track the availability and borrowing status of books.
                ◦ Implement basic authentication for admin access to add or remove books.
            • Concepts Demonstrated:
                ◦ File handling to store the library data.
                ◦ Structures to manage book records.
                ◦ Use of arrays or linked lists for dynamic data handling.

 * @version 0.1
 * @date    2024-08-13
 *  
 * @copyright Copyright (c) 2024 (PUBLIC)
 * 
 */

#include "header.h"        //include all required header files
#include "definations.h"

extern libraryData *library_data;
extern studentData *student;

/* This is main function which is responsible to manage all functions */
int main()
{
    
    STAR_LINE(10);
    NEW_LINE;
    /* To display Lable of project*/
    projectLable();
    NEW_LINE;
    STAR_LINE(10);
    NEW_LINE;
    int choice;
    while(1)
    {
        printf("Please enter the choice\n");
        printf(MAGENTA"1. Add Member Name\n2.Edit Member Name\n3.Delete Member Name\n4.display List of Members\n"RESET);
        
        scanf("%d",&choice);
        __fpurge(stdin);

        switch(choice)
        {
            case 1: student = addMember(student);
            break;
            case 11: 
                    exit(1);

            default : printf("\nplease enter valid choice\n");
        }
    }
}
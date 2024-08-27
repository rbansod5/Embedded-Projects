/**
 * @file    main.c
 * @author  RAHUL SHRIDHAR BANSOD
 *
 *  @brief   Library Management System
 *            # Overview: Create a console-based application that allows users to manage
 *              a small library. Users can add books, view available books, borrow books,
 *              and return them.
 *            # Key Features:
 *                * Add, delete, and search books.
 *                * Track the availability and borrowing status of books.
 *                * Implement basic authentication for admin access to add or remove books.
 *            # Concepts Demonstrated:
 *                * File handling to store the library data.
 *                * Structures to manage book records.
 *                * Use of arrays or linked lists for dynamic data handling.
 *
 * @version 0.2
 * @date    2024-08-13
 *
 * @copyright Copyright (c) 2024 (PUBLIC)
 *
 */

#include "header.h"      // include all required header files
#include "definations.h" // include definitions and macros

LibraryData *library_data;
studentData *student;

/* Function declarations */
void displayMenu();

int main()
{
    STAR_LINE(10);
    NEW_LINE;
    /* To display Label of project */
    projectLable();
    NEW_LINE;
    STAR_LINE(10);
    NEW_LINE;

    int choice;
    while (1)
    {
        displayMenu();

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input, Please enter a number.\n");
            logError(__LINE__, "In main.c : Invalid input, Please enter a number.\n");
            while (getchar() != '\n')
                ; // Clear the input buffer
            continue;
        }

        // Clear the input buffer safely
        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 1:
            logInfo(__LINE__, "Add Member\n");
            student = addMember(student);
            break;
        case 2:
            // Edit member name functionality here
            student = editMember(student);
            break;
        case 3:
            // Delete member name functionality here
            student = deleteMember(student);
            break;
        case 4:
            // Display list of members functionality here
            displayMember(student);
            break;
        case 11:
            logInfo(__LINE__, "In main.c : Exit the program\n");
            printf(RED BBLACK "Exiting...\n" RESET);
            exit(0); // Exit the program
        default:
            logInfo(__LINE__, "In main.c : Please enter a valid choice.\n");
            printf(YELLOW BBLACK "Please enter a valid choice.\n" RESET);
        }
    }
    return 0;
}

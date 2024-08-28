/****************************************************************************************
 * @file   library_structure.h
 * @author RAHUL SHRIDHAR BANSOD
 * @brief  Library structure to store information about books and students
 *
 * @version 0.2
 * @date 2024-08-13
 *
 * @copyright Copyright (c) 2024 (PUBLIC)
 ****************************************************************************************
 */

#ifndef _LIBRARY_STRUCTURE_H
#define _LIBRARY_STRUCTURE_H

#include <time.h>  // for date handling

/* Enumeration for book availability status */
typedef enum {
    AVAILABLE = 0,
    ISSUED,
    RESERVED
} BookStatus;

/* Structure for managing library book information */
typedef struct library {
    char           *bookName;          // Book name 
    short int       edition;           // Book edition
    int             price;             // Book market price
    int             publicationYear;   // Publication year
    struct tm       issueDate;         // Issue date 
    BookStatus      status;            // Availability status
    struct library *next;              // Pointer to next book in the list
} LibraryData; 
 
/* Structure for managing student information */
typedef struct student {
    int             rollNumber;
    char           *studentName;       // Student name
    long int        contactNo;         // Contact number
    char           *address;           // Address
    struct student *next;              // Pointer to next student in the list
} studentData;

/* Enumeration for function return status */
typedef enum {
    SUCCESS = 0,
    FAILED
} RET;

#endif 

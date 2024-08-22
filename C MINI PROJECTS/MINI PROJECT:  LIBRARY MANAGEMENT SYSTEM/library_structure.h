/****************************************************************************************
 * @file   library_structure.h
 * @author RAHUL SHRIDHAR BANSOD (https://github.com/rbansod5/Embedded-Projects.git)
 * @brief  This is for design library structure which store information
 *         about book name, Edition, price, publication year, date, flag
 *
 * @version 0.1
 * @date 2024-08-13
 *
 * @copyright Copyright (c) 2024 (PUBLIC)
 ****************************************************************************************
 */

#ifndef _LIBRARY_STRUCTURE_H
#define _LIBRARY_STRUCTURE_H

/* this structure is design for library management*/
typedef struct library
{
    char          *bookName;        // book name 
    short int      Edition;          // book edition
    int            price;            // book market price
    int            publicationYear;  // publication year
    char           *date;            // issue date 
    char           flag;             // flag for aviability
    struct library *lib;

} libraryData; 
 
typedef struct student
{
    char            *studentName;
    long int        contactNo;
    char            *address;
    struct student  *next;

}studentData;
#endif
typedef enum
{
    SUCCESS=0,
    FAILED
}RET;


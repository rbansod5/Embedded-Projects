#include "library_structure.h"

void displayMenu();
void projectLable();
studentData *addMember(studentData *student);
long int validate(long int );
char *getstring(void);
studentData *deleteMember(studentData *student);
studentData *editMember(studentData *student);

LibraryData *addLibraryData(LibraryData *library);
void displayLibraryData(LibraryData *library);
char *currentTime();
void displayMember(studentData *student);
char *itoa(long int number);
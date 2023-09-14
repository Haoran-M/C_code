#ifndef A3_Q1_H
#define A3_Q1_H

#include <stdlib.h> //needed for handling dynamic memory
#include <string.h> //needed for some string functions

//the structure used for holding one birthday entry
typedef struct {
short year;
short month;
short day;
char* name;
char* knownFor;
} Birthday;

//Creates a Birthday struct variable storing three short representing 
// year, month, and day respectively, a char* array representing a name,
// and a char* array representing a trait (knownFor)
//Returns the address of the dynamically (i.e., uses malloc) created variable
//For example:
//Given the code:
//Birthday* person = create_Birthday(1985, 1, 1, 
//                                      "J. Edgar Hoover",
//                                      "First director of the FBI");
//printf("%d-%d-%d\n%s\n%s\n", person->year, person->month, person->day, 
//      person->name, person->knownFor);
//will result in an output like this:
//1985-1-1
//J. Edgar Hoover
//First director of the FBI
Birthday* create_Birthday(short year, short month, short day,
                            char* name, char* knownFor);


//Releases the memory created to store the 2 members name and knownFor using
// the address of a Birthday struct variable
//Note that the person parameter can be NULL
// and if this is the case the function should do nothing.
//Also, this function does not release the memory used for the Birthday struct variable,
// but only those used by the members name and knownFor. 
//To properly release all the memory dynamically allocated for the struct variable,
// call the free() function with the address of the Birthday struct variable right
// after this function returns.
void clear_Birthday(Birthday* person);

//helper function to look up a birthday entry by month and day
//returns a dynamic array storing all the indexes with the same month and day, NULL if not found
//To make the size known to the caller, put a -1 as the last item. For example,
// if indexes 2, 4, 6 match with the month and day, the array would be {2, 4, 6, -1}
int* lookupBirthdayByMD(Birthday **array, int size, short month, short day);

//helper function for qsort to compare birthdays by month and day
int compareBirthdaysByMD(const void *p1, const void *p2);

//helper function for qsort to compare birthdays by name
int compareBirthdaysByName(const void *p1, const void *p2);

#endif
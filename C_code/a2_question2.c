#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// haoran miao
//301541289
//hma98@sfu.ca

typedef struct {
  short year;
  short month;
  short day;
  char *name;
  char *knownFor;
} Birthday;

int lenstr(char *Str) {
  int i;
  for (i = 0; Str[i] != '\0'; i++); // find the length of the string
  return i;
}

Birthday *create_Birthday(short year, short month, short day, char *name,char *knownFor) {
  int len_name = lenstr(name);
  int len_kF = lenstr(knownFor);
  Birthday *person = (Birthday *)malloc(sizeof(Birthday));
  person->year = year;
  person->month = month;
  person->day = day;
  person->name = (char *)malloc(len_name + 1);
  strcpy(person-> name , name);// +1 for the null terminator

  person->knownFor = (char *)malloc(len_kF + 1);
  strcpy(person->knownFor , knownFor);// +1 for the null terminator

  return person;
}

void clear_Birthday(Birthday *person) {
  if (person != NULL) {
    free(person->name);
    person->name = NULL;
    free(person->knownFor);
    person->knownFor = NULL;//free person and name and set value to null.
  }
}

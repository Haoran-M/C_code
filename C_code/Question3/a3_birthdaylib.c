#include "a3_birthdaylib.h"


void clear_Birthday(Birthday *person) {
  if (person != NULL) {
    person->year = -1;
    person->month = -1;
    person->day = -1;
    free(person->name);
    free(person->knownFor);
  }
}

Birthday *create_Birthday(short year, short month, short day, char *name,
                          char *knownFor) {
  Birthday *newBDay = (Birthday *)malloc(sizeof(Birthday));
  // only access member values if memory is successfully allocated
  if (newBDay != NULL) {
    newBDay->year = year;
    newBDay->month = month;
    newBDay->day = day;
    // create a deep copy of name, dont' forget size is length+1
    newBDay->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    if (newBDay->name != NULL) {
      strcpy(newBDay->name, name);
    }
    // create a deep copy of knownFor, don't forget size is length+1
    newBDay->knownFor = (char *)malloc(sizeof(char) * (strlen(knownFor) + 1));
    if (newBDay->knownFor != NULL) {
      strcpy(newBDay->knownFor, knownFor);
    }
  }
  return newBDay;
}

// helper function for qsort to compare birthdays by month and day
int compareBirthdaysByMD(const void *p1, const void *p2) {
  const Birthday *bday1 = *(const Birthday **)p1;
  const Birthday *bday2 = *(const Birthday **)p2;

  if (bday1->month == bday2->month) {
    return bday1->day - bday2->day;
  } else {
    return bday1->month - bday2->month;
  }
}

// helper function for qsort to compare birthdays by name
int compareBirthdaysByName(const void *p1, const void *p2) {
  const Birthday *bday1 = *(const Birthday **)p1;
  const Birthday *bday2 = *(const Birthday **)p2;

  return strcmp(bday1->name, bday2->name);
}

int *lookupBirthdayByMD(Birthday **array, int size, short month, short day) {
  int *idx = NULL;
  int numMatches = 0;

  for (int i = 0; i < size; i++) {
    if (array[i]->month == month && array[i]->day == day) {
      numMatches++;
      idx = realloc(idx, (numMatches + 1) * sizeof(int));
      idx[numMatches - 1] = i;
    }
  }

  if (numMatches > 0) {
    // put a -1 as the last item to make the size known to the caller
    idx[numMatches] = -1;
    return idx;
  } else {
    free(idx);
    return NULL;
  }
}

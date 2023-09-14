#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a3_birthdaylib.h"

int main() {
  FILE *filePtr = NULL;
  Birthday **birthdayArr = NULL;
  int numBirthdays = 0;
  short month, day;
  int end = 1;
  printf("========================================\n");
  printf("=====famous Birthday lookup system======\n");
  printf("==============Haoran Miao===============\n");
  printf("=========SFU ID: 301542189==============\n");
  printf("============hma98@sfu.ca================\n");
  printf("========================================\n");
  while (end != 0) {
    int option;
    printf("\nSelect an option:\n");
    printf("1. Load a birthday file\n");
    printf("2. List birthdays sorted by Month-Day\n");
    printf("3. List birthdays sorted by Name\n");
    printf("4. Lookup a birthday\n");
    printf("5. Exit\n");
    printf("Enter option (1-5): ");
    if (scanf("%d", &option) != 1) {
      printf("Invalid input\n");
      continue;
    }
    if (option < 1 || option > 5) {
      printf("Invalid option\n");
      continue;
    }
    if (option == 1) {
      char fileName[100];
      printf("Enter file name: ");
      scanf("%99s", fileName);
      if (filePtr != NULL) {
        fclose(filePtr);
        for (int i = 0; i < numBirthdays; i++) {
          clear_Birthday(birthdayArr[i]);
          free(birthdayArr[i]);
        }
        free(birthdayArr);
        birthdayArr = NULL;
        numBirthdays = 0;
      }
      filePtr = fopen(fileName, "r");
      if (filePtr == NULL) {
        printf("Failed to open file.\n");
      } else {
        char nameBuffer[100], knownForBuffer[100];
        short year, month, day;
        while (fscanf(filePtr, "%hd,%hd,%hd\n", &year, &month, &day) != EOF) {
          fgets(nameBuffer, 100, filePtr); // get the name
          nameBuffer[strlen(nameBuffer) - 1] =
              '\0'; // overwrite the \n char at the end
          fgets(knownForBuffer, 100, filePtr); // get the knownFor
          knownForBuffer[strlen(knownForBuffer) - 1] =
              '\0'; // overwrite the \n char at the end

          Birthday *newBirthday =
              create_Birthday(year, month, day, nameBuffer, knownForBuffer);
          if (newBirthday != NULL) {
            numBirthdays++;
            birthdayArr =
                realloc(birthdayArr, numBirthdays * sizeof(Birthday *));
            birthdayArr[numBirthdays - 1] = newBirthday;
          }
        }
        printf("Loaded %d birthdays from file.\n", numBirthdays - 1);
      }
    } else if (option == 2) {
      qsort(birthdayArr, numBirthdays, sizeof(Birthday *),
            compareBirthdaysByMD);
      printf("Birthdays sorted by Month-Day:\n");
      for (int i = 0; i < numBirthdays; i++) {
        Birthday *bday = birthdayArr[i];
        printf("========================================\n%d-%d-%d\n%s\n%s\n==="
               "=====================================\n",
               bday->year, bday->month, bday->day, bday->name, bday->knownFor);
      }
    } else if (option == 3) {
      qsort(birthdayArr, numBirthdays, sizeof(Birthday *),
            compareBirthdaysByName);
      printf("Birthdays sorted by Name:\n");
      for (int i = 0; i < numBirthdays; i++) {
        Birthday *bday = birthdayArr[i];
        printf("========================================\n%d-%d-%d\n%s\n%s\n==="
               "=====================================\n",
               bday->year, bday->month, bday->day, bday->name, bday->knownFor);
      }
    } else if (option == 4) {
      printf("Enter a month: ");
      scanf("%hd", &month);
      printf("Enter a day: ");
      scanf("%hd", &day);

      // Call lookupBirthdayByMD and print results
      int *matches = lookupBirthdayByMD(birthdayArr, numBirthdays, month, day);
      if (matches == NULL) {
        printf("No birthdays found for %hd-%hd\n", month, day);
      } else {
        printf("Birthdays on %hd-%hd:\n", month, day);
        for (int i = 0; matches[i] != -1; i++) {
          Birthday *bday = birthdayArr[matches[i]];
          printf("========================================\n%d-%d-%d\n%s\n%s\n="
                 "=======================================\n",
                 bday->year, bday->month, bday->day, bday->name,
                 bday->knownFor);
        }
      }
      // Free memory allocated for matches
      free(matches);
    } else if (option == 5) {
      for (int i = 0; i < numBirthdays; i++) {
        clear_Birthday(birthdayArr[i]);
        free(birthdayArr[i]);
      }
      free(birthdayArr);
      end = 0;
    }
  }
}

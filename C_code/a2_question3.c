#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a2_question2.c"
// haoran miao
//301541289
//hma98@sfu.ca


void merge(Birthday* arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Birthday L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i].month < R[j].month || (L[i].month == R[j].month && L[i].day < R[j].day)) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Birthday* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
//Added a basic mergesort to sort the array of birthdays.

int main() {
    
    int capacity = 16;
    int i = 0,k=0;
    int used =0;
    int year, month, day; // variables to hold values read from file
    int pmonth =1;
    int pday = 1;
    char name[100], KF[100]; // arrays to hold strings read from file
    Birthday* BdayArray = (Birthday *)malloc(sizeof(Birthday)*capacity);
    printf("========================================================\n");
    printf("Famous Birthday Lookup system");
    printf("Haoran Miao\n");
    printf("SFU ID: 301542189\n");
    printf("Email: hma98@sfu.ca\n");
    printf("========================================================\n");
    
    FILE* Bdays = fopen("famousBDays.txt", "r");
    if (Bdays == NULL) {
        printf("Error: could not open file famousBDays.txt.\n");
        exit(1);
        //open file, returns error if file does not work.
    }
    // read in data from file using fscanf until end of file
    while (fscanf(Bdays, "%d,%d,%d\n%[^\n]\n%[^\n]\n", &year, &month, &day, name, KF) == 5) {
       

        Birthday* person = create_Birthday(year,month,day,name,KF);//Create a struct for each birthday
        BdayArray[i] = *person;//append to array
        i++;
        used++;
        if ( used == capacity){
          capacity = capacity *2;
          BdayArray = (Birthday*)realloc(BdayArray,sizeof(Birthday)*capacity);//realloc array size
          
        }
     
    }
    fclose(Bdays);//close file.
  // Call this function to sort the BdayArray
mergeSort(BdayArray, 0, used - 1);
 k=0;
  while(k<used){

    switch(pmonth){
      case 1://for jan
       for (pday=1; pday<32;pday++){
          if(BdayArray[k].month == pmonth && BdayArray[k].day == pday){
          printf("=========================================\n%d-%d-%d\n%s\n%s\n=========================================\n", BdayArray[k].year, BdayArray[k].month, BdayArray[k].day,  BdayArray[k].name, BdayArray[k].knownFor);
            
          clear_Birthday(&BdayArray[k]);

            k++;
            
           
        }else{
          printf("=========================================\nNo birthday on %d-%d on record.\n=========================================\n",pmonth,pday);
            
            } 
  
          }
        pmonth++;
        break;
        
  case 2://for feb
       for (pday=1; (pday<30);pday++){
          if(BdayArray[k].month == pmonth && BdayArray[k].day == pday){
          printf("=========================================\n%d-%d-%d\n%s\n%s\n=========================================\n", BdayArray[k].year, BdayArray[k].month, BdayArray[k].day,  BdayArray[k].name, BdayArray[k].knownFor);
            clear_Birthday(&BdayArray[k]);

            k++;
           
        }else{
          printf("=========================================\nNo birthday on %d-%d on record.\n=========================================\n",pmonth,pday);
            
            } 
  
          }
        pmonth++;
        break;

      case 3://other month with 31 days
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
          
       for (pday=1; pday<32;pday++){
          if(BdayArray[k].month == pmonth && BdayArray[k].day == pday){
          printf("=========================================\n%d-%d-%d\n%s\n%s\n=========================================\n", BdayArray[k].year, BdayArray[k].month, BdayArray[k].day,  BdayArray[k].name, BdayArray[k].knownFor);
            
          clear_Birthday(&BdayArray[k]);
            k++;
            
           
        }else{
          printf("=========================================\nNo birthday on %d-%d on record.\n=========================================\n",pmonth,pday);
            
            } 
  
          }
        pmonth++;
        break;

      case 4://month with 30 dyas
      case 6:
      case 9:
      case 11:
        for (pday=1; pday<31;pday++){
          if(BdayArray[k].month == pmonth && BdayArray[k].day == pday){
          printf("=========================================\n%d-%d-%d\n%s\n%s\n=========================================\n", BdayArray[k].year, BdayArray[k].month, BdayArray[k].day,  BdayArray[k].name, BdayArray[k].knownFor);
            
          clear_Birthday(&BdayArray[k]);
            k++;
            
           
        }else{
          printf("=========================================\nNo birthday on %d-%d on record.\n=========================================\n",pmonth,pday);
            
            } 
  
          }
        pmonth++;
        break;

      default:
        break;
    }
    }

    free(BdayArray);//free array memory
    BdayArray = NULL; 

    return 0;

    }
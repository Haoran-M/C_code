#ifndef A1_Q2_H
#define A1_Q2_H

#include <string.h>
// haoran miao
// hma98@sfu.ca
// student id = 301542189

// top 3 lines were directly downloaded and unchanged, it is not being used in the rest
#include <stdio.h>

int lenstr(char* Str1){
  int i;
  for(i=0; Str1[i]!= '\0'; i++);// find the length of the string
  return i;
}

int compStrA(char* s1,char* s2){
    int s1len = lenstr(s1);// compare two strings for the start of the string. s1 is string for arra and s2 is target
    int idxa = 0;
    int k;
    
    for(k=0; s1[k]!='\0' && s2[k]!= '\0'; k++){
      if(s1[k] == s2[k]){
        idxa++;//comparing the string by comparing each character
      }
    }
    
    if(idxa != s1len){
      idxa = -1;// if string is comtained, the length should equal to idxa, which is how many times the char matchs
    }
    return idxa;
  }

int compStrB(char* s1,char* s2){
    int s1len = lenstr(s1);
    int s2len = lenstr(s2);
    int idxb = 0;
    int j=0,k=0;
    
    for(k=0, j= s2len-s1len; s1[k]!='\0'&& s2[j]!= '\0'; k++,j++){
      if(s1[k] == s2[j]){
        idxb++;//comparing two strings from the tail.
      }
    }
    if(idxb != s1len){
      idxb = -1;
    } 
  
    return idxb;
  }

void findElements(char* arrA[], unsigned int sizeA, char* arrB[], unsigned int sizeB, char* target, int* result){
    int i=0;
    int j=0;
    int Astrlen=0;
    int Bstrlen=0;
    int targetlen = lenstr(target);

    while(i<sizeA){
        Astrlen = compStrA(arrA[i],target);
        if(Astrlen != -1){
            result[0] = i;// loop to find substrings in arra 
            break;
        }
        i++;
    
  }
 
  while(j<sizeB){
    Bstrlen = compStrB(arrB[j],target);
    
     if(Bstrlen != -1){
        result[1] = j;// loop to find substrings in arrb
        break;
    }
    j++;
  }
  
  if(result[0]!= -1 && result[1]!=-1){
    if(targetlen > Astrlen + Bstrlen){
      result[0] = -1;
      result[1] = -1;// check if string is overfitting, target that contains extra char

    }
  }


}

#endif
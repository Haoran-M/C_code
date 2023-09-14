#include <math.h> //needed for the absolute function
#include <stdbool.h> //needed for C to have bool (boolean) variables
#include <stdio.h>

// haoran miao
// hma98@sfu.ca
// student id = 301542189

float calculateAreaShoelace(unsigned int rows, int points[][2], int index){
    int i = 0;
    int j = 0;// int created for loops below
    int k = 0;
    int s1 = 0, s2 = 0;
    int tmpmatrix[rows][2];
    float area = 0;

    for (int i = 0; i < rows; i++){
        tmpmatrix[i][0] = points[i][0];// get pointer and place its values in a new 2d array
        tmpmatrix[i][1] = points[i][1];
    }
    i = 0;

    if( index < rows){
        for(k = index; k < rows-1;k++){
            tmpmatrix[k][0]= tmpmatrix[k+1][0];
            tmpmatrix[k][1]= tmpmatrix[k+1][1]; // remove index
        }
    }
    while(i < rows-1){
        s2 += tmpmatrix[i][0]*tmpmatrix[i+1][1]; // loop for s2
        i++;

    }
    s2 = s2+ tmpmatrix[rows-1][0]*tmpmatrix[0][1]; // adding x4 * y1

    while(j < rows-1){
        s1 += tmpmatrix[j][1]*tmpmatrix[j+1][0];// loop for s1
        j++;

    }
    s1 = s1+ tmpmatrix[rows-1][1]*tmpmatrix[0][0];// adding y4*x1


    if(s1>s2){
        area = 0.5*(s1-s2);// absolute value function of the area
    }else{
        area = 0.5*(s2-s1);
    }

    return area;

}

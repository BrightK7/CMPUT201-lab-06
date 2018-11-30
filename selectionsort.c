#include <stdio.h>
#include "selectionsort.h"
void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectyionsort(int arr[],int n, int *a){
    int i,j,min_indx;
    for (i = 0; i < n-1; i++){
        min_indx = i;
        for (j = i+1; j < n;j++){
            if (arr[j] < arr[min_indx]){
                min_indx = j;
                *a+=1;
            }
            else{
                *a+=1;
            }
        }
        swap(&arr[min_indx],&arr[i]);
    }
}


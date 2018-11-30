#include <stdio.h>
#include "bubblesort.h"

void bubblesort(int arr[],int n,int *compare_num){
    int i,j,temp;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j]   = temp;
                *compare_num +=1;
            }
            else{
                *compare_num+=1;
            }
        }
    }
}

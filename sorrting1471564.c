#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"


int main(int argc, char const *argv[])
{
	if (argc != 2){										// if input != 2 printf the error in stderr
		fprintf(stderr,"./sorting -q|-m|-i|b|s|h\n");
		return 0;
	}
    int num;
    printf("Enther the interger to be sort: ");
    scanf("%d",&num);
    int *sort_num = malloc(num*sizeof(int));
    for (int i = 0; i < num; i++){
        scanf("%d",sort_num + i);
    }
    printf("The input order for the  %d intergers is ",num);
    for (int i = 0; i < num; i++){
        printf(" %d",sort_num[i]);

    }
    printf("\n");
    int compare_num;
    if(strcmp(argv[1],"-q") ==0){
        quicksort(sort_num,0,num-1,&compare_num);
    }
    printf("compare num is %d",compare_num);	
    free(sort_num);
    return 0;
}

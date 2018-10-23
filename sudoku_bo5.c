#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 9 
void slo(int matrix[N][N]);
void find_zeros(int matrix[N][N],int find_zeros[N]);
void try(int zero_num,int index, int matrix[N][N]);
int main(int argc, char** argv){
    FILE *sudoku;
    int matrix[N][N];
    int used[N][N];
    if (argc != 2){										// if input != 2 printf the error in stderr
		fprintf(stderr,"./my program file_name\n");
		return 0;
    }
    sudoku = fopen(argv[1],"r");
    if (sudoku == NULL) exit (1);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            fscanf(sudoku,"%d",&matrix[i][j]);
        }
    }
    slo(matrix,used);
    return 0;
}


void slo(int matrix[N][N],used[N][N]){
    int min = N;
    int dex = 0;
    int zero_num[N] = { 0 };
    find_zeros(matrix,zero_num,used[N][N]);
    for (int i = 0; i < N; i++){
        printf("value in zeros are %d\n",zero_num[i]);
        if (zero_num[i] < min){
            min = zero_num[i];
            dex = i;
        }
    }   
    try(min,dex, matrix);
}


void try(int zero_num,int index, int matrix[N][N]){
        int row,col,send_r,send_s,count = 0;
        int used[N];
        printf("zero_num is %d and index is %d\n",zero_num,index);
        col = index % 3 * 3;
        row = index / 3 * 3;
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
            if (matrix[row+j][col+k] != 0){
                used[count] = matrix[row+j][col+k];
                count++;
            }
            }
        }
        for (int i = 0; i < zero_num; i++){

        }
}

bool place_in (int row, int col, int matrix[N][N]){

}

void find_zeros(int matrix[N][N],int zero_num[N],used[N][N]){
    int row,col;
    for (int i = 0; i < N; i++){
        col = i % 3 * 3;
        row = i / 3 * 3;
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
            if (matrix[row+j][col+k] == 0){
               // printf("%d and %d is zero\n",row+j,col+k);
                zero_num [i] += 1;
            }
            }
        }
    }
}

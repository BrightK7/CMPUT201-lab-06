#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define N 9 
int canbe[N][N][N];
void slo(int matrix[N][N]);
void find_zeros(int matrix[N][N]);

int main(int argc, char** argv){
    FILE *sudoku;
    int matrix[N][N];
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
    for(int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        if (matrix[i][j] == 0){

        for(int x = 0; x < N; x++)
        canbe[i][j][x] = x+1;
      }
    }
    }
    int zero_num[N] = { 0 };
    find_zeros(matrix);
    //slo(matrix);
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
          for (int x = 0; x < N; x++){
            printf("%d",canbe[i][j][x]);
          }
          printf("\n");
        }
        printf("\n");
    }  
  return 0;
}

void slo(int matrix[N][N]){
    printf("11111\n");
    int count,key = 0;

      for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
          count = 0;
          for (int x = 0; x < N; x++){
            if (canbe[i][j][x] == 0){
              count++;
              key = x+1;
            }           
          }
          //printf("row %d and clo %d is %d\n",i,j,count);
          if (count == 1){
            matrix[i][j] = key;
            canbe[i][j][key-1] = key; 
            printf("row %d and clo %d is %d\n",i+1,j+1,key);
            slo(matrix);
          }  
        }

    }


}

void find_zeros(int matrix[N][N]){
    int row,col,ind;
    for (;row < N; row++){
      for (;col<N;col++){
        if (matrix[row][col] != 0)
          continue;
        else{
          for (int i = 0; i < N;i++){       /// row
            if (matrix[row][i] != 0){
              ind = matrix[row][i];
              canbe[row][col][ind-1] = 0;
            }
              
          }
          for(int i = 0; i< N; i++){        /// col
            if (matrix[i][col] != 0){
              ind = matrix[i][col];
              canbe[row][col][ind-1] = 0;
            }
          }
        }
      }
    }






    for (int i = 0; i < N; i++){
        int words[N] = { 0 };
        int count = 0;
        col = i % 3 * 3;
        row = i / 3 * 3;
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
              if (matrix[row+j][col+k] != 0){
                ind = matrix[row+j][col+k];
                canbe[row+j][col+k][ind-1] = 0;
              }
            }
        }
    }    
    
}
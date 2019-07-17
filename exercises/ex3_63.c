#include "stdio.h"
#include "stdlib.h"

int ***malloc3d(int M,int N,int L){
  int i,j,k;
  int ***t = malloc(M * sizeof(int **));
  for(i = 0;i < M; i++){
    t[i] = malloc(N * sizeof(int *));
    for(j = 0;j < N; j++){
      t[i][j] = malloc(L * sizeof(int));
    }
  }
  return t;
}

int main(){
  int ***matriz_3d = malloc3d(2,2,2);
  int i,j,k;
  for(i = 0;i < 2;i++){
    for(j = 0;j < 2;j++){
      for(k = 0; k < 2; k++){
        matriz_3d[i][j][k] = (j+1)*(i+1)*(k+1);
        printf("%i", matriz_3d[i][j][k]);
      }
    }
  }
}

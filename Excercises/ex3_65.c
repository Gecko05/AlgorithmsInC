#include <stdio.h>
#include <stdlib.h>

int N = 5;
int M = 7;
int array_2d[5][7];

int max(int a, int b){
  if(a>b){
    return a;
  }
  else{
    return b;
  }
}

int gcd(int a, int b){
  if(a == 0 || b == 0){
    return max(a,b);
  }
  else{
    int c = a;
    a = b;
    b = c%b;
    return gcd(a,b);
  }
}

int main(){
  int i, j;
  for(i = 0;i < N;i++){
    for(j = 0;j < M; j++){
      if(gcd(i,j) == 1){
        array_2d[i][j] = 1;
      }
      else{
        array_2d[i][j] = 0;
      }
      printf("Pos: %i, %i: %i\n",i,j,array_2d[i][j]);
    }
  }
}

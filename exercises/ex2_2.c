#include <time.h>
#include <stdio.h>
clock_t start, end;
double cpu_time_used;

int N = 1;
int main(){
  start = clock();
  int i,j,k,count = 0;
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      for(k=0;k<N;k++)
        count++;
  end = clock();
  cpu_time_used = ((double) (end - start)) /CLOCKS_PER_SEC;
  printf("time used: %f\n",cpu_time_used);
}

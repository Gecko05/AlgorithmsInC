//Quick find algorithm
#include <stdio.h>
#define N 10
int main(){
  long int counter = 0;
  //scanning loop
  int j,i,p,q,t,id[N];
  for(i=0;i<N;i++){
    id[i] = i;      //Fills vector
  }
  while(scanf("%d %d",&p,&q)==2){
    for (i = p; i != id[i]; i = id[i]){
      counter++;
    }
    for (j = q; j != id[j]; j = id[j]){
      counter++;
    }
    if(i == j){
      continue;
    }
    id[i] = j;
    counter++;
    printf("Accessed id array: %li\n",counter);
    printf(" %d %d\n", p, q);
    for(i=0;i<N;i++){
      printf("%d ",id[i]);
    }
    printf("\n");
  }
  return 0;
}

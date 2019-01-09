//Quick find algorithm
#include <stdio.h>
#define N 10
int main(){
  long int counter = 0;
  //scanning loop
  int i,p,q,t,id[N];
  for(i=0;i<N;i++){
    id[i] = i;      //Fills vector
  }
  while(scanf("%d %d",&p,&q)==2){
    if(id[p]==id[q]){
      printf("not a new relation");
      continue;
    }
    for(t = id[p],i=0;i<N;i++){
      if(id[i] == t){
        id[i] = id[q];
      }
      counter++;
    }
    printf("Accessed id array: %li\n",counter);
    printf(" %d %d\n", p, q);
    for(i=0;i<N;i++){
      printf("%d ",id[i]);
    }
    printf("\n");
  }
  return 0;
}

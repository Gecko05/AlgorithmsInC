//Quick find algorithm
#include <stdio.h>
#define N 10
int main(){
  long int counter = 0;
  //scanning loop
  int j,i,p,q,newp,t,id[N],sz[N],root;
  for(i=0;i<N;i++){
    id[i] = i;      //Fills vector
    sz[i] = 1;
  }
  while(scanf("%d %d",&p,&q)==2){
    for (i = p; i != id[i]; i = id[i]){
    }
    root = i;
    for (i = p; i != id[i]; i = id[i]){
      id[i] = root;
    }
    for (j = q; j != id[j]; j = id[j]){
    }
    root = j;
    for (j = q; j != id[j]; j = id[j]){
      id[j] = root;
    }
    if(i == j){
      continue;
    }
    if(sz[i]<sz[j]){
      id[i] = j;
      sz[j] += sz[i];
    }
    else{
      id[j] = i;
      sz[i] += sz[j];
    }
    printf(" %d %d\n", p, q);
    for(i=0;i<N;i++){
      printf("%d ",id[i]);
    }
    printf("\n");
  }
  return 0;
}

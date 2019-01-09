#include <stdlib.h>
#include <stdio.h>
typedef struct node* link;
struct node { int item; link next; };

/*
 *  Josephus problem solver
*/
int main(int argc, char *argv[]){
  int i, N = atoi(argv[1]), M = atoi(argv[2]);
  int x;
  int next[N];
  int item[N];
  for(i = 0; i< N; i++){
    next[i] = i + 1;
    item[i] = i + 1;
  }
  next[N-1] = 0;
  /*while(x != x->next){
    for(i = 1; i < M; i++){
      x = x->next;
    }
    x->next = x->next->next;
  }*/
  x = N-1;
  int F = N;
  while(x != next[x]){
    for(i = 1; i < M; i++){
      x = next[x];
    }
    next[x] = next[next[x]];
  }
  printf("%d\n", item[next[x]]);
}

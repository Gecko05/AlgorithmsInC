#include <stdlib.h>
#include <stdio.h>
typedef struct node* link;
struct node { int item; link next; };

/*
 *  Function that returns number of nodes on a list
*/
int number_nodes(link i_node){
  int n_nodes = 1;
  link current;
  for(current = i_node->next; current != i_node;current = current->next){
    n_nodes++;
  }
  printf("Nodes in buffer: %d\n", n_nodes);
  return n_nodes;
}

/*
 *  Funcion that returns number of nodes between two specified nodes
*/
int nodes_between(link node_1, link node_2){
  int n_nodes = 0;
  link current_node;
  for(current_node = node_1; current_node != node_2; current_node = current_node->next){
    n_nodes++;
  }
  printf("Nodes between: %d\n", n_nodes);
  return n_nodes;
}

/*
 *  Josephus problem solver
*/
int main(int argc, char *argv[]){
  int i, N = atoi(argv[1]), M = atoi(argv[2]);
  link t = malloc(sizeof *t), x = t;
  t->item = 1; t->next = t;
  for (i = 2; i <= N; i++){
    x->next = malloc(sizeof *x);
    x = x->next;
    x->item = i;
  }
  x->next = t;
  number_nodes(x);
  nodes_between(x, x->next->next);
  while(x != x->next){
    for(i = 1; i < M; i++){
      x = x->next;
    }
    x->next = x->next->next;
  }
  printf("%d\n", x->item);
}

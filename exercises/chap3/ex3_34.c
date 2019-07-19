#include <stdlib.h>
#include <stdio.h>
typedef struct node* link;
struct node{
  int item;
  link next;
};
void move_largest_last(link head_node){
  link largest_node = head_node;
  link current_node = head_node;
  link prev_larg_node = NULL;
  link previous_node = NULL;
  while(current_node != NULL){
    if(largest_node->item<current_node->item){
      largest_node = current_node;
      prev_larg_node = previous_node;
    }
    previous_node = current_node;
    current_node = current_node->next;
  }
  prev_larg_node->next = largest_node->next;
  largest_node->next = NULL;
  //printf("crash\n");
  previous_node->next = largest_node;
}

void move_smallest_first(link *head_node){
  link smallest_node = *head_node;
  link current_node = *head_node;
  link prev_small_node = NULL;
  link previous_node = NULL;
  while(current_node != NULL){
    if(smallest_node->item>current_node->item){
      smallest_node = current_node;
      prev_small_node = previous_node;
    }
    previous_node = current_node;
    //printf("Item iterated: %d\n", current_node->item);
    current_node = current_node->next;

  }
  printf("Smallest item: %d\n", smallest_node->item);
  printf("Prev Smallest item: %d\n", prev_small_node->item);
  printf("Smallest next item: %d\n", smallest_node->next->item);
  prev_small_node->next = smallest_node->next;
  smallest_node->next = *head_node;
  *head_node = smallest_node;
}

void swap_next_nodes(link t, link u){
  if(t->next == NULL || t->next == NULL){     //Make sure the next nodes exist
    return;
  }

}

void odds_first(link head){
  link h_node = head;
  link last_odd = head;
  link x = head;
  while(x != NULL){   //Find the last odd positioned node
    last_odd = x;
    if(x->next == NULL){
      break;
    }
    x = x->next->next;
  }
  printf("Last odd found %d\n ", last_odd->item);
  link y = head;
  link first_even = head->next;
  x = first_even;
  while(y != last_odd){
    if(y->next !=NULL){
      printf("%d\n",y->item);
      y->next = y->next->next;
      y = y->next;
    }
    if(x->next != NULL){
      printf("%d\n",x->item);
      x->next = x->next->next;
      x = x->next;
    }
    /*char keep;
    scanf("%c",&keep);*/
  }
  last_odd->next = first_even;
}

link save_list(link first_node){
  link x, new_first, y;
  link t = first_node;
  new_first = malloc(sizeof *new_first);
  new_first->item = first_node->item;
  t = t->next;
  y = new_first;
  while(t!=NULL){
    x = malloc(sizeof *x);
    y->next = x;
    x->item = t->item;
    t = t->next;
    y = x;
  }
  y->next = NULL;
  return new_first;
}

int is_even(link node){
  if(node->item % 2 == 0){
    return 1;
  }
  else{
    return 0;
  }
}

void remove_nodes(link head, int (*function)(link)){
  link x = head;
  link t;
  printf("Erasing nodes\n");
  while(x != NULL){
    if(function(x) != 0){
      if(x == head){
        head = x->next;
      }
      else{
        t->next = x->next;
      }
      free(x);
      t = x;
      x = x->next;
    }
    else{
      t = x;
      x = x->next;
    }
  }
}


int main(){
  int i = 0;
  int N = 1005;
  link x, t, head;
  t = malloc(sizeof *x);
  t->item = 1;
  head = t;
  for(i=2;i<=N;i++){
    x = malloc(sizeof *x);
    x->item = i;
    t->next = x;
    t = x;
  }
  t->next = NULL;
  /*head->next->next->next->item = 12;
  head->next->next->next->next->next->next->item = 0;*/
  t = head;
  printf("Original Linked List\n");
  while(t!=NULL){
    printf("node_item: %d\n", t->item);
    t = t->next;
  }
  //odds_first(head);
  //link new_head = save_list(head);
  remove_nodes(head, is_even);
  printf("Modified Linked List\n");
  t = head;
  while(t!=NULL){
    printf("node_item: %d\n", t->item);
    t = t->next;
  }
}

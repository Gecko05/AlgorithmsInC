#include <stdio.h>
#include <stdlib.h>
typedef struct *node link;
struct node{
  int item;
  link next_x;
  link next_y;
}

int multi_array[3][3] = {{0, 0, 1}, {1, 0, 0}, {1, 0, 1}};

void convert_multilist(int **m_array){
  link head;
  link x = malloc(sizeof *x);
  link t_x = NULL;
  link t_y = NULL;
  head = x;
  int rows = sizeof(m_array);
  int columns = sizeof(m_array[0]);
  int i,j,k;
  for(i=0;i<rows;i++){

    for(j = 0; j < columns; i++){
      if(m_array[i][j] != 0){
        x = malloc(sizeof *x);
        x->item = m_array[i][j];
        t_y = x;
      }
    }
  }

}
int main(){

}

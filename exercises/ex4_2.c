#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct Points{
  float x;
  float y;
}Point;

#define eq(a,b) (a.x==b.x && a.y == b.y)

Point a, b, c;

int main(){
  a.x = 1.5;
  a.y = 3.2;

  b.x = 2.5;
  b.y = 5.6;

  c.x = 2.5;
  c.y = 5.6;
  if(eq(a,b)){
    printf("They're equal\n");
  }
  else{
    printf("They're not equal\n");
  }
  if(eq(c,b)){
    printf("They're equal\n");
  }
  else{
    printf("They're not equal\n");
  }

}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef float Item;
#define max(A,B) \
  ({ __typeof__ (A) _a = (A);\
      __typeof__ (B) _b = (B);\
    _a > _b ? _a : _b; })
#define eq(A,B) ((fabs(A - B)/fabs(max(A,B))) < 10E-6)

Item a = 2.44;
Item b = 2.44;

int main(){
  if(eq(a,b)){
    printf("Son iguales\n");
  }
}

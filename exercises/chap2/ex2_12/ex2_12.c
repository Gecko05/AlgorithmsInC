#include <math.h>
#include "stdio.h"
#define N 5

double harmonic(double num){
  return log(num) + 0.57721;
}

int main(){
  printf("Harmonic of %i: %f",N,harmonic((double)N));
}

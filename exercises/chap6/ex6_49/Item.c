// Sample implementation for item data type

#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
long int ITEMrand(void){
    return rand() / RAND_MAX;
}
int ITEMscan(double *x){
    return scanf("%ld", x);
}
void ITEMshow(double x){
    printf("%ld ", x);
}
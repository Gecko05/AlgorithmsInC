// Sample implementation for item data type

#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
double ITEMrand(void){
    return 1.0 * rand() / RAND_MAX;
}
int ITEMscan(double *x){
    return scanf("%f", x);
}
void ITEMshow(double x){
    printf("%7.5f ", x);
}
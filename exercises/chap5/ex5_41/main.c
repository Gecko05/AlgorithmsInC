#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int *res;

int calculateP(int n){
    
    return res;
}

int main(int argc, char *argv[])
{
    int a = *argv[1] - '0';
    res = malloc(sizeof(int) * a);
    int b = calculateP(a);
    printf("Result is: %i\n", b);
    free(res);
}
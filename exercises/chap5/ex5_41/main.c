#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int res;
int *ar;

int calculateP(int n){
    if (ar[n] != -1){
        return ar[n];
    }
    int a = floor(n/2);
    int b = ceil((float)n/2);
    if (ar[a] != -1){
        a = ar[a];
    }
    else{
        a = calculateP(a);
    }
    if (ar[b] != -1){
        b = ar[b];
    }
    else{
        b = calculateP(b);
    }
    res = floor(n/2) + a + b;
    ar[n] = res;
    return res;
}

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    ar = malloc(sizeof(int) * (a + 1));
    ar[0] = 0;
    ar[1] = 1;
    for (int i = 2; i <= a; i++){
        ar[i] = -1;
    }
    int b = calculateP(a);
    printf("Result is: %i\n", b);
    free(ar);
}
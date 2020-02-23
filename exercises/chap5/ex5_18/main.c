#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 10

int max(int *a, int l, int r){
    int u, v;
    int n = l + r;
    int m = pow(2, log10(n) - 1);
    printf("%i\n", m);
    if (l == r){
        return a[l];
    }
    u = max(a, l, m);
    v = max(a, m+1, r);
    if (u > v){
        return u;
    }
    else{
        return v;
    }
}

int main(int argc, char *argv[]){
    int a[N];
    for (int i = 0; i < N; i++){
        a[i] = i;
    }
    int b = max(a, 0, N);
    printf("Max: %i\n", b);
}
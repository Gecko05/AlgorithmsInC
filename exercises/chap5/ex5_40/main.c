#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int *ar;

int calculateP(int n){
    int res = 0;
    int c = 1;
    int p = 0;
    int q = 0;
    if (n == 0 || n == 1){
        return n;
    }
    for (int i = 2; i <= n; i++){
        res = floor(i/2) + ar[p] + ar[q];
        printf("%i %i %i\n", (int)floor(i/2), ar[p],  ar[q]);
        if (p == q){
            q = q + 1;
        }
        else{
            p = q;
        }
        ar[c] = res;
        if (p >= n){
            p = 0;
        }
        if (c >= n){
            c = 0;
        }
        c++;
    }
    return res;
}

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    ar = malloc(sizeof(int) * (a/2));
    printf("size %i\n", a);
    for (int i = 0; i < a; i++){
        ar[i] = 1;
    }
    int b = calculateP(a);
    free(ar);
    printf("Result is: %i\n", b);
}
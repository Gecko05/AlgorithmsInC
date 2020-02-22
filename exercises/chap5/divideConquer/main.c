#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRAY_LEN 33

int max0(int *a){
    int max = 0;
    for (int i = 0; i < ARRAY_LEN; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int max1(int *a, int l, int r){
    int u, v;
    int m = (l+r)/2;
    if (l == r){
        return a[l];
    }
    u = max1(a, l, m);
    v = max1(a, m+1, r);
    if (u > v){
        return u;
    }
    else{
        return v;
    }
}


int main(int arc, char *argv[]){
    clock_t start;
    clock_t end;
    int a[] = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2};
    start = clock();
    max0(a);
    end = clock();
    int elapsed = (end - start);
    printf("Elapsed 1: %i\n", elapsed);
    start = clock();
    max1(a,0,ARRAY_LEN);
    end = clock();
    elapsed = (end - start);
    printf("Elapsed 2: %i\n", elapsed);
}
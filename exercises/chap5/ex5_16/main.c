#include <stdio.h>
#include <stdlib.h>

#define N 6

int getMax(int a, int b){
    return a > b ? a : b;
}

int max(int *a, int i){
    if (i == 0){
        return a[0];
    }
    else{
        int b = max(a, i - 1);
        return getMax(b, a[i]);
    }
}

int main(int arc, char *argv[]){
    int a[N];
    for (int i = 0; i < N; i++){
        a[i] = i;
    }
    int b = max(a, N-1);
    printf("Max: %i\n", b);

}
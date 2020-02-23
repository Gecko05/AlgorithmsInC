#include <stdlib.h>
#include <stdio.h>

#define N 5

int exptwo(int b){
    if (b == 0){
        return 1;
    }
    return (exptwo(b - 1) * 2);
}

void fillBinRec(int r, int l, int **a, int h){
    int m = (r + l) / 2;
    if (h > 0){
        
        for (int i = r; i < m; i++){
            a[i][h-1] = 0;
        }

        fillBinRec(r, m, a, h - 1);
        
        for (int i = m; i < l; i++){
            a[i][h-1] = 1;
        }

        fillBinRec(m, l, a, h - 1);
    }
    
}

void fillBin(int **a, int d){
    int len = exptwo(d);
    int r = 0;
    fillBinRec(r, len, a, d);
}

int main(int argc, char *argv[]){
    int a = exptwo(N);
    printf("lenght %i\n", a);
    int *array[a];
    for (int i = 0; i < a; i++){
        array[i] = (int *)malloc(sizeof(int) * N);
    }

    fillBin(array, N);
    for (int i = 0; i < a; i++){
        for (int j = N - 1; j >= 0; j --){
            printf("%i", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    free(*array);
}
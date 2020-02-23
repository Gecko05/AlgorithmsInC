#include <stdlib.h>
#include <stdio.h>

#define N 5

int exptwo(int b){
    if (b == 0){
        return 1;
    }
    return (exptwo(b - 1) * 2);
}

void fillBin(int r, int l, int **a, int h){
    int m = (r + l) / 2;
    if (h > 0){
        
        for (int i = r; i < m; i++){
            a[i][h-1] = 0;
        }

        fillBin(r, m, a, h - 1);
        
        for (int i = m; i < l; i++){
            a[i][h-1] = 1;
        }

        fillBin(m, l, a, h - 1);
    }
    
}

int main(int argc, char *argv[]){
    int a = exptwo(N);
    printf("lenght %i\n", a);
    int *array[a];
    for (int i = 0; i < a; i++){
        array[i] = (int *)malloc(sizeof(int) * N);
    }

    fillBin(0, a, array, N);
    for (int i = 0; i < a; i++){
        for (int j = N - 1; j >= 0; j --){
            printf("%i", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    free(*array);
}
#include <stdlib.h>
#include <stdio.h>

int table[6][3];

int coef(int *bin)
{
    int x[2];
    int y[2];
    int N = bin[0];
    int k = bin[1];
    int km = k - 1;
    int a;
    int b;

    if (table[N][k] != -1){
        return table[N][k];
    }
    if (N == k || k == 0){
        table[N][k] = 1;
        return 1;
    }
    N = N - 1;
    if (table[N][k] != -1){
        a = table[N][k];
    }
    else{
        x[0] = N;
        x[1] = k;
        a = coef(x);
    }
    if (table[N][km] != -1){
        b = table[N][km];
    }
    else{
        y[0] = N;
        y[1] = km;
        b = coef(y);
    }
    int c = a + b;
    table[N+1][k] = c;
    return c;    
}

int main(int argc, char *argv[]){
    int *binCo = malloc(sizeof(int) * 2);
    binCo[0] = 5;
    binCo[1] = 2;
    for (int i = 0; i <= 5; i++){
        for (int j = 0; j <= 2; j++){
            table[i][j] = -1;
        }
    }
    int res = coef(binCo);
    printf("Result is: %i\n", res);
    free(binCo);
}
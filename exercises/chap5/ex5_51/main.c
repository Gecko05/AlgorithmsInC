#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int size;
    int val;
} Item;

int maxInt(int a, int b){
    return a > b ? a : b;
}

#define N 5
Item items[N];

int knap(int cap){
    int table[N+1][cap+1];
    memset(table, 0, cap*N*4);
    int maxC = 0;
    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= cap; j++){
            if (i == 0 || j == 0){
                table[i][j] = 0;
                printf("0 ");
            }
            else {
                // Previous value with same size
                int prev = table[i-1][j];
                // Previous row value plus the weight of the curent item if posssible
                int new;
                if (items[i - 1].size <= j){
                    new = items[i-1].val + table[i-1][j-items[i-1].size];
                }
                else{
                    new = 0;
                }
                int max = maxInt(prev, new);
                printf("%i ", max);
                table[i][j] = max;
                if (max > maxC){
                    maxC = max;
                }
            }
        }
        printf("\n");
    }
    printf("max: %i\n", table[N-1][cap-1]);
    return table[N][cap];
}

int main(int argc, char *argv[]){
    Item itemA = {.size = 3, .val = 4};
    Item itemB = {.size = 4, .val = 5};
    Item itemC = {.size = 7, .val = 10};
    Item itemD = {.size = 8, .val = 11};
    Item itemE = {.size = 9, .val = 13};
    items[0] = itemA;
    items[1] = itemB;
    items[2] = itemC;
    items[3] = itemD;
    items[4] = itemE;
    printf("Knap of %i: %i\n", 10, knap(10));
}
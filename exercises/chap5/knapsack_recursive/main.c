#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int size;
    int val;
} Item;

#define N 5
Item items[N];

int knap(int cap){
    int space;
    int max;
    int t;
    int i; // Declaring it inside the loop would also declare max inside the loop
    for (i = 0, max = 0; i < N; i++){
        if ((space = cap - items[i].size) >= 0)
        {
            if ((t = knap(space) + items[i].val) > max)
            {
                max = t;
                printf("max: %i\n", max);
            }
        }
    }
    printf("max: %i\n", max);
    return max;
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
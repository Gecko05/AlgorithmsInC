#include <stdio.h>
#include "UF.h"

int main(int argc, char *argv[])
{
    int p;
    int q;
    int N = atoi(argv[1]);
    UFinit(N);
    while (scanf("%d %d", &p, &q) == 2){
        if (UFfindAndUnion(p, q)){
            printf(" %d %d\n", p, q);
        }
    }
}
// Key-indexed counting as a pointer sort
#include <stdlib.h>
#include <stdio.h>

#define M 5
#define maxN 8

void distcount(int *a[], int l, int r)
{
    int i;
    int j;
    int cnt[M];
    //int b[maxN];
    int *b[maxN];
    
    for (j = 0; j < M; j++){
        cnt[j] = 0;
    }
    for (i = l; i <= r; i++){
        cnt[(*a[i])+1]++;
    }
    for (j = 1; j < M; j++){
        cnt[j] += cnt[j-1];
    }
    for (i = l; i <= r; i++){
        b[cnt[*a[i]]++] = a[i];
    }
    for (i = l; i <= r; i++){
        a[i] = b[i-l];
    }
}

int main(){
    int v1 = 1;
    int v2 = 3;
    int v3 = 4;
    int v4 = 2;
    int v5 = 0;
    int v6 = 3;
    int v7 = 1;
    int v8 = 0;
    int *data[8] = {&v1,&v2,&v3,&v4,&v5,&v6,&v7,&v8};
    for (int i = 0; i < 8; i++){
        printf("%i ", *(data[i]));
    }
    printf("\n");
    distcount(data, 0, 7);
    for (int i = 0; i < 8; i++){
        printf("%i ", *(data[i]));
    }
    printf("\n");
}
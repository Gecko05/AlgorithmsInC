#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "sort.h"
#include "Item.h"

#define DEBUG
// Exercise driver client to run sort
#define NUM_OF_TESTS 4
const char *testFiles[] = {"file1",
                           "file2",
                           "file3",
                           "file4"};

Item *sortFile(const char *name, int *l, int *r){
    FILE *fp = fopen(name, "r");
    char rBuffer[10];
    Item v;
    char *s;
    Item *a = malloc(sizeof(*a));
    int c = 0;
    do{
        s = fgets(rBuffer,10,fp);
        v = atoi(rBuffer);
        c++;
        a = realloc(a, c*(sizeof(*a)));
        a[c-1] = v;
        //printf("%i", a[c-1]);
    }while (s != NULL);
    *l = 0;
    *r = c;
    sort(a, 0, c);
    fclose(fp);
    return a;
}

int verifySort(Item *a, int l, int r){
    int res = 1;
    for (int i = l + 1; i <= r; i++){
        printf("%i ", a[i]);
        if (a[i] < a[i-1]){
            res = 0;
        }
    }
    printf("\n");
    return res;
}

int runSort(const char* name){
    int l, r;
    Item *a = sortFile(name, &l, &r);
    int result = verifySort(a, l, r);
    free(a);
    return result;
}

int main(){
    int result;
    for (int i = 0; i < NUM_OF_TESTS; i++)
    {
        result = runSort(testFiles[i]);
        assert(result == 1);
        printf("%s Passed\n", testFiles[i]);
    }
    return 0;
}
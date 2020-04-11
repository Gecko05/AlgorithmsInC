#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "verify_sort.h"

int main(int argc, char *argv[])
{
    int a = runSortTests();
    if (a){
        printf("Passed tests!\n");
    }
    else{
        printf("Didn't pass\n");
    }
}
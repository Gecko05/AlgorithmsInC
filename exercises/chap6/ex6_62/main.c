// In-place sort for pointers
// The idea is to use pointers as indexes, subtracting and adding pointers
// from the array of pointers
#include <stdio.h>
#include <stdlib.h>
typedef int dataType;

int toIndex(dataType *p, dataType *a){
    return (p - a);
}

dataType *toPointer(int n, dataType *a){
    return a + n;
}

void insitu(dataType data[], dataType *a[], int N){
    int i, j, k;
    for (i = 0; i < N; i++){
        dataType v = data[i];
        k = i;
        while (toIndex(a[k],data) != i){
            j = k;
            data[k] = data[toIndex(a[k],data)];
            k = toIndex(a[j],data);
            a[j] = toPointer(j,data);
        }
        data[k] = v;
        a[k] = toPointer(k,data);
    }
}

int main(int argc, char *argv[])
{
    dataType a[] = {4,1,3,5,0,2};
    dataType *sortedIndexes[] = {a+4,a+1,a+5,a+2,a+0,a+3};
    printf("Data array: ");
    for (int i = 0; i < 6; i++){
        printf("%i ", a[i]);
    }
    printf("\nPointer array: ");
    for (int i = 0; i < 6; i++){
        printf("%i ", toIndex(sortedIndexes[i], a));
    }
    insitu(a, sortedIndexes, 6);
    printf("\nData array: ");
    for (int i = 0; i < 6; i++){
        printf("%i ", a[i]);
    }
    printf("\nIndexes array: ");
    for (int i = 0; i < 6; i++){
        printf("%i ", *sortedIndexes[i]);
    }
    printf("\n");
    return 0;
}
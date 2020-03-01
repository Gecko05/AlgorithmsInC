#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// Incomplete
int calculateP(int n){
    int res = 0;
    int a = 0;
    int b = 1;
    int m = 0;
    int h = 0;
    if (n == 0){
        return 0;
    }
    for (int i = 0; i <= n; i++){
        res = floor(i/2) + a + b;
        printf("%i %i %i\n", (int)floor(i/2),a ,b);
        m = i * 2;
        h = floor(m/2);
        if (h != i){
            b = res;
        }
        else{
            a = b;
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    int a = *argv[1] - '0';
    int b = calculateP(a);
    printf("Result is: %i\n", b);
}
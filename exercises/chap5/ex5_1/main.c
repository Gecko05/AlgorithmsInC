#include <stdlib.h>
#include <stdio.h>

int getFactorial(int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * getFactorial(n - 1);
    }
}

float getLog(float n){
    if (n <= 10){
        return 1;
    }
    else{
        return getLog(n/10) + 1;
    }
}

int main(){
    printf("8! is %i\n", getFactorial(8));
    printf("Log(8!) is %0.2f\n", getLog(getFactorial(8)));
}
#include <stdlib.h>
#include <stdio.h>

int getExp(int a, int c, int n){
    if (c >= a){
        return n;
    }
    return getExp(a, c * 2, n + 1);
}

int getPow(int a, int b){
    if (b <= 0){
        return 1;
    }
    return getPow(a, b - 1) * a;
}

int trailingRec(int r, int l, int h, int k){
    int m = (r + l) / 2;
    if (k < m){
        return trailingRec(r, m, h - 1, k);
    }
    else if (k == m){
        return h;
    }
    else if (k > m){
        return trailingRec(m, l, h - 1, k);
    }
}

int getTrailingZeroes(int n){
    int r = 0;
    int powN = getExp(24, 1, 0);
    printf("Power of 2: %i\n", powN);
    int end = getPow(2, powN);
    printf("Max rep: %i\n", end);
    trailingRec(0, end, powN - 1, n);
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int c = getTrailingZeroes(n);
    printf("Trailing zeroes of %i: %i\n", n , c);
}
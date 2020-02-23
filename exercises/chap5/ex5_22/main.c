#include <stdlib.h>
#include <stdio.h>

int ruler(int l, int r, int h, int i){
    int m = (l + r) / 2;
    if (h > 0){
        if (i < m){
            return ruler(l, m, h - 1, i);
        }
        else if (i == m){
            printf("h %i\n", h);
            return h;
        }
        else if(i > m){
            return ruler(m, r, h - 1, i);
        }
            
    }
}

int main(int argc, char *argv[]){
    int r = 0;
    r = ruler(0, 32, 9, 4);
    printf("Result: %i\n", r);
}
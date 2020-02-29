#include "stdio.h"
#include "stdlib.h"
#include "math.h"
// Program to draw a koch star

const char *box = "box";
FILE *fp;

void printFractalStar(int len, int order){
    len = len/3;
    if (order >= 1){
        printFractalStar(len, order - 1);
        fprintf(fp, "-60 rotate\n");
        printFractalStar(len, order - 1);
        fprintf(fp, "120 rotate\n");
        printFractalStar(len, order - 1);
        fprintf(fp, "-60 rotate\n");
        printFractalStar(len, order - 1);
    }
    else{
        fprintf(fp, "%i 0 rlineto\n", len);
    }
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int l = 10;
    fp = fopen("kochstar.ps", "w+");
    fprintf(fp, "100 500 moveto\n");
    for (int i = 0; i < n; i++){
        l = l * 3;
    }
    printFractalStar(l, n);
    fprintf(fp, "-120 rotate\n");
    printFractalStar(l, n);
    fprintf(fp, "-120 rotate\n");
    printFractalStar(l, n);
    fprintf(fp, "stroke\nshowpage\n");
    fclose(fp);
}
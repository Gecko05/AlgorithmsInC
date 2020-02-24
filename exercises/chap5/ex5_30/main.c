#include "stdio.h"
#include "stdlib.h"
#define SCALE 20

const char *box = "box";

void printFractalRec(int x0, int y0, int r){
    int dx = r/2;
    int dy = r/2;
    if (r >= 5){
        int vr = r;
        int vx = ((x0-dx));
        int zx = ((x0+dx));
        int vy = ((y0-dy));
        int zy = ((y0+dy));
        printFractalRec(vx, vy, r/2);
        printFractalRec(zx, vy, r/2);
        printf("%i %i %i %s\n", vr, vx, zy, box);
        printFractalRec(vx, zy, r/2);
        printFractalRec(zx, zy, r/2);
    }
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    printFractalRec(200, 200, n);
}
#include <stdio.h>
int main(int argc, char** argv){
  float h = 0;
  int n;
  sscanf(argv[1],"%i",&n);
  printf("Scanned: %i\r\n",n);
  for(int i=1;i<=n;i++){
    h+= 1.0/i;
    printf("%f\n",h);
  }
}

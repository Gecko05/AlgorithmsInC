#include <stdio.h>
int lg(int num){
  int bits = 0;
  if(num>0xFFFF){
    num>>=16;
    bits |= 0x10;
  }
  if(num>0xFF){//1
    num>>=8;
    bits |= 0x08;
  }
  if(num>0xF){
    num>>=4;
    bits |= 0x04;
  }
  if(num>0x3){
    num>>=2;
    bits |= 0x02;
  }
  if(num>0x1){
    bits |= 0x01;
  }
  printf("Bits: %i\n",bits);
  return bits;
}
int lglg(int num){
  return lg(lg(num));
}

int main(int argc, char *argv[]){
  for(int j = 2;j<argc;j++){
    int arg_n;
    printf("Arg: %s\n",argv[j]);
    if(sscanf(argv[j],"%i",&arg_n)){
      lglg(arg_n);
    }
    else{
      printf( "error not integer\n");
    }
  }
}

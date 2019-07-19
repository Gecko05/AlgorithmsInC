#include "stdio.h"
#include "string.h"
int i = 0, freepos = 0;
//char msg[30] = "abcdefghijklmnoprqstuvwxyz";
char msg[30] = "hola mundo como andamos ??";
char unique[30];
int reps[30];

int find_char(char *str_s, char char_f){
  int j = 0;
  while(str_s[j] != 0){
    if(str_s[j] == char_f){
      return j;
    }
    j++;
  }
  return -1;
}

int main(){
  memset(unique,0,30);
  memset(reps,0,30);
  //Iterate over the string
  while(msg[i] != 0){
    // Find out if the first character has repeated
    if(find_char(unique, msg[i]) == -1){
      //Hasn't repeated
      unique[freepos] = msg[i]; //Add to repeated array
      reps[freepos] = 1; //Initialize repetitions
      freepos++;          //Count up in position of rep array
    }
    else{
      //search the position in repetitions array and increment
      int pos_r = find_char(unique, msg[i]);
      reps[pos_r]++;
    }
    printf("%c",msg[i]);
    i++;
  }
  printf("\nReps:\n");
  for(i=0;i<30;i++){
    printf("%c :", unique[i]);
    printf("%i\n", reps[i]);
  }
}

//Find the longes sequence of blanks
#include "time.h"
#include "stdio.h"
#include "string.h"
clock_t start, end;
double cpu_time_used;
char sentence[] = "             hola amigos      esto viene           siendo una          cadena larga      ";
int i,j,k;
int is_blank = 1;
int longest = 0;
int current = 0;
int max_len = 0;

int main(){
  start = clock();
  //iterate over the sentence
  while(sentence[current] != 0){
    //find blank space
    printf("Current: %c\n", sentence[current]);
    if(sentence[current] == ' '){
      //Check if it might be longer than the current longest
      if(sentence[current + max_len] == ' '){
        //Check that it is indeed a blank space sequence
        for(i = current;i<current + max_len;i++){
            if(sentence[i] != ' '){
              is_blank = 0;
              break;
            }
            else{
              is_blank = 1;
            }
        }
        //check the blank space sequence flag
        if(is_blank){
          longest = current;
          current = current + max_len;
          while(sentence[current] == ' '){
            max_len++;
            current++;
          }
        }
        else{
          current = i;
        }
      }
      else{
        current++;
      }
    }
    else{
      current++;
    }
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) /CLOCKS_PER_SEC;
  printf("time used: %f\n",cpu_time_used);
  printf("Position of longest: %i\n", longest);
  printf("Size of longest: %i\n", max_len);
}

/* Double stack inside Array */
#include <stdlib.h>
typedef int Item;
static Item *s;
static int n1;
static int n2;
void STACKinit(int sizeN){
  s = malloc(sizeN*sizeof(Item));
  n1 = 0;
  n2 = sizeN-1;
}
void STACKpush(int n, Item item){
  if(n == 0){
    if(n1<n2+1){
      s[n++] = item;
    }
  }
  else if(n == 1){
    if(n2>n1+1){
      s[n--] = item;
    }
  }
}
int STACKempty(int n){
  if(n == 0){
    return n1 == 0;
  }
  else if(n == 1){
    return n2 == sizeof(s)/sizeof(Item);
  }
}
Item STACKpop(int n){
  if(n == 0){
    if(!STACKempty(n)){
      return s[--n1];
    }
  }
  else if(n == 1){
    if(!STACKempty(n)){
      return s[++n2];
    }
  }
}

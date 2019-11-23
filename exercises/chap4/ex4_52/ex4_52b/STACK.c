#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

static Item *s;
static int N;

void STACKinit(int maxN){
	s = malloc(maxN * sizeof(Item));
	N = 0;
}

int STACKempty(void){
	return N == 0;
}

int isAvailable(Item item){
	for(int i = 0; i < N; i++){
		if (item == s[i]){
			return i;
		}
	}
	return -1;
}

void STACKpush(Item item){
	int position = isAvailable(item);
	if (position != -1){
		for (int i = position; i < N; i++){
			s[i] = s[i + 1];
		}
		s[N - 1] = item;
	}
	else{
		s[N++] = item;
	}
}

Item STACKpop(void){
	if (STACKempty() == 0){
		return s[--N];
	}
	return -1;
}

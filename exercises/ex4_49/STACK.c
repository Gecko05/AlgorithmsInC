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
	return 0;
}

void STACKpush(Item item){
	int position = isAvailable(item);
	if (item){
		for (int i = position; i < N; i++){
			s[i] = s[i + 1];
		}
	}
	s[N++] = item;
}

Item STACKpop(void){
	return s[--N];
}

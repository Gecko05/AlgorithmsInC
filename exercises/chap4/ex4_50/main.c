#include "STACK.h"
#include "Item.h"
#include <assert.h>
#include <stdio.h>

void dumpStack(){
	printf("Dumping stack... ");
	while (STACKempty() == 0){
		Item a = STACKpop();
		printf(" %i", a);
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	STACKinit(10);
	Item a = 2;
	Item b = 4;
	STACKpush(a);
	STACKpush(b);
	STACKpush(a);
	printf("Pushed Items...\n");
	assert(STACKpop() == b);
	assert(STACKpop() == a);

	printf("Popped Items...\n");
	assert(STACKpop() == -1);
	assert(STACKempty() == 1);
	
	printf("Successful execution\n");
}

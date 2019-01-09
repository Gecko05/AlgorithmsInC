#include "STACK.h"
#include "Item.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	STACKinit();
	Item a = 2;
	Item b = 4;
	Item c = 15;
	STACKpush(a);
	STACKpush(b);
	STACKpop();
	assert(STACKpop() == a);
	assert(STACKempty());
	STACKpush(c);
	STACKpush(c);
	STACKpush(a);
	assert(STACKpop() == a);
}

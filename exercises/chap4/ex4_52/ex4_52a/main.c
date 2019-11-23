#include "STACK.h"
#include "Item.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	QUEUEinit(10);
	Item a = 1;
	Item b = 2;
	Item c = 3;
	Item d = 5;
	Item e = 6;

	QUEUEput(a);
	assert(QUEUEget() == a);
	QUEUEput(b);
	QUEUEput(b);
	QUEUEput(a);
	QUEUEput(c);
	assert(QUEUEget() == b);
	assert(QUEUEget() == a);
	assert(QUEUEget() == c);
	
	printf("Successful execution\n ");
}

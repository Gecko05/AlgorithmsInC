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
	QUEUEput(a);
	QUEUEput(c);
	QUEUEput(a);
	QUEUEput(b);
	assert(QUEUEget() == c);
	assert(QUEUEget() == a);
	assert(QUEUEget() == b);

	assert(QUEUEget() == -1);
	
	printf("Successful execution\n ");
}

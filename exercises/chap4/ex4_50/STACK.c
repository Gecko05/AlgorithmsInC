#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

typedef struct STACKnode* link;
struct STACKnode {
	Item item;
	link next;
};

static link head;

link NEW(Item item, link next){
	link x = malloc(sizeof *x);
	x->item = item;
	x->next = next;
	return x;
}

void STACKinit(int maxN){
	head = NULL;
}

int STACKempty(void){
	return head == NULL;
}

int isAvailable(Item item){
	link x = head;
	while (x != NULL){
		if (x->item == item){
			return 1;
		}
		x = x->next;
	}
	return -1;
}

void STACKpush(Item item){
	if (isAvailable(item) == -1){
		head = NEW(item, head);
	}
}

Item STACKpop(void){
	if (STACKempty() == 1){
		return -1;
	}
	Item item = head->item;
	link t = head->next;
	free(head);
	head = t;
	return item;
}

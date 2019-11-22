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
	int c = 0;
	while (x != NULL){
		if (x->item == item){
			return c;
		}
		c = c + 1;
		x = x->next;
	}
	return -1;
}

void STACKpush(Item item){
	int p = isAvailable(item);
	if (p == -1){
		head = NEW(item, head);
		return;
	}
	int c = 0;
	link x = head;
	link t = NULL;
	while (c <= p){
		if (t != NULL){
			x->item = t->item;
		}
		t = x;
		x = x->next;
		c = c + 1;
	}
	head->item = item;
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

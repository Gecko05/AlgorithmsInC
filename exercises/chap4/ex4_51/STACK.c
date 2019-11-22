#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

typedef struct STACKnode* link;
struct STACKnode {
	Item item;
	link next;
	link prev;
};

static link head;
int max;

static link *nodes;

link NEW(Item item, link next, link prev){
	link x = malloc(sizeof *x);
	x->item = item;
	if (next != NULL){
		next->prev = x;
	}
	if (prev != NULL){
		prev->next = x;
	};
	
	x->next = next;
	x->prev = prev;
	return x;
}

void STACKinit(int maxN){
	head = NULL;
	max = maxN;
	nodes = malloc(sizeof(link) * maxN);
	for (int i = 0; i < maxN; i ++){
		nodes[i] = NULL;
	}
}

int STACKempty(void){
	return head == NULL;
}

link isAvailable(Item item){
	link c = nodes[item];
	if (c == NULL){
		return NULL;
	}
	return c;
}

void popFromList(link n){
	if (n->next != NULL){
		n->next->prev = n->prev;
	}
	if (n->prev != NULL){
		n->prev->next = n->next;
	}
}

void insertIn(link n, link next, link prev){
	n->next = next;
	n->prev = prev;
	if (prev != NULL){
		prev->next = n;
	}
	if (next != NULL){
		next->prev = n;
	}
}

void STACKpush(Item item){
	link p = isAvailable(item);
	if (p == NULL){
		head = NEW(item, head, NULL);
		nodes[item] = head;
		return;
	}
	popFromList(p);
	insertIn(p, head, NULL);
	head = p;
}

Item STACKpop(void){
	if (STACKempty() == 1){
		return -1;
	}
	Item item = head->item;
	link t = head->next;
	popFromList(head);
	free(head);
	head = t;
	return item;
}

void STACKdestroy(){
	link x = head;
	while (x != NULL){
		free(x);
		x = x->next;
	}
	free(nodes);
}
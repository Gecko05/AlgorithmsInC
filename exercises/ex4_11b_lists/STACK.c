#include "STACK.h"
static int max_n;

typedef struct node* link;
struct node{
	link next;
	Item item;
};
typedef uint8_t error_t;
enum ERROR_TYPE{
	NO_ERROR,
	MEM_ERROR,
	EMPTY_STACK
};

void STACKerror(error_t error){
	switch (error){
		case EMPTY_STACK:
			printf("Empty Stack");
			break;
		case MEM_ERROR:
			printf("Not enough memory");
			break;
		default:
			break;
	}
}

static link head;
link NEW(Item item, link next){
	link x = malloc(sizeof(*x));
	if (x == NULL){
		STACKerror(MEM_ERROR);
		return NULL;
	}
	x->next = next;
	x->item = item;
	return x;
}

void STACKinit(int maxN)
{
	head = NULL;
}

Item STACKpop(void)
{
	Item item = head->item;
	link t = head->next;
	free(head);
	head = t;
	return item;
}

void STACKpush(Item item)
{
	head = NEW(item, head);
}

int STACKempty(void)
{
	return head == NULL;
}

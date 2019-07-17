#include "STACK.h"
static int max_n;
void STACKinit(int maxN)
{
	s = malloc(sizeof(Item) * maxN);
	n = 0;
	max_n = maxN;
}

Item STACKpop(void)
{
	return s[--n];
}

void STACKpush(Item item)
{
	if (n < max_n)
		s[n++] = item;
	return;	
}

int STACKempty(void)
{
	if (n == 0)
		return 1;
	return 0;
}

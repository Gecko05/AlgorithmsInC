// List insertion sort

struct node heada;
struct node headb;
link t;
link u;
link x;
link a = &heada;
link b;

for (i = 0, t = a; i < N; i++)
{
    t->next = malloc(sizeof *t);
    t = t->next;
    t->next = NULL;
    t->item = rand() % 1000;
}

b = &headb;
b->next = NULL;
for (t = a->next; t != NULL; t = u)
{
    u = t->next;
    for (x = b; x->next != NULL; x = x->next)
    {
        if (x->next->item > t->item){
            break;
        }
    }
    t->next = x->next;
    x->next = t;
}
// Linked-list-type interface definition
typedef struct node* link;
struct node{
    Item item;
    link next;
};

link NEW(Item, link);
link init(int);
void show(link);
link sort(link);
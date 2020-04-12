// Sample interface for item data type

typedef long int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A,B) { Item t = A; A = B; B = t; }
#define compexc(A, B) if (less(A, B)) exch(A, B)
Item ITEMrand(void);
int ITEMscan(Item *);
void ITEMshow(Item);
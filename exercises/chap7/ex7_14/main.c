// Program 7.3 Nonrecursive quicksort

#define push2(A, B) if (B > A){ push(B); push(A);}

void quicksort(Item a[], int l, int r)
{
    int i;
    stackinit();
    push2(l, r);
    while (!stackempty())
    {
        l = pop();
        r = pop();
        //if (r <= l) continue; // Nothing to do
        i = partition(a, l, r);
        if (i-l > r-i){ // Find the biggest partition
            push2(l, i-1);
            push2(i+1, r);
        }
        else{
            push2(i+1, r);
            push2(l, i-1);
        }
    }
}
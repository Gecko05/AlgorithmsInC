// Partioning for quicksort without break or goto

int partition(Item a[], int l, int r)
{
    int i = l-1;
    int j = r;
    Item v = a[r];

    while (i < j){
        while (less(a[++i], v));
        while (less(v, a[--j]) || j != l);
        if (i < j){
            exch(a[i], a[j]);
        }
    }
    exch(a[i], a[r]);
    return i;
}
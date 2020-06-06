// Partioning for quicksort

int partition(Item a[], int l, int r)
{
    int i = l-1;
    int j = r;
    Item v = a[r];

    for (;;){
        while (less(a[++i], v));
        while (less(v, a[--j])){
            if (j == l){
                break;
            }
        }
        if (i >= j){
            break;
        }
        exch(a[i], a[j]);
    }
    exch(a[i], a[r]);
    return i;
}
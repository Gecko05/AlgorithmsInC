// Optimized insertion sort

void insertion(Item a[], int l, int r){
    int ;
    // Find and place sentinel
    for (i = r; i > l; i--){
        compexch(a[i-1], a[i]);
    }
    for (i = l + 2; i <= r; i++){
        int j = i;
        Item v = a[i];
        while (less(v, a[j-1])){
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}
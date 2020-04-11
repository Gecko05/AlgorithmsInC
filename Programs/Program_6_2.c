// Selection Sort

void selection(Item a[], int l, int r){
    int i, j;
    for (int i = l; i < r; i++){
        int min = i;
        for (j = i+1; j <= r; j++){
            if (less(a[j], a[min])){
                min = j;
            }
            exch(a[i], a[min]);
        }
    }
}
// In-place sort, less ofuscated version

insitu(dataType data[], int a[], int N){
    int i, j, k;
    for (i = 0; i < N; i++){
        dataType v = data[i];
        k = i;
        // While the current index isn't in order
        while (a[k] != i){
            j = k;
            data[k] = data[a[k]];
            k = a[j];
            a[j] = j;
        }
        data[k] = v;
        a[k] = k;
    }
}
int compare(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

bool checkIfExist(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);
    int table[2001] = {0};
    int count0 = 0;
    for(int i = 0; i < arrSize; i++){
        table[arr[i]+1000] = 1;
        if(arr[i] == 0) count0++;
    }
    if(count0 > 1) return 1;
    for(int i = 0; i < arrSize; i++){
        if(arr[i]%2 == 0 && table[arr[i]/2+1000] && (arr[i]+1000 != arr[i]/2+1000)) return 1;
    }
    return 0;
}

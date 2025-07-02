int cmp(const void* a, const void* b){
    return *(int*)b-*(int*)a;
}

int minSetSize(int* arr, int arrSize) {
    int freq[arrSize];
    for(int i = 0; i < arrSize; i++){
        freq[i] = 0;
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    int size = 0;
    freq[0] = 1;
    for(int i = 1; i < arrSize; i++){
        if(arr[i] != arr[i-1]) size++;
        freq[size]++;
    }
    qsort(freq, size+1, sizeof(int), cmp);
    int ans = 0, half = 0;
    while(half < arrSize/2){
        half += freq[ans];
        ans++;
    }
    return ans;
}

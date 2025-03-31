int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

long long putMarbles(int* weights, int weightsSize, int k) {
    if(k == 1 || weightsSize == k) return 0;
    long long cut[weightsSize-1];
    for(int i = 0; i < weightsSize-1; i++){
        cut[i] = weights[i]+weights[i+1];
    }
    qsort(cut, weightsSize-1, sizeof(long long), cmp);
    long long max = 0, min = 0;
    for(int i = 0; i < k-1; i++){
        max += cut[weightsSize-2-i];
        min += cut[i];
    }
    return max-min;
}

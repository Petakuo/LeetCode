long long get(int n){
    long long count = 0;
    int bit = 1, base = 1;
    while(base <= n){
        int end = base*2-1 < n ? base*2-1 : n;
        count += (long long)(bit+1)/2*(end-base+1);
        bit++;
        base *= 2;
    }
    return count;
}

long long minOperations(int** queries, int queriesSize, int* queriesColSize) {
    long long ans = 0;
    for(int i = 0; i < queriesSize; i++){
        long long start = get(queries[i][0]-1);
        long long end = get(queries[i][1]);
        ans += (end-start+1)/2;
    }
    return ans;
}

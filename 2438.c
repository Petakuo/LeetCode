/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MOD 1000000007

int* productQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int bits = 0, temp = n;
    while(temp){
        if((temp&1) == 1) bits++;
        temp >>= 1;
    }
    int* powers = (int*)malloc(bits*sizeof(int));
    int base = 1;
    for(int i = 0; i < bits; i++){
        while((n&1) == 0){
            n >>= 1;
            base *= 2;
        }
        powers[i] = base;
        n >>= 1;
        base *= 2;
    }
    int* ans = (int*)malloc(queriesSize*sizeof(int));
    *returnSize = queriesSize;
    for(int i = 0; i < queriesSize; i++){
        long long cal = 1;
        for(int j = queries[i][0]; j <= queries[i][1]; j++){
            cal *= powers[j]%MOD;
            cal %= MOD;
        }
        ans[i] = (int)cal;
    }
    free(powers);
    return ans;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int* ans = (int*)malloc(161700*sizeof(int));
    int table[1000] = {0};
    (*returnSize) = 0;
    for(int i = 0; i < digitsSize; i++){
        if(digits[i] != 0){
            for(int j = 0; j < digitsSize; j++){
                if(j == i) continue;
                for(int k = 0; k < digitsSize; k++){
                    if(k == i || k == j) continue;
                    if((digits[k]&1) == 0){
                        int n = digits[i]*100+digits[j]*10+digits[k];
                        if(table[n] == 0) ans[(*returnSize)++] = n;
                        table[n]++;
                    }
                }
            }
        }
    }
    qsort(ans, *returnSize, sizeof(int), cmp);
    return ans;
}

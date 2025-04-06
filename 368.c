/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    int* dp = (int*)malloc(numsSize*sizeof(int));
    int* prev = (int*)malloc(numsSize*sizeof(int));
    for(int i = 0; i < numsSize; i++){
        dp[i] = 1;
        prev[i] = -1;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int maxLen = 0, maxIndex = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < i; j++){
            if(nums[i]%nums[j] == 0 && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
                prev[i] = j;
            }
        }
        if(dp[i] > maxLen){
            maxLen = dp[i];
            maxIndex = i;
        }
    }
    int* ans = (int*)malloc(maxLen*sizeof(int));
    *returnSize = maxLen;
    while(maxLen){
        ans[maxLen-1] = nums[maxIndex];
        maxIndex = prev[maxIndex];
        maxLen--;
    }
    free(dp);
    free(prev);
    return ans;
}

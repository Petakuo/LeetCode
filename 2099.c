/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    int* ans = (int*)malloc(k*sizeof(int));
    *returnSize = k;
    int sort[numsSize];
    for(int i = 0; i < numsSize; i++){
        sort[i] = nums[i];
    }
    qsort(sort, numsSize, sizeof(int), cmp);
    bool used[numsSize];
    for(int i = 0; i < numsSize; i++){
        used[i] = 0;
    }
    int ansIdx = 0, idx = numsSize-1, temp = k;
    while(temp > 0){
        for(int j = 0; j < numsSize; j++){
            if(used[j] == 0 && nums[j] == sort[idx]){
                ans[ansIdx++] = j;
                temp--;
                used[j] = 1;
                break;
            }
        }
        idx--;
    }
    qsort(ans, k, sizeof(int), cmp);
    for(int i = 0; i < k; i++){
        ans[i] = nums[ans[i]];
    }
    return ans;
}

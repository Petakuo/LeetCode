/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    int* positive = (int*)malloc(numsSize/2*sizeof(int));
    int* negative = (int*)malloc(numsSize/2*sizeof(int));
    int pIdx = 0, nIdx = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0) positive[pIdx++] = nums[i];
        else negative[nIdx++] = nums[i];
    }
    for(int i = 0; i < numsSize; i++){
        if((i&1) == 0) ans[i] = positive[i/2];
        else ans[i] = negative[i/2];
    }
    free(positive);
    free(negative);
    return ans;
}

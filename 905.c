/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    int left = 0, right = numsSize-1;
    for(int i = 0; i < numsSize; i++){
        if((nums[i]&1) == 0) ans[left++] = nums[i];
        else ans[right--] = nums[i];
    }
    return ans;
}

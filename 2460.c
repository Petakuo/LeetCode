/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* applyOperations(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)calloc(numsSize, sizeof(int));
    for(int i = 0; i < numsSize-1; i++){
        if(nums[i] == nums[i+1]){
            nums[i] <<= 1;
            nums[i+1] = 0;
            i++;
        }
    }
    int index = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            ans[index] = nums[i];
            index++;
        }
    }
    *returnSize = numsSize;
    return ans;
}

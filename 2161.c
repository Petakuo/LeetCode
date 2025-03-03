/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int* ans = (int*)malloc(numsSize*sizeof(int));
    int index = 0;
    for(int i = index; i < numsSize; i++){
        if(nums[i] < pivot) ans[index++] = nums[i];
    }
    for(int i = i; i < numsSize; i++){
        if(nums[i] == pivot) ans[index++] = nums[i];
    }
    for(int i = i; i < numsSize; i++){
        if(nums[i] > pivot) ans[index++] = nums[i];
    }
    *returnSize = numsSize;
    return ans;
}

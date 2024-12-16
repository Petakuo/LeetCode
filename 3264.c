/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    *returnSize = numsSize;
    while(k > 0){
        int min = nums[0], index = 0;
        for(int i = 0; i < numsSize; i++){
            if(nums[i] < min){
                min = nums[i];
                index = i;
            }
        }
        nums[index] *= multiplier;
        k--;
    }
    return nums;
}

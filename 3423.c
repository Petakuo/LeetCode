int maxAdjacentDistance(int* nums, int numsSize) {
    int max = 0;
    for(int i = 1; i < numsSize; i++){
        max = abs(nums[i]-nums[i-1]) > max ? abs(nums[i]-nums[i-1]) : max;
    }
    max = abs(nums[0]-nums[numsSize-1]) > max ? abs(nums[0]-nums[numsSize-1]) : max;
    return max;
}

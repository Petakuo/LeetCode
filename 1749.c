int maxAbsoluteSum(int* nums, int numsSize) {
    int max = 0, curMax = 0, min = 0, curMin = 0;
    for(int i = 0; i < numsSize; i++){
        curMax = fmax(curMax+nums[i], nums[i]);
        max = max > curMax ? max : curMax;
    }
    for(int i = 0; i < numsSize; i++){
        curMin = fmin(curMin+nums[i], nums[i]);
        min = min > abs(curMin) ? min : abs(curMin);
    }
    return max > min ? max : min; 
}

int maximumDifference(int* nums, int numsSize) {
    int ans = -1;
    int min = nums[0];
    for(int i = 1; i < numsSize; i++){
        min = nums[i] < min ? nums[i] : min;
        if(nums[i]-min > ans && nums[i] != min) ans = nums[i]-min;
    }
    return ans;
}

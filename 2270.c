int waysToSplitArray(int* nums, int numsSize) {
    long long left = nums[0];
    long long right = 0;
    for(int i = 1; i < numsSize; i++){
        right += nums[i];
    }
    int ans = 0;
    if(left >= right) ans++;
    for(int i = 1; i < numsSize-1; i++){
        left += nums[i];
        right -= nums[i];
        if(left >= right) ans++;
    }
    return ans;
}

int countPartitions(int* nums, int numsSize) {
    int ans = 0, left = nums[0], right = 0;
    for(int i = 1; i < numsSize; i++){
        right += nums[i];
    }
    if(((right-left)&1) == 0) ans++;
    for(int i = 1; i < numsSize-1; i++){
        left += nums[i];
        right -= nums[i];
        if(((right-left)&1) == 0) ans++;
    }
    return ans;
}

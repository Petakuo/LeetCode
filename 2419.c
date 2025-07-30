int longestSubarray(int* nums, int numsSize) {
    int max = nums[0];
    for(int i = 1; i < numsSize; i++){
        max = max > nums[i] ? max : nums[i];
    }
    int ans = 1, cur = 1;
    for(int i = 0; i < numsSize-1; i++){
        if(nums[i] == max && nums[i] == nums[i+1]) cur++;
        else cur = 1;
        ans = ans > cur ? ans : cur;
    }
    return ans;
}

long long maximumTripletValue(int* nums, int numsSize) {
    long long ans = 0, cur = 0;
    for(int k = 2; k < numsSize; k++){
        int maxi = nums[0];
        for(int j = 1; j < k; j++){
            cur = (long long)(maxi-nums[j])*nums[k];
            ans = ans > cur ? ans : cur;
            maxi = maxi > nums[j] ? maxi : nums[j];
        }
    }
    return ans;
}

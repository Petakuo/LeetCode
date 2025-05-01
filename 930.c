int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    int freq[numsSize+1];
    memset(freq, 0, sizeof(freq));
    freq[0] = 1;
    int preSum = 0, ans = 0;
    for(int i = 0; i < numsSize; i++){
        preSum += nums[i];
        if(preSum >= goal) ans += freq[preSum-goal];
        freq[preSum]++;
    }
    return ans;
}

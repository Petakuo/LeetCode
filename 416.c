bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    if((sum&1) == 1) return 0;
    sum /= 2;
    bool* dp = (bool*)malloc((sum+1)*sizeof(bool));
    for(int i = 0; i < sum+1; i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i = 0; i < numsSize; i++){
        for(int j = sum; j >= 0; j--){
            if(j >= nums[i]) dp[j] = dp[j] || dp[j-nums[i]];
        }
    }
    return dp[sum];
}

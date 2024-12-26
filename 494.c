int findTargetSumWays(int* nums, int numsSize, int target) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    if(sum < abs(target)) return 0;
    int dp[sum*2+1];
    memset(dp, 0, sizeof(dp));
    int min = sum, Max = sum, offset = sum;
    dp[sum+offset] = 1;
    for(int i = 0; i < numsSize; i++){
        for(int j = min; j <= Max; j++){
            int sumWay = dp[j+offset];
            if(sumWay > 0){
                int newSum = j-nums[i]*2;
                dp[newSum+offset] += sumWay;
                min = min < newSum ? min : newSum;
                Max = Max > newSum ? Max : newSum;
            }
        }
    }
    return dp[target+offset];
}

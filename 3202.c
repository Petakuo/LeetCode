int maximumLength(int* nums, int numsSize, int k) {
    int dp[k][k];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        int cur = nums[i]%k;
        for(int j = 0; j < k; j++){
            dp[cur][j] = dp[j][cur]+1;
            ans = ans > dp[cur][j] ? ans : dp[cur][j];
        }
    }
    return ans;
}

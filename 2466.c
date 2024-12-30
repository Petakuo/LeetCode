int countGoodStrings(int low, int high, int zero, int one) {
    int* dp = (int*)calloc(high+1, sizeof(int));
    dp[0] = 1;
    int mod = 1000000007;
    for(int i = 1; i < high+1; i++){
        if(i >= zero) dp[i] = (dp[i]+dp[i-zero])%mod;
        if(i >= one) dp[i] = (dp[i]+dp[i-one])%mod;
    }
    int ans = 0;
    for(int i = low; i <= high; i++){
        ans = (ans+dp[i])%mod;
    }
    free(dp);
    return ans;
}

#define mod 1000000007

int numTilings(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    int* dp = (int*)malloc((n+1)*sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for(int i = 4; i < n+1; i++){
        dp[i] = (2*dp[i-1]%mod+dp[i-3]%mod)%mod;
    }
    int ans = dp[n];
    free(dp);
    return ans;
}

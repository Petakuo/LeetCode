#define MOD 1000000007

int numberOfWays(int n, int x) {
    long long dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i < n+1; i++){
        long long val = (long long)pow(i, x);
        for(int j = 0; j < n+1; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= val) dp[i][j] = (dp[i][j]+dp[i-1][j-val])%MOD;
        }
    }
    return dp[n][n];
}

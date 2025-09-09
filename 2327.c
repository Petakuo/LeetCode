#define MOD 1000000007

int peopleAwareOfSecret(int n, int delay, int forget) {
    long long dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    long long share = 0;
    for(int i = 2; i < n+1; i++){
        if(i-delay >= 1) share = (share+dp[i-delay])%MOD;
        if(i-forget >= 1) share = (share-dp[i-forget]+MOD)%MOD;
        dp[i] = share;
    }
    long long ans = 0;
    for(int i = n-forget+1; i < n+1; i++){
        ans = (ans+dp[i])%MOD;
    }
    return (int)ans;
}

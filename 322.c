int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount+1];
    dp[0] = 0;
    for(int i = 1; i < amount+1; i++){
        dp[i] = INT_MAX;
    }
    for(int i = 1; i < amount+1; i++){
        for(int j = 0; j < coinsSize; j++){
            if(i >= coins[j]) dp[i] = dp[i] < dp[i-coins[j]]+1 ? dp[i] : dp[i-coins[j]]+1;
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

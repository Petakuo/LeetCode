int minScoreTriangulation(int* values, int valuesSize) {
    int dp[valuesSize][valuesSize];
    memset(dp, 0, sizeof(dp));
    for(int d = 2; d < valuesSize; d++){
        for(int i = 0; i+d < valuesSize; i++){
            int j = i+d;
            dp[i][j] = INT_MAX;
            for(int k = i+1; k < j; k++){
                int val = dp[i][k]+dp[k][j]+values[i]*values[k]*values[j];
                dp[i][j] = dp[i][j] < val ? dp[i][j] : val;
            }
        }
    }
    return dp[0][valuesSize-1];
}

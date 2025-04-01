long long mostPoints(int** questions, int questionsSize, int* questionsColSize) {
    long long dp[questionsSize+1];
    dp[questionsSize] = 0;
    for(int i = questionsSize-1; i >= 0; i--){
        long long solve = questions[i][0];
        int next = questions[i][1]+1;
        if(i+next < questionsSize) solve += dp[i+next];
        dp[i] = solve > dp[i+1] ? solve : dp[i+1];
    }
    return dp[0];
}

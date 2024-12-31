int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
    int lastDay = days[daysSize-1];
    int* dp = (int*)calloc(lastDay+1, sizeof(int));
    int index = 0;
    for(int i = 1; i < lastDay+1; i++){
        if(i == days[index]){
            dp[i] = dp[i-1]+costs[0];
            if(i < 7) dp[i] = dp[i] < dp[0]+costs[1] ? dp[i] : dp[0]+costs[1];
            else dp[i] = dp[i] < dp[i-7]+costs[1] ? dp[i] : dp[i-7]+costs[1];
            if(i < 30) dp[i] = dp[i] < dp[0]+costs[2] ? dp[i] : dp[0]+costs[2];
            else dp[i] = dp[i] < dp[i-30]+costs[2] ? dp[i] : dp[i-30]+costs[2];
            index++;
        }
        else dp[i] = dp[i-1];
    }
    int ans = dp[lastDay];
    free(dp);
    return ans;
}

int lengthOfLIS(int* nums, int numsSize) {
    int* dp = (int*)malloc(numsSize*sizeof(int));
    for(int i = 0; i < numsSize; i++){
        dp[i] = 1;
    }
    int ans = 1;
    for(int i = 1; i < numsSize; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = dp[i] > dp[j]+1 ? dp[i] : dp[j]+1;
            }
        }
        ans = ans > dp[i] ? ans : dp[i];
    }
    free(dp);
    return ans;
}

long long countSubarrays(int* nums, int numsSize, long long k) {
    long long ans = 0, score = 0;
    int left = 0, right = 0;
    while(right < numsSize){
        score += nums[right];
        while(score*(right-left+1) >= k){
            score -= nums[left];
            left++;
        }
        ans += right-left+1;
        right++;
    }
    return ans;
}

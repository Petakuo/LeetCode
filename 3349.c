bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    int ans = 1;
    for(int i = 0; i < numsSize-2*k+1; i++){
        int a = i, b = i+k;
        ans = 1;
        for(int l = 1; l < k; l++){
            if(nums[a] >= nums[a+1] || nums[b] >= nums[b+1]){
                ans = 0;
                break;
            }
            a++;
            b++;
        }
        if(ans == 1) return ans;
    }
    return ans;
}

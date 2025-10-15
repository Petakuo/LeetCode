Sol1: 
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

Sol2: 
bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    int inc[numsSize];
    inc[numsSize-1] = 1;
    for(int i = numsSize-2; i >= 0; i--){
        inc[i] = nums[i] < nums[i+1] ? inc[i+1]+1 : 1;
    }
    for(int i = 0; i < numsSize-2*k+1; i++){
        if(inc[i] >= k && inc[i+k] >= k) return 1;
    }
    return 0;
}

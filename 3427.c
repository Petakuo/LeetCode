int subarraySum(int* nums, int numsSize) {
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        int start = fmax(0, i-nums[i]);
        for(int j = start; j <= i; j++){
            ans += nums[j];
        }
    }
    return ans;
}

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

int maxIncreasingSubarrays(int* nums, int numsSize) {
    int left = 1, right = numsSize/2;
    int ans = 0;
    while(left <= right){
        int mid = left+(right-left)/2;
        if(hasIncreasingSubarrays(nums, numsSize, mid)){
            ans = mid;
            left = mid+1;
        }
        else right = mid-1;
    }
    return ans;
}

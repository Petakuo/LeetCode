long long maximumTripletValue(int* nums, int numsSize) {
    long long ans = 0, maxi = 0, maxIJDiff = 0;
    for(int k = 2; k < numsSize; k++){
        if(nums[k-2] > maxi) maxi = nums[k-2];
        if(maxi-nums[k-1] > maxIJDiff) maxIJDiff = maxi-nums[k-1];
        if(nums[k]*maxIJDiff > ans) ans = nums[k]*maxIJDiff;
    }
    return ans;
}

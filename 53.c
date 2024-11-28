int maxSubArray(int* nums, int numsSize) {
    int sum = nums[0];
    int max = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(sum < 0){
            sum = nums[i];
        }
        else {
            sum = nums[i] > sum+nums[i] ? nums[i] : sum+nums[i];
        }
        max = max > sum ? max : sum;
    }
    return max;
}

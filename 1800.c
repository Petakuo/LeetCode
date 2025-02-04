int maxAscendingSum(int* nums, int numsSize) {
    int ans = 0;
    for(int i = 0; i < numsSize;){
        int curSum = nums[i];
        while((i+1 < numsSize) && (nums[i+1] > nums[i])){
            curSum += nums[i+1];
            i++;
        }
        ans = ans > curSum ? ans : curSum;
        i++;
    }
    return ans;
}

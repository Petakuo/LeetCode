int maxProduct(int* nums, int numsSize) {
    int ans = nums[0];
    int Max = ans, min = ans;
    for(int i = 1; i < numsSize; i++){
        Max *= nums[i];
        min *= nums[i];
        if(nums[i] < 0){
            int temp = Max;
            Max = min;
            min = temp;
        }
        Max = Max > nums[i] ? Max : nums[i];
        min = min < nums[i] ? min : nums[i];
        ans = ans > Max ? ans : Max;
    }
    return ans;
}

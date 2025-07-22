int maximumUniqueSubarray(int* nums, int numsSize) {
    int left = 0, right = 0;
    int table[10001] = {0};
    int ans = 0, curSum = 0;
    while(right < numsSize){
        if(table[nums[right]] == 0){
            table[nums[right]]++;
            curSum += nums[right];
            right++;
            ans = ans > curSum ? ans : curSum;
        }
        else{
            table[nums[left]]--;
            curSum -= nums[left];
            left++;
        }
    }
    return ans;
}

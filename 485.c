int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int ans = 0, max = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 1) max++;
        else {
            ans = ans > max ? ans : max;
            max = 0;
        }
        ans = ans > max ? ans : max;
    }
    return ans;
}

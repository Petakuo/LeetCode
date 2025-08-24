int longestSubarray(int* nums, int numsSize) {
    int left = 0, right = 0, zero = 0, ans = 0;
    while(right < numsSize){
        if(nums[right] == 0) zero++;
        while(zero == 2){
            if(nums[left] == 0) zero--;
            left++;
        }
        ans = ans > right-left ? ans : right-left;
        right++;
    }
    return ans;
}

int countHillValley(int* nums, int numsSize) {
    int ans = 0;
    int idx = 1;
    while(idx < numsSize-1) {
        int left = idx-1, right = idx+1;
        while(right < numsSize-1 && nums[right] == nums[idx]){
            right++;
        }
        if((idx >= numsSize-1) || (idx < 0)) break;
        if((nums[idx] > nums[left] && nums[idx] > nums[right]) || (nums[idx] < nums[left] && nums[idx] < nums[right])) ans++;
        idx = right;
    }
    return ans;
}

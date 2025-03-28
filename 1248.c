int numberOfSubarrays(int* nums, int numsSize, int k) {
    int ans = 0, left = 0, right = 0, count = 0;
    while(right < numsSize){
        int temp = right+1, tempCount = 0;
        while(temp < numsSize && (nums[temp]&1) == 0){
            tempCount++;
            temp++;
        }
        if((nums[right]&1) == 1) count++;
        while(count == k){
            ans += (tempCount+1);
            if((nums[left]&1) == 1) count--;
            left++;
        }
        right++;
    }
    return ans;
}

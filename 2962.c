long long countSubarrays(int* nums, int numsSize, int k) {
    int max = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max) max = nums[i];
    }
    long long ans = 0;
    int left = 0, right = 0, count = 0;
    while(right < numsSize){
        if(nums[right] == max) count++;
        while(count >= k){
            if(nums[left] == max) count--;
            left++;
        }
        ans += left;
        right++;
    }
    return ans;
}

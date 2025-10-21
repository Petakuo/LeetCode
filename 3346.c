int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    int max = 0, min = INT_MAX;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max) max = nums[i];
        if(nums[i] < min) min = nums[i];
    }
    int range = max-min+1;
    int freq[range], prefix[range];
    memset(freq, 0, sizeof(freq));
    for(int i = 0; i < numsSize; i++){
        freq[nums[i]-min]++;
    }
    prefix[0] = freq[0];
    for(int i = 1; i < range; i++){
        prefix[i] = prefix[i-1]+freq[i];
    }
    int ans = 0;
    for(int i = 0; i < range; i++){
        int left = 0, right = prefix[range-1];
        if(i-k-1 >= 0) left = prefix[i-k-1];
        if(i+k < range) right = prefix[i+k];
        int cur = right-left-freq[i] > numOperations ? freq[i]+numOperations : right-left;
        ans = ans > cur ? ans : cur;
    }
    return ans;
}

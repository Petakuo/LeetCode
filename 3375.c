int minOperations(int* nums, int numsSize, int k) {
    int count[101] = {0};
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < k) return -1;
        if(count[nums[i]] == 0 && nums[i] != k) ans++;
        count[nums[i]]++;
    }
    return ans;
}

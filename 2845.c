long long countInterestingSubarrays(int* nums, int numsSize, int modulo, int k) {
    for(int i = 0; i < numsSize; i++){
        nums[i] = nums[i]%modulo == k;
    }
    for(int i = 1; i < numsSize; i++){
        nums[i] += nums[i-1];
    }
    long long ans = 0;
    int* mod = calloc(modulo, sizeof(int));
    mod[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        int cur = nums[i]%modulo;
        int target = (cur-k+modulo)%modulo;
        ans += mod[target];
        mod[cur]++;
    }
    free(mod);
    return ans;
}

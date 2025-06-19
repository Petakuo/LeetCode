int cmp(void const* a, void const* b){
    return *(int*)a-*(int*)b;
}

int partitionArray(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0, curMin = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(nums[i]-curMin > k){
            ans++;
            curMin = nums[i];
        }
    }
    ans++;
    return ans;
}

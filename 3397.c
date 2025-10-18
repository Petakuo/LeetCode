int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int maxDistinctElements(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    nums[0] -= k;
    int ans = 1, prev = nums[0];
    for(int i = 1; i < numsSize; i++){
        int cur = fmin(fmax(prev+1, nums[i]-k), nums[i]+k);
        if(cur > prev){
            ans++;
            prev = cur;
        }
    }
    return ans;
}

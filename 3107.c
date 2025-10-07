int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

long long minOperationsToMakeMedianK(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int mid = numsSize/2;
    long long ans = 0;
    if(nums[mid] == k) return 0;
    else if(nums[mid] < k){
        for(int i = mid; i < numsSize; i++){
            if(k > nums[i]) ans += k-nums[i];
            else break;
        }
    }
    else{
        for(int i = mid; i >= 0; i--){
            if(nums[i] > k) ans += nums[i]-k;
            else break;
        }
    }
    return ans;
}

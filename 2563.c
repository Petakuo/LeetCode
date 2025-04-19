int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    qsort(nums, numsSize, sizeof(int), cmp);
    long long ans = 0;
    int left = numsSize-1, right = numsSize-1;
    for(int i = 0; i < numsSize; i++){
        while((left >= 0) && (nums[i]+nums[left] >= lower)){
            left--;
        }
        while((right >= 0) && (nums[i]+nums[right]) > upper){
            right--;
        }
        ans += right-left-(i > left && i <= right);
    }
    return ans/2;
}

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int minMoves2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int m = nums[numsSize/2];
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        ans += abs(nums[i]-m);
    }
    return ans;
}

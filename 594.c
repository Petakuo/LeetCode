int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int findLHS(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int start = 0;
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        int cur = 0;
        while(start < numsSize && nums[i]-nums[start] > 1){
            start++;
        }
        if(nums[i]-nums[start] == 1) cur = i-start+1;
        ans = ans > cur ? ans : cur;
    }
    return ans;
}

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int triangleNumber(int* nums, int numsSize) {
    int ans = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = numsSize-1; i >= 2; i--){
        int left = 0, right = i-1;
        while(left < right){
            if(nums[left]+nums[right] > nums[i]){
                ans += (right-left);
                right--;
            }
            else left++;
        }
    }
    return ans;
}

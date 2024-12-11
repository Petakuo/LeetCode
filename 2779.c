int compare(const void *a, const void *b){
    return *(int*) a-*(int*)b;
}

int maximumBeauty(int* nums, int numsSize, int k) {
    qsort(nums, numsSize,sizeof(int), compare);
    int left = 0, right = 0, max = 0, K = k*2;
    while(right < numsSize){
        while(right < numsSize && nums[right]-nums[left] <= K) {
            right++;
        }
        max = right-left > max ? right-left : max;
        left++;
        right++;
    }
    return max;
}

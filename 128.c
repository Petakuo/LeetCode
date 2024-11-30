int compare(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int longestConsecutive(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int count = 1, max = 0;
    if(numsSize == 1) return 1;
    for(int i = 0; i < numsSize-1; i++){
        if(nums[i+1] == nums[i]+1) count++;
        else if(nums[i+1] == nums[i]) count = count;
        else count = 1;
        max = max > count ? max : count;
    } // 0 1 1 2
    return max;
}

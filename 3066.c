int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int minOperations(int* nums, int numsSize, int k) {
    int temp[numsSize];
    long long x = 0, y = 0;
    int i = 0, j = 0, tempSize = 0, count = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    while(1){
        if((i < numsSize) && ((j >= tempSize) || nums[i] <= temp[j])) x = nums[i++];
        else x = temp[j++];
        if(x >= k) return count;
        if((i < numsSize) && ((j >= tempSize) || nums[i] <= temp[j])) y = nums[i++];
        else y = temp[j++];
        long long add = 2*x+y;
        temp[tempSize++] = add < k ? (int)add : k;
        count++;
    }
}

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int minimizeMax(int* nums, int numsSize, int p) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int left = 0, right = nums[numsSize-1]-nums[0];
    while(left < right){
        int guess = left+(right-left)/2;
        int count = 0, idx = 0;
        while(idx < numsSize-1){
            if(abs(nums[idx+1]-nums[idx]) <= guess){
                idx += 2;
                count++;
            }
            else idx++;
        }
        if(count >= p) right = guess;
        if(count < p) left = guess+1;
    }
    return left;
}

void subset(int* nums, int numsSize, int i, int curOr, int or, int* count){
    if(curOr == or){
        *count += 1 << (numsSize-i);
        return;
    }
    while(i < numsSize){
        subset(nums, numsSize, i+1, curOr|nums[i], or, count);
        i++;
    }
}

int countMaxOrSubsets(int* nums, int numsSize) {
    int or = nums[0], count = 0;
    for(int i = 1; i < numsSize; i++){
        or |= nums[i];
    }
    subset(nums, numsSize, 0, 0, or, &count);
    return count;
}

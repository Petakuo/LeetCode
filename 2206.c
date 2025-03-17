bool divideArray(int* nums, int numsSize) {
    int table[501] = {0};
    for(int i = 0; i < numsSize; i++){
        table[nums[i]]++;
    }
    for(int i = 0; i < 501; i++){
        if((table[i]&1) == 1) return 0;
    }
    return 1;
}

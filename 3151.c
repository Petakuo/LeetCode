bool isArraySpecial(int* nums, int numsSize) {
    for(int i = 0; i < numsSize-1; i++){
        if((nums[i]&1) == (nums[i+1]&1)) return 0;
    }
    return 1;
}

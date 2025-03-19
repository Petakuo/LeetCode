int minOperations(int* nums, int numsSize) {
    int count = 0;
    for(int i = 0; i < numsSize-2; i++){
        if(nums[i] == 0){
            nums[i] ^= 1;
            nums[i+1] ^= 1;
            nums[i+2] ^= 1;
            count++;
        }
    }
    if(nums[numsSize-1] == 1 && nums[numsSize-2] == 1) return count;
    return -1;
}

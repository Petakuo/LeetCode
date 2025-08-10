int sortPermutation(int* nums, int numsSize) {
    int first = 0, idx = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != i){
            first = nums[i];
            idx = i;
            break;
        }
    }
    if(first == 0 && idx == 0) return 0;
    int ans = first;
    for(int i = idx+1; i < numsSize; i++){
        if(nums[i] != i) ans &= nums[i];
    }
    return ans;
}

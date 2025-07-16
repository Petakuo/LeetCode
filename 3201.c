int findOdd(int* nums, int numsSize, int* idx){
    while((*idx) < numsSize){
        if((nums[(*idx)]&1) == 1){
            (*idx)++;
            return 1;
        }
        else (*idx)++;
    }
    return 0;
}

int findEven(int* nums, int numsSize, int* idx){
    while((*idx) < numsSize){
        if((nums[(*idx)]&1) == 0){
            (*idx)++;
            return 1;
        }
        else (*idx)++;
    }
    return 0;
}

int maximumLength(int* nums, int numsSize) {
    int odd = 0, even = 0, oddeven = 0, evenodd = 0;
    for(int i = 0; i < numsSize; i++){
        if((nums[i]&1) == 1) odd++;
        else even++;
    }
    int oddIdx = 0, evenIdx = 0, idx = 0;
    while(idx < numsSize){
        if((oddIdx&1) == 0) oddeven += findOdd(nums, numsSize, &idx);
        else oddeven += findEven(nums, numsSize, &idx);
        oddIdx++;
    }
    idx = 0;
    while(idx < numsSize){
        if((evenIdx&1) == 0) evenodd += findEven(nums, numsSize, &idx);
        else evenodd += findOdd(nums, numsSize, &idx);
        evenIdx++;
    }
    int max = odd > even ? odd : even;
    max = max > oddeven ? max : oddeven;
    return max > evenodd ? max : evenodd;
}

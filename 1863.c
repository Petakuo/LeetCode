Sol1: 
int subsetXORSum(int* nums, int numsSize) {
    int ans = 0, total = 1 << numsSize;
    for(int i = 1; i < total; i++){
        int temp = i, sum = 0;
        for(int j = numsSize-1; j >= 0; j--){
            if((temp&1) == 1) sum ^= nums[j];
            temp >>= 1;
        }
        ans += sum;
    }
    return ans;
}

Sol2: 
int subsetXORSum(int* nums, int numsSize) {
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        ans |= nums[i];
    }
    return ans << numsSize-1;
}

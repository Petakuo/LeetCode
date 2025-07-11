Sol1: 
int maximumXOR(int* nums, int numsSize) {
    int bitTable[27] = {0};
    for(int i = 0; i < numsSize; i++){
        int temp = nums[i], idx = 0;
        while(temp){
            if((temp&1) == 1) bitTable[idx] = 1;
            idx++;
            temp >>= 1;
        }
    }
    int ans = 0;
    for(int i = 26; i >= 0; i--){
        ans = ans*2+bitTable[i];
    }
    return ans;
}

Sol2: 
int maximumXOR(int* nums, int numsSize) {
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        ans |= nums[i];
    }
    return ans;
}

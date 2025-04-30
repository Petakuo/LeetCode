int findNumbers(int* nums, int numsSize) {
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        int temp = nums[i], digits = 0;
        while(temp){
            temp /= 10;
            digits++;
        }
        ans += (digits&1) == 0;
    }
    return ans;
}

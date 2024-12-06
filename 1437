bool kLengthApart(int* nums, int numsSize, int k) {
    int i = 0;
    int temp = k;
    while(i < numsSize){
        if(nums[i] == 1){
            if(temp < k){
                return 0;
            }
            temp = 0;
        }
        else temp++;
        i++;
    }
    return 1;
}

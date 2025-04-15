int movesToMakeZigzag(int* nums, int numsSize) {
    int even = 0, odd = 0, temp = nums[0];
    for(int i = 0; i < numsSize-1; i++){
        if((i&1) == 0){
            if(temp <= nums[i+1]){
                even += (nums[i+1]-temp+1);
                temp--;
            }
            else temp = nums[i+1];
        }
        else{
            if(temp >= nums[i+1]) even += (temp-nums[i+1]+1);
            temp = nums[i+1];
        }
    }
    temp = nums[0];
    for(int i = 0; i < numsSize-1; i++){
        if((i&1) == 0){
            if(temp >= nums[i+1]) odd += (temp-nums[i+1]+1);
            temp = nums[i+1];
        }
        else{
            if(temp <= nums[i+1]){
                odd += (nums[i+1]-temp+1);
                temp--;
            }
            else temp = nums[i+1];
        }
    }
    return even < odd ? even : odd;
}

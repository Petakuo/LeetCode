int waysToMakeFair(int* nums, int numsSize) {
    int ans = 0;
    int righteven = 0, rightodd = 0;
    for(int i = 0; i < numsSize; i++){
        if((i&1) == 0) righteven += nums[i];
        else rightodd += nums[i];
    }
    int lefteven = 0, leftodd = 0;
    for(int i = 0; i < numsSize; i++){
        if((i&1) == 0) righteven -= nums[i];
        else rightodd -= nums[i];
        if(lefteven+rightodd == leftodd+righteven) ans++;
        if((i&1) == 0) lefteven += nums[i];
        else leftodd += nums[i];
    }
    return ans;
}

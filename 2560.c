int minCapability(int* nums, int numsSize, int k) {
    int left = nums[0], right = nums[0];
    for(int i = 0; i < numsSize; i++){
        if(left > nums[i]) left = nums[i];
        if(right < nums[i]) right = nums[i];
    }
    while(left < right){
        int mid = left+(right-left)/2;
        int house = 0;
        for(int i = 0; i < numsSize; i++){
            if(nums[i] <= mid){
                house++;
                i++;
            }
        }
        if(house >= k) right = mid;
        if(house < k) left = mid+1;
    }
    return right;
}

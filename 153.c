int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize-1;
    if(nums[left] < nums[right]) return nums[left];
    else{
        while(left < right){
            int mid = left+(right-left)/2;
            if(nums[mid] < nums[left]) right = mid;
            else if(nums[mid] > nums[left]) left = mid;
            else left++;
        }
        return nums[left];
    }
    return 0;
}

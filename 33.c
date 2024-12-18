int search(int* nums, int numsSize, int target) {
    int taregion = target >= nums[0] ? 1 : 2;
    int left = 0, right = numsSize-1;
    while(left <= right){
        int mid = left+(right-left)/2;
        int midregion = nums[mid] >= nums[0] ? 1 : 2;
        if(taregion == 1 && midregion == 2) right = mid-1;
        else if(taregion == 2 && midregion == 1) left = mid+1;
        else if(target > nums[mid]) left = mid+1;
        else if(target < nums[mid]) right = mid-1;
        else return mid;
    }
    return -1;
}

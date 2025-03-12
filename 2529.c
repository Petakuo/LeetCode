int biSearch(int* nums, int numsSize, int val){
    int left = 0, right = numsSize;
    while(left < right){
        int mid = left+(right-left)/2;
        if(nums[mid] >= val) right = mid;
        else left = mid+1;
    }
    return left;
}

int maximumCount(int* nums, int numsSize) {
    int neg = biSearch(nums, numsSize, 0);
    int pos = numsSize-biSearch(nums, numsSize, 1);
    return neg > pos ? neg : pos;
}

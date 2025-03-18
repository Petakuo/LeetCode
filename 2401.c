int longestNiceSubarray(int* nums, int numsSize) {
    int left = 0, right = 0, max = 0, bitmask = 0;
    while(right < numsSize){
        while((bitmask&nums[right]) != 0){
            bitmask ^= nums[left];
            left++;
        }
        bitmask |= nums[right];
        max = max > (right-left+1) ? max : (right-left+1);
        right++;
    }
    return max;
}

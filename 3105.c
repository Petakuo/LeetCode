int longestMonotonicSubarray(int* nums, int numsSize) {
    int inc = 1, dec = 1, maxinc = 1, maxdec = 1;
    for(int i = 0; i < numsSize-1; i++){
        if(nums[i] < nums[i+1]){
            inc++;
            dec = 1;
            maxinc = maxinc > inc ? maxinc : inc;
        }
        else if(nums[i] > nums[i+1]){
            inc = 1;
            dec++;
            maxdec = maxdec > dec ? maxdec : dec;
        }
        else{
            inc = 1;
            dec = 1;
        }
    }
    return maxinc > maxdec ? maxinc : maxdec;
}

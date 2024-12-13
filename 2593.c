long long findScore(int* nums, int numsSize) {
    long long sum = 0;
    for(int i = 0; i < numsSize; i += 2){
        int start = i;
        while(i+1 < numsSize && nums[i+1] < nums[i]){
            i++;
        }
        for(int j = i; j >= start; j -= 2){
            sum += nums[j];
        }
    }
    return sum;
}

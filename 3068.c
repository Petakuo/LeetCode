long long maximumValueSum(int* nums, int numsSize, int k, int** edges, int edgesSize, int* edgesColSize) {
    long long sum = 0;
    int count = 0;
    long long minusDiff = LLONG_MAX;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        int diff = (nums[i]^k)-nums[i];
        if(diff > 0){
            sum += diff;
            count++;
        }
        minusDiff = minusDiff < abs(diff) ? minusDiff : abs(diff);
    }
    if((count&1) == 1) sum -= minusDiff;
    return sum;
}

#define MOD 1000000007

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int numSubseq(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0;
    int left = 0, right = numsSize-1;
    int power[numsSize];
    power[0] = 1;
    for(int i = 1; i < numsSize; i++){
        power[i] = (power[i-1]*2)%MOD;
    }
    while(left <= right){
        while(right >= 0 && nums[left]+nums[right] > target){
            right--;
        }
        if(left <= right){
            ans += power[right-left];
            ans %= MOD;
            left++;
        }
    }
    return ans;
}

int maxSum(int* nums, int numsSize) {
    int ans = 0, neg = 1;
    int freq[101] = {0};
    for(int i = 0; i < numsSize; i++){
        if(nums[i] >= 0){
            freq[nums[i]]++;
            neg = 0;
        }
    }
    if(neg == 0){
        for(int i = 1; i <= 100; i++){
            if(freq[i] > 0) ans += i;
        }
    }
    else{
        ans = nums[0];
        for(int i = 1; i < numsSize; i++){
            if(nums[i] > ans) ans = nums[i];
        }
    }
    return ans;
}

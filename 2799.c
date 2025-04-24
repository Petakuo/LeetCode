int countCompleteSubarrays(int* nums, int numsSize) {
    int table[2001] = {0};
    int distinct = 0;
    for(int i = 0; i < numsSize; i++){
        if(table[nums[i]] == 0) distinct++;
        table[nums[i]]++;
    }
    memset(table, 0, sizeof(table));
    int left = 0, right = 0, count = 0, ans = 0;
    while(left < numsSize){
        while(count < distinct && right < numsSize){
            if(table[nums[right]] == 0) count++;
            table[nums[right]]++;
            right++;
        }
        if(count == distinct) ans += numsSize-right+1;
        else break;
        table[nums[left]]--;
        if(table[nums[left]] == 0) count--;
        left++;
    }
    return ans;
}

int maxFrequencyElements(int* nums, int numsSize) {
    int ans = 0, max = 0;
    int freq[101] = {0};
    for(int i = 0; i < numsSize; i++){
        freq[nums[i]]++;
        if(freq[nums[i]] > max) max = freq[nums[i]];
    }
    for(int i = 0; i < 101; i++){
        if(freq[i] == max) ans += freq[i];
    }
    return ans;
}

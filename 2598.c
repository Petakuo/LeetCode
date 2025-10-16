int findSmallestInteger(int* nums, int numsSize, int value) {
    int freq[value];
    memset(freq, 0, sizeof(freq));
    for(int i = 0; i < numsSize; i++){
        freq[(nums[i]%value+value)%value]++;
    }
    if(freq[0] == 0) return 0;
    int minIdx = 0, minRound = INT_MAX;
    for(int i = 0; i < value; i++){
        if(freq[i] < minRound){
            minRound = freq[i];
            minIdx = i;
        }
    }
    return minRound*value+minIdx;
}

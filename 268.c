Sol1:
int missingNumber(int* nums, int numsSize) {
    int* table = (int*)calloc((numsSize+1), sizeof(int));
    for(int i = 0; i < numsSize; i++){
        table[nums[i]]++;
    }
    for(int i = 0; i < (numsSize+1); i++){
        if(table[i] == 0) return i;
    }
    return 0;
}

Sol2:
int missingNumber(int* nums, int numsSize) {
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        ans ^= i^nums[i];
    }
    return ans^numsSize;
}

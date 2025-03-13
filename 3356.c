bool canCover(int* nums, int numsSize, int** queries, int k){
    int* prefix = (int*)calloc(numsSize, sizeof(int));
    for(int i = 0; i <= k; i++){
        prefix[queries[i][0]] += queries[i][2];
        if(queries[i][1]+1 < numsSize) prefix[queries[i][1]+1] -= queries[i][2];
    }
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += prefix[i];
        if(sum < nums[i]){
            free(prefix);
            return 0;
        }
    }
    free(prefix);
    return 1;
}

int minZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int zero = 0;
    for(int i = 0; i < numsSize; i++){
        zero |= nums[i];
    }
    if(zero == 0) return 0;
    int left = 0, right = queriesSize-1;
    int ans = -1;
    while(left <= right){
        int mid = left+(right-left)/2;
        if(canCover(nums, numsSize, queries, mid)){
            ans = mid+1;
            right = mid-1;
        }
        else left = mid+1;
    }
    return ans;
}

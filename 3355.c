bool isZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int* pre = (int*)calloc(numsSize+1, sizeof(int));
    for(int i = 0; i < queriesSize; i++){
        pre[queries[i][0]]++;
        pre[queries[i][1]+1]--;
    }
    for(int i = 1; i < numsSize+1; i++){
        pre[i] += pre[i-1];
    }
    for(int i = 0; i < numsSize; i++){
        if(pre[i] < nums[i]) return 0;
    }
    free(pre);
    return 1;
}

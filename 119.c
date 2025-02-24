Sol1: 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int* ans = (int*)malloc((rowIndex+1)*sizeof(int));
    *returnSize = rowIndex+1;
    long long Pascal[rowIndex+1][rowIndex+1];
    for(int i = 0; i < rowIndex+1; i++){
        Pascal[0][i] = 1;
        Pascal[i][0] = 1;
    }
    for(int i = 1; i < rowIndex+1; i++){
        for(int j = 1; j < rowIndex+1; j++){
            Pascal[i][j] = Pascal[i-1][j]+Pascal[i][j-1];
        }
    }
    int j = rowIndex;
    for(int i = 0; i < rowIndex+1; i++){
        ans[i] = Pascal[i][j--];
    }
    return ans;
}

Sol2: 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int* ans = (int*)malloc((rowIndex+1)*sizeof(int));
    *returnSize = rowIndex+1;
    ans[0] = 1;
    for(int i = 1; i < rowIndex+1; i++){
        ans[i] = (long)ans[i-1]*(rowIndex-i+1)/i;
    }
    return ans;
}

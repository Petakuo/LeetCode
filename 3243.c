/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int table[n][n];
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            table[i][j] = j-i;
        }
    }
    int* ans = (int*)malloc(queriesSize*sizeof(int));
    for(int i = 0; i < queriesSize; i++){
        int left = queries[i][0];
        int right = queries[i][1];
        for(int j = 0; j <= left; j++){
            for(int k = right; k < n; k++){
                int old = table[j][k];
                int new = table[j][left]+table[right][k]+1;
                table[j][k] = old > new ? new : old;
            }
        }
        ans[i] = table[0][n-1];
    }
    return ans;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return *(*(int**)a)-*(*(int**)b);
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int** ans = (int**)malloc(intervalsSize*sizeof(int*));
    for(int i = 0; i < intervalsSize; i++){
        ans[i] = (int*)malloc(2*sizeof(int));
    }
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(intervalsSize*sizeof(int));
    for(int i = 0; i < intervalsSize; i++){
        (*returnColumnSizes)[i] = 2;
    }
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int left = intervals[0][0], right = intervals[0][1];
    for(int i = 1; i < intervalsSize; i++){
        if(intervals[i][0] <= right && intervals[i][1] > right) right = intervals[i][1];
        if(intervals[i][0] > right){
            ans[(*returnSize)][0] = left;
            ans[(*returnSize)][1] = right;
            left = intervals[i][0];
            right = intervals[i][1];
            (*returnSize)++;
        }
    }
    ans[(*returnSize)][0] = left;
    ans[(*returnSize)][1] = right;
    (*returnSize)++;
    return ans;
}

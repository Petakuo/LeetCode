/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrack(int* candidates, int candidatesSize, int target, int index, int* temp, int tempSize, int** ans, int* returnSize, int* returnColSize){
    if(target == 0){
        ans[(*returnSize)] = malloc(tempSize*sizeof(int));
        for(int i = 0; i < tempSize; i++){
            ans[(*returnSize)][i] = temp[i];
        }
        returnColSize[(*returnSize)] = tempSize;
        (*returnSize)++;
        return;
    }
    for(int i = index; i < candidatesSize; i++){
        if(target < candidates[i]) continue;
        temp[tempSize] = candidates[i];
        backtrack(candidates, candidatesSize, target-candidates[i], i, temp, tempSize+1, ans, returnSize, returnColSize);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** ans = (int**)malloc(150*sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(150*sizeof(int));
    int* temp = (int*)malloc(target*sizeof(int));
    backtrack(candidates, candidatesSize, target, 0, temp, 0, ans, returnSize, *returnColumnSizes);
    free(temp);
    return ans;
}

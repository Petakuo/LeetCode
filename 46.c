/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtracking(int* num, int numsSize, int** ans, int* returnSize, int n, int* cur, int* used){
    if(n == numsSize){
        for(int i = 0; i < numsSize; i++){
            ans[(*returnSize)][i] = cur[i];
        }
        (*returnSize)++;
        return;
    }
    for(int i = 0; i < numsSize; i++){
        if(used[i] == 1) continue;
        else{
            cur[n] = num[i];
            used[i] = 1;
            backtracking(num, numsSize, ans, returnSize, n+1, cur, used);
            used[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int size = 1;
    for(int i = 1; i <= numsSize; i++){
        size *= i;
    }
    int** ans = (int**)malloc(size*sizeof(int*));
    for(int i = 0; i < size; i++){
        ans[i] = (int*)malloc(numsSize*sizeof(int));
    }
    int* cur = (int*)malloc(numsSize*sizeof(int));
    int* used = (int*)calloc(numsSize, sizeof(int));
    *returnSize = 0;
    backtracking(nums, numsSize, ans, returnSize, 0, cur, used);
    *returnColumnSizes = (int*)malloc((*returnSize)*sizeof(int));
    for(int i = 0; i < (*returnSize); i++){
        (*returnColumnSizes)[i] = numsSize;
    }
    return ans;
}

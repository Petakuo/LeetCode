/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** ans = (int**)malloc(numsSize*sizeof(int*));
    for(int i = 0; i < numsSize; i++){
        ans[i] = (int*)calloc(numsSize, sizeof(int));
    }
    *returnColumnSizes = (int*)malloc(numsSize*sizeof(int));
    *returnSize = 0;
    for(int i = 0; i < numsSize; i++){
        (*returnColumnSizes)[i] = 0;
        int used[201] = {0};
        for(int j = 0; j < numsSize; j++){
            if(nums[j] != 0 && used[nums[j]] == 0){
                ans[i][(*returnColumnSizes)[i]++] = nums[j];
                used[nums[j]] = 1;
                nums[j] = 0;
            }
        }
        if(ans[i][0] != 0) (*returnSize)++;
    }
    return ans;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int** ans = (int**)malloc((numsSize/3)*sizeof(int*));
    *returnSize = 0;
    for(int i = 0; i < numsSize/3; i++){
        ans[i] = (int*)malloc(3*sizeof(int));
    }
    int idx = 0;
    while(idx < numsSize-2){
        if(nums[idx+2]-nums[idx] <= k){
            for(int i = 0; i < 3; i++){
                ans[(*returnSize)][i] = nums[idx];
                idx++;
            }
            (*returnSize)++;
        }
        else{
            *returnSize = 0;
            return NULL;
        }
    }
    *returnColumnSizes = (int*)malloc((*returnSize)*sizeof(int));
    for(int i = 0; i < (*returnSize); i++){
        (*returnColumnSizes)[i] = 3;
    }
    return ans;
}

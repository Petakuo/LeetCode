/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 1 << numsSize;
    *returnColumnSizes = (int*)malloc((1 << numsSize)*sizeof(int));
    int** ans = (int**)malloc((1 << numsSize)*sizeof(int*));
    for(int i = 0; i < (1 << numsSize); i++){
        int count = 0, temp = i;
        while(temp){
            count += temp&1;
            temp >>= 1;
        }
        (*returnColumnSizes)[i] = count;
        ans[i] = (int*)malloc(count*sizeof(int));
    }
    for(int i = 0; i < (1 << numsSize); i++){
        int temp = i, index = 0, j = 0;
        while(temp){
            if((temp&1) == 1){
                ans[i][j] = nums[index];
                j++;
            }
            temp >>= 1;
            index++;
        }
    }
    return ans;
}

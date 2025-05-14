/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int** ans = (int**)malloc(numsSize*numsSize*sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(numsSize*numsSize*sizeof(int));
    for(int i = 0; i < numsSize-2; i++){
        if(i == 0 || nums[i] != nums[i-1]){
            int l = i+1, r = numsSize-1;
            while(l < r){
                if(nums[i]+nums[l]+nums[r] < 0){
                    l++;
                }
                else if(nums[i]+nums[l]+nums[r] > 0){
                    r--;
                }
                else{
                    ans[(*returnSize)] = (int*)malloc(3*sizeof(int));
                    (*returnColumnSizes)[(*returnSize)] = 3;
                    ans[(*returnSize)][0] = nums[i];
                    ans[(*returnSize)][1] = nums[l];
                    ans[(*returnSize)++][2] = nums[r];
                    l++;
                    while(l < r && nums[l] == nums[l-1]){
                        l++;
                    }
                }
            }
        }
    }
    return ans;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestSubarrays(int* nums, int numsSize, int* returnSize) {
    int* bit = (int*)malloc(31*sizeof(int));
    memset(bit, -1, sizeof(bit));
    int* ans = (int*)malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    for(int i = numsSize-1; i >= 0; i--){
        int j = i;
        for(int cur = 0; cur < 31; cur++){
            if((nums[i]&(1 << cur)) == 0){
                if(bit[cur] != -1) j = j > bit[cur] ? j : bit[cur];
            }
            else bit[cur] = i;
        }
        ans[i] = j-i+1;
    }
    free(bit);
    return ans;
}

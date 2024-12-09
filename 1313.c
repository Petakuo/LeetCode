/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
    int size = 0;
    for(int i = 0; i < numsSize; i += 2){
        size += nums[i];
    }
    *returnSize = size;
    int* ans = (int*)malloc(size*sizeof(int));
    int index = 0;
    for(int i = 0; i < numsSize; i += 2){
        int k = nums[i];
        while(k > 0){
            ans[index] = nums[i+1];
            index++;
            k--;
        }
    }
    return ans;
}

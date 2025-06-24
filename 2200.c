/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    int* ans = (int*)malloc(numsSize*sizeof(int));
    int idx = 0, keyIdx = 0, ansIdx = 0;
    while(idx < numsSize && keyIdx < numsSize){
        while(keyIdx < numsSize && nums[keyIdx] != key){
            keyIdx++;
        }
        for(int i = idx; i < numsSize; i++){
            if(keyIdx < numsSize && abs(i-keyIdx) <= k){
                ans[ansIdx++] = i;
                idx = i;
            }
        }
        keyIdx++;
        idx++;
    }
    *returnSize = ansIdx;
    return ans;
}

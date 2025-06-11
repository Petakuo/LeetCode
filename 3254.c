Sol1: 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    int* ans = (int*)calloc(numsSize-k+1, sizeof(int));
    for(int i = 0; i < numsSize-k+1; i++){
        for(int j = i; j < i+k-1; j++){
            if(nums[j] >= nums[j+1]){
                ans[i] = -1;
            } 
        }
        ans[i] = ((nums[i+k-1] == nums[i]+k-1) && ans[i] == 0) ? nums[i+k-1] : -1;
    }
    *returnSize = numsSize-k+1;
    return ans;
}

Sol2: 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    int* ans = (int*)malloc((numsSize-k+1)*sizeof(int));
    int* diff = (int*)malloc((numsSize-1)*sizeof(int));
    for(int i = 0; i < numsSize-1; i++){
        diff[i] = (nums[i+1]-nums[i] == 1) ? 1 : 0;
    }
    int sum = 0;
    for(int i = 0; i < k-1; i++){
        sum += diff[i];
    }
    for(int i = 0; i < numsSize-k+1; i++){
        if(sum == k-1) ans[i] = nums[i+k-1];
        else ans[i] = -1;
        if(i+k-1 < numsSize-1) sum = sum-diff[i]+diff[i+k-1];
    }
    *returnSize = numsSize-k+1;
    return ans;
}

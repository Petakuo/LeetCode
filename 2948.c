/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp2D(const void *a, const void *b){
    int* arr1 = (int*)a;
    int* arr2 = (int*)b;
    return arr1[1]-arr2[1];
}

int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize) {
    int* ans = (int*)malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    int copy[numsSize][2];
    for(int i = 0; i < numsSize; i++){
        copy[i][0] = i;
        copy[i][1] = nums[i];
    }
    qsort(copy, numsSize, sizeof(copy[1]), cmp2D);
    int group[numsSize];
    for(int i = 0; i < numsSize;){
        int size = 0;
        int prev = copy[i][1];
        while(i < numsSize && (copy[i][1]-prev) <= limit){
            group[size] = copy[i][0];
            size++;
            prev = copy[i][1];
            i++;
        }
        qsort(group, size, sizeof(int), cmp);
        for(int j = 0, k = i-size; j < size; j++, k++){
            ans[group[j]] = copy[k][1];
        }
    }
    return ans;
}

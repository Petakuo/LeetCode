/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct topk{
    int num;
    int freq;
};

int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int cmptopk(const void *a, const void *b){
    return ((struct topk*)b)->freq-((struct topk*)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;
    struct topk* ans = (struct topk*)malloc(numsSize*sizeof(struct topk));
    if(numsSize == 1){
        return nums;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int ptr = 0, index = 0;
    while(ptr < numsSize){
        int count = 1;
        while((ptr < numsSize-1) && (nums[ptr] == nums[ptr+1])){
            ptr++;
            count++;
        }
        ans[index].num = nums[ptr];
        ans[index].freq = count;
        index++;
        ptr++;
    }
    qsort(ans, numsSize, sizeof(struct topk), cmptopk);
    int* topKFreq = (int*)malloc(k*sizeof(int));
    for(int i = 0; i < k; i++){
        topKFreq[i] = ans[i].num;
    }
    free(ans);
    return topKFreq;
}

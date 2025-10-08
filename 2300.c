/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    qsort(potions, potionsSize, sizeof(int), cmp);
    int* ans = (int*)malloc(spellsSize*sizeof(int));
    *returnSize = 0;
    for(int i = 0; i < spellsSize; i++){
        int left = 0, right = potionsSize-1;
        while(left <= right){
            int mid = left+(right-left)/2;
            long long temp = (long long)spells[i]*potions[mid];
            if(temp >= success) right = mid-1;
            else left = mid+1;
        }
        ans[(*returnSize)++] = potionsSize-left;
    }
    return ans;
}

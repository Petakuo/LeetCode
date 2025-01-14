/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    *returnSize = ASize;
    int* ans = (int*)calloc(ASize, sizeof(int));
    int* AIndex = (int*)calloc(ASize+1, sizeof(int));
    for(int i = 0; i < ASize; i++){
        AIndex[A[i]] = i;
    }
    for(int i = 0; i < BSize; i++){
        if(AIndex[B[i]] > i) ans[AIndex[B[i]]]++;
        else ans[i]++;
    }
    for(int i = 1; i < ASize; i++){
        ans[i] += ans[i-1];
    }
    free(AIndex);
    return ans;
}

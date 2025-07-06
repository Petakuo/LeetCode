


typedef struct {
    int* nums1;
    int nums1Size;
    int* nums2;
    int nums2Size;
    int* freq;
} FindSumPairs;


FindSumPairs* findSumPairsCreate(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    FindSumPairs* obj = (FindSumPairs*)malloc(sizeof(FindSumPairs));
    obj->nums1 = (int*)malloc(nums1Size*sizeof(int));
    memcpy(obj->nums1, nums1, nums1Size*sizeof(int));
    obj->nums1Size = nums1Size;
    obj->nums2 = (int*)malloc(nums2Size*sizeof(int));
    memcpy(obj->nums2, nums2, nums2Size*sizeof(int));
    obj->nums2Size = nums2Size;
    obj->freq = (int*)calloc(10000001, sizeof(int));
    for(int i = 0; i < nums2Size; i++){
        (obj->freq)[nums2[i]]++;
    }
    return obj;
}

void findSumPairsAdd(FindSumPairs* obj, int index, int val) {
    (obj->freq)[(obj->nums2)[index]]--;
    (obj->nums2)[index] += val;
    (obj->freq)[obj->nums2[index]]++;
}

int findSumPairsCount(FindSumPairs* obj, int tot) {
    int ans = 0;
    for(int i = 0; i < obj->nums1Size; i++){
        int need = tot-(obj->nums1)[i];
        if(need >= 0 && need < 10000001) ans += (obj->freq)[need];
    }
    return ans;
}

void findSumPairsFree(FindSumPairs* obj) {
    free(obj->nums1);
    free(obj->nums2);
    free(obj->freq);
    free(obj);
}

/**
 * Your FindSumPairs struct will be instantiated and called as such:
 * FindSumPairs* obj = findSumPairsCreate(nums1, nums1Size, nums2, nums2Size);
 * findSumPairsAdd(obj, index, val);
 
 * int param_2 = findSumPairsCount(obj, tot);
 
 * findSumPairsFree(obj);
*/

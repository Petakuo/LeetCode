/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    *returnSize = 0;
    char** ans = (char**)malloc(words1Size*sizeof(char*));
    int MaxCount[26] = {0};
    for(int i = 0; i < words2Size; i++){
        int count[26] = {0};
        for(int j = 0; j < strlen(words2[i]); j++){
            count[words2[i][j]-'a']++;
        }
        for(int j = 0; j < 26; j++){
            MaxCount[j] = MaxCount[j] > count[j] ? MaxCount[j] : count[j];
        }
    }
    for(int i = 0; i < words1Size; i++){
        int count[26] = {0};
        for(int j = 0; j < strlen(words1[i]); j++){
            count[words1[i][j]-'a']++;
        }
        bool IsSub = 1;
        for(int j = 0; j < 26; j++){
            IsSub &= (count[j] >= MaxCount[j]);
        }
        if(IsSub){
            ans[*returnSize] = words1[i];
            (*returnSize)++;
        }
    }
    return ans;
}

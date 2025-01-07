/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** stringMatching(char** words, int wordsSize, int* returnSize) {
    char** ans = (char**)malloc(wordsSize*sizeof(char*));
    bool* IsUsed = (bool*)calloc(wordsSize, sizeof(bool)); 
    *returnSize = 0;
    for(int i = 0; i < wordsSize; i++){
        int len1 = strlen(words[i]);
        for(int j = 0; j < wordsSize; j++){
            int len2 = strlen(words[j]);
            if((len2 < len1) && IsUsed[j] == 0){
                char* same = strstr(words[i], words[j]);
                if(same != NULL){
                    ans[*returnSize] = words[j];
                    (*returnSize)++;
                    IsUsed[j] = 1;
                }
            }
        }
    }
    free(IsUsed);
    return ans;
}

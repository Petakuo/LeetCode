/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char*** ans = (char***)malloc(strsSize*sizeof(char**));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(strsSize*sizeof(int));
    int* used = (int*)calloc(strsSize, sizeof(int));
    for(int i = 0; i < strsSize; i++){
        if(used[i] == 0){
            used[i] = 1;
            ans[(*returnSize)] = (char**)malloc(strsSize*sizeof(char*));
            int size = 0;
            ans[(*returnSize)][size++] = strs[i];
            int table[26] = {0};
            for(int j = 0; strs[i][j] != '\0'; j++){
                table[strs[i][j]-'a']++;
            }
            for(int j = i+1; j < strsSize; j++){
                if(strlen(strs[j]) != strlen(strs[i])) continue;
                int table2[26] = {0};
                for(int k = 0; strs[j][k] != '\0'; k++){
                    table2[strs[j][k]-'a']++;
                }
                bool isAn = 0;
                for(int k = 0; k < 26; k++){
                    if(table[k] != table2[k]){
                        isAn = 0;
                        break;
                    }
                    else isAn = 1;
                }
                if(isAn == 1){
                    used[j] = 1;
                    ans[(*returnSize)][size++] = strs[j];
                }
            }
            (*returnColumnSizes)[(*returnSize)++] = size;
        }
    }
    free(used);
    return ans;
}

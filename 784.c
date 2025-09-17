/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isAl(char s){
    if((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) return 1;
    return 0;
}

char** letterCasePermutation(char* s, int* returnSize) {
    int size = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(isAl(s[i])) size++;
    }
    char** ans = (char**)malloc((1 << size)*sizeof(char*));
    *returnSize = (1 << size);
    int len = strlen(s);
    for(int i = 0; i < (1 << size); i++){
        ans[i] = malloc((len+1)*sizeof(char));
        ans[i][len] = '\0';
        int bitIdx = 0;
        for(int j = 0; j < len; j++){
            if(isAl(s[j])){
                if(((i >> bitIdx)&1) == 1) ans[i][j] = toupper(s[j]);
                else ans[i][j] = tolower(s[j]);
                bitIdx++;
            }
            else ans[i][j] = s[j];
        }
    }
    return ans;
}

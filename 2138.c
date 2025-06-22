/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** divideString(char* s, int k, char fill, int* returnSize) {
    int len = strlen(s);
    (*returnSize) = (len+k-1)/k;
    char** ans = (char**)malloc((*returnSize)*sizeof(char*));
    int idx = 0;
    for(int i = 0; i < (*returnSize); i++){
        ans[i] = (char*)malloc((k+1)*sizeof(char));
        ans[i][k] = '\0';
        for(int j = 0; j < k; j++){
            if(idx < len){
                ans[i][j] = s[idx++];
            }
            else{
                ans[i][j] = fill;
            }
        }
    }
    return ans;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    int table[26] = {0};
    int len = strlen(s);
    for(int i = len-1; i >= 0; i--){
        if(table[s[i]-'a'] == 0) table[s[i]-'a'] = i;
    }
    int* ans = (int*)malloc(len*sizeof(int));
    *returnSize = 0;
    int left = 0, right = 0;
    for(int i = 0; i < len; i++){
        right = table[s[i]-'a'] > right ? table[s[i]-'a'] : right;
        if(i == right){
            ans[(*returnSize)] = right-left+1;
            (*returnSize)++;
            left = right+1;
        }
    }
    return ans;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool IsVowel(char* s){
    int last = strlen(s)-1;
    return ((s[0] == 'a') || (s[0] == 'e') || (s[0] == 'i') || (s[0] == 'o') || (s[0] == 'u')) && ((s[last] == 'a') || (s[last] == 'e') || (s[last] == 'i') || (s[last] == 'o') || (s[last] == 'u'));
}

int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* prefix = (int*)calloc(wordsSize+1, sizeof(int));
    for(int i = 1; i < wordsSize+1; i++){
        prefix[i] = prefix[i-1]+IsVowel(words[i-1]);
    }
    int* ans = (int*)calloc(queriesSize, sizeof(int));
    for(int i = 0; i < queriesSize; i++){
        ans[i] = prefix[queries[i][1]+1]-prefix[queries[i][0]];
    }
    free(prefix);
    return ans;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isAna(char* a, char* b, int len){
    int tableA[26] = {0};
    int tableB[26] = {0};
    for(int i = 0; i < len; i++){
        tableA[a[i]-'a']++;
        tableB[b[i]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(tableA[i] != tableB[i]) return 0;
    }
    return 1;
}

char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    char** ans = (char**)malloc(wordsSize*sizeof(char*));
    *returnSize = 0;
    for(int i = wordsSize-1; i > 0; i--){
        int lenA = strlen(words[i]);
        int lenB = strlen(words[i-1]);
        if(lenA != lenB) continue;
        else{
            if(isAna(words[i], words[i-1], lenA)) words[i] = "0";
        }
    }
    for(int i = 0; i < wordsSize; i++){
        if(words[i] != "0") ans[(*returnSize)++] = words[i];
    }
    return ans;
}

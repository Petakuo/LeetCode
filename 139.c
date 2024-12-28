int find(int* unionArr, int n){
    while(unionArr[n] != n){
        n = unionArr[n];
    }
    return n;
}

void Union(int* unionArr, int i, int j){
    unionArr[find(unionArr, j)] = find(unionArr, i);
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    int* arr = (int*)malloc((len+1)*sizeof(int));
    for(int i = 0; i < len+1; i++){
        arr[i] = i;
    }
    for(int i = 0; i < wordDictSize; i++){
        int subLen = strlen(wordDict[i]);
        for(int j = 0; j <= len-subLen; j++){
            if(strncmp(s+j, wordDict[i], subLen) == 0){
                Union(arr, j, j+subLen);
            }
        }
    }
    bool ans = (find(arr, len) == find(arr, 0));
    free(arr);
    return ans;
}

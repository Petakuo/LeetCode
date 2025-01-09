bool IsPre(char* a, char* b){
    int len1 = strlen(a);
    int len2 = strlen(b);
    if(len1 >= len2){
        for(int i = 0; i < len2; i++){
            if(a[i] != b[i]) return 0;
        }
        return 1;
    }
    return 0;
}

int prefixCount(char** words, int wordsSize, char* pref) {
    int ans = 0;
    for(int i = 0; i < wordsSize; i++){
        ans += IsPre(words[i], pref);
    }
    return ans;
}

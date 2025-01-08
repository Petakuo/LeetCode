bool isPrefixAndSuffix(char* a, char* b){
    int lena = strlen(a);
    int lenb = strlen(b);
    if(lena <= lenb){
        for(int i = 0; i < lena; i++){
            if(a[i] != b[i]) return 0;
            if(a[i] != b[lenb-lena+i]) return 0;
        }
        return 1;
    }
    return 0;
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
    int ans = 0;
    for(int i = 0;i < wordsSize; i++){
        for(int j = i+1; j < wordsSize; j++){
            ans += isPrefixAndSuffix(words[i], words[j]);
        }
    }
    return ans;
}

int PalinLen(char* s, int left, int right){
    int len = strlen(s);
    while(left >= 0 && right < len && s[left] == s[right]){
        left--;
        right++;
    }
    return right-left-1;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    int max = 0, maxindex = 0;
    for(int i = 0; i < len; i++){
        int curlen = 0;
        int oddlen = PalinLen(s, i, i);
        int evenlen = PalinLen(s, i, i+1);
        curlen = oddlen > evenlen ? oddlen : evenlen;
        if(curlen > max){
            max = curlen;
            maxindex = i;
        }
    }
    char* ans = (char*)malloc((max+1)*sizeof(char));
    ans[max] = '\0';
    for(int i = 0; i < max; i++){
        ans[i] = s[i+maxindex-(max-1)/2];
    }
    return ans;
}

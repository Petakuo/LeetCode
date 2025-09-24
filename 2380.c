int secondsToRemoveOccurrences(char* s) {
    int ans = 0, have = 1;
    int len = strlen(s);
    while(have){
        have = 0;
        for(int i = 0; i < len-1; i++){
            if(s[i] == '0' && s[i+1] == '1'){
                s[i] = '1';
                s[i+1] = '0';
                i++;
                have = 1;
            }
        }
        ans++;
    }
    return ans-1;
}

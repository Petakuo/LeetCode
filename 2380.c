Sol1: 
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

Sol2: 
int secondsToRemoveOccurrences(char* s) {
    int ans = 0, zero = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '0') zero++;
        else{
            if(zero > 0) ans = ans+1 > zero ? ans+1 : zero;
        }
    }
    return ans;
}

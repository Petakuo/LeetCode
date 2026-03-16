int minOperations(char* s) {
    int odd = 0, even = 0;
    int idx = 0;
    while(s[idx] != '\0'){
        if((idx%2) == 0 && s[idx] == '0') even++;
        if((idx%2) == 0 && s[idx] == '1') odd++;
        if((idx%2) == 1 && s[idx] == '1') even++;
        if((idx%2) == 1 && s[idx] == '0') odd++;
        idx++;
    }
    return odd < even ? odd : even;
}

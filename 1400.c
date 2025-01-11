bool canConstruct(char* s, int k) {
    int count[26] = {0};
    int len = strlen(s);
    if(k > len) return 0;
    for(int i = 0; i < len; i++){
        count[s[i]-'a']++;
    }
    int countOdd = 0, countEven = 0;
    for(int i = 0; i < 26; i++){
        if(count[i]%2 == 1) countOdd++;
        if(count[i] != 0 && count[i]%2 == 0) countEven++;
    }
    if(countOdd <= k) return 1;
    return 0;
}

int minimumLength(char* s) {
    int table[26] = {0};
    int len = strlen(s);
    int ans = 0;
    for(int i = 0; i < len; i++){
        table[s[i]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        while(table[i] >= 3){
            table[i] -= 2;
        }
        ans += table[i];
    }
    return ans;
}

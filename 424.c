int characterReplacement(char* s, int k) {
    int table[26] = {0};
    int len = strlen(s);
    int left = 0, right = 0;
    int maxChar = 0, maxlen = 0;
    while(right < len){
        table[s[right]-'A']++;
        maxChar = maxChar > table[s[right]-'A'] ? maxChar : table[s[right]-'A'];
        while(right-left+1-maxChar > k){
            table[s[left]-'A']--;
            left++;
        }
        maxlen = maxlen > (right-left+1) ? maxlen : (right-left+1);
        right++;
    }
    return maxlen;
}

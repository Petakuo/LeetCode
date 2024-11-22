int lengthOfLongestSubstring(char* s) {
    int slen = strlen(s);
    int table[129] = {0};
    int left = 0, right = 0, ans = 0;
    if(slen == 1) return 1;
    while(right < slen){
        table[s[right]-' ']++;
        while(table[s[right]-' '] > 1){
            table[s[left]-' ']--;
            left++;
        }
        ans = ans > (right-left+1) ? ans : (right-left+1);
        right++;
    }
    return ans;
}

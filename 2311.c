int longestSubsequence(char* s, int k) {
    int len = strlen(s);
    int ans = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == '0') ans++;
    }
    int val = 0, base = 1;
    for(int i = len-1; i >= 0; i--){
        if(s[i] == '1' && val+base <= k){
            ans++;
            val += base;
        }
        if((val+base) > k) break;
        base *= 2;
    }
    return ans;
}

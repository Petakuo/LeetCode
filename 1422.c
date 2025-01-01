int maxScore(char* s) {
    int len = strlen(s);
    int left = s[0] == '0' ? 1 : 0;
    int right = 0;
    for(int i = 1; i < len; i++){
        if(s[i] == '1') right++;
    }
    int ans = left+right;
    for(int i = 1; i < len-1; i++){
        if(s[i] == '0') left++;
        if(s[i] == '1') right--;
        ans = ans > left+right ? ans : left+right;
    }
    return ans;
}

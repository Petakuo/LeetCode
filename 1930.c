int countPalindromicSubsequence(char* s) {
    int len = strlen(s);
    int count = 0;
    for(char now = 'a'; now <= 'z'; now++){
        int left = -1, right = -1;
        for(int i = 0; i < len; i++){
            if(s[i] == now){
                if(left == -1) left = i;
                right = i;
            }
        }
        if((left != -1) && right-left >= 2){
            int used[26] = {0};
            for(int i = left+1; i < right; i++){
                if(used[s[i]-'a'] == 0){
                    used[s[i]-'a'] = 1;
                    count++;
                }
            }
        }
    }
    return count;
}

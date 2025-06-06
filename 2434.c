char* robotWithString(char* s) {
    int len = strlen(s);
    int freq[26] = {0};
    for(int i = 0; i < len; i++){
        freq[s[i]-'a']++;
    }
    char now = 'a';
    char* stack = (char*)malloc(len*sizeof(char));
    int top = 0;
    char* ans = (char*)malloc((len+1)*sizeof(char));
    int idx = 0;
    for(int i = 0; i < len; i++){
        stack[top++] = s[i];
        freq[s[i]-'a']--;
        while(now != 'z' && freq[now-'a'] == 0){
            now++;
        }
        while(top > 0 && stack[top-1] <= now){
            ans[idx++] = stack[top-1];
            top--;
        }
    }
    ans[idx] = '\0';
    free(stack);
    return ans;
}

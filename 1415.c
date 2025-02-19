bool backtracking(char* s, int n, int k, int index, int* count){
    if(index == n){
        (*count)++;
        return (*count) == k;
    }
    for(int i = 0; i < 3; i++){
        if((index > 0) && (s[index-1] == 'a'+i)) continue;
        s[index] = 'a'+i;
        if(backtracking(s, n, k, index+1, count)) return 1;
    }
    return 0;
}

char* getHappyString(int n, int k) {
    char* ans = (char*)malloc((n+1)*sizeof(char));
    ans[n] = '\0';
    int count = 0;
    if(!backtracking(ans, n, k, 0, &count)){
        free(ans);
        return "";
    }
    return ans;
}

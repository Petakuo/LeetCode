bool backtracking(char* pattern, char* ans, int len, int index, bool* used){
    if(index == len+1) return 1;
    for(int i = 1; i <= len+1; i++){
        if(!used[i]){
            if(index > 0){
                if((pattern[index-1] == 'I') && (ans[index-1] >= i+'0')) continue;
                if((pattern[index-1] == 'D') && (ans[index-1] <= i+'0')) continue;
            }
            ans[index] = i+'0';
            used[i] = 1;
            if(backtracking(pattern, ans, len, index+1, used)) return 1;
            used[i] = 0;
        }
    }
    return 0;
}

char* smallestNumber(char* pattern) {
    int len = strlen(pattern);
    char* ans = (char*)malloc((len+2)*sizeof(char));
    bool* used = (bool*)calloc(10, sizeof(bool));
    ans[len+1] = '\0';
    backtracking(pattern, ans, len, 0, used);
    return ans;
}

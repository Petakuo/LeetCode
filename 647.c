Sol1: 
bool IsPal(char* s, int left, int right){
    while(left < right){
        if(s[left++] != s[right--]) return 0;
    }
    return 1;
}

int countSubstrings(char* s) {
    int len = strlen(s);
    int ans = len;
    for(int i = 2; i <= len; i++){
        for(int j = 0; j < len-i+1; j++){
            int k = j+i-1;
            if(IsPal(s, j, k)) ans++;
        }
    }
    return ans;
}

Sol2: 
int countSubstrings(char* s) {
    int len = strlen(s);
    int ans = 0;
    for(int i = 0; i < 2*len-1; i++){
        int left = i/2;
        int right = left+i%2;
        while((left >= 0) && (right < len) && (s[left] == s[right])){
            ans++;
            left--;
            right++;
        }
    }
    return ans;
}

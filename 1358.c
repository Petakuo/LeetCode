bool check(int* table){
    for(int i = 0; i < 3; i++){
        if(table[i] < 1) return 0;
    }
    return 1;
}

int numberOfSubstrings(char* s) {
    int len = strlen(s);
    int ans = 0, left = 0, right = 0;
    int* table = (int*)calloc(3, sizeof(int));
    while(right < len){
        table[s[right]-'a']++;
        while(check(table)){
            ans += len-right;
            table[s[left]-'a']--;
            left++;
        }
        right++;
    }
    free(table);
    return ans;
}

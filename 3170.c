char* clearStars(char* s) {
    int len = strlen(s);
    int position[26][len];
    int freq[26] = {0};
    for(int i = 0; i < len; i++){
        if(s[i] != '*'){
            int smallest = s[i]-'a';
            position[smallest][freq[smallest]] = i;
            freq[smallest]++;
        }
        else if(s[i] == '*'){
            int find = 0;
            while(find < 26 && freq[find] == 0){
                find++;
            }
            s[position[find][freq[find]-1]] = '*';
            freq[find]--;
        }
    }
    int idx = 0;
    for(int i = 0; i < len; i++){
        if(s[i] != '*') s[idx++] = s[i];
    }
    s[idx] = '\0';
    return s;
}

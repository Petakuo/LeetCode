char* reorganizeString(char* s) {
    int freq[26] = {0};
    int len = strlen(s);
    int maxLetter = 0;
    for(int i = 0; i < len; i++){
        freq[s[i]-'a']++;
        if(freq[s[i]-'a'] > (len+1)/2) return "";
        maxLetter = freq[maxLetter] > freq[s[i]-'a'] ? maxLetter : s[i]-'a';
    }
    int index = 0;
    while(freq[maxLetter] > 0){
        s[index] = maxLetter+'a';
        index += 2;
        freq[maxLetter]--;
    }
    for(int i = 0; i < 26; i++){
        while(freq[i] != 0){
            if(index >= len) index = 1;
            s[index] = i+'a';
            index += 2;
            freq[i]--;
        }
    }
    return s;
}

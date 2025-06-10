int maxDifference(char* s) {
    int max = 0, min = 100;
    int len = strlen(s);
    int freq[26] = {0};
    for(int i = 0; i < len; i++){
        freq[s[i]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        int val = freq[i];
        if(val != 0){
            if(val%2 == 1) max = max > val ? max : val;
            else min = min < val ? min : val;
        }
    }
    return max-min;
}

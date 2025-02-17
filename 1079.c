void backtracking(int* freq, int* ans){
    for(int i = 0; i < 26; i++){
        if(freq[i] > 0){
            (*ans)++;
            freq[i]--;
            backtracking(freq, ans);
            freq[i]++;
        }
    }
}

int numTilePossibilities(char* tiles) {
    int len = strlen(tiles);
    int freq[26] = {0};
    for(int i = 0; i < len; i++){
        freq[tiles[i]-'A']++;
    }
    int ans = 0;
    backtracking(freq, &ans);
    return ans;
}

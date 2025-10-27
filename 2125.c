int numberOfBeams(char** bank, int bankSize) {
    int ans = 0, prev = 0;
    for(int i = 0; i < bankSize; i++){
        int cur = 0;
        for(int j = 0; bank[i][j] != '\0'; j++){
            if(bank[i][j] == '1') cur++;
        }
        if(cur > 0){
            ans += prev*cur;
            prev = cur;
        }
    }
    return ans;
}

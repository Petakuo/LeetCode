int maximumLength(char* s) {
    int max = -1, len = strlen(s);
    for(int k = 1; k < len-1; k++){
        for(int i = 0; i < len-k+1; i++){
            int count = 1, special = 1;
            for(int j = 1; j < k; j++){
                if(s[i] != s[i+j])
                    special = 0;
            }
            if(special == 0)
                continue;
            for(int j = i+1; j < (len-k+1) && count < 3; j++){
                if(strncmp(s+i, s+j, k) == 0) count++;
            }
            if(count >= 3){
                max = k;
                break;
            }
        }
    }
    return max;
}

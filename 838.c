char* pushDominoes(char* dominoes) {
    int len = strlen(dominoes);
    if(dominoes[0] == '.'){
        int i = 0;
        while(dominoes[i] == '.' && i < len){
            i++;
        }
        if(i == len) return dominoes;
        if(dominoes[i] == 'L'){
            for(i; i > 0; i--){
                dominoes[i-1] = dominoes[i];
            }
        }
    }
    if(dominoes[len-1] == '.'){
        int i = len-1;
        while(dominoes[i] == '.' && i > 0){
            i--;
        }
        if(dominoes[i] == 'R'){
            for(i; i < len-1; i++){
                dominoes[i+1] = dominoes[i];
            }
        }
    }
    for(int i = 1; i < len-1; i++){
        if(dominoes[i] == '.'){
            int temp = i;
            while(dominoes[temp+1] == '.'){
                temp++;
            }
            int count = temp-i+1;
            if(dominoes[i-1] == 'R' && dominoes[temp+1] == 'L'){
                for(int j = i; j < i+count/2; j++){
                    dominoes[j] = 'R';
                }
                for(int j = temp-count/2+1; j <= temp; j++){
                    dominoes[j] = 'L';
                }
            }
            if(dominoes[i-1] == 'R' && dominoes[temp+1] == 'R'){
                for(int j = i; j <= temp; j++){
                    dominoes[j] = 'R';
                }
            }
            if(dominoes[i-1] == 'L' && dominoes[temp+1] == 'L'){
                for(int j = i; j <= temp; j++){
                    dominoes[j] = 'L';
                }
            }
        }
    }
    return dominoes;
}

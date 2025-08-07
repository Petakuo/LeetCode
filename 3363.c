int dpTopRight(int** fruits, int fruitsSize, int* fruitsColSize){
    int* prev = (int*)malloc(fruitsSize*sizeof(int));
    int* cur = (int*)malloc(fruitsSize*sizeof(int));
    for(int i = 0; i < fruitsSize; i++){
        prev[i] = -1;
    }
    prev[fruitsSize-1] = fruits[0][fruitsSize-1];
    for(int i = 1; i < fruitsSize-1; i++){
        for(int j = 0; j < fruitsSize; j++){
            cur[j] = -1;
        }
        for(int j = (fruitsSize-1-i > i+1 ? fruitsSize-1-i : i+1); j < fruitsSize; j++){
            int best = prev[j];
            if(j > 0) best = best > prev[j-1] ? best : prev[j-1];
            if(j < fruitsSize-1) best = best > prev[j+1] ? best : prev[j+1];
            cur[j] = best+fruits[i][j];
        }
        int* temp = prev;
        prev = cur;
        cur = temp;
    }
    int res = prev[fruitsSize-1];
    free(prev);
    free(cur);
    return res;
}

int maxCollectedFruits(int** fruits, int fruitsSize, int* fruitsColSize) {
    int ans = 0;
    for(int i = 0; i < fruitsSize; i++){
        ans += fruits[i][i];
    }
    ans += dpTopRight(fruits, fruitsSize, fruitsColSize);
    for(int i = 0; i < fruitsSize; i++){
        for(int j = i+1; j < *fruitsColSize; j++){
            int temp = fruits[i][j];
            fruits[i][j] = fruits[j][i];
            fruits[j][i] = temp;
        }
    }
    ans += dpTopRight(fruits, fruitsSize, fruitsColSize);
    return ans;
}

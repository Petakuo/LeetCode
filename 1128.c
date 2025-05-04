int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int ans = 0;
    for(int i = 0; i < dominoesSize; i++){
        if(dominoes[i][0] == -1) continue;
        int count = 0;
        for(int j = i+1; j < dominoesSize; j++){
            if((dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]) || (dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0])){
                count++;
                dominoes[j][0] = -1;
            }
        }
        ans += count*(count+1)/2;
    }
    return ans;
}

int numSpecial(int** mat, int matSize, int* matColSize) {
    int ans = 0;
    for(int i = 0; i < matSize; i++){
        int rowi = 0;
        int pos = -1;
        for(int j = 0; j < (*matColSize); j++){
            if(mat[i][j] == 1) rowi++;
            if((mat[i][j] == 1) && (rowi == 1)) pos = j;
            if(rowi > 1) break;
        }
        if((rowi == 1) && (pos > -1)){
            int coli = 0;
            for(int l = 0; l < matSize; l++){
                coli += mat[l][pos];
            }
            if(coli == 1) ans++;
        }
    }
    return ans;
}

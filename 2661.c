int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize) {
    int* table = (int*)calloc(arrSize+1, sizeof(int));
    for(int i = 0; i < arrSize; i++){
        table[arr[i]] = i;
    }
    int ans = arrSize;
    for(int i = 0; i < matSize; i++){
        int finish = -1;
        for(int j = 0; j < (*matColSize); j++){
            if(table[mat[i][j]] > finish) finish = table[mat[i][j]];
        }
        ans = ans > finish ? finish : ans;
    }
    for(int i = 0; i < (*matColSize); i++){
        int finish = -1;
        for(int j = 0; j < matSize; j++){
            if(table[mat[j][i]] > finish) finish = table[mat[j][i]];
        }
        ans = ans > finish ? finish : ans;
    }
    free(table);
    return ans;
}

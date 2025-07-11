Sol1:(O(m*n) space)
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int table[matrixSize][(*matrixColSize)];
    memset(table, 0, sizeof(table));
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < (*matrixColSize); j++){
            if(matrix[i][j] == 0) table[i][j] = 1;
        }
    }
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < (*matrixColSize); j++){
            if(table[i][j] == 1){
                for(int u = i-1; u >= 0; u--){
                    matrix[u][j] = 0;
                }
                for(int d = i+1; d < matrixSize; d++){
                    matrix[d][j] = 0;
                }
                for(int l = j-1; l >= 0; l--){
                    matrix[i][l] = 0;
                }
                for(int r = j+1; r < (*matrixColSize); r++){
                    matrix[i][r] = 0;
                }
            }
        }
    }
}

Sol2:(O(m+n) space)
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int* row = (int*)calloc(matrixSize, sizeof(int));
    int* col = (int*)calloc((*matrixColSize), sizeof(int));
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < (*matrixColSize); j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < (*matrixColSize); j++){
            if(row[i] == 1 || col[j] == 1) matrix[i][j] = 0;
        }
    }
    free(row);
    free(col);
}

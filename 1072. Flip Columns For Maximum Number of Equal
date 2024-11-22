int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize) {
    int max = 0;
    for(int i = 0; i < matrixSize; i++){
        int count = 0;
        for(int j = 0; j < matrixSize; j++){
            int match = 1, flipmatch = 1;
            for(int k = 0; k < (*matrixColSize); k++){
                if(matrix[i][k] != matrix[j][k]) match = 0;
                if(matrix[i][k] == matrix[j][k]) flipmatch = 0;
            }
            if(match || flipmatch) count++;
        }
        max = max > count ? max : count;
    }
    return max;
}

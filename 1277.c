int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int ans = 0;
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[0]; j++){
            if(matrix[i][j] == 1 && i != 0 && j != 0){
                int min = matrix[i-1][j] < matrix[i][j-1] ? matrix[i-1][j] : matrix[i][j-1];
                min = min < matrix[i-1][j-1] ? min : matrix[i-1][j-1];
                matrix[i][j] += min;
            }
            ans += matrix[i][j];
        }
    }
    return ans;
}
